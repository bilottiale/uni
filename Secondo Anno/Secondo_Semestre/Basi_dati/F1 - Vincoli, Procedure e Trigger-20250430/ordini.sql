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

---- tuple inserite nella tabella magazzino:
INSERT INTO MAGAZZINO VALUES (1,150,100);
INSERT INTO MAGAZZINO VALUES (3,130,80);
INSERT INTO MAGAZZINO VALUES (4,170,50);
INSERT INTO MAGAZZINO VALUES (5,500,150);


