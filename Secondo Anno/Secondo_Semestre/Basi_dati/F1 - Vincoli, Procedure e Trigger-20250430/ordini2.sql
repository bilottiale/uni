
-- creazione tabelle del database:

CREATE TABLE MAGAZZINO
	(   COD_PROD        	NUMERIC(3) NOT NULL,
	    QTA_DISP           	NUMERIC(5),
	    QTA_RIORD          	NUMERIC(5),
	    PRIMARY KEY (COD_PROD)
	);

CREATE TABLE RIORDINO
	(   COD_PROD           	NUMERIC(3) NOT NULL,
	    DATA               	DATE,
	    QTA_ORD            	NUMERIC(5),
	    PRIMARY KEY (COD_PROD),
	    FOREIGN KEY (COD_PROD) REFERENCES MAGAZZINO (COD_PROD)
	);


-- funzione PRELIEVO:
	
CREATE FUNCTION prelievo(PROD INTEGER, QUANT INTEGER) RETURNS INTEGER AS $$
	DECLARE
	    Q1 INTEGER;
	    Q2 INTEGER;
	BEGIN
	    SELECT QTA_DISP INTO Q1
	    FROM MAGAZZINO
	    WHERE COD_PROD = PROD;
	    
	    Q2 := Q1 - QUANT;
	            
	    UPDATE MAGAZZINO
	    SET QTA_DISP = Q2
	    WHERE COD_PROD = PROD;
	    
	    RETURN Q2;
	END;
	$$ LANGUAGE plpgsql;

	
-- trigger:

CREATE FUNCTION riordino() RETURNS trigger AS $$
	    BEGIN
	        IF NEW.QTA_DISP < 0 THEN
	            RAISE EXCEPTION 'Modifica impossibile';
	        ELSE   
	            INSERT INTO RIORDINO
	            VALUES(NEW.COD_PROD, CURRENT_DATE, NEW.QTA_RIORD);
	        END IF;
	        RETURN NEW;
	    END;
	$$ LANGUAGE plpgsql;

CREATE TRIGGER GESTIONE_RIORDINO
	AFTER UPDATE ON MAGAZZINO
	FOR EACH ROW
	WHEN (NEW.QTA_DISP < NEW.QTA_RIORD)
	EXECUTE PROCEDURE riordino();


-- Per provare funzione e trigger:

---- tuple inserite nella tabella magazzino:
INSERT INTO MAGAZZINO VALUES (1,150,100);
INSERT INTO MAGAZZINO VALUES (3,130,80);
INSERT INTO MAGAZZINO VALUES (4,170,50);
INSERT INTO MAGAZZINO VALUES (5,500,150);

---- query di esempio: 
SELECT prelievo(1,70);
SELECT prelievo(3,200);



-- funzione ARRIVO_ORDINE:
	
CREATE FUNCTION arrivo_ordine(PROD INTEGER) RETURNS INTEGER AS $$
	DECLARE
	    Q1 INTEGER;
    	    Q2 INTEGER;
	BEGIN
	    SELECT QTA_ORD INTO Q1
	    FROM RIORDINO
	    WHERE COD_PROD = PROD;

	    IF Q1 > 0 THEN
	          UPDATE MAGAZZINO
	          SET QTA_DISP = QTA_DISP + Q1
	          WHERE COD_PROD = PROD;
	          DELETE FROM RIORDINO WHERE COD_PROD = PROD;
                  
	          SELECT QTA_DISP INTO Q2
	          FROM MAGAZZINO
	          WHERE COD_PROD = PROD;

	          RETURN Q2;
	    ELSE 
	          RAISE EXCEPTION 'Riordino non presente';
 	    END IF;    
	END;
	$$ LANGUAGE 'plpgsql';


---- query di esempio: 
SELECT arrivo_ordine(1);
SELECT arrivo_ordine(4);
SELECT arrivo_ordine(1);

