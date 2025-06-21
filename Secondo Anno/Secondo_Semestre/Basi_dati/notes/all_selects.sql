SELECT * FROM amministratore;

SELECT * FROM cliente;

SELECT * FROM componente;

SELECT * FROM componente_materiale;

SELECT * FROM dipendente;

SELECT * FROM fornitore;

SELECT * FROM installazione;

SELECT * FROM materiale;

SELECT * FROM ordine;

SELECT * FROM prodotto;

SELECT * FROM produzione;

SELECT * FROM report;

SELECT * FROM tratta;

SELECT * FROM modello;

SELECT * FROM composizione;


----------------------- SELECT Viste -----------------------

-- Ordini con quantità > 50
SELECT * FROM vista_ordini_completi
WHERE "quantità" > 50;

-- Prodotti realizzati nel 2024
SELECT * FROM vista_prodotti_modelli
WHERE anno_prod = 2024;

-- Installazioni effettuate in questo mese
SELECT * FROM vista_installazioni
WHERE DATE_TRUNC('month', data_installazione) = DATE_TRUNC('month', CURRENT_DATE);

-- Modelli con almeno 3 componenti
SELECT modello, COUNT(*) AS num_componenti
FROM vista_composizione_modelli
GROUP BY modello
HAVING COUNT(*) >= 3;

