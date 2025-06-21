-- View: vista_produzione_dipendente
CREATE OR REPLACE VIEW vista_produzione_dipendente AS
SELECT
    p.id AS produzione_id,
    pr.sku,
    d.nome || ' ' || d.cognome AS dipendente,
    p.data_produzione
FROM produzione p
JOIN prodotto pr ON p.id_prodotto = pr.id
JOIN dipendente d ON p.cf_dipendente = d.codice_fiscale
ORDER BY p.data_produzione DESC;

SELECT * FROM vista_produzione_dipendente;

-- View: vista_prodotti_dettagliati
CREATE OR REPLACE VIEW vista_prodotti_dettagliati AS
SELECT
    p.id AS id_prodotto,
    p.sku,
    p.anno_prod,
    m.nome AS nome_modello,
    m.lunghezza,
    m.larghezza,
    m.altezza,
    d.nome AS nome_dipendente,
    d.cognome AS cognome_dipendente
FROM prodotto p
JOIN modello m ON p.modello = m.nome
LEFT JOIN produzione prod ON p.id = prod.id_prodotto
LEFT JOIN dipendente d ON prod.cf_dipendente = d.codice_fiscale;

SELECT * FROM vista_prodotti_dettagliati;

-- View: vista_ordini_clienti
CREATE OR REPLACE VIEW vista_ordini_clienti AS
SELECT
    o.id AS id_ordine,
    c.rag_soc AS cliente,
    o.quantità,
    o.prezzo,
    o.stato,
	o.team,
    a.nome AS amministratore,
    a.cognome AS cognome_amministratore
FROM ordine o
JOIN cliente c ON o.cliente = c.rag_soc
LEFT JOIN amministratore a ON o.id_amministratore = a.id_amministratore;

SELECT * FROM vista_ordini_clienti;

-- View: vista_materiali_per_componente
CREATE OR REPLACE VIEW vista_materiali_per_componente AS
SELECT
    cm.nome_comp AS componente,
    cm.nome_mat AS materiale,
    cm.quantità,
    m.prezzo,
    f.nome AS fornitore
FROM componente_materiale cm
JOIN materiale m ON cm.nome_mat = m.nome
JOIN fornitore f ON m.fornitore = f.nome;

SELECT * FROM vista_materiali_per_componente;

-- View: vista_installazioni_per_tratta
CREATE OR REPLACE VIEW vista_installazioni_per_tratta AS
SELECT
    i.prodotto_id,
    t.inizio_tratta,
    t.fine_tratta,
    i.data_installazione,
    d.nome AS installatore,
    d.cognome AS cognome_installatore
FROM installazione i
JOIN tratta t ON i.inizio_tratta = t.inizio_tratta AND i.fine_tratta = t.fine_tratta
LEFT JOIN dipendente d ON i.cf_dipendente = d.codice_fiscale;

SELECT * FROM vista_installazioni_per_tratta;


--- Indice prodotto_modello
CREATE INDEX idx_prodotto_modello ON prodotto(modello);

EXPLAIN ANALYZE
SELECT * FROM vista_ordini_clienti
WHERE cliente = 'Trenitalia S.p.A.';

-- ALTRI INDICI
-- Stato ordini
CREATE INDEX idx_ordine_stato ON ordine(stato);

-- Amministratore sugli ordini
CREATE INDEX idx_ordine_admin ON ordine(id_amministratore);

-- Team ordine
CREATE INDEX idx_ordine_team ON ordine(team);

-- Ruolo dipendenti
CREATE INDEX idx_dipendente_ruolo ON dipendente(ruolo);

-- Team dipendenti
CREATE INDEX idx_dipendente_team ON dipendente(id_team);

-- Composizione per modello
CREATE INDEX idx_composizione_modello ON composizione(modello_id);

-- Materiali per componente
CREATE INDEX idx_comp_mat_mat ON componente_materiale(nome_mat);

-- Produzione per prodotto
CREATE INDEX idx_produzione_prodotto ON produzione(id_prodotto);

-- Produzione per dipendente
CREATE INDEX idx_produzione_dipendente ON produzione(cf_dipendente);

-- Certificazioni per prodotto
CREATE INDEX idx_certificazione_prodotto ON certificazione(prodotto_id);

-- Materiale per fornitore
CREATE INDEX idx_materiale_fornitore ON materiale(fornitore);

-- Installazioni per data
CREATE INDEX idx_installazione_data ON installazione(data_installazione);
