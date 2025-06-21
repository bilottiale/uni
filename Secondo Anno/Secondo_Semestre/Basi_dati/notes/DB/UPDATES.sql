----------------------- UPDATE -----------------------

-- cambio stato ordine
UPDATE ordine
SET stato = 'installazione'
WHERE id = 1 AND cliente = 'Trenitalia S.p.A.';

UPDATE ordine
SET stato = 'validato'
WHERE id = 2
RETURNING *; -- per verificare l'aggiornamento

-- cambio team di un dipendente
UPDATE dipendente
SET id_team = 2
WHERE codice_fiscale = 'BNCLRA88B55F205X';

-- cambio indirizzo di un dipendente
UPDATE dipendente
SET sede_paese = 'Roma',
    sede_via = 'Via Nuova',
    sede_civico = '10',
    "sede_CAP" = 00100
WHERE codice_fiscale = 'BNCLRA88B55F205X';
