----------------------- Types: ENUM -----------------------
CREATE TYPE stato_ordine AS ENUM ('ordinato', 'in produzione', 'installazione', 'validato');
CREATE TYPE tipo_cliente AS ENUM ('pubblico', 'privato');
CREATE TYPE tipo_tratta AS ENUM ('merci', 'urbana');

----------------------- DROP/TRUNCATE all -----------------------

-- DROP/TRUNCATE TABLEs
DROP TABLE
    installazione,
    produzione,
    prodotto,
    composizione,
    componente_materiale,
    componente,
    materiale,
    fornitore,
    ordine,
    report,
    modello,
    tratta,
    dipendente,
    team,
    amministratore,
    sede,
    cliente,
	certificazione
CASCADE
-- RESTART IDENTITY CASCADE;

----------------------- INDICI -----------------------

-- ordine cliente
CREATE INDEX idx_ordine_cliente ON ordine(cliente);
SELECT * FROM ordine WHERE cliente = 'Trenitalia S.p.A.';

-- ruolo dipendente
CREATE INDEX idx_ruolo_dipendente ON dipendente(ruolo);
SELECT * FROM dipendente WHERE ruolo = 'installatore';

-- prodotto modello
CREATE INDEX idx_prodotto_modello ON prodotto(modello_id);
SELECT COUNT(*) FROM prodotto WHERE modello_id = 2;

-- prodotto modello
CREATE INDEX idx_prodotto_dipendente ON prodotto(cf_dipendente);
SELECT * FROM prodotto WHERE cf_dipendente = 'BNCLRA88B55F205X';

-- certificazione
CREATE INDEX idx_certificazione_prodotto ON certificazione(prodotto_id);
SELECT * FROM certificazione WHERE prodotto_id = 5;

-- tratta installazione (multicolonna)
CREATE INDEX idx_installazione_tratta ON installazione(inizio_tratta, fine_tratta);
SELECT * FROM installazione WHERE inizio_tratta = 'Milano' AND fine_tratta = 'Bologna';

\di -- mostra indici


----------------------- VISTE -----------------------

CREATE OR REPLACE VIEW vista_produzione_dipendente AS
SELECT 
    p.id AS produzione_id,
    pr.sku,
    d.nome || ' ' || d.cognome AS dipendente,
    p.data_produzione
FROM produzione p
JOIN prodotto pr ON p.prodotto_id = pr.id
JOIN dipendente d ON p.cf_dipendente = d.codice_fiscale
ORDER BY p.data_produzione DESC;

-- Prodotti dettagliati
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

-- Ordini clienti
CREATE OR REPLACE VIEW vista_ordini_clienti AS
SELECT
  o.id AS id_ordine,
  c.rag_soc AS cliente,
  o."quantità",
  o.prezzo,
  o.stato,
  a.nome AS amministratore,
  a.cognome AS cognome_amministratore
FROM ordine o
JOIN cliente c ON o.cliente = c.rag_soc
LEFT JOIN amministratore a ON o.id_amministratore = a.id_amministratore;

SELECT * FROM vista_ordini_clienti;

-- Materiali per componente
CREATE OR REPLACE VIEW vista_materiali_per_componente AS
SELECT
  cm.nome_comp AS componente,
  cm.nome_mat AS materiale,
  cm."quantità",
  m.prezzo,
  f.nome AS fornitore
FROM componente_materiale cm
JOIN materiale m ON cm.nome_mat = m.nome
JOIN fornitore f ON m.fornitore = f.id;

SELECT * FROM vista_materiali_per_componente;

-- Installazioni per tratta
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


END;