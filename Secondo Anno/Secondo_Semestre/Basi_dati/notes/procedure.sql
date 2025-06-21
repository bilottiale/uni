----------------------- PRODCEDURE -----------------------

-- Crea ordine
CREATE OR REPLACE PROCEDURE crea_ordine(
    cliente_input VARCHAR,
    prezzo_input SMALLINT,
    quantita_input INTEGER,
    stato_input stato_ordine,
    id_amm_input VARCHAR
)
LANGUAGE plpgsql
AS $$
BEGIN
    IF quantita_input <= 0 THEN
        RAISE EXCEPTION 'La quantità deve essere positiva';
    END IF;

    INSERT INTO ordine (cliente, prezzo, "quantità", stato, id_amministratore)
    VALUES (cliente_input, prezzo_input, quantita_input, stato_input, id_amm_input);
END;
$$;

-- Chiamata della procedura
CALL crea_ordine('Trenitalia S.p.A.', 10000, 100, 'ordinato', 'amm01');


-- Registra installazione
CREATE OR REPLACE PROCEDURE registra_installazione(
    prodotto_id_input INTEGER,
    cf_dipendente_input VARCHAR,
    inizio_tratta_input VARCHAR,
    fine_tratta_input VARCHAR,
    data_input DATE DEFAULT CURRENT_DATE
)
LANGUAGE plpgsql
AS $$
DECLARE
    ruolo_dip TEXT;
BEGIN
    -- Controlla che il prodotto esista
    IF NOT EXISTS (SELECT 1 FROM prodotto WHERE id = prodotto_id_input) THEN
        RAISE EXCEPTION 'Prodotto con ID % non esistente', prodotto_id_input;
    END IF;

    -- Controlla che il dipendente sia un installatore
    SELECT ruolo INTO ruolo_dip FROM dipendente WHERE codice_fiscale = cf_dipendente_input;

    IF ruolo_dip IS NULL THEN
        RAISE EXCEPTION 'Dipendente non trovato';
    ELSIF ruolo_dip <> 'installatore' THEN
        RAISE EXCEPTION 'Dipendente con CF % non è un installatore', cf_dipendente_input;
    END IF;

    -- Inserimento installazione
    INSERT INTO installazione (prodotto_id, cf_dipendente, inizio_tratta, fine_tratta, data_installazione)
    VALUES (prodotto_id_input, cf_dipendente_input, inizio_tratta_input, fine_tratta_input, data_input);
END;
$$;

-- Chiamata della procedura
CALL registra_installazione(3, 'BNCLRA88B55F205X', 'Milano', 'Bologna');


-- Aggiorna stato ordine
CREATE OR REPLACE PROCEDURE aggiorna_stato_ordine(
    ordine_id_input INTEGER,
    cliente_input VARCHAR,
    nuovo_stato stato_ordine
)
LANGUAGE plpgsql
AS $$
BEGIN
    IF NOT EXISTS (
        SELECT 1 FROM ordine
        WHERE id = ordine_id_input AND cliente = cliente_input
    ) THEN
        RAISE EXCEPTION 'Ordine non trovato per id % e cliente %', ordine_id_input, cliente_input;
    END IF;

    UPDATE ordine
    SET stato = nuovo_stato
    WHERE id = ordine_id_input AND cliente = cliente_input;
END;
$$;

-- Chiamata della procedura
CALL aggiorna_stato_ordine(1, 'Trenitalia S.p.A.', 'in produzione');