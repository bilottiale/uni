-- DROP/TRUNCATE TABLEs
TRUNCATE TABLE
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
RESTART IDENTITY CASCADE;

-- Modello
INSERT INTO modello
(nome, carico_assi, v_max, tipo_cem, peso, lunghezza, larghezza, altezza)
VALUES
('GR 260',    25, 250, 'C50/60', 390, 2600, 320, 266),
('GR 240',    25, 250, 'C50/60', 340, 2400, 320, 266),
('GR 230',    25, 250, 'C50/60', 270, 2300, 320, 225),
('GR 190',    15, 250, 'C50/60', 240, 1900, 320, 224),
('GR B 70',   25, 250, 'C50/60', 280, 2600, 317, 253),
('GR B 70CH', 25, 250, 'C50/60', 280, 2600, 317, 253);

SELECT * FROM modello;


-- Prodotto
INSERT INTO prodotto (modello, anno_prod) VALUES
('GR 260', 2023),
('GR 240', 2023),
('GR 230', 2024);

SELECT * FROM prodotto;


-- Amministratore
INSERT INTO amministratore (id_amministratore, nome, cognome, email, telefono) VALUES
('amm01', 'Laura', 'Rossi', 'laura.rossi@greenrail.com', '3281122334'),
('amm02', 'Marco', 'Verdi', 'marco.verdi@greenrail.com', '3299988776');

SELECT * FROM amministratore;


-- Cliente
INSERT INTO cliente (id, tipo, rag_soc, cod_fis, email, telefono) VALUES
(1, 'pubblico', 'Trenitalia S.p.A.', 'TRNITL1234567890', 'info@trenitalia.it', '0647891234'),
(2, 'privato', 'Logistica Verde SRL', 'LGVSRL9876543210', 'info@logverde.it', '0591234567'),
(3, 'privato', 'Italo Spa', '9876543210ABCDEF', 'ordini@italo.it', '0643219876');

SELECT * FROM cliente where rag_soc ='Trenitalia S.p.A.';


-- Componente
INSERT INTO componente (nome, descrizione, "quantità") VALUES
('Telaio', 'componente strutturale', 5),
('Ruota', 'componente meccanica', 12),
('Motore', 'componente elettrico', 10);

SELECT * FROM componente;

-- Fornitore
INSERT INTO fornitore (id, nome, email, telefono) VALUES
(1, 'Forniture Industriali S.p.A.', 'ind_forn@mail.com', '0112345678'),
(2, 'Materiali Ecologici SRL', 'eco_mat@mail.com', '0123456789'),
(3, 'Componenti Tecnologici Spa', 'tech@mail.com', '0987654321');

SELECT * FROM fornitore;


-- Materiale
INSERT INTO materiale (nome, descrizione, prezzo, fornitore) VALUES
('Acciaio (90% riciclato)', 'Acciaio ad alta resistenza con il 90% di materiale riciclato', 50, 'Forniture Industriali S.p.A.'),
('Gomma (100% riciclato)', 'Gomma ecologica al 100% riciclata', 30, 'Materiali Ecologici SRL'),
('Elettronica', 'Componenti elettronici per motori e sistemi di controllo', 200, 'Componenti Tecnologici Spa');

SELECT * FROM materiale;


-- Componente_materiale
INSERT INTO componente_materiale (nome_comp, nome_mat, "quantità") VALUES
('Telaio', 'Acciaio (90% riciclato)', 10),
('Ruota', 'Gomma (100% riciclato)', 4),
('Motore', 'Elettronica', 1);

SELECT * FROM componente_materiale;


-- Composizione
INSERT INTO composizione (modello_id, nome_comp, "quantità") VALUES
(1, 'Telaio', 1),
(1, 'Ruota', 4),
(1, 'Motore', 1),
(2, 'Telaio', 1),
(2, 'Ruota', 4),
(2, 'Motore', 1),
(3, 'Telaio', 1),
(3, 'Ruota', 4),
(3, 'Motore', 1);

SELECT * FROM composizione;

