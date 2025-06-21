Buongiorno, sono Bilotti Alessandro e in questo video presenterò il progetto di database realizzato per il corso di base di dati.

"Il progetto consiste nello sviluppo completo di un sistema relazionale per la gestione della produzione, installazione, gestione ordini e altro per GreenRail, azienda che produce traversine per le ferrovie.


CLIENTI E ORDINI:
cliente: contiene le informazioni identificative dei clienti, pubblici o privati (tipo_cliente è un ENUM). La chiave primaria è composta da rag_soc e id per garantire univocità e storicizzazione.

ordine: collega i clienti con gli ordini. Ogni ordine ha una quantità, un prezzo e uno stato definito da un ENUM (stato_ordine: es. "ordinato", "in produzione", "installato", ecc.).

id_amministratore: indica quale amministratore ha gestito l’ordine.

[comment]: <> (separare ordini dai clienti permette di avere uno storico degli ordini associati a più amministratori (svolgono funzione di controllo))

PRODUZIONE E CERTIFICAZIONE
modello: contiene le specifiche tecniche di ogni modello di prodotto, come dimensioni, carico assi e tipo di cemento.

prodotto: istanze fisiche dei modelli. Ogni prodotto ha un sku generato automaticamente da un trigger.

produzione: rappresenta la registrazione della produzione effettuata da un dipendente su un determinato prodotto.

certificazione: ogni prodotto può avere un certificato rilasciato da un ente certificante, con data di rilascio e scadenza.

[comment]: <> (questa struttura consente di separare la progettazione (del modello singolo), dalla produzione reale (prodotto generico))

INSTALLZIONE E TRATTE
tratta: definisce un segmento geografico (inizio/fine) di linea ferroviaria, con il tipo (tipo_tratta: urbana o merci).

installazione: collega un prodotto installato a una tratta, indicando il dipendente che l’ha eseguita e la data.

[comment]: <> (modellare in modo esplicito le tratte e le installazioni permette la tracciabilità geografica)

COMPONENTI E MATERIALI
componente: componenti fisici usati per comporre un modello (es. ruote, assi, blocchi).

materiale: materie prime fornite da un fornitore.

componente_materiale: relazione molti-a-molti che indica quali materiali compongono un dato componente.

composizione: dice quali componenti e in che quantità compongono un modello.

[comment]: <> (separando componenti dai materiali possiamo gestire sia il costo che la tracciabilità delle singole risorse)

STRUTTURA AZIENDALE
dipendente: identifica ogni lavoratore, con ruolo (es. "installatore", "produttore") e sede.

sede: ogni dipendente è associato a una sede, utile anche per aggiornare il numero di dipendenti automaticamente tramite trigger.

team: organizzazione in gruppi di lavoro, ciascuno sotto un amministratore.

amministratore: utenti che possono gestire ordini, report e supervisione.

[comment]: <> (pre tracciare i vari dipendenti, che, in team, lavorano sui prodotti)

Ora vediamo come implementare il tutto tramite SQL


------------------------- VISTE ------------------------------
Le viste sono “finestre virtuali” sul database: sono query salvate che ci permettono
di accedere a dati "complessi" in modo semplice e strutturato, come se fossero tabelle.
Ci semplificano le interrogazioni.

vista_prodotti_dettagliati: mostra informazioni unendo le tabelle prodotto + modello + dipendente

vista_ordini_clienti: Unisce ordine + cliente + amministratore

vista_produzione_dipendente: unisce produzione e dati del dipendente

vista_materiali_per_componente: per la tracciabilità materiali

vista_installazioni_per_tratta: collega tratte e installazioni





Query:
SELECT 
    p.id AS prodotto_id,
    m.nome AS modello,
    c.nome_comp AS componente,
    comp."quantità"
FROM 
    prodotto p
JOIN modello m ON p.modello_id = m.id
JOIN composizione comp ON p.id = comp.prodotto_id
JOIN componente c ON comp.nome_comp = c.nome_comp;

- JOIN su 3 tabelle

--------------------------------------------------------

SELECT 
    o.id AS ordine_id,
    o.stato,
    c.rag_soc,
    c.tipo,
    o."quantità",
    o.prezzo
FROM 
    ordine o
JOIN cliente c ON o.cliente = c.rag_soc
WHERE 
    c.tipo = 'pubblico';

- Tipo ENUM
- Filtro condizionale

----------------------------------------------------------

SELECT 
    cm.nome_mat AS materiale,
    SUM(comp."quantità" * cm."quantità") AS totale_materiale
FROM 
    composizione comp
JOIN componente_materiale cm ON comp.nome_comp = cm.nome_comp
WHERE 
    comp.prodotto_id = 1
GROUP BY 
    cm.nome_mat;

- Usa JOIN con moltiplicazione tra quantità di componenti e materiale per ottenere fabbisogno totale.
- Uso di GROUP BY e SUM

TRIGGER QUANTITà (prodotto) -> prova quantità negativa

trigger genera sku


