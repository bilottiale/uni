-- Tot ordini e medio per cliente
SELECT
  c.rag_soc AS cliente,
  COUNT(o.id) AS numero_ordini,
  SUM(o.prezzo * o.quantità) AS valore_totale_euro,
  ROUND(AVG(o.prezzo * o.quantità)::numeric, 2) AS valore_medio_per_ordine
FROM ordine o
JOIN cliente c ON o.cliente = c.rag_soc
GROUP BY c.rag_soc
ORDER BY valore_totale_euro DESC;

-- modelli più prodotti ultimo anno
WITH produzioni_ultimi_12_mesi AS (
  SELECT
    id_prodotto,
    data_produzione
  FROM produzione
  WHERE data_produzione >= CURRENT_DATE - INTERVAL '1 year'
)
SELECT
  m.nome                                             AS modello,
  COUNT(p.id)                                        AS quantita_prodotti,
  RANK() OVER (ORDER BY COUNT(p.id) DESC)            AS posizione
FROM produzioni_ultimi_12_mesi pr
JOIN prodotto p ON pr.id_prodotto = p.id
JOIN modello m   ON p.modello = m.nome
GROUP BY m.nome
ORDER BY quantita_prodotti DESC
LIMIT 5;