--INSERT INTO composizione (modello_id, nome_comp, "quantità") VALUES
--(1, 'Telaio', 0); -- errore quantità < 0


-- Sede
INSERT INTO sede (paese, via, civico, "CAP", n_dipendenti) VALUES
('Italia', 'Via Milano', '10', 20100, 5),
('Italia', 'Via Roma', '22A', 40100, 3);

SELECT * FROM sede;

-- Team
INSERT INTO team (id, nome, id_amministratore) VALUES
(1, 'Squadra 1', 'amm01'),
(2, 'Squadra 2', 'amm02');

SELECT * FROM team;


-- Dipendente
INSERT INTO dipendente (
  codice_fiscale, nome, cognome, email, telefono, ruolo, id_team,
  sede_paese, sede_via, sede_civico, "sede_CAP"
) VALUES
('RSSMRA90A01F205X', 'Mario', 'Rossi', 'mario.rossi@greenrail.com', '3331234567', 'installatore', 1, 'Italia', 'Via Milano', '10', 20100),
('BNCLRA88B55F205X', 'Lara', 'Bianchi', 'lara.bianchi@greenrail.com', '3347654321', 'produttore', 2, 'Italia', 'Via Roma', '22A', 40100),
('BNCLRA88B55F105F', 'Antonio', 'Rossi', 'a.r@greenrail.com', '3347654321', 'installatore', 2, 'Italia', 'Via Roma', '22A', 40100);

SELECT * FROM dipendente;


-- Tratta
INSERT INTO tratta (inizio_tratta, fine_tratta, lunghezza, tipo) VALUES
('Milano', 'Bologna', 215, 'merci'),
('Roma', 'Napoli', 230, 'urbana');

SELECT * FROM tratta;


-- Installazione
INSERT INTO installazione (prodotto_id, cf_dipendente, inizio_tratta, fine_tratta, data_installazione) VALUES
(1, 'BNCLRA88B55F205X', 'Milano', 'Bologna', CURRENT_DATE),
(2, 'BNCLRA88B55F205X', 'Roma', 'Napoli', CURRENT_DATE);

SELECT * FROM installazione;


-- Ordine
INSERT INTO ordine (id, cliente, prezzo, "quantità", stato, id_amministratore, team) VALUES
(1, 'Trenitalia S.p.A.', 10000, 100, 'ordinato', 'amm01', 1),
(2, 'Italo Spa', 8000, 80, 'in produzione', 'amm02', 2);

SELECT * FROM ordine;


-- Produzione
INSERT INTO produzione (id_prodotto, cf_dipendente, data_produzione) VALUES
(1, 'BNCLRA88B55F205X', CURRENT_DATE),
(2, 'BNCLRA88B55F205X', '2022-08-01'),
(3, 'BNCLRA88B55F205X', '2024-01-15');

SELECT * FROM produzione;


-- Report
INSERT INTO report (titolo, contenuto, id_amministratore)
VALUES (
    'Report produzione 2024',
    'Produzione completata con successo per i modelli GR 260 e GR 240. Nessun difetto rilevato.',
    'amm01'
),
(
    'Report installazioni 2024',
    'Installazioni effettuate con successo in Lombardia e Campania. Tutti i prodotti funzionanti.',
    'amm02'
),
('Report trimestrale', 'Analisi delle vendite e produzione del primo trimestre 2024.', 'amm01'),
('Report annuale', 'Riepilogo delle attività e performance aziendali del 2023.', 'amm02');

SELECT * FROM report;


-- Certificazione
INSERT INTO certificazione (codice, prodotto_id, data_rilascio, validità, descrizione, ente_certificante)
VALUES
('CERT-2024-001', 1, '2024-01-01', '2025-01-01', 'Certificazione di qualità per il modello GR 260', 'Ente Certificatore Italiano'),
('CERT-2024-002', 2, '2024-02-01', '2025-02-01', 'Certificazione di sicurezza per il modello GR 240', 'Ente Certificatore Europeo');

SELECT * FROM certificazione;
