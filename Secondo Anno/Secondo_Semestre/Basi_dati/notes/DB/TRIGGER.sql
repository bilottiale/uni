----------------------- TRIGGERs -----------------------

-- Generazione SKU
-- Crea la funzione di trigger
CREATE OR REPLACE FUNCTION genera_sku()
RETURNS TRIGGER AS $$
BEGIN
  NEW.sku := 'TRV-' || NEW.modello::text || '-' || NEW.anno_prod::text;
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

-- ID certificato
CREATE OR REPLACE FUNCTION genera_id_certificazione()
RETURNS trigger AS $$
DECLARE
    sigla_emittente text;
BEGIN
    -- Usa il campo corretto 'ente_certificante'
    sigla_emittente := upper(substring(NEW.ente_certificante from 1 for 3));
    -- Assegna il valore generato alla colonna 'codice' (chiave primaria)
    NEW.codice := 'CERT-' || NEW.prodotto_id || '-' || to_char(NEW.data_rilascio, 'YYYYMMDD') || '-' || sigla_emittente;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Trigger che associa la funzione alla tabella certificazione
DROP TRIGGER IF EXISTS trg_generazione_id_cert ON public.certificazione;
CREATE TRIGGER trg_generazione_id_cert
BEFORE INSERT ON public.certificazione
FOR EACH ROW
EXECUTE FUNCTION genera_id_certificazione();
