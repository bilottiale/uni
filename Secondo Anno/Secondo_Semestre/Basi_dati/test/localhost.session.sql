-- -- IMPLEMENTAZIONE DATABASE GREENRAIL (PostgreSQL)

-- -- =========================
-- -- 1. CREAZIONE DEL DATABASE
-- -- =========================
-- --CREATE DATABASE greenrail;

-- -- =========================
-- -- 2. TABELLE
-- -- =========================
-- -- CLIENTE
-- CREATE TABLE Cliente (
--     id_cliente SERIAL PRIMARY KEY,
--     ragione_sociale VARCHAR(100),
--     partita_iva VARCHAR(20) UNIQUE,
--     tipo_cliente VARCHAR(10) CHECK (tipo_cliente IN ('Pubblico', 'Privato')),
--     contatti VARCHAR(100)
-- );

-- -- PRODOTTO
-- CREATE TABLE Prodotto (
--     id_prodotto SERIAL PRIMARY KEY,
--     nome VARCHAR(100),
--     prezzo NUMERIC,
--     num_componenti INTEGER DEFAULT 0
-- );

-- -- COMPONENTE
-- CREATE TABLE Componente (
--     id_componente SERIAL PRIMARY KEY,
--     nome VARCHAR(100),
--     tipo VARCHAR(50),
--     prezzo NUMERIC,
--     peso NUMERIC
-- );

-- -- COMPOSIZIONE (relazione tra Prodotto e Componente)
-- CREATE TABLE Composizione (
--     id_prodotto INTEGER REFERENCES Prodotto(id_prodotto),
--     id_componente INTEGER REFERENCES Componente(id_componente),
--     PRIMARY KEY (id_prodotto, id_componente)
-- );

-- -- ORDINE
-- CREATE TABLE Ordine (
--     id_ordine SERIAL PRIMARY KEY,
--     data DATE,
--     id_cliente INTEGER REFERENCES Cliente(id_cliente)
-- );

-- -- INCLUDE (relazione tra Ordine e Prodotto)
-- CREATE TABLE Include (
--     id_ordine INTEGER REFERENCES Ordine(id_ordine),
--     id_prodotto INTEGER REFERENCES Prodotto(id_prodotto),
--     quantita INTEGER,
--     PRIMARY KEY (id_ordine, id_prodotto)
-- );

-- -- =========================
-- -- 3. INDICI
-- -- =========================
-- CREATE INDEX idx_composizione_prodotto ON Composizione(id_prodotto);
-- CREATE INDEX idx_composizione_componente ON Composizione(id_componente);
-- CREATE INDEX idx_include_ordine ON Include(id_ordine);

-- -- =========================
-- -- 4. VISTE
-- -- =========================
-- -- Vista: componenti di un prodotto
-- CREATE VIEW VistaComponenti AS
-- SELECT 
--     p.id_prodotto,
--     p.nome AS nome_prodotto,
--     c.id_componente,
--     c.nome AS nome_componente,
--     c.tipo,
--     c.prezzo
-- FROM Prodotto p
-- JOIN Composizione comp ON p.id_prodotto = comp.id_prodotto
-- JOIN Componente c ON comp.id_componente = c.id_componente;

-- -- Vista: prodotti di un ordine
-- CREATE VIEW VistaOrdineProdotti AS
-- SELECT 
--     o.id_ordine,
--     c.ragione_sociale,
--     p.nome AS nome_prodotto,
--     i.quantita
-- FROM Ordine o
-- JOIN Cliente c ON o.id_cliente = c.id_cliente
-- JOIN Include i ON o.id_ordine = i.id_ordine
-- JOIN Prodotto p ON i.id_prodotto = p.id_prodotto;

-- -- =========================
-- -- 5. QUERY ESEMPIO
-- -- =========================
-- -- Numero componenti per prodotto
-- SELECT id_prodotto, COUNT(*) AS num_componenti
-- FROM Composizione
-- GROUP BY id_prodotto;

-- -- Prezzo totale per ordine
-- SELECT o.id_ordine, SUM(p.prezzo * i.quantita) AS totale
-- FROM Ordine o
-- JOIN Include i ON o.id_ordine = i.id_ordine
-- JOIN Prodotto p ON i.id_prodotto = p.id_prodotto
-- GROUP BY o.id_ordine;

-- -- =========================
-- -- 6. TRIGGER
-- -- =========================
-- -- Aggiorna num_componenti in Prodotto ogni volta che si inserisce in Composizione
-- CREATE OR REPLACE FUNCTION aggiorna_num_componenti()
-- RETURNS TRIGGER AS $$
-- BEGIN
--     UPDATE Prodotto
--     SET num_componenti = (
--         SELECT COUNT(*)
--         FROM Composizione
--         WHERE id_prodotto = NEW.id_prodotto
--     )
--     WHERE id_prodotto = NEW.id_prodotto;
--     RETURN NEW;
-- END;
-- $$ LANGUAGE plpgsql;

-- CREATE TRIGGER trg_aggiorna_num_componenti
-- AFTER INSERT OR DELETE ON Composizione
-- FOR EACH ROW
-- EXECUTE FUNCTION aggiorna_num_componenti();
-- Vedi tutti i prodotti (anche se vuoto)
-- Inserisci un prodotto di prova
INSERT INTO Prodotto (nome, prezzo) VALUES ('Binario Eco', 1000);

-- Visualizza
SELECT * FROM Prodotto;
