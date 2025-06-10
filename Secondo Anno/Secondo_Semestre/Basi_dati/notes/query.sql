----------------------- ENUM -----------------------
CREATE TYPE stato_ordine AS ENUM ('ordineto', 'in produzione', 'installazione', 'validato');
CREATE TYPE tipo_cliente AS ENUM ('pubblico', 'privato');
CREATE TYPE tipo_modello AS ENUM ('GR 260', 'GR 240', 'GR 230', 'GR 190', 'GR B 70', 'GR B 70CH');
CREATE TYPE tipo_tratta AS ENUM ('merci', 'urbana');

----------------------- INSERT -----------------------

-- Modello
INSERT INTO public.modello
(nome, carico_assi, v_max, tipo_cem, peso, lunghezza, larghezza, altezza)
VALUES
('GR 260',    25, 250, 'C50/60', 390, 2600, 320, 266),
('GR 240',    25, 250, 'C50/60', 340, 2400, 320, 266),
('GR 230',    25, 250, 'C50/60', 270, 2300, 320, 225),
('GR 190',    15, 250, 'C50/60', 240, 1900, 320, 224),
('GR B 70',   25, 250, 'C50/60', 280, 2600, 317, 253),
('GR B 70CH', 25, 250, 'C50/60', 280, 2600, 317, 253);

SELECT * FROM modello;

-- Cliente
INSERT INTO public.cliente (id, tipo, rag_soc, cod_fis, email, telefono) VALUES
(1, 'pubblico', 'Trenitalia S.p.A.', 'TRNITL1234567890', 'info@trenitalia.it', '0647891234'),
(2, 'privato', 'Logistica Verde SRL', 'LGVSRL9876543210', 'info@logverde.it', '0591234567'),
(3, 'privato', 'Italo Spa', '9876543210ABCDEF', 'ordini@italo.it', '0643219876');

SELECT * FROM cliente;

-- Ordine
INSERT INTO ordine (id, cliente, prezzo, "quantità", stato, id_amministratore) VALUES
(1, 'Trenitalia S.p.A.', 10000, 100, 'ordinato', 'amm01'),
(2, 'Italo Spa', 8000, 80, 'in produzione', 'amm02');

SELECT * FROM ordine;

-- Amministratore
INSERT INTO public.amministratore (id_amministratore, nome, cognome, email, telefono) VALUES
('amm01', 'Laura', 'Rossi', 'laura.rossi@greenrail.com', '3281122334'),
('amm02', 'Marco', 'Verdi', 'marco.verdi@greenrail.com', '3299988776');

SELECT * FROM amministratore;

-- Sede
INSERT INTO public.sede (paese, via, civico, "CAP", n_dipendenti) VALUES
('Italia', 'Via Milano', '10', 20100, 5),
('Italia', 'Via Roma', '22A', 40100, 3);

SELECT * FROM sede;

-- Team
INSERT INTO public.team (id, nome, id_amministratore) VALUES
(1, 'Squadra 1', 'amm01'),
(2, 'Squadra 2', 'amm02');

SELECT * FROM team;

-- Dipendente
INSERT INTO public.dipendente (
  codice_fiscale, nome, cognome, email, telefono, ruolo, id_team,
  sede_paese, sede_via, sede_civico, "sede_CAP"
) VALUES
('RSSMRA90A01F205X', 'Mario', 'Rossi', 'mario.rossi@greenrail.com', '3331234567', 'installatore', 1, 'Italia', 'Via Milano', '10', 20100),
('BNCLRA88B55F205X', 'Lara', 'Bianchi', 'lara.bianchi@greenrail.com', '3347654321', 'produttore', 2, 'Italia', 'Via Roma', '22A', 40100);

SELECT * FROM dipendente

-- Prodotto
INSERT INTO public.prodotto (modello_id, anno_prod, cf_dipendente) VALUES
(1, 2023, 'BNCLRA88B55F205X'),
(2, 2023, 'BNCLRA88B55F205X'),
(3, 2024, 'BNCLRA88B55F205X');

SELECT * FROM prodotto;

-- Report
INSERT INTO public.report (titolo, contenuto, id_amministratore)
VALUES (
    'Report produzione 2024',
    'Produzione completata con successo per i modelli GR 260 e GR 240. Nessun difetto rilevato.',
    'amm01'
);

SELECT * FROM report;


----------------------- TRIGGER -----------------------

-- Generazione SKU
-- Crea la funzione di trigger
CREATE OR REPLACE FUNCTION genera_sku()
RETURNS TRIGGER AS $$
BEGIN
  NEW.sku := 'TRV-' || NEW.modello_id::text || '-' || NEW.anno_prod::text;
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Crea il trigger collegato alla tabella prodotto
DROP TRIGGER IF EXISTS trg_genera_sku ON prodotto;

CREATE TRIGGER trg_genera_sku
BEFORE INSERT ON prodotto
FOR EACH ROW
EXECUTE FUNCTION genera_sku();

-- Check qty > 0
-- Crea la funzione di trigger
CREATE OR REPLACE FUNCTION check_quantita_composizione()
RETURNS TRIGGER AS $$
BEGIN
  IF NEW."quantità" <= 0 THEN
    RAISE EXCEPTION 'La quantità deve essere maggiore di zero';
  END IF;
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Crea il trigger collegato
DROP TRIGGER IF EXISTS trg_check_quantita_composizione ON composizione;

CREATE TRIGGER trg_check_quantita_composizione
BEFORE INSERT OR UPDATE ON composizione
FOR EACH ROW
EXECUTE FUNCTION check_quantita_composizione();

-- Aggiorna n dipendenti
-- Crea la funzione di trigger
CREATE OR REPLACE FUNCTION aggiorna_n_dipendenti()
RETURNS TRIGGER AS $$
BEGIN
  -- Aggiorna il conteggio dopo INSERT
  IF TG_OP = 'INSERT' THEN
    UPDATE sede
    SET n_dipendenti = n_dipendenti + 1
    WHERE paese = NEW.sede_paese AND via = NEW.sede_via AND civico = NEW.sede_civico AND "CAP" = NEW."sede_CAP";
  END IF;

  -- Aggiorna il conteggio dopo DELETE
  IF TG_OP = 'DELETE' THEN
    UPDATE sede
    SET n_dipendenti = n_dipendenti - 1
    WHERE paese = OLD.sede_paese AND via = OLD.sede_via AND civico = OLD.sede_civico AND "CAP" = OLD."sede_CAP";
  END IF;

  RETURN NULL;
END;
$$ LANGUAGE plpgsql;


-- Crea il trigger collegato
DROP TRIGGER IF EXISTS trigger_aggiorna_n_dipendenti ON composizione;

CREATE TRIGGER trigger_aggiorna_n_dipendenti
AFTER INSERT OR DELETE ON dipendente
FOR EACH ROW
EXECUTE FUNCTION aggiorna_n_dipendenti();


----------------------- VISTE -----------------------

-- Prodotti dettagliati
CREATE OR REPLACE VIEW vista_prodotti_dettagliati AS
SELECT
  p.id AS prodotto_id,
  p.sku,
  p.anno_prod,
  m.nome AS nome_modello,
  m.lunghezza,
  m.larghezza,
  m.altezza,
  d.nome AS nome_dipendente,
  d.cognome AS cognome_dipendente
FROM prodotto p
JOIN modello m ON p.modello_id = m.id
LEFT JOIN dipendente d ON p.cf_dipendente = d.codice_fiscale;

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