# Analisi delle Distribuzioni delle variabili nel Dataset `storms`
Nel presente esercizio, è stata analizzata la distribuzione delle variabili **"velocità del vento"** e **"pressione"** nel dataset `storms`, contenente informazioni su 425 tempeste tropicali avvenute nell'Atlantico. L'obiettivo è esplorare come queste due variabili siano distribuite e come la categoria della tempesta influenzi la pressione e la velocità del vento.
## Distribuzione della Velocità del Vento
La distribuzione della velocità del vento nel dataset presenta una forma **positivamente asimmetrica**. La maggior parte delle tempeste ha velocità del vento relativamente basse, con una ridotta frequenza di tempeste che presentano velocità del vento molto elevate. In particolare, le tempeste di bassa categoria (come la Categoria 1 e 2) tendono ad avere velocità del vento comprese tra 50 e 100 mph, mentre le tempeste di categoria superiore (come la Categoria 4 e 5) presentano velocità del vento molto più elevate, ma sono meno frequenti.
**Conclusioni sulla distribuzione della velocità del vento:**
- La distribuzione è **positivamente asimmetrica**, con una concentrazione di tempeste a bassa velocità del vento.
- Le velocità del vento superiori ai 100 mph sono meno frequenti e associate alle tempeste di categoria più alta.
## Distribuzione della Pressione
La distribuzione della pressione atmosferica mostra una forma **negativamente asimmetrica**. La maggior parte delle tempeste ha valori di pressione relativamente alti (superiori a 990 mb), mentre un numero ridotto di tempeste, soprattutto quelle di categoria superiore, mostra valori di pressione molto bassi. Le tempeste di alta categoria (come la Categoria 4 e 5) presentano pressioni molto basse, generalmente inferiori ai 940 mb, mentre le tempeste di bassa categoria (come la Categoria 1 e 2) hanno valori di pressione più elevati.
**Conclusioni sulla distribuzione della pressione:**
- La distribuzione è **negativamente asimmetrica**, con una maggiore frequenza di tempeste a pressioni più elevate.
- Le pressioni molto basse sono più comuni nelle tempeste di categoria alta e più rare nelle tempeste di categoria bassa.
## Impatto sui grafici:
Poiché la variabile `category` è un fattore, nei grafici viene trattata come una variabile qualitativa, e non numerica. Questo consente di distinguere i gruppi di tempeste in base alla loro categoria, utilizzando colori differenti per ogni categoria. Nei grafici a istogramma ogni barra verrà colorata in base alla categoria della tempesta, facilitando la comparazione tra le diverse categorie di tempeste.
Se la variabile fosse stata trattata come una variabile numerica, potrebbe essere stato difficile rappresentare correttamente la natura categorica della variabile, creando confusione nel visualizzare le distribuzioni delle categorie di tempesta.
## Conclusioni
L'analisi delle distribuzioni delle variabili **velocità del vento** e **pressione** conferma che, in generale, le tempeste di **alta categoria** tendono ad avere **basse pressioni** e **alte velocità del vento**. Queste osservazioni sono coerenti con la comprensione fisica dei cicloni tropicali, dove l'intensità della tempesta aumenta con l'abbassamento della pressione atmosferica e l'aumento della velocità del vento.
