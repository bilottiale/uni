# Cinematica
## Vettori e scalari
Un *vettore* è una grandezza definita attraverso una intensità e una direzione orientata. La forza è un esempio di grandezza vettoriale.
$$
\mathbf{F} \text{ oppure } \vec{F}
$$
Intensità o modulo di un vettore: $F \text{ o }|\mathbf{F}| \text{ o } |\vec{F}|$.
Direzione orientata di un vettore: esempio, "$20°$ rispetto all'asse $x$".
Uno *scalare* è una grandezza definita da un numero. La massa di un oggetto è un esempio di grandezza scalare.
$$
m
$$
Rappresentazione di un vettore:
![[Pasted image 20241128140121.png|50]]
La lunghezza del segmento indica l'intensità del vettore.
### Somma di due vettori
Per sommare Per sommare graficamente due vettori $A$ e $B$ bisogna disegnarli collocandoli “punta-coda”. Il risultato della somma $A+B$ è un vettore che punta dalla coda del primo vettore alla punta del secondo vettore.
![[Pasted image 20241128140253.png|200]]
### Prodotto di uno scalare per un vettore
Moltiplicare o dividere un vettore per uno scalare equivale a moltiplicare o dividere il modulo del vettore per il valore assoluto dello scalare, lasciando invariata la direzione e il verso se lo scalare è positivo, invertendo il verso se lo scalare è negativo.
![[Pasted image 20241128140402.png|200]]
### Scomposizione di un vettore nelle sue componenti cartesiane
![[Pasted image 20241128140547.png|400]]
**Esempio**:
Il vettore $A$ ha modulo $5.00m$ e ha direzione orientata coincidente con quella dell'asse $x$ del riferimento cartesiano in figura. Il vettore $B$ ha modulo $3.00m$ e forma un angolo di $120°$ con l'asse $x$.
- Calcolare $C = A + B$
![[Pasted image 20241128140731.png|200]]
Sappiamo che:
$$
\begin{gather}
\sin \theta = \frac{\text{opp}}{\text{hyp}} \\
\cos \theta = \frac{\text{adj}}{\text{hyp}} \\
\tan \theta = \frac{\sin \theta}{\cos \theta} = \frac{\text{opp}}{\text{adj}}
\end{gather}
$$
Scomponiamo $B$:
$$
\begin{align}
&\sin(180°-120°) = \frac{B_{y}}{B} \Rightarrow B_{y} = B\sin 60° = (3.00m)\sin 60° = 2.60m \\
&\cos(180°-120°) = \frac{-B_{x}}{B} \Rightarrow B_{x} = -B\cos 60° = -(3.00m)\cos 60° = -1.5m
\end{align}
$$
Con $A_{x}=5.00m$ e $A_{y}=0.00m$.
Calcoliamo le componenti di $C$:
$$
\begin{align}
&C_{x} = A_{x} + B_{x} = 5.00m+(-1.5)m = 3.5m \\
&C_{y} = A_{y} + B_{y} = 0.00m + 2.6m = 2.6m
\end{align}
$$
Calcoliamo il modulo di $C$:
$$
\begin{align}
C &= |C| = \sqrt{ C_{x}^{2} + C_{y}^{2} } \\
&= \sqrt{ (3.5m)^{2} + (2.6m)^{2} } \\
&= 4.36m
\end{align}
$$
La direzione di $C$:
$$
\begin{align}
&\tan \theta = \frac{C_{y}}{C_{x}} = \frac{2.60m}{3.50m} = 0.7429 \\
&\theta = \tan^{-1}(0.7429) = 36.6° \text{ rispetto all'asse }x 
\end{align}
$$
![[Pasted image 20241128142301.png|400]]
# Le forze
**Come si misura una forza?**
Per esempio con una bilancia a molla.
Appendendo masse diverse ad una molla otteniamo che l’allungamento della molla $\propto$ forza applicata(entro certi limiti di massa).
![[Pasted image 20241128144504.png|100]]
Le forze sono grandezze vettoriali.
L’unità di misura della forza nel SI è il *Newton*($N$).
### Prima legge della dinamica (o principio di inerzia)
Un corpo in quiete rimane fermo se la somma delle forze che agiscono su di esso è nulla o nel caso in cui non agisca alcuna forza. Se il corpo è in movimento, continuerà a muoversi di moto rettilineo uniforme.
**L'inerzia** è una misura della resistenza di un corpo a cambiamenti del suo stato di moto.
### Seconda legge della dinamica (di Newton)
La forza che agisce su un corpo è direttamente proporzionale alla massa del corpo e all’accelerazione, ha stessa direzione e verso.  
Quindi, l’accelerazione è proporzionale alla forza e inversamente proporzionale alla massa.
$$
F = m \cdot a
$$
### Terza legge della dinamica (o principio di azione e reazione)
Per ogni forza che un corpo A esercita su un altro corpo B, ne esiste un’altra uguale, in modulo e direzione, e contraria in verso, che B esercita su A.
$$
F_{AB} = -F_{AB}
$$
## Diagramma di corpo libero
![[Pasted image 20241128150153.png|400]]
# Forze a lungo raggio
## Gravità
La gravità è la forza, sempre attrattiva, tra due masse. È una forza a lungo raggio: non è richiesto contatto tra i due corpi.
$$
F = G \frac{M_{1}M_{2}}{r^{2}}
$$
$r$ è la distanza tra le due masse $M_{1}$ e $M_{2}$ e $G=6.67\times 10^{-11}Nm^{2}/kg^{2}$.
![[Pasted image 20241013145758.png|400]]
**Esempio**:
Qual è la forza di attrazione gravitazionale tra due persone di 50 Kg e 75 Kg ad una distanza di 50 cm?
Sostituendo nella forza di gravità:
$$
\begin{gather}
F = 6.67 \times 10^{-11} Nm^{2}/kg^{2} \frac{50kg\times 75kg}{50^{2}cm} \\
F = 1 \times 10^{-6}N 
\end{gather}
$$
**Esempio**:
Il centro della Luna dista dal centro della Terra $3.9\times10^{5} km$. La massa del Sole è di $2.0\times10^{30} kg$ e la massa della Terra è di $6.0\times10^{24} kg$. La distanza della Luna dal Sole è di $1.5\times10^{8} km$. Si trovi il rapporto tra la forza esercitata sulla Luna dalla Terra e dal Sole.
Facendo il rapporto tra le due forze coinvolte:
$$
\frac{F_{TL}}{F_{SL}}=\frac{m_{T}}{m_{S}} \frac{d^{2}_{LS}}{d^{2}_{TL}}=0,44
$$
**Il peso**:
Sia $M_{E}$ la masse della Terra $= 5.98 \times 10^{24 kg}$.
$$
F = \left(G \frac{M_{E}}{r^{2}}\right)M_{2}
$$
$F$ è la forza che la Terra esercita sulla massa $M_{2}$. Questa forza si chiama peso, $w$.
$$
w=\left(G \frac{M_{E}}{r^{2}}\right)M_{2} = gM_{2}
$$
$$
r_{E}=6400km
$$
dove $g=\frac{GM_{e}}{r^{2}_{E}}=9.8N/kg=9.8m/s^{2}$ vicino la superficie della Terra.
**Esempio**:
Qual’è il peso di un astronauta di massa $100 kg$ sulla superficie della Terra? Come cambia il peso se l’astronauta si trova in orbita a circa $300 km$ dalla superficie della Terra?
- Sulla Terra: $w=mg=980N$
- In orbita: $w=mg(r_{o})=m(\frac{GM_{E}}{(R_{E}+h)^{2}})=890N$
Il peso è ridotto di circa $10\%$.
## Il campo gravitazionale
$$
g=\frac{F}{m}
$$
È la forza gravitazionale per unità di massa. Questa quantità si chiama intensità sul corpo gravitazionale o "*accelerazione*" dovuta alla gravità.
$g$ dipende solo dalla massa della Terra.
Il peso dipende sia da $g$ che dalla massa "partner" dell'attrazione gravitazionale.
**Esempio**:
L’intensità del campo gravitazionale sulla Luna è circa $1/6$ di quello alla superficie della terra. Se $m$ and $w$ sono la massa e il peso di una persona sulla terra, quanto varranno le stesse quantità sulla luna?
$$
1m,\quad \frac{1}{6}w
$$
La massa non cambia, il peso sì.
# Forze di contatto
## La forza normale
Questa forza agisce in direzione perpendicolare alla superficie di contatto. 
![[Pasted image 20241128151101.png|250]]![[Pasted image 20241128151217.png|153]]
## Attrito
**È una forza di contatto parallela alla superficie di contatto tra due corpi.**
- **Attrito statico**: impedisce agli oggetti di scivolare.
- **Attrito dinamico**: rallenta il moto degli oggetti.
### Forza di attrito statico
$$
f_{s}\leq \mu_{s}N
$$
$\mu_{s}$ è il coefficiente di attrito **statico** ed $N$ è la forza normale.
### Forza di attrito dinamico
$$
f_{k}=\mu_{k}N
$$
$\mu_{k}$ è il coefficiente di attrito **dinamico** ed $N$ la forza normale.
**Esempio**:
Uno scatolone pieno di libri è appoggiato su un pavimento di legno. La forza normale che il pavimento esercita sullo scatolone è di $250 N$. Spingendo orizzontalmente con una forza di $120 N$ lo scatolone non si sposta. Cosa si può dire riguardo al coefficiente di attrito statico tra lo scatolone e il pavimento? Con una forza di $150 N$ lo scatolone comincia a spostarsi. Cosa si può dire riguardo al coefficiente di attrito statico tra lo scatolone e il pavimento? Una volta in movimento, basta spingere lo scatolone con una forza di $120 N$. Cosa si può dire riguardo al coefficiente di attrito dinamico tra lo scatolone e il pavimento?
1. Spingi orizzontalmente la scatola con una forza di $120 N$, ma questa non si muove. Che cosa puoi dire riguardo al coefficiente di attrito tra la scatola e il pavimento?
$$
\begin{align}
&(1)\sum F_{y} = N - w = 0 \\
&(2)\sum F_{x} = F- f_{S} = 0
\end{align}
$$
![[Pasted image 20241013152859.png|200]]
Da $(2)$:
$$
F=f_{s}=\mu_{s}N \Longrightarrow \mu_{s} = \frac{F}{N}=0.48
$$
Questo è il valore minimo di $\mu_{s}$, quindi $\mu_{s}>0.48$.
2. Se devi spingere orizzontalmente la scatola con una forza di $150 N$ affinché si metta in movimento, qual è il coefficiente di attrito statico?
da $(2)$:
$$
F=f_{s}=\mu_{s}N \Longrightarrow = \frac{F}{N}=0.60
$$
3. Una volta che la scatola si muove, devi spingere solo con una forza di $120 N$ per mantenerla in movimento. Qual è il coefficiente d’attrito dinamico?
da $(2)$:
$$
F=f_{k}=\mu_{k}N \Longrightarrow \frac{F}{N} = \frac{120N}{250N} = 0.48
$$
## La tensione
È la forza trasmessa attraverso una fune da un estremo all’altro.
Una fune ideale ha massa trascurabile non si deforma e mantiene la stessa tensione lungo tutta la lunghezza.
**Esempio**:
Una carrucola è appesa al soffitto attraverso una corda. Un blocco di massa $M$ è sospeso attraverso un’altra corda che scorre sulla carrucola ed è attaccata alla parete. La corda fissata alla parete forma con la parete stessa un angolo retto. Trascurando le masse delle corde e della carrucola calcolare la tensione della corda che sostiene la carrucola e l’angolo $\theta$.
![[Pasted image 20241013154912.png|250]]![[Pasted image 20241013154935.png|196]]
$$
\sum F_{y}=T-w=0
$$
$$
T = w = mg
$$
Applicando la *seconda legge di Newton*:
$$
\sum F_{x}=F\cos \theta-T=0
$$
$$
\sum F_{y}=F\sin \theta-T=0
$$
L'uguaglianza è vera solo se $\theta=45°$ e
$$
F=\sqrt{ 2 }T=\sqrt{ 2 }Mg
$$
## La forza elastica
In assenza di attrito la forza elastica genera un moto periodico.
$$
F=-kx
$$
![[Pasted image 20241013155355.png|300]]
## Posizione e spostamento
La **posizione** $r$ di un oggetto descrive la sua collocazione rispetto ad una *origine*.
$$
\Delta r = r_{\text{finale}}-r_{\text{iniziale}}
$$
Lo **spostamento** rappresenta la variazione della posizione di un oggetto. Dipende solo dalle posizioni iniziale e finale.
## Velocità
La **velocità** è un vettore che misura quanto rapidamente e in quale direzione orientata un oggetto puntiforme si muove.
*Velocità media*:
$$
v_{\text{media}}=\frac{\Delta r}{\Delta t}
$$
**Velocità istantanea = derivata temporale dello spostamento**
$$
\vec{v}=\lim_{ \Delta t \to 0 }\frac{\Delta \vec{s}}{\Delta t} = \frac{d\vec{s}}{dt}
$$
$$
\vec{s} = \int \vec{v} \, dt
$$
In un grafico di posizione vs tempo la **velocità media** è rappresentata dalla pendenza della corda:
![[Pasted image 20241011172450.png|300]]
Velocità media $= v_{\text{media}}=\frac{x_{2}-x_{1}}{t_{2}-t_{1}}$.
In un grafico di posizione vs tempo la **velocità istantanea** è rappresentata dalla pendenza della tangente alla curva $x(t)$ all'istante considerato:
![[Pasted image 20241011172733.png|300]]
## Notazione di Leibnitz per le derivate e gli integrali
Sia $y = f(x)$ una funzione reale dell’incognita reale $x$. Chiamiamo derivata prima della $f(x)$ la funzione:
$$
f'(x) = \lim_{ h \to 0 } \frac{f(x+h)-f(x)}{h}
$$
Nella notazione di Leibnitz la derivata si denota così:
$$
\frac{dy}{dx} = \frac{df}{dx}
$$
Per le derivate di ordine successivo:
$$
\begin{gather}
f'' = f^{(2)} = \frac{d^{2}f}{dx^{2}} \\
f''' = f^{(3)} = \frac{d^{3}f}{dx^{3}} \\
\vdots \\
f^{(n)} = \frac{d^{n}f}{dx^{n}} 
\end{gather}
$$
Il concetto di differenziale e la notazione di Leibnitz vengono ripresi nella definizione matematica di integrale. Se $y=f(x)$ è una funzione reale definita nell’intervallo $(a,b)$ della variabile indipendente $x$ e suddiviso questo intervallo in n suddivisioni di ampiezza $\delta$:
$$
\begin{gather}
\lim_{ \delta \to 0 } \sum_{i=0}^{n-1} f(x_{i})(x_{i+1}-x_{i}) = \int_{a}^{b} f(x) dx \\
= F(b)-F(a) \text{ con } \frac{dF}{dx} = f(x) \\
\int\frac{dF(x)}{dx} dx = \int dF(x) = F(x) + \text{costante}
\end{gather}
$$
- $F(x)$ primitiva
- $f(x)$ derivata
## Accelerazione media e istantanea
*Accelerazione media*:
$$
\vec{a}_{av} = \frac{\Delta \vec{v}}{\Delta t}
$$
*Accelerazione istantanea*:
$$
\vec{a} = \lim_{ \Delta t \to 0 } \frac{\Delta \vec{v}}{\Delta t} = \frac{d\vec{v}}{dt} = \frac{d^{2}\vec{s}}{dt^{2}}
$$
In coordinate cartesiane:
$$
a_{x} = \frac{dv_{x}}{dt} = \frac{d^{2}x}{dt^{2}} \quad a_{y} = \frac{dv_{y}}{dt} = \frac{d^{2}y}{dt^{2}} \quad a_{z} = \frac{dv_{z}}{dt} = \frac{d^{2}z}{dt^{2}}
$$
In generale il vettore $\vec{a}$ avrà una componente parallela alla traiettoria(*accelerazione tangenziale*) ed una componente perpendicolare alla traiettoria(*accelerazione normale*).
**Esempio**:
Un’auto che viaggia a 28 m/s viene decelerata fino ad un completo arresto in 4 s. Trovare la decelerazione media durante la frenata.
$$
\text{Dati }v_{i}=28m/s,v_{f}=0m/s,\text{ e }\Delta t=4s
$$
$$
a_{av}=\frac{\Delta v}{\Delta t} = \frac{0-28m/s}{4s}=-7m/s^{2}
$$
**Esempio**:
km/h a 45° a ovest della direzione nord.
- Disegnare i vettori velocità iniziale e finale.
- Trovare il vettore $\Delta v$.
- Qual è l’accelerazione media durante il viaggio?
1. 
![[Pasted image 20241013142745.png|200]]
2. Le componenti sono:
$$
\Delta v_{x}=v_{fx}-v_{ox}=-v_{f}\sin45°-0=-170km/h
$$
$$
\Delta v_{y}=v_{fy}-v_{oy}=+v_{f}\cos45°-v_{0}=-22.3km/h
$$
$$
|\Delta v|=\sqrt{ \Delta v_{x}^{2}+\Delta v_{y}^{2} }=171km/h
$$
$$
\tan \phi=\frac{|\Delta v_{y}|}{|\Delta v_{x}|}=0.1312 \Longrightarrow \phi = \tan^{-1}(0.1312)=7.5° \text{(sud-ovest)}
$$
3. Qual'è $a_{av}$?
$$
a_{av}=\frac{\Delta v}{\Delta t}
$$
$$
a_{x,av}=\frac{\Delta v_{x}}{\Delta t}=\frac{-170km/h}{3h}=-56.7km/h^{2}
$$
$$
a_{y,av}=\frac{\Delta v_{y}}{\Delta t}=\frac{-22.3km/h}{3h}=-7.43km/h^{2}
$$
Il modulo e la posizione sono:
$$
|a_{av}|=\sqrt{ a_{x,av}^{2}+a_{y,av}^{2} }=57.2km/h^{2}
$$
$$
\tan \phi = \frac{|a_{y,av}|}{|a_{x,av}|}=0,1310 \Longrightarrow \phi = \tan^{-1}(0.1310)=7.5° \text{ (sud-ovest)}
$$
# Seconda legge di Newton
Si chiama **somma risultante** la somma vettoriale $\sum \mathbf{F}$ di tutte le forze applicate ad un corpo.
La forza risultante agente su un corpo è direttamente proporzionale all’ accelerazione del corpo. La costante di proporzionalità è chiamata **massa**(inerziale) del corpo.
$$
\begin{gather}
\sum \mathbf{F} = m\mathbf{a} \\
\text{Unità della forza: }1N = 1kg \ m/s^{2}
\end{gather}
$$
Se $\mathbf{a}=0$, allora $\sum\mathbf{F}=0$, in questo caso:
- $v=0$ *equilibrio statico*, $\mathbf{o}$.
- $v\neq 0\text{ (costante)}$ *equilibrio dinamico*.
**Esempio**:
Trovare la tensione che agisce sulla corda che collega i due blocchi in figura quando una forza di $10 N$ viene applicata al blocco di destra. Supporre trascurabile l’attrito. Le masse dei due blocchi sono $m_{1} = 3.00 kg$ e $m_{2} = 1.00 kg$.
![[Pasted image 20241013160342.png|300]]
Assumi che la corda rimanga tesa cosicché entrambi i blocchi abbiano la stessa accelerazione.
![[Pasted image 20241013160441.png|400]]
$$
\begin{align}
F-&T=m_{1}a \quad(1) \\
&T=m_{2}a \quad(2)
\end{align}
$$
Queste 2 equazioni contengono le incognite: $a$ and $T$.
Per risolvere per $T$, $a$ deve essere eliminata. Risolvi per $a$ in $(2)$ e sostituisci in $(1)$.
$$
\begin{gather}
F-T=m_{1}a=m_{1}\left( \frac{T}{m_{2}} \right) \\
F=m_{1}\left( \frac{T}{m_{2}} \right)+T=\left( 1+\frac{m_{1}}{m_{2}} \right)T \\
\therefore T = \frac{F}{\left( 1+\frac{m_{1}}{m_{2}} \right)}= \frac{10N}{\left( 1+\frac{3kg}{1kg} \right)}=2.5N
\end{gather}
$$
**Esempio**:
Una scatola scivola su una superficie rugosa. Sapendo che il coefficiente di attrito dinamico è $0,3$ calcolare l’accelerazione della scatola.
![[Pasted image 20241013161302.png|200]]
Applica la seconda legge di Newton:
$$
\begin{gather}
\sum F_{x}=-F_{k}=ma \\
\sum F_{y}=N-w=0
\end{gather}
$$
$$
\begin{align}
(1) \quad &-F_{k}=ma \\
(2) \quad &N-w=0 \quad \therefore N=w=mg
\end{align}
$$
Da $(1)$: $-F_{k} =-\mu_{k}mg = ma$
Risolvendo per $a$:
$$
a=-\mu_{k}g=-(0.3)(9.8m/s^{2})=-2.94m/s^{2}
$$
## Composizione delle velocità
![[Pasted image 20241013162008.png|500]]
**Esempio**:
Il motore di una barca la fa muovere rispetto all’acqua di una velocità $v_{ba}=4.0m/s$, secondo la direzione perpendicolare alla corrente. Se la velocità dell’acqua rispetto alla riva è $v_{ar} =2.0 m/s$, quanto vale la velocità $v_{br}$ della barca rispetto alla riva? Se il fiume è largo $1800m$, quanto tempo impiega la barca per attraversarlo?
![[Pasted image 20241013162157.png|250]]
1. Rispetto alla riva, la velocità della barca (vettore) ha due componenti:
	- Una lungo $x$ ($v_{ar}$)
	- Una lungo $y$ ($v_{ba}$)
![[Pasted image 20241013162330.png|250]]
2. Il modulo della velocità totale $v_{TOT}$ della barca sarà dato:
$$
v_{TOT}=\sqrt{ v^{2}_{ar}+v^{2}_{ba} }=(\sqrt{ 4^{2}+2^{2} })m/s=4.5m/s
$$
La direzione della velocità è individuato dall’ angolo $\alpha$ formato dal vettore velocità totale $v_{TOT}$ con l’asse $x$.
Dalla trigonometria so che la tangente dell'angolo $\alpha$ è pari al rapporto tra i cateti:
$$
\tan \alpha=\frac{v_{ba}}{v_{ar}}=2
$$
da cui $\alpha=\tan^{-1} 2=63°$.
3. La seconda parte del problema chiede: ‘se il fiume è largo $1800m$, quanto tempo impiega la barca per attraversarlo?’.
Dalla velocità della barca si risale al tempo necessario per percorrere $1800 m$, infatti:
$$
\text{Sapendo che }v_{ba}=\frac{y}{t} \Longrightarrow t=\frac{y}{v_{ba}}=\frac{1800m}{4m/s}=450s
$$
## Quantità di moto
La quantità vettoriale $p = mv$ è chiamata quantità di moto o “*momento lineare*”.
La sua unità di misura è $kg \ m/s$.
La *seconda legge della dinamica* per una particella di massa $m$ costante si può scrivere in termini della quantità di moto:
$$
\mathbf{F}=m\mathbf{a}=m \ \frac{\Delta \mathbf{v}}{\Delta t}= \frac{\Delta \mathbf{p}}{\Delta t}
$$
## Teorema dell'impulso
*Se la risultante delle forze applicate al corpo è nulla la quantità di moto si conserva.*
Per un sistema di particelle in cui le forze sono solo interne (cioè esercitate da particelle del sistema su altre particelle del sistema) la risultante delle forze applicate al corpo è nulla per la terza legge della dinamica e la quantità di *moto TOTALE* si conserva.
# Moti unidimensionali
## Moto rettilineo con velocità costante (uniforme)
- $\mathbf{v}$ costante
- $x=vt+x_{0} \quad a=0$
![[Pasted image 20241013164257.png|300]]
$$
\begin{align}
&v = \frac{\Delta x}{\Delta t} \quad\quad \Delta x = v\Delta t \rightarrow \int_{x_{0}}^{x(t)} dx' = \int_{0}^{t} dt'v \\ \\
&\rightarrow x(t) - x_{0} = v \cdot (t-0) \text{ da cui } x(t)=x_{0}+vt
\end{align}
$$
**Esempio**:
Un cane che corre a $10 m/s$ è a $30 m$ dietro un coniglio che si muove a $5m/s$. Quando il cane raggiungerà il coniglio? Disegnare i diagrammi $x$-$t$ e $v$-$t$ per il moto del cane e del coniglio.
![[Pasted image 20241013164408.png|500]]
1. Sia il moto del cane sia il moto del coniglio sono due moti rettilinei uniformi. Per cui le leggi orarie (spostamento in funzione del tempo) che descrivono i due moti sono dati da:
$$
\begin{align}
&x_{cane}=x_{0_{cane}}+v_{cane}t \\
&x_{coniglio}=x_{0_{coniglio}}+v_{coniglio}t
\end{align}
$$
dove $v_{cane}=10m/s$ e $v_{coniglio}=5m/s$. All'istante iniziale il cane si trova $30 m$ dietro il coniglio, ovvero:
$$
x_{0_{cane}}=x_{0_{coniglio}}-30m
$$
2. Quando il cane raggiunge il coniglio
$$
\begin{align}
&x_{cane}=x_{coniglio} \\
&x_{0_{cane}}+v_{cane}t=x_{0_{coniglio}}+v_{coniglio}t \text{ sapendo che }x_{0_{cane}}=x_{0_{coniglio}}-30m \\
&x_{0_{coniglio}}-30m+v_{cane}t=x_{0_{coniglio}}+v_{coniglio}t
\end{align}
$$
Risolvendo l'ultima rispetto al tempo si ottiene:
$$
t=\frac{30m}{v_{cane}-v_{coniglio}}=6s
$$
3. ![[Pasted image 20241013164825.png|250]]
## Moto rettilineo con accelerazione costante
Formule in notazione di Leibniz:
- Sia $v_{0}$ la velocità a $t=0$.
- Sia $x_{0}$ la posizione del corpo a $t=0$.
$$
\begin{align}
a=\frac{dv}{dt} \quad\quad &dv=adt \rightarrow \int_{v_{0}}^{v(t)} dv'=\int_{0}^{t} dt'a \\
&\rightarrow v(t)-v_{0}=a\cdot(t-0) \text{ da cui } v(t)=v_{0}+at
\end{align}
$$
$$
\begin{align}
v=\frac{dx}{dt} \quad &dx=vdt \rightarrow \int_{x_{0}}^{x(t)}dx'=\int_{0}^{t}dt'(v_{0}+at') \\
&\rightarrow x(t)-x_{0}=\int_{0}^{t}dt'(v_{0}+at')= \\
&\int_{0}^{t}dt'v_{0}+a\int_{0}^{t}t'dt'= \\
&v_{0}t+\frac{1}{2}at^{2}
\end{align}
$$
*Se l’accelerazione è costante le equazioni cinematiche sono*:
![[Pasted image 20241013165630.png|500]]
**Esempio**:
Si supponga di dover disegnare un sistema di air-bag che possa proteggere il guidatore nel caso di un urto frontale alla velocità di $100 km/h$. Stimare quanto rapidamente si deve gonfiare l’air-bag per proteggere efficacemente il guidatore. Supporre che, in conseguenza dell’urto, l’auto si accartocci di $1 m$.
$$
\begin{align}
v_{i} = &100km/h = \frac{10^{2}\times10^{3}}{3.6\times 10^{3}} \frac{m}{s} = 0.28 \times 10^{2}m/s \\
v_{f} = &0 \\
\overline{a} = &\frac{v_{f}-v_{i}}{\Delta t} \\
\Delta x = &\frac{1}{2}\overline{a}\Delta t^{2}+v_{i}\Delta t=1m \\
&\frac{1}{2} \frac{\Delta v}{\Delta t}\Delta t^{2}+v_{i}\Delta t = 1m \\
&\left(\frac{1}{2}\Delta v+v_{i}\right)\Delta t=1m \\
\Delta t &= \frac{1m}{\frac{1}{2}(v_{f}+v_{i})}= \frac{1m}{\frac{1}{2}v_{f}-\frac{1}{2}v_{i}+v_{i}} \\
&=\frac{1m}{\frac{1}{2}(v_{f}+v_{i})}=\frac{1m}{\frac{1}{2}\cdot 0.28 \times 10^{2}} \\
&=7.14 \times 10^{-2}s = 0.07s
\end{align}
$$
## Caduta libera
Un sasso è lanciato dalla cima di una collina. Trascurando la resistenza dell’aria solo la forza di gravità agisce sul sasso. Diciamo che iI sasso è in **caduta libera**.
il diagramma di corpo libero del sasso è:
![[Pasted image 20241013171752.png|150]]
Applicando la seconda legge di Newton:
$$
\begin{align}
\sum F_{y}&=-w=mg=ma \\
a&=-g-9.8N/kg \\
&=-9.8m/s^{2}
\end{align}
$$
### Resistenza dell'aria
Se in un moto di caduta sotto l’azione della forza di gravità la resistenza dell’aria NON si può trascurare il diagramma di corpo libero del corpo si modifica come segue:
Dalla seconda legge di Newton:
$$
\sum F_{y}=F_{d}-w=ma
$$
dove $F_{d}$ è l'intensità della forza d'attrito ($d=$drag).
Questa forza è in verso opposto alla velocità e ad essa proporzionale:
$$
F_{d}=bv^{2}
$$
con $b$ parametro che dipende dalla forma e dalle dimensioni del corpo.
La forza di attrito aumenta man mano che aumenta la velocità.
Si raggiungerà quindi ad un certo dato istante della caduta una condizione in cui $F_{d}=w$, cioè:
$$
\begin{gather}
\sum F_{y}=F_{d}-w=ma=0 \\
bv^{2}-mg=0 \\
\text{ quando } v=v_{i}=\sqrt{ \frac{mg}{b} }
\end{gather}
$$
# Moto armonico
## Moto armonico semplice
Un corpo si muove di **moto armonico semplice** quando al corpo è applicata una **forza di richiamo**, cioè una forza sempre diretta verso un *punto di equilibrio stabile*, **direttamente proporzionale allo spostamento** del corpo dalla posizione di equilibrio.
Il moto di una massa su un piano orizzontale privo di attrito collegata ad una molla, trascurando la resistenza dell’aria, è un esempio di moto armonico semplice.
![[Pasted image 20241013172151.png|250]]
Il modulo della forza esercitata sull’estremo libero della molla è:
$$
F_{x}=-kx
$$
$F_{x}$ è la forza di richiamo di questo moto.
$x$ è la lunghezza dello spostamento e $k$ è la costante elastica; caratteristica della molla, le sua unità di misura sono $N/m$.
Se la superficie d’appoggio è senza attrito (legge di Hooke):
$$
\begin{align}
&\sum F_{x}=-kx=ma_{x} \\
&a_{x}(t)=-\frac{k}{m}x(t)
\end{align}
$$
Nel punto di equilibrio $x=0$ e $a=0$.
*Quando è massima l’elongazione della molla è massima la forza e quindi anche l’accelerazione*.

L’equazione (differenziale) che descrive un moto armonico semplice è:
$$
\begin{align}
&\sum F_{x}=-kx=ma_{x} \\
\frac{d^{2}x(t)}{dt^{2}}=&a_{x}(t)=-\frac{k}{m}x(t)
\end{align}
$$
![[Pasted image 20241013172647.png|500]]
$$
\omega = \sqrt{ \frac{k}{m} }
$$
![[Pasted image 20241013172744.png|350]]
$$
\begin{align}
&x(t)=A\cos \omega t \\
&v(t)=\frac{\Delta x}{\Delta t}=-A\omega \sin \omega t \\
&a(t)=\frac{\Delta v}{\Delta t}=-A\omega^{2}\cos \omega t
\end{align}
$$
Cosa significa $\omega=\sqrt{ \frac{k}{m} }$?
Se $T$ è il tempo necessario una oscillazione completa ($T=$ periodo) allora $\omega T=2\pi$ cioè:
$$
\omega=\frac{2\pi}{T}
$$
$\omega$ è la **frequenza** angolare delle oscillazioni.
$A$ è l'**ampiezza** del moto, cioè il massimo spostamento dalla posizione di equilibrio.
Inoltre $A\omega=v_{max}$ e $A\omega^{2}=a_{max}$.
La velocità si annulla agli estremi dell’oscillazione ed è massima quando il corpo passa per la posizione di equilibrio.
### Oscillazioni smorzate
Quando l’attrito non è trascurabile l’ampiezza delle oscillazioni diminuisce nel tempo:
![[Pasted image 20241013173206.png|350]]
## Moto dei proiettili
Un aereo vola alla quota di $1050 m$ alla velocità di $115 m/s$. Ad un certo istante lancia una cassa contenente generi di pronto soccorso. A quale distanza dal punto di lancio la cassa colpirà il suolo?
![[Pasted image 20241013174440.png|400]]
# Moti 2d circolari
**La variabile angolare**:
$$
\begin{gather}
\theta = \text{coordinata angolare} \\
\theta = \frac{s}{r}
\end{gather}
$$
$\theta$ è misurato in *radianti*, è il rapporto tra due lunghezze.
Gli angoli misurati in senso *antiorario* sono positivi.
$2\pi$ radianti $= 360° = 1$ rotazione completa.
Usando la variabile angolare il moto circolare si può descrivere con una sola *coordinata cinematica*.
![[diagram-20241016.svg#invert|400]]
La *lunghezza dell'arco percorso* nel tempo è:
$$
\begin{gather}
\Delta t = t_{f} - t_{i} \\
\Delta s = r \Delta \theta
\end{gather}
$$
dove:
$$
\Delta \theta = \theta_{f} - \theta_{i}
$$
è lo *spostamento angolare*.
## Velocità angolare media e istantanea
$$
\omega_{av} = \frac{\Delta \theta}{\Delta t} \ \text{ e } \ \omega = \lim_{ \Delta t \to 0 } \frac{\Delta \theta}{\Delta t}
$$
$\omega$ si misura in $rad/s$ (radianti al secondo).
![[Screenshot 2024-10-16 alle 16.36.47.png|400]]
Il vettore $\mathbf{\omega}$ ha direzione perpendicolare al piano del moto, è diretto verso di voi se la rotazione è antioraria, ha invece verso opposto se la rotazione è oraria.
**Velocità media**:
$$
v_{av} = \frac{\text{distanza totale}}{\text{tempo totale}} = \frac{r\Delta \theta}{\Delta t} = r\left( \frac{\Delta \theta}{\Delta t} \right) = r\omega_{av}
$$
Vale anche per i valori istantanei $v = r\omega$.
## Accelerazione
La velocità di una particella che si muove su una traiettoria circolare è tangente alla traiettoria.
Varia in modulo, direzione e verso, generando una accelerazione $\neq 0$ e quindi deve essere soggetto ad una forza non nulla.
L’accelerazione, in generale, ha una componente lungo la direzione tangente una componente lungo la direzione radiale.
![[diagram-20241016.svg#invert]]
## Moto circolare uniforme
$r$ raggio della traiettoria circolare percorsa.
$T$ il tempo necessario a compiere un giro completo.
$f$ la frequenze, cioè il numero di cicli per secondo.
$$
|v| = \frac{2\pi r}{T}
$$
$$
v = v_{av} = \frac{\text{distanza totale}}{\text{tempo totale}} = \frac{2\pi r}{T}
$$
Anche la velocità angolare è costante:
$$
\omega = \frac{2\pi}{T} = 2\pi f \quad \quad v = \omega r
$$
La *direzione* di $v$ cambia, quindi, $\Delta v \neq 0 \Rightarrow a\neq 0$. È quindi presente una forza $\neq 0$.
## Accelerazione: modulo
$$
\frac{\Delta v}{v} \sim \frac{v\Delta t}{r} \rightarrow \frac{\Delta v}{\Delta t} \sim \frac{v^{2}}{r}
$$
Il modulo dell’accelerazione radiale è costante e vale:
$$
a_{r} = \frac{v^{2}}{r} = r\omega^{2} = \omega v
$$
### Direzione orientata
L’accelerazione istantanea in un moto circolare uniforme è diretta lungo la direzione radiale e orientata verso il centro della traiettoria circolare.
![[Pasted image 20241016170359.png|300]]
## Forza centripeta
La forza che tiene il corpo in rotazione uniforme è, quindi, costante in modulo e diretta *verso il centro*, ed è chiamata **forza centripeta**.
$$
F_{c} = \frac{mv^{2}}{r}
$$
**Esempio**:
Una palla di $150 g$ legata all’estremità di una corda rotea uniformemente lungo una circonferenza orizzontale di raggio $0.6 m$. La palla compie due rivoluzioni in un secondo.
- Quanto valgono l’ accelerazione e la forza radiale?
$$
\begin{gather}
a_{r} = \frac{v^{2}}{r} = \frac{(2\pi rf)^{2}}{r} = \frac{(2\pi \times 0.6 \times 2)^{2}}{ 0.6} = 94.8 \frac{m}{s^{2}} \\
F_{r} = ma_{r} = 0.15 \times 94.8 = 14.37 N
\end{gather}
$$
**Esempio**:
Si supponga che il filo di guida usato nella figura sia lungo $14 m$ e sia capace di resistere alla tensione massima di $85 N$ senza rompersi. Quanto vale il modulo della velocità che un aeromodello di $0,90 Kg$ può avere?
$$
\begin{gather}
F_{c} = \frac{mv^{2}}{r} \\
v = \sqrt{ \frac{rF_{c}}{m} } = \sqrt{ \frac{14 \times 85}{0.90} } = 36 m/s
\end{gather}
$$
# Lavoro ed energia
## Lavoro
Quando una forza non nulla sposta un corpo viene compiuto **LAVORO**. Se la forza $F$ è costante e ha la direzione orientate dello spostamento $s$:
$$
W = Fs
$$
L’unità di misura della forza è il *Joule*($J$).
$$
1J = 1Nm = 1kg \ m^{2}/s^{2}  
$$
Il lavoro compiuto da una forza costante non parallela allo spostamento è definito come:
$$
W = Fs \cdot \cos \theta
$$
Dove $F$ è l'intensità della forza, $s$ la lunghezza dello spostamento, e $\theta$ l'angolo tra $F$ e $s$.
![[Pasted image 20241022113529.png|500]]
### Prodotto scalare tra due vettori
Il **prodotto scalare** di due vettori $a$ e $b$ è una grandezza scalare.
$$
\overrightarrow{a} \cdot \overrightarrow{b} = ab \cdot \cos \alpha
$$
In coordinate cartesiane:
$$
\overrightarrow{a} \cdot \overrightarrow{b} = a_{x}b_{x} + a_{y}b_{y} + a_{z}b_{z}
$$
## Lavoro come prodotto scalare
possiamo definire il lavoro come *prodotto scalare del vettore forza per il vettore spostamento*:
$$
W = F \circ S
$$
In presenza di più forze $F = F_{1}+F_{2} + \dots + F_{n}$ il lavoro gode della *proprietà additiva*:
$$
L = L_{1}+L_{2}+L_{2}+\dots+L_{n}
$$
**Esempio**:
Una scatola di massa m viene trascinata a velocità costante su un piano privo di attrito. La forza applicata $F$ è parallela al piano. Calcolare il lavoro totale compiuto sulla scatola.
Velocità costante, quindi accelerazione $a = 0$.
![[Pasted image 20241022115127.png|400]]
Applico la seconda legge di Newton:
$$
\begin{gather}
\sum F_{x} = F - w\sin \theta = 0 \\
\sum F_{y} = N - w\cos \theta = 0
\end{gather}
$$
Il modulo di $F$ vale:
$$
F = mg \cdot \sin \theta
$$
La scatola percorre lungo la rampa una distanza $\Delta x$, il lavoro della forza $F$ è:
$$
W_{F} = F\Delta x \cdot \cos0° = mg\Delta x \cdot \sin \theta
$$
Il lavoro della gravità è:
$$
W_{g} = w\Delta x \cdot \cos(\theta + 90°) = -mg\Delta x \cdot \sin \theta
$$
Il lavoro della forza normale è:
$$
W_{N} = N\Delta x \cdot \cos90° = 0
$$
Il lavoro netto compiuto sulla scatola è:
$$
\begin{align}
W_{net} &= W_{F} + W_{g} + W_{N} \\
&= mg\Delta x\sin \theta - mg\Delta x\sin \theta + 0 \\
&= 0
\end{align}
$$
**Esempio**:
Qual è il lavoro totale sulla scatola dell’esercizio precedente se la scatola non è tirata a velocità costante?

$$
\begin{align}
&\sum F_{x} = F - w\sin \theta = ma \\
&\therefore F = ma + w\sin \theta
\end{align}
$$
Se la velocità NON è costante, significa che ci sarà una accelerazione non nulla, e quindi anche la risultante delle forze sarà non nulla.
Procedendo come prima:
$$
W_{net} = W_{F} + W_{a} = (ma\Delta x + mg\sin \theta \Delta x) - mg\sin \theta \Delta x = ma\Delta x
$$
## Lavoro di una forza variabile
Se la forza varia da punto a punto lungo lo spostamento, allora il lavoro deve essere calcolato con l’aiuto dell’analisi matematica.
$$
\int_{x_{1}}^{x_{2}} F(x) \cdot dx 
$$
Anche in questo caso il lavoro può essere calcolato determinando l’area delimitate dal grafico della forza applicata in funzione dello spostamento.
**Esempio**:
Una molla ideale ha $k = 20,0 N/m$. Qual’è il lavoro compiuto da un agente esterno per deformare la molla di $0.40 m$ partendo dalla molla non deformata?
Usiamo l’interpretazione grafica dell’integrale:
![[Screenshot 2024-10-22 alle 12.10.11.png|300]]
$$
\begin{align}
W &= \text{area sotto la curva} \\
&= \frac{1}{2} (kx_{1})(x_{1}) = \frac{1}{2}kx_{1}^{2}  = \frac{1}{2}(20.0N/m)(0.4m)
^{2} = 1.6J\end{align}
$$
Usiamo l'analisi matematica per l'integrale:
$$
\begin{align}
L_{i \rightarrow f} = \int_{0}^{x_{1}} F \circ  dx' \\
= k \int_{x}^{x_{1}} x' dx' = \frac{1}{2}kx_{1}^{2}
\end{align}
$$
## Energia Cinetica
$$
K = \frac{1}{2}mv^{2}\ \  \text{è l'energia cinetica traslazionale di un corpo} 
$$
È posseduta da un corpo in virtù del suo stato di moto.
**Teorema dell'energia cinetica**:
$$
W_{i \to f} = \Delta E_{C} = E^{f}_{C} - E_{C}^{i}  
$$
Dimostrazione:
$$
\begin{gather}
dW = Fdx = m \frac{dv}{dt}dx = m \frac{dv}{dt}vdt \\
W = \int_{i}^{f} dW = \int_{i}^{f} mvdv = m \int_{i}^{f} vdv = \frac{1}{2} mv_{f}^{2} - \frac{1}{2} mv_{i}^{2}  
\end{gather}
$$
## Lavoro e forza gravitazionale
Il **lavoro** compiuto dalla forza gravitazionale quando un corpo si sposta verticalmente è dato da:
$$
W = mg \cdot |\Delta h| \cdot \cos \theta = (mg h_{f} - mg h_{i})
$$
## Lavoro ed energia potenziale gravitazionale
L'energia potenziale gravitazionale $U$ di un corpo è definita come:
$$
U = m \cdot g \cdot h
$$
$m =$ massa, $g=$ forza di gravità e $h=$ altezza.
Il lavoro compiuto dalla forza gravitazionale tra due posizioni è legato alla variazione di energia potenziale gravitazionale:
$$
W_{if} = -(U_{f}-U_{i}) = -\Delta U
$$
Una forza è **conservativa** quando il lavoro compiuto NON dipende dal particolare cammino seguito per andare dalla posizione iniziale a quella finale, ma solo dalla posizione iniziale e finale. Per questa categoria di forze:
$$
W_{cons} = -\Delta U
$$
La forza gravitazionale è una forza conservativa. *Vicino* alla superficie della Terra:
$$
\Delta U_{g} = mg\Delta y
$$
dove $\Delta y$ è la variazione della coordinata verticale del corpo rispetto ad una arbitraria posizione di riferimento.
*Lontano* dalla superficie della Terra la forza gravitazionale che agisce su una massa $M_{2}$ per effetto di una massa $M_{1}$ a distanza $r$ è:
$$
\begin{gather}
F(r) = - \frac{GM_{1}M_{2}}{r^{2}} \\
L = \int_{r_{i}}^{r_{f}} drF(r) = GM_{1}M_{2}\int_{r_{i}}^{r_{f}} - \frac{1}{2} dr = \frac{GM_{1}M_{2}}{r_{f}} - \frac{GM_{1}M_{2}}{r_{i}}
\end{gather}
$$
l’espressione più generale per l’energia potenziale gravitazionale della massa $M_{2}$ è:
$$
U(r) = - \frac{GM_{1}M_{2}}{r}
$$
dove $U(r=\infty)=0$.
**La forza elastica è una forza conservativa**.
## Energia potenziale elastica
Il lavoro della forza elastica, come quello della forza peso, *non dipende dalla traiettoria*,  ma solo dalla posizione iniziale e finale.
Introducendo la funzione $U(x) = \frac{1}{2}kx^{2}$ il lavoro è dato da:
$$
L = \frac{1}{2} kx_{A}^{2} - \frac{1}{2}kx_{B}^{2}  = U(A) - U(B) = -\Delta U
$$
La funzione $U(x)$ è detta *energia potenziale elastica* ed è una grandezza scalare associata alla *posizione* in cui si trova il punto, è definita a meno di una costante: se si pone $U(x) = \frac{1}{2} kx^{2}+c$ vale sempre la relazione $L = -\Delta U$.
L’energia meccanica di una massa $m$ collegata ad una molla è:
$$
E(t) = K(t) + U(t) = \frac{1}{2} mv(t)^{2} + \frac{1}{2} kx(t)^{2}  
$$
- $K(t) = \frac{1}{2}mv(t)^{2}$: energia cinetica.
- $U(t) = \frac{1}{2}kx(t)^{2}$: energia potenziale elastica.
Se non ci sono forze dissipative (es. attrito), l'energia meccanica totale $E$ si conserva:
$$
E_{i} = E_{f}
$$
equivale a:
$$
\Delta K = -\Delta U
$$
## Potenza
La **potenza** è una misura della velocità con cui viene trasferita o convertita energia. Si può distinguere tra **potenza media** e **potenza istantanea**:
$$
\begin{gather}
\text{Potenza media} \ P_{av} = \frac{\Delta E}{\Delta t} \\ \\
\text{Potenza istantanea} \ P = Fv \cdot \cos \theta
\end{gather}
$$
Unità di misura è il Watt. $1 W = 1J/s$.
# Elettrostatica
## Conduttori e isolanti
- **Conduttore**: formato da un materiale che consente alle cariche elettriche di muoversi attraverso esso in modo facile.
- **Isolante**(o dielettrico) è formato da un materiale che non consente alle cariche elettriche di muoversi facilmente attraverso esso.
Ci sono due tipi di **carica elettrica**: *positiva* e *negativa*.
L’unità elementare di carica è
$$
|e| = 1.602 \times 10^{-19}C
$$
La carica dell’elettrone è $-1e$.
La carica del protone è $+1e$.
La carica del neutrone è $0e$.
La carica elettrica è *conservativa*.
Un oggetto può diventare **polarizzato** se le cariche al suo interno possono essere separate.
![[Pasted image 20241028093013.png|500]]
## Carica puntiforme e Legge di Coulomb
La **legge di Coulomb** descrive l'intensità della forza elettrica che agisce tra due cariche puntiformi. La legge afferma che:
$$
F = k \frac{|q_{1}||q_{2}|}{r^{2}}
$$
dove $q_{1}$ e $q_{2}$ sono le cariche e $r$ è la distanza tra le due cariche.
$$
k = 8.99 \times 10^{9} Nm^{2}/C^{2}   
$$
dove $k = \frac{1}{4\pi\varepsilon_{0}}$ e $\varepsilon_{0} = 8.85 \times 10^{-12} \frac{C^{2}}{Nm^{2}}$, costante dielettrica nel vuoto.
La costante dielettrica di un mezzo($\varepsilon$) la possiamo anche scrivere come:
$$
\varepsilon = \varepsilon_{r} \varepsilon_{0}
$$
- $\varepsilon_{r} = \frac{\varepsilon}{\varepsilon_{0}}$.
La forza di Coulomb è radiale, si esplica lungo la direzione congiungente delle due cariche.
![[Pasted image 20241028095336.png|500]]
**Esempio**:
Qual’ è il rapporto tra la forza elettrica e quella gravitazionale tra un protone e un elettrone separati da $5.3 \times 10^{11}$m (il raggio di un atomo di idrogeno)?
$$
\begin{align}
&F_{e} = k\frac{|q_{1}||q_{2}|}{r^{2}} && |q_{1}| = |q_{2}|= e = 1.602 \times 10^{-19}C\\
&F_{g} = G\frac{m_{1}m_{2}}{r^{2}} && m_{1} = m_{p} = 1.67 \times 1^{-27}kg \\
& && m_{2} = m_{e} = 9,11 \times 10^{-31}kg 
\end{align}
$$
Il rapporto tra le due forze è:
$$
\frac{F_{e}}{F_{g}} = \frac{k}{G}\frac{|q_{1}||q_{2}|}{m_{1}m_{2}} = \frac{k}{G}\frac{e^{2}}{m_{e}m_{p}} = 2.3 \times 10^{39} 
$$
## Il campo elettrico
$F_{g} = m\mathbf{g}$ dove $\mathbf{g}$ è l'accelerazione di gravità.
$$
F_{e} = qE
$$
simile per le forze elettriche possiamo definire il modulo del campo elettrico $\mathbf{E}$.
Per una carica puntiforme $Q$, il modulo della forza per unità di carica alla distanza $r$ (il campo elettrico) è:
$$
E = \frac{F_{e}}{q} = k\frac{|Q|}{r^{2}}
$$
Il campo elettrico in un punto dello spazio si trova sommando tutti i campi elettrici presenti in quel punto:
$$
E_{net} = \sum_{i} E_{i} \quad \text{Attenzione! Il campo elettrico è un vettore!}
$$
## Linee di Campo Elettrico
Le linee di campo elettrico sono un modo utile per rappresentare il modulo e la direzione di un campo elettrico nello spazio.
1. La direzione del campo $E$ è tangente alle linee di campo in ciascun punto dello spazio.
2. Il campo è intenso nelle regioni dove sono presenti molte linee di campo e debole dove ce ne sono poche.
3. Le linee di campo partono dalle cariche $+$ e terminano sulle cariche $–$ .
4. Le linee di campo non si incrociano mai.
![[Pasted image 20241028103016.png|500]]
## Condensatore piano
Un **condensatore piano** è un dispositivo composto da due conduttori piani paralleli, separati da un dielettrico (un materiale isolante) o dal vuoto. La sua funzione è quella di accumulare carica elettrica ed energia nel campo elettrico generato tra le sue armature.
![[Pasted image 20241126110702.png|150]]
La *densità superficiale di carica* è:
$$
\sigma = \frac{|q|}{A}
$$
Come è fatto il campo dentro al condensatore?
$$
E = \frac{\sigma}{\varepsilon_{0}} = \frac{Q}{\varepsilon_{0}A} = \frac{V}{d}
$$
- $\varepsilon_{0}$ la densità del materiale(in questo caso il vuoto).
- $A$ l'area del condensatore.
- $d$ la distanza.
- $V$ la differenza di potenziale tra le armature.
La *capacità* del condensatore è:
$$
C = \varepsilon \frac{A}{d}
$$
L'*energia accumulata* dal condensatore è:
$$
U = \frac{1}{2}CV^{2} 
$$
Una maggiore area $A$ aumenta la capacità.
Una minore distanza $d$ tra le armature aumenta la capacità.
La *densità di energia. nel campo* è:
$$
u = \frac{1}{2}\varepsilon E^{2}
$$
## Flusso e Teorema di Gauss
![[Pasted image 20241126111211.png|250]]
Circonda una carica puntiforme $+Q$ con una sfera immaginaria.
Le linee del campo $E$ escono dalla sfera.
![[Pasted image 20241028103342.png|200]]
Il **flusso** è una quantità scalare correlate al numero di linee di campo che attraversano la superficie:
$$
\text{flux} = \Phi_{E} = E_{\perp}A = EA \cdot \cos \theta
$$
$\Phi_{E} > 0$ quando le linee di campo escono dalla superficie.
$\Phi_{E} < 0$ quando entrano nella superficie.
**Esempio**:
Trova il flusso del campo elettrico attraverso ciascuna faccia di una cubo di spigolo a immerso in un campo elettrico uniforme di intensità $E$.
![[Pasted image 20241028104313.png|250]]
Il cubo ha sei facce: le linee di campo entrano in una faccia ed escono attraverso la faccia opposta. Qual’ è il flusso attraverso ciascuna delle altre quattro facce?
- Il flusso attraverso la faccia sinistra è $–EA$.
- Il flusso attraverso la faccia destra è $+EA$.
- il flusso netto attraverso il cubo è *nullo*($-EA+EA = 0$).
**Definizione**: il flusso attraverso una superficie chiusa dipende quindi dalla quantità di carica all’interno della superficie chiusa stessa.
Il **teorema di Gauss** mette in relazione il flusso del campo elettrico attraverso una superficie chiusa con la **carica totale racchiusa** all'interno della superficie. È espressa come:
$$
\Phi_{E} = \frac{Q_{\text{inside}}}{\varepsilon_{0}}
$$
Esplicitando:
$$
\oint\vec{E} \cdot d\vec{A}_{superficie} = \frac{Q_{\text{inside}}}{\varepsilon_{0}} = \frac{Q}{4\pi\varepsilon_{0}r^{2}} = E(r) \cdot 4\pi r^{2}
$$
## Calcolo del campo elettrico a partire dalla legge di Gauss
*Densità di carica*:
$$
\rho = \frac{Q}{V} = \frac{Q}{\frac{4}{3}\pi R^{3}} = \frac{3Q}{4\pi R^{3}}
$$
![[Pasted image 20241126113732.png|150]]
- Per $r < R$:
$$
\int_{\text{sfera di raggio }r} \overrightarrow{E} \cdot \overrightarrow{A}_{rea} = \frac{Q_{in}}{\varepsilon_{0}}
$$
Primo membro:
$$
E(r)4\pi r^{2}
$$
Secondo membro:
$$
\frac{\rho}{\varepsilon_{0}} \frac{r}{3} \pi r^{3}
$$
Quindi:
$$
E(r) = \frac{p}{\varepsilon_{0}} \frac{r}{3} = \frac{Q}{4\pi \varepsilon_{0}R^{3}} r = kr
$$
- Per $r \geq R$:
$$
\int_{\text{sfera di raggio }r} \overrightarrow{E} \cdot \overrightarrow{A}_{rea} = \frac{Q_{in}}{\varepsilon_{0}}
$$
Primo membro:
$$
E(r)4\pi r^{2} 
$$
secondo membro:
$$
\frac{\rho}{\varepsilon_{0}} \frac{4}{3}\pi R^{3} 
$$
Quindi:
$$
\begin{gather}
E(r)4\pi r^{2} = \frac{\rho}{\varepsilon_{0}} \frac{4}{3} \pi R^{3} = \frac{3Q}{4\pi\varepsilon_{0}R^{3}} \frac{4}{3} \pi R^{3} \\
E(r) = \frac{Q}{4\pi \varepsilon_{0}r^{2}}
\end{gather}
$$
## Moto di una carica puntiforme in un campo elettrico uniforme
Una regione di spazio in cui è presente un campo elettrico $E$ uniforme contiene una particella di carica $q>0$ di massa $m$.
![[Pasted image 20241028110211.png|300]]
Applica la seconda legge di Newton e risolviamo per l'accelerazione:
$$
\begin{align}
\sum F_{x} &= F_{e} = ma \\
F_{e} &= qE = ma \\
a &= \frac{q}{m} E
\end{align}
$$
**Esempio**:
Qual è l’intensità del campo elettrico necessaria per mantenere un elettrone sospeso in aria?
![[Pasted image 20241028110259.png|150]]
Seconda legge di Newton:
$$
\begin{align}
\sum F_{y} &= F_{e}-w = 0 \\
F_{e} &= w \\
qE &= eE = mg \\
E &= \frac{mg}{e} = 5.6\times 10^{-11} N/C 
\end{align}
$$
## Energia potenziale elettrica (Joule)
L'*energia potenziale elettrica* $U_{e}$ è l'energia posseduta da una carica $q$ in un punto di un campo elettrico generato da altre cariche.
- $U_{e}$ dipende solo dalla *posizione* della carica.
- $U_{e}$ è determinata a meno di una costante che dipende dalla scelta del punto a cui attribuire $U_{e} = 0$.
Per particelle puntiformi si prende $U_{e} = 0$ a $r= \infty$.
Per una carica $q$ posizionata a una distanza $r$ da un'altra carica $Q$. l'energia potenziale elettrica $U_{e}$ è:
$$
U_{e} = k \cdot \frac{Q \cdot q}{r}
$$
- $k$ è la costante di Coulomb ($8,99 \times 10^{9} Nm^{2}/C^{2}$).
- $Q$ e $q$ le cariche in gioco.
- $r$ la distanza tra le due cariche.
## Potenziale elettrico (Volt)
Il **potenziale elettrico** $V_{e}$​ in un punto dello spazio, generato da una distribuzione di cariche, è definito come l'energia potenziale elettrica $U_{e}$ di una carica $q$ in quel punto divisa per il valore della carica stessa.
$$
V_{e} = \frac{U_{e}}{q}
$$
- $V_{e}$ dipende SOLO dal punto.
- $V_{e} =0$ dove $U_{e}=0$ (per esempio a $r = \infty$), potenziale elettrico.
- $q$ valore della carica.
- $k$ è la costante di Coulomb ($8,99 \times 10^{9} Nm^{2}/C^{2}$).
Per una singola carica $Q$, a una distanza $r$ dal punto, il potenziale è:
$$
V_{e} = \frac{k \cdot Q}{r}
$$
**Esempio**
Un protone e un elettrone, inizialmente separati da una distanza $r$, vengono avvicinati.
Come cambia l’energia potenziale di questo sistema di cariche?
$$
U_{e} = -k \frac{e^{2}}{r}
$$
Avvicinare le cariche significa diminuire $r$:
$$
\Delta U_{e} = U_{ef} - U_{ei} < 0
$$
Come cambierebbe l energia potenziale elettrica se entrambe le particelle avessero carica positiva (o negativa)?
Se $q_{1}$ e $q_{2}$ hanno lo stesso segno $\Delta U_{e} > 0$.
### Differenze tra $V_{e}$ e $U_{e}$

- **Potenziale Elettrico** ($V_{e}$​): Energia per unità di carica.
- **Energia Potenziale Elettrica** ($U_{e}$​): Energia totale posseduta dalla carica $q$, calcolabile con $U_{e} = V_{e} \cdot q$.
## Sorgenti di f.e.m: la batteria
### Cariche in movimento in campi elettrostatici
Quando solo forze elettriche agiscono su una carica, la sua energia meccanica totale si conserva.
$$
E_{i} = E_{f}
$$
 **Esempio**:
 Il punto $P$ ha un potenziale di $500.0 kV$ e il punto $S$ con potenziale $200.0kV$. Lo spazio tra questi è vuoto. Quando una carica di $+2e$ si sposta da $P$ a $S$, si quanto varia la sua energia cinetica?
$$
\begin{gather}
E_{i} = E_{f} \\
K_{i} + U_{i} = K_{f} + U_{f} \\
\end{gather}
$$
$$
\begin{align}
K_{f} - K_{i} &= U_{i} - U_{f} = -(U_{f} - U_{i}) \\
&= -\Delta U = -q\Delta V=-q(V_{s}-V_{p})  \\
&= -(+2e)(200.0-500.0)kV \\
&= +9.6\times 10^{-14} J 
\end{align}
$$
## Relazioni tra $E$ e $V$
![[Pasted image 20241126141844.png|200]]
Campo $E$ uniforme.
$$
\Delta V=\frac{\Delta U}{q} = -Ed \quad d\text{ è la distanza a cui si ha }\Delta V
$$
quindi:
$$
E = \frac{\Delta U}{d}
$$
## Superfici Equipotenziali
Sono superfici in cui il potenziale elettrico è costante.
- **Forma**: le superfici equipotenziali sono sfere concentriche con centro nella carica $Q$.
- **Caratteristiche**:
    - Il potenziale è lo stesso in ogni punto della superficie.
    - Non è necessario compiere lavoro per spostarsi su una superficie equipotenziale.
    - Perpendicolari alle linee del campo elettrico.
# Condensatori
Formato da due strati (armature $A$) conduttrici separate da uno strato isolante(dielettrico $d$).
Un **condensatore** è un dispositivo progettato per **immagazzinare energia potenziale elettrica** (Joule) accumulando cariche positive e negative sulle due armature. Una piastra accumula carica positiva ($+Q$) e l’altra accumula una carica uguale e opposta ($-Q$).
$$
C = \frac{Q}{\Delta V}
$$
Per un condensatore a *facce parallele*:
$$
\begin{align}
&E \propto Q \\
&E \propto \Delta V \\
&\therefore Q \propto \Delta V
\end{align}
$$
Scritto sotto forma di equazione:
$$
Q = C\Delta V
$$
- Costante di proporzionalità $C$ si chiama *capacità*(Farad $F = 1 \frac{C_{oulomb}}{V_{olt}}$).
$$
\begin{gather}
\Delta V=Ed = \frac{\sigma}{\varepsilon_{0}}d=\frac{Q}{\varepsilon_{0}A}d \\
\therefore Q = \frac{\varepsilon_{0}A}{d}\Delta V = C\Delta V \\
\text{dove }C = \frac{\varepsilon_{0}A}{d}
\end{gather}
$$
- $C$ dipende solo dalla costante dielettrica dell'isolante e da fattori geometrici.
**Esercizio**:
Un condensatore a facce piane parallele ha una capacità di $1.20 \ nF$. Vi è una carica di $0.800 \mu C$ su ciascuna armatura.
- Quale è la differenza di potenziale tra le armature?
$$
\begin{align}
&Q=C\Delta V \\
&\Delta V=\frac{Q}{C} = \frac{0.800\mu C}{1.20\ nF} = 667 \ Volts
\end{align}
$$
- Se la separazione tra le armature raddoppia e la carica viene mantenuta costante, cosa succede alla differenza di potenziale?
$$
\begin{align}
&\Delta V=\frac{Q}{C} = \frac{Qd}{\varepsilon_{0}A} \\
&\Delta V \propto d
\end{align}
$$
se $d$ raddoppia, così fa la differenza di potenziale.
Per aumentare la capacità di un condensatore , si può mettere un dielettrico tra le armature del condensatore.
$$
\begin{align}
&C = kC_{0} \\
\text{dove } &C_{0} = \frac{\varepsilon_{0}A}{d}
\end{align}
$$
$k$ è la costante dielettrica relativa$\left( k = \frac{\varepsilon}{\varepsilon_{0}} \right)$.
**Esempio**:
Un condensatore può essere realizzato con due fogli di alluminio separati da un foglio di carta oleata. Se i fogli di alluminio misurano $0.3m$ per $0.4m$ e la carta oleata di dimensioni leggermente superiori, è di spessore $0.030mm$ e ha $k=2.5$.
- Quale è la capacità di questo condensatore?
$$
\begin{align}
C_{0}&=\frac{\varepsilon_{0}A}{d} \\
&=\frac{(8.85\times 10^{-12} Nm^{2}/C^{2})(0.40*0.30)m^{2}}{0.030x_{1}0^{-3}m} \\
&= 3.54 \times 10^{-8} F \\
\text{con } C &= kC_{0} = (2.5)(3.54 \times 10^{-8}F) = 8.85 \times 10^{-8}F 
\end{align}
$$
## Rigidità dielettrica
La **rigidità dielettrica** è la capacità di un materiale isolante (dielettrico) di resistere a un campo elettrico senza rompersi (cioè senza che avvenga il passaggio di corrente dovuto alla formazione di un arco elettrico). Indica il valore massimo del campo elettrico ​$(E_{max})$ che il materiale può sopportare prima che si verifichi la **scarica elettrica**.
Quando il campo elettrico supera la rigidità dielettrica, il materiale si ionizza, diventa conduttore e si verifica la scarica elettrica.
**Influenza**:
- **Purezza del materiale:** Impurità o difetti riducono la rigidità dielettrica.
- **Temperatura:** La rigidità dielettrica generalmente diminuisce con l’aumentare della temperatura.
- **Spessore del materiale:** Materiali più sottili tendono a rompersi più facilmente.
## Energia immagazzinata in un condensatore
![[Pasted image 20241126155023.png|500]]
L'energia immagazzinata vale(Lavoro differenziale):
$$
\Delta L = \Delta Q^{*}\Delta V
$$
- $\Delta V$ è la differenza di potenziale istantanea tra le piastre del condensatore.
- $\Delta Q^{*}$ l'incremento infinitesimale della carica.
**Espressione della differenza di potenziale**:
$$
\Delta L = \Delta Q^{*} \Delta V = \Delta Q^{*} \frac{Q^{*}}{C}
$$
La carica massima $Q$ che si può trasferire sulla capacità si ottiene dalla legge dei condensatori: $Q=C\Delta V$. Il lavoro totale è quindi dato da:
$$
L = \int_{0}^{Q} \Delta L = \frac{1}{C} \int_{0}^{Q} \Delta Q^{*} Q^{*} = \frac{Q^{2}}{2C}
$$
Dunque l'*energia potenziale*(immagazzinata) è:
$$
\begin{align}
U &= \frac{1}{2}Q\Delta V \\
&\begin{rcases}
=\frac{1}{2}C(\Delta V)^{2}\\
=\frac{Q^{2}}{2C}\end{rcases} \text{si trovano usando }Q=C\Delta V \text{ e la prima relazione}
\end{align}
$$
**Esempio**:
Un condensatore a facce piane parallele è formato da due armature quadrate di $10.0 cm$ di lato, separate da un’intercapedine di aria di $0.75 mm$.
(a) Qual è la carica sul condensatore quando la differenza di potenziale è di $150 Volts$?
(b) Quanta energia è immagazzinata nel condensatore?
1. Calcolare l'**area della armature**: $0.10^{2} = 0.01m^{2}$
2. **Calcolare la Capacità del Condensatore**:
$$
C = \frac{\varepsilon_{0} \cdot A}{d}
$$
- $\varepsilon_{0}$ è la costante dielettrica nel vuoto, $\varepsilon_{0} = 8.854 \times 10^{-12}F/m$.
- $A$ 'area delle armature.
- $d$ distanza tra le armature $0.00075m$.
$$
C = \frac{(8.854 \times 10^{-12}F/m)\cdot(0.01m^{2})}{0.00075m} \approx 1.177 \times 10^{-10} F 
$$
3. **Calcolare la Carica sul Condensatore**:
$$
Q = C \cdot V
$$
Sostituendo:
$$
Q = (1.177 \times 10^{-10}F) \cdot (150V) \approx 1.7708 \times 10^{-8} C
$$
4. **Calcolare l'energia immagazzinata**:
$$
U = \frac{1}{2} CV^{2} 
$$
Sostituendo:
$$
U = \frac{1}{2} \cdot (1.177 \times 10^{-10}F) \cdot (150V)^{2} \approx 1.3281 \times 10^{-6} J
$$
# Correnti e circuiti elettrici
La **corrente elettrica** è una misura della quantità di carica che passa attraverso un'area perpendicolare al flusso di carica.
$$
I = \frac{\Delta q}{\Delta t}
$$
- $I$ Corrente elettrica, misurata in **ampere**$(A_{mp}) = \frac{1C_{oulomb}}{s_{econdo}}$.
- $\Delta q$ Quantità di carica elettrica trasferita, misurata in **coulomb**$(C)$.
- $\Delta t$Intervallo di tempo, misurato in **secondi**$(s)$.
La corrente di elettroni fluisce fino a che la differenza di potenziale non si annulla.
![[Pasted image 20241126162012.png|200]]
Per convenzione si assume che la corrente sia trasportata da cariche positive. La direzione di scorrimento della corrente in un filo sarà opposta al reale flusso degli elettroni.
#### Tipi di Corrente Elettrica
1. **Corrente Continua (DC)**: Fluisce in una sola direzione (es. batterie).
2. **Corrente Alternata (AC)**: Cambia direzione periodicamente (es. rete elettrica domestica).
**Esempio**:
Se una corrente di $80.0mA$ sussiste in un filo metallico.
- Quanti elettroni fluiscono attraverso una certa sezione del filo in $10.0\min$?
$$
\begin{align}
I &= \frac{\Delta q}{\Delta t} \\
\Delta q & = I\Delta t = (80\times 10^{-3}A)(600\sec) = 48.0C
\end{align}
$$
Numero di elettroni:
$$
\begin{align}
&=\frac{q}{\text{e = carica per elettrone}} \\
&= \frac{48.0C}{e = 1.60\times 10^{-19}\text{C/Elettrone}} \\
&= 3.00\times 10^{20} \text{ elettroni} 
\end{align}
$$
## Descrizione Microscopica della correte in un Metallo
Gli elettroni in un metallo hanno velocità di $\sim 10^{6}m/s$, ma la direzione del loro moto è casuale, quindi la loro velocità di deriva $v_{drift}=0$.
![[Pasted image 20241126163634.png|250]]
Solo quando le estremità del filo si trovano a potenziali diversi $(E\neq 0)$ ci sarà un flusso netto di elettroni lungo il filo $(v_{drift} \neq 0)$. Tipicamente, $v_{drift} < 1 mm/\sec$.
![[Pasted image 20241126163835.png|250]]
## FEM e Circuiti
Una batteria ideale mantiene una differenza di potenziale costante tra i suoi morsetti. Questa differenza di potenziale si chiama *forza elettromotrice* della batteria(FEM $\varepsilon$).
Il lavoro svolto da una batteria ideale nello spostare una carica $q$ tra i due morsetti è $W = q\varepsilon$.
![[Pasted image 20241126164823.png|250]]
Le batterie funzionano convertendo *energia chimica* in *energia elettrica*. Una batteria si esaurisce quando non può più sostenere le reazioni chimiche al suo interno e quindi non può più produrre lavoro per spostare le cariche.
## Resistenza e Resistività
Un materiale è considerato **ohmico** se $\Delta V \propto I$.
La **legge di Ohm** è:
$$
\Delta V = IR
$$
La costante di proporzionalità $R$ viene chiamata *resistenza* e si misura in *ohm* $(\Omega; 1 \Omega = 1 V/A)$.
$$
R = \frac{\Delta V}{I} \quad [R] = \frac{[V]}{[J]}
$$
La resistenza di un conduttore è:
$$
R = \rho \frac{L}{A} \quad\quad\quad [\rho] = \frac{[R] \cdot [L]^{2}}{[L]} = [R][L] = \Omega \text{m}
$$
- $\rho$ è la *resistività* del materiale.
- $L$ la lunghezza del conduttore.
- $A$ l'area della sezione trasversale.
Con $R \propto \rho$ un materiale è considerato un conduttore se $\rho$ è "piccolo", isolante se $\rho$ è "grande".
La resistività di un materiale dipende dalla sua temperatura:
$$
\rho = \rho_{0} (1 + \alpha(T-T_{0}))
$$
dove $\rho_{0}$ è la resistività alla temperatura $T_{0}$, e $\alpha$ è il coefficiente di temperatura della resistività.
Un materiale è un superconduttore se $\rho = 0$.
## Misurare Correnti e Voltaggi
Le correnti si misurano con un *amperometro*.
Un amperometro è posizionato in serie al componente circuitale di interesse.
![[Pasted image 20241126170519.png|500]]
Un *voltmetro* si usa per misurare la caduta di potenziale su un elemento circuitale. Viene posizionato in parallelo al componente. Un voltmetro ha una resistenza interna elevata rispetto alle resistenza del circuito.
![[Pasted image 20241126170658.png|175]]
## Potenza e Energia nei Circuiti
Il tasso di dissipazione di energia è:
$$
P = \frac{\Delta U}{\Delta t} = \frac{q}{\Delta t}\Delta V=I\Delta V
$$
Per una sorgente di fem:
$$
P=I\varepsilon
$$
Per una resistenza:
$$
P = I\Delta V=I^{2}R=\frac{\Delta V^{2}}{R}
$$
**Esempio**:
Il filamento metallico percorso da corrente in una lampada elettrica si riscalda fino a diventare incandescente. Se vengono utilizzate due batterie di $1.5V$ che producono una ddp di $3V$ ai capi del filamento per fornire una corrente di $0.4 A$, determinare la resistenza del filamento. Trovare inoltre la potenza erogata dalla lampada e l’energia dissipata in $5.5 \min$ di funzionamento.
La resistenza è data dalla legge di Ohm:
$$
R = \frac{\Delta V}{I} = \frac{3}{0.4} = 7.5\Omega
$$
La potenza erogata è data da:
$$
P = I^{2}R = 0.4^{2}\times 7.5 = 1.2W 
$$
L'energia dissipata in $5.5\min$ è:
$$
E = P\cdot t=1.2W\cdot 5.5 \cdot 60s = 396.0J
$$
**Esempio**:
La resistenza di un conduttore è $19.8\Omega$ a $15.0°C$ e $25.0\Omega$ a $85.0°C$. Trascurando l’effetto della variazione di temperatura sui parametri geometrici del resistore, qual è il coefficiente di temperature della resistività?
Sono dati i valori di $R$ a diverse temperatura, non quelli di $\rho$. Ma le due quantità sono collegate.
$$
\begin{gather}
R = \rho \frac{L}{A} \\
\rho = \rho_{0}(1+\alpha(T-T_{0}))
\end{gather}
$$
Moltiplica entrambi i membri della seconda equazione per $\frac{L}{A}$ e usa la prima equazione per ottenere:
$$
R = R_{0}(1+\alpha(T-T_{0}))
$$
Quindi:
$$
\alpha = \frac{\frac{R}{R_{0}}-1}{\Delta T} = \frac{\frac{25.0\Omega}{19.8\Omega}-1}{85.0°C - 15.0°C} = 3.75 \times 10^{-3}°C^{-1}  
$$
## Principi di Kirchhoff
Un *nodo* è un punto in cui tre o più fili (o componenti) si incontrano.
- **Legge dei nodi**: la corrente che entra in un nodo è la stessa che esce da esso. (questo principio esprime la conservazione della carica elettrica).
![[Pasted image 20241126171959.png|350]]
Una *maglia* è un percorso chiuso all'interno di un circuito.
- **Legge delle maglie**: la somma delle cadute di potenziale in una maglia è zero. (questo principio esprima la conservazione dell'energia).
![[Pasted image 20241126172109.png|350]]
Una corrente scorrerà solo attorno a una maglia.
![[Pasted image 20241126172329.png|500]]
Applicando la *legge delle maglie*:
$$
\begin{gather}
V_{AB} - IR = 0 \\
\varepsilon - Ir - IR = 0
\end{gather}
$$
## Circuiti in Serie e in Parallelo
**In serie**:
![[Pasted image 20241126172614.png|250]]
Applicando la legge di Kirchhoff delle maglie:
$$
\begin{align}
&\varepsilon-IR_{i}-IR_{2} = 0 \\
&\varepsilon=IR_{1} + IR_{2} = I(R_{1}+R_{2})=IR_{eq}
\end{align}
$$
La coppia di resistenze $R_{1}$ e $R_{2}$ può essere sostituita con un'unica resistenza equivalente $R_{eq} = R_{1}+R_{2}$.
In generale, per le resistenze in serie:
$$
\begin{align}
R_{eq} &= R_{1}+R_{2}+\dots+R_{n} \\
&=\sum_{i=1}^{n} R_{i}
\end{align}
$$
**In parallelo**:
![[Pasted image 20241126173003.png|250]]
Applicando la legge di Kirchhoff delle maglie:
$$
\begin{align}
&\varepsilon-I_{1}R_{1}=0 \\
&\varepsilon-I_{2}R_{2}=0
\end{align}
$$
La caduta di potenziale attraverso ciascuna resistenza è la stessa.
Applicando la legge dei nodi in $A: I = I_{1}+I_{2}$.
Dalla legge delle maglie: $\varepsilon=I_{1}R_{1}=I_{2}R_{2}$.
Sostituendo $I_{1}$ e $I_{2}$ nella legge dei nodi:
$$
\begin{align}
&I=\frac{\varepsilon}{R_{1}} + \frac{\varepsilon}{R_{2}} \\
&\frac{I}{\varepsilon} = \frac{1}{R_{1}} + \frac{1}{R_{2}} = \frac{1}{R_{eq}}
\end{align}
$$
La coppia di resistenze $R_{1}$ e $R_{2}$ può essere sostituita con una sola resistenza equivalente:
$$
\frac{1}{R_{eq}} = \frac{1}{R_{1}}+\frac{1}{R_{2}}
$$
In generale, per le resistenza in parallelo:
$$
\begin{align}
\frac{1}{R_{eq}} &= \frac{1}{R_{1}}+\frac{1}{R_{2}}+\dots+\frac{1}{R_{n}} \\
&=\sum_{i=1}^{n} \frac{1}{R_{i}}
\end{align}
$$
**Esempio**:
Per rendere più lungo possibile l’uso della catena di luci del vostro albero di Natale conviene che le lampadine siano collegate in serie o in parallelo?
Nel collegamento in serie se una resistenza si rompe si interrompe la circolazione della corrente in tutte le altre. Nel collegamento in parallelo, invece, le altre resistenze continuano a funzionare, sebbene con una corrente di intensità maggiore. Conviene quindi questa seconda configurazione di collegamento.
**Esempio**:
Il vostro impianto elettrico è alimentato da una potenza di $5 KW$. Ad un certo istante la differenza di potenziale erogata è $220 V$. Se avete collegati quattro elettrodomestici che assorbono, rispettivamente $100 W, 1,8 KW, 350 W$ e $1,2 kW$, quale corrente elettrica li attraversa? Quale potenza e quale corrente vi rimangono disponibili per collegare altri elettrodomestici?
![[Pasted image 20241126173810.png|250]]
Gli elettrodomestici sono collegati in parallelo. Quindi hanno tutti la stessa ddp di $220V$.
Le varie correnti si calcolano dividendo la potenza assorbita da ogni singolo utilizzatore per la ddp comune:
$I_{n}=\frac{P_{n}}{\Delta V}$
$$
\begin{align}
&I_{\text{lampadina}} = \frac{100}{220} = 0.45A \\
&I_{\text{scaldabagno}} = \frac{1800}{220} = 8.18A \\
&I_{\text{stereo}} = \frac{350}{220} = 1.59A \\
&I_{\text{asciugacapelli}} = \frac{1200}{220} = 5.45A
\end{align}
$$
La potenza complessiva utilizzata è
$$
\begin{align}
P &= I\Delta V = (I_{1}+I_{2}+I_{3}+I_{4})\Delta V =  \\
&= P_{1}+P_{2}+P_{3}+P_{4} = (1.8+0.1+0.35+1.2) = \\
&= 3.45kW
\end{align}
$$
Rimangono a disposizione $5-3.45 = 1.55kW$ per altri elettrodomestici.
La corrente residua sarà:
$$
I_{\text{residua}} = \frac{P_{\text{residua}}}{\Delta V} = \frac{1550}{220} = 7.05A
$$
**Esempio**:
Nel circuito quale è la resistenza totale tra i punti $A$ e $B$?
![[Pasted image 20241126183321.png|500]]
$R_{2}$ e §$R_{3}$ sono resistenze in parallelo. Sostituisci con una resistenza equivalente $R_{23}$.
$$
\begin{align}
&\frac{1}{R_{23}} = \frac{1}{R_{2}}+\frac{1}{R_{3}} \\
&R_{23} = \frac{1}{12} + \frac{1}{24} = \frac{2}{24} + \frac{1}{24} = \frac{3}{24} \\
&R_{23}= \frac{24}{3} = 8\Omega
\end{align}
$$
Le resistenze $R_{1}$ e $R_{23}$ sono in serie:
$$
\begin{align}
R_{123} &= R_{1} + R_{23} \\
&= 15\Omega + 8\Omega = 23\Omega = R_{eq}
\end{align}
$$
Questo è il circuito equivalente e la resistenza totale è $23\Omega$.
### Condensatori
La carica sulle armature è la stessa. I due condensatori sono collegati in serie.
![[Pasted image 20241126194256.png|250]]
$$
Q = C\Delta V
$$
Si applica la legge di Kirchhoff delle maglie:
$$
\begin{align}
&\varepsilon-\frac{Q}{C_{1}} - \frac{Q}{C_{2}} = 0 \\
&\frac{\varepsilon}{Q} = \frac{1}{C_{1}} + \frac{1}{C_{2}} = \frac{1}{C_{eq}}
\end{align}
$$
In generale, per i condensatori in serie:
$$
\begin{align}
\frac{1}{C_{eq}} &= \frac{1}{C_{1}} + \frac{1}{C_{2}} +\dots+\frac{1}{C_{n}} \\
&=\sum_{i=1}^{n} \frac{1}{C_{i}}
\end{align}
$$
![[Pasted image 20241126194651.png|250]]
I due condensatori sono collegati in parallelo.
Si applica la legge di Kirchhoff delle maglie:
$$
\begin{align}
&\varepsilon-\frac{Q_{1}}{C_{1}} = 0 \\
&\varepsilon-\frac{Q_{2}}{C_{2}} = 0
\end{align}
$$
quindi:
$$
\begin{align}
Q_{eq} &= Q_{1}+Q_{2} \\
\varepsilon C_{eq} &= \varepsilon C_{1}+\varepsilon C_{2}
\end{align}
$$
In generale, per i condensatori in parallelo:
$$
C_{eq}=C_{1}+C_{2}+\dots+C_{n} = \sum_{i=1}^{n} C_{i}
$$
**Esempio**:
Trova il valore della capacità equivalente nel circuito seguente se $C_{1}=C_{2}=C_{3}=12\mu F$.
![[Pasted image 20241126195137.png|250]]
$C_{2}$ e $C_{3}$ sono in parallelo.
$$
\begin{align}
&C_{23} = C_{2}+C_{3} \\
&=24\mu F
\end{align}
$$
Ora possiamo mettere in serie i due condensatori $C_{23}$ e $C_{1}$.
$$
\begin{align}
\frac{1}{C_{123}} &= \frac{1}{C_{1}} + \frac{1}{C_{23}} \\
&= \frac{1}{12\mu F} + \frac{1}{24\mu F} \\
C_{123} &= 8\mu F
\end{align}
$$
# Elettromagnetismo
I magneti esercitano una forza uno sull'altro.
Poli magnetici "opposti" si attraggono, poli "uguali" si respingono.
Il **dipolo** magnetico genera un campo, le linee di campo escono dal polo Nord ed entrano nel polo Sud.
## Legge di Gauss per il magnetismo
Il flusso del campo magnetico attraverso qualunque superficie chiusa è sempre nullo.
Intorno alla Terra il campo magnetico è simile a quello di un dipolo, il magnete a sbarra.
Prove di una inversione dei poli magnetici sono state trovate sui fondali oceanici. Minerali ricchi di ferro nelle rocce contengono un registro del campo magnetico terrestre.
## Prodotto vettoriale tra due vettori
Prodotto vettoriale generico: $\vec{c} = \vec{a}\times \vec{b}$, ma $\vec{b} \times \vec{a}$ non sono uguali.
![[Pasted image 20241126200449.png|250]]
$$
|\vec{c}| = |\vec{a}|\cdot |\vec{b}|\cdot \sin \theta
$$
## Forza magnetica su una carica puntiforme(forza di Lorentz)
La *forza magnetica* su una carica puntiforme è:
$$
F_{B} = q(v\times B)
$$
L'unità di misura del campo magnetico($B$) è il Tesla($1T = 1 n/Am$).
Il modulo di $F_{B}$ è:
$$
F_{B} = qB(v\sin \theta)
$$
dove $v\sin \theta$ è la componente della velocità perpendicolare alla direzione del campo magnetico. $\theta$ rappresenta l'angolo tra $v$ e $B$.
La direzione di $F_{B}$ si trova dalla regola della mano destra.
**Esempio**:
Un protone con velocità di $5 \times 10^{6} m/s$ incontra un campo di induzione magnetica di $0.4T$ la cui direzione orientata forma un angolo $\theta = 30°$ con la velocità del protone.
- Si trovino il modulo e la direzione orientata della forza magnetica agente sul protone e l'accelerazione del protone.
- Quali sarebbero la forza e l'accelerazione se la particella fosse un elettrone?
$$
\begin{align}
&F_{p} = qvB\sin 30° = 1.6 \times 10^{-13}N \\
&F_{p} = 1.6\times 10^{-13}N = ma \Rightarrow a_{p} = \frac{F_{p}}{m_{p}} = \frac{1.6 \times 10^{-13}}{1.67\times 10^{-27}} = 0.96 \times 10^{14} m/s^{2}
\end{align}
$$
Per l'elettrone:
$$
\begin{align}
&F_{e} = qvB\sin 30°=1.6\times 10^{13}N \\
&F_{e} = 1.6\times 10^{-13}N = ma \Rightarrow \frac{F_{e}}{m_{e}} = \frac{1.6\times 10^{-13}}{9.109 \times 10^{-31}} = 0.18 \times 10^{18} m/s^{2} 
\end{align}
$$
## Cariche in campo magnetico uniforme
### Caso $v \perp B$
![[Pasted image 20241126201807.png|250]]
Una particella carica positivamente ha una velocità $v$ come in figura. Il campo magnetico è diretto verso l'interno.
Applicando la seconda legge di Newton alla carica:
$$
\begin{align}
\sum F &= F_{B} = ma_{r} \\
&qvB = m\frac{v^{2}}{r}
\end{align}
$$
### Caso $v \not\perp B$
![[Pasted image 20241126202111.png|250]]
Se una particella carica ha una componente della propria velocità perpendicolare a $B$, allora la sua traiettoria sarà circolare. Se ha anche una componente di $v$ parallela a $B$, si muoverà anche verso l'alto. Il risultato è un moto elicoidale.
**Esempio**:
Un protone parte dalla posizione di quiete sull'armatura positiva di un condensatore piano e viene accelerato verso l'armatura negativa dalla forza elettrica. La differenza di potenziale tra le armature è $2100V$. Il protone ad alta velocità abbandona il condensatore attraverso un piccolo foro dell'armatura negativa. Uscito dal condensatore il protone si muove a velocità costante fino a che non entra in una regione dove c'è un campo magnetico uniforme di modulo pari a $0.10T$. La velocità e l'induzione magnetica sono *mutuamente perpendicolari*.
- Si trovino la velocità del protone quando esce dal condensatore, la variazione dell'energia cinetica del protone causata dal campo magnetico e il raggio della traiettoria circolare su cui il protone si muove nel campo magnetico.
![[Pasted image 20241127105427.png|250]]
Per trovare la velocità del protone all'uscita del condensatore, applichiamo la conservazione dell'energia totale. Ovvero l'energia del protone sull'armatura positiva $A$:
$$
E_{A} = E_{kA} + U_{A} = q_{p}V_{A}
$$
L'energia cinetica($E_{kA}$) del protone sull'armatura positiva è nulla perché parte da fermo.
Deve essere uguale all'energia del protone sull'armatura negativa $B$:
$$
E_{B} = E_{kB} + U_{B} = \frac{1}{2}_{B}mv^{2} + q_{p}V_{B}
$$
Eguagliando l'energia totale del protone sull'armatura positiva e su quella negativa:
$$
\begin{align}
&E_{A} = E_{B} \\
& q_{p}V_{A} = \frac{1}{2}mv_{B}^{2}+q_{p}V_{B} \Rightarrow \\
&V_{B} = \sqrt{ \frac{2q_{p}(V_{A}-V_{B})}{m}} = \sqrt{ \frac{2 \times 1.6 \times 10^{-19} \times 2100}{1.67 \times 10^{-27} }} m/s = 6.3 \times 10^{5} m/s 
\end{align}
$$
Quando il protone è al di fuori del condensatore agisce il campo magnetico.
Quindi il protone è soggetto alla forze di Lorentz:
$$
\vec{F_{L}} = q_{p} (\vec{v} \times \vec{B})
$$
Per calcolare la variazione di energia cinetica dovuta al campo magnetico, applichiamo il *teorema dell'energia cinetica*:
$$
\Delta E_{k} = L = \vec{F_{L}} \cdot \vec{s} = |F_{L}||s|\cos90° = 0
$$
$\vec{F_{L}} \perp \vec{v} \Rightarrow \vec{F_{L}} \perp \vec{s}$
Il lavoro della forza di Lorentz è nullo, da cui la variazione di energia cinetica è anch'essa nulla, per cui la velocità del protone non cambia ed è sempre pari a $6.3 \times 10^{5} m/s$.
La forza di Lorentz agisce come forza centripeta, quindi possiamo uguagliare:
$$
\begin{align}
&|\vec{F_{L}}| = \frac{mv^{2}}{r} \\
&q_{p}Bv_{B}\sin 90° = \frac{mv_{B}^{2}}{r} \Rightarrow q_{p}Bv_{B} = \frac{mv_{B}^{2}}{r} \quad v \text{ e }B\text{ sono perpendicolari} \\
&r=\frac{mv}{q_{p}B} = \frac{1.67 \times 10^{-27} \times 6.6 \times 10^{5}}{1.69 \times 10^{-19}\times 0.1} m = 6.2 \times 10^{-2}m
\end{align}
$$
## Forza magnetica su un filo percorso da corrente
![[Pasted image 20241127141013.png|250]]
La forza su un filo percorso da corrente in un campo magnetico esterno è:
$$
\vec{F} = I(\vec{L}\times \vec{B})
$$
$\vec{L}$ è un vettore che punta nel verso di scorrimento della corrente. Il suo modulo è la lunghezza del filo, $\vec{B}$ vettore induzione magnetica e $I$ intensità della corrente elettrica.
Il modulo della forza sarà:
$$
F = IBL\sin \theta
$$
- $L = |\vec{L}|$: lunghezza del filo.
- $B = |\vec{B}|$: modulo del campo elettrico.
- $\theta$: angolo tra $\vec{L}$ e $\vec{B}$.
## Campo magnetico dovuto a una corrente
![[Pasted image 20241127143024.png|500]]
Il campo magnetico ad una distanza $r$ da un filo lungo e dritto percorso dalla corrente $I$ è:
$$
B = \frac{\mu_{0}I}{2\pi r} = \frac{\mu_{0}}{2\pi} \cdot \frac{I}{r}
$$
dove $\mu_{0} = 4\pi \times 10^{-7} Tm/A$ è la permeabilità del vuoto.
La direzione delle linee di campo $B$ è data dalla regola della mano destra. Il pollice punta nel verso di scorrimento della corrente. Chiudendo la mano, le altre dita si chiudono nel verso di percorrenza delle linee del campo.
### Caso della spira
![[Pasted image 20241127145138.png|500]]
![[Pasted image 20241127145248.png|500]]
### Solenoide
Un solenoide è un avvolgimento di spire a forma di cilindro.
Il campo dentro al solenoide è quasi uniforme ed ha intensità:
$$
B = \mu_{0}nI
$$
dove $n = \frac{N}{L}$ è il numero di avvolgimenti($N$) per unità di lunghezza ($L$) e $I$ la corrente nel filo.
## La legge di Ampère
La legge di Ampère per la magnetostatica gioca un un ruolo simile a quello che la legge di Gauss rappresenta in elettrostatica.
La legge di Gauss è una relazione matematica tra il campo elettrico e le sue sorgenti: le cariche elettriche.
La legge di Ampère è una relazione matematica che lega il campo magnetico alle sue sorgenti: le correnti elettriche.
### Circuitazione di un campo vettoriale lungo una linea chiusa
![[Pasted image 20241127145758.png|250]]
Consideriamo una linea chiusa $I$ in ogni punto della quale è definito un campo vettoriale $B$.
Fissato un orientamento sulla linea, si definisce *circuitazione di $B$* lungo la linea $I$ la quantità:
$$
\oint B \cdot dl = \lim_{ N \to \infty } \sum_{1}^{N} B \cdot dl
$$
dove $B \cdot dl$ rappresenta il prodotto scalare tra il vettore $B$ e il vettore $dl$ che ha come modulo l'elemento infinitesimo di lunghezza $dl$, orientato secondo la tangente alla linea $I$ nel punto considerato.
La *circuitazione* di $B$ lungo qualsiasi percorso chiuso è uguale a $\mu_{0}I$, dove $I$ è la *corrente stazionaria totale* che attraversa una qualunque superficie delimitata dal percorso chiuso di integrazione.
$$
\oint \vec{B} \cdot d\vec{l} = \mu_{0}\sum_{1}^{n} I_{n} = \mu_{0}I_{\text{tot}}
$$
- $\mu_{0}$ impermeabilità del vuoto.
- $I_{\text{tot}}$ corrente totale.
![[Pasted image 20241127151056.png|350]]
Nell’esperimento di Oersted si vuole valutare l’intensità di $B$ ad una distanza $r$ dal filo percorso dalla corrente stazionaria $I$. Prendiamo come percorso chiuso su cui calcolare la circuitazione una circonferenza con centro sul filo e di raggio $r$ contenuta in un piano perpendicolare al filo.
Per questioni di simmetria $B$ ha lo stesso modulo in ogni punto della circonferenza. Inoltre sappiamo dall’esperimento che $B$ è tangente alla circonferenza in ogni punto. Quindi:
$$
\oint B \cdot dl = B \cdot 2\pi r = \mu I
$$
per la legge di Ampère. Quindi:
$$
B = \frac{\mu}{2\pi} \frac{I}{r}
$$
Questo risultato è indipendente dalla particolare scelta della linea chiusa che racchiuda il filo.
## Interazione tra correnti elettriche: la definizione dell'Ampere
![[Pasted image 20241127151542.png|500]]
Due fili conduttori rettilinei paralleli, percorsi da correnti di intensità $I_{1}$ e $I_{2}$ aventi lo stesso verso, si attraggono mutuamente.
I fili si respingono mutuamente quando le correnti hanno versi opposti.
**Esempio**:
Due fili paralleli che giacciono su un piano orizzontale trasportano le correnti $I_{1}$ e $I_{2}$ verso destra. I fili sono lunghi entrambi $L$ e sono separate da una distanza $d$.
![[Pasted image 20241127152726.png|350]]
Scriviamo il modulo e la direzione del campo $B$ generato dal filo $1$ nella posizione del filo:
$$
B_{1} = \frac{\mu_{0}I_{1}}{2\pi d}
$$
Ora scriviamo il modulo della forza magnetica sul filo $2$ dovuti al filo:
$$
\begin{align}
F_{12} &= I_{2}LB_{1}\sin \theta \\
&= I_{2}LB_{1} = \frac{\mu_{0}I_{1}I_{2}L}{2\pi d}
\end{align}
$$
$L$ è un tratto del filo $2$ dove misuriamo la forza, essendo perpendicolari $\sin \theta = \sin 90° = 1$.
Reciprocamente, scriviamo il modulo e verso del campo $B$ generato dal filo $2$ nella posizione del filo:
$$
B_{2}= \frac{\mu_{0}I_{2}}{2\pi d}
$$
Infine, il modulo della forza magnetica sul filo $1$ dovuto al $2$ è:
$$
\begin{align}
F_{21} &= I_{1}LB_{2}\sin \theta \\
&= I_{1}LB_{2}= \frac{\mu_{0}I_{1}I_{2}L}{2\pi d}
\end{align}
$$
**Esempio**:
Un filo orizzontale è percorso dalla corrente continua $I=I_{1}=80A$.
- Quanto deve valere la corrente in un secondo filo, parallelo al primo e posto $20cm$ più basso, perché questo non cada sotto l'effetto della gravità. La massa per metro di lunghezza del filo in basso è $0.12g$.
![[Pasted image 20241127154120.png|250]]
$$
\begin{align}
F_{mag} &= I_{2}LB_{1}\sin \theta = I_{2}L\frac{\mu_{0}I_{1}}{2\pi d} \\
P &= mgL
\end{align}
$$
Quindi:
$$
mgL = I_{2}L\frac{\mu_{0}I_{1}}{2\pi d} \Rightarrow I_{2} = \frac{mgL 2\pi d}{\mu_{0}I_{1}L} = \frac{0.00012 \cdot 9.81 \cdot 2\pi \cdot 0.2}{4\pi \cdot 10^{-7} \cdot 80} = 14.72A
$$
## Materiali Magnetici
Nella materia esistono delle cariche che ruotano su orbite chiuse(es: elettroni atomici, ma anche lo spin).
Queste microspire percorse da corrente sono normalmente orientate in tutte le direzioni e i corrispondenti campi magnetici annullano i loro effetti: il campo magnetico netto è quindi nullo(materiali non ferromagnetici).
I materiali ferromagnetici sono formati da *domini*, regioni in cui i campi magnetici "atomici" sono allineati, fornendo localmente un campo magnetico più forte.
- Quando i campi magnetici dei domini sono orientati in modo casuale, non c'è una magnetizzazione netta sull'oggetto.
- Quando i domini sono allineati, per esempio da un campo magnetico esterno, il materiale avrà una magnetizzazione netta.
# Onde elettromagnetiche
## Forza elettromotrice indotta
Considera un conduttore in un campo $B$ in moto verso destra.
![[Pasted image 20241101142653.png|250]]
$$
F_{B} = q(v \times B)
$$
Un elettrone nel conduttore sperimenta una forza verso il basso.
![[Pasted image 20241101142907.png|150]]
Ciò crea nella sbarra un campo elettrico e una differenza di potenziale tra l'apice e il fondo della sbarra. Il trasferimento di carica ha termine quando la forza dovuta al campo magnetico viene annullata dalla forza elettrica repulsiva tra la carica accumulata e la nuova carica in arrivo.
Cosa accadrebbe se la sbarra fosse posta perpendicolarmente a dei binari conduttivi (in rosso) in modo da formare una spira per gli elettroni?
![[Pasted image 20241127160142.png|250]]
In questo circuito, gli elettroni girano in senso orario; la corrente scorre in senso antiorario.
La FEM indotta $\varepsilon$ agli estremi del conduttore si può ottenere considerando che:
$$
\begin{gather}
q\varepsilon = F_{B}L = qvBL \\
\varepsilon = vBL
\end{gather}
$$
dove $L$ è la separazione tra i binari.
$$
\text{La corrente nella sbarra è} \quad I = \frac{\Delta V}{R} = \frac{\varepsilon}{R} = \frac{vBL}{R}
$$
dove $R$ è la resistenza della sbarra.
La sbarra è dunque percorsa da corrente. Qual è la direzione della forza magnetica sulla sbarra dovuta al campo magnetico esterno?
$$
F = I(L\times B)
$$
Il modulo della forza magnetica sulla sbarra è:
$$
F = ILB\sin90° = ILB = \frac{vBL}{R}LB = \frac{vB^{2}L^{2}}{R}
$$
Usando la regola della mano destra, la forza sulla sbarra è diretta verso sinistra.
Per mantenere una FEM costante tra i due estremi, la sbarra deve muoversi verso destra con velocità costante. Un agente esterno deve quindi compiere lavoro sulla sbarra (conservazione dell’energia).
## Induzione elettromagnetica
L'induzione elettromagnetica è il fenomeno per cui una **variazione del flusso magnetico** che attraversa una superficie genera una forza elettromotrice (f.e.m.) indotta, che può causare il passaggio di una corrente elettrica in un circuito conduttore.
Il *flusso magnetico* è proporzionale al numero di linee del campo B che attraversano una determinata area.
$$
\Phi_{B} = BA\cos \theta
$$
L'unità di misura del flusso magnetico è il *Weber*: $1Wb = 1Tm^{2}$.
- $A$ area della spira.
**Esempio**:
La spira in figura ha un'area di $0.1m^{2}$. Il campo magnetico è perpendicolare al piano della spira e ha una intensità costante di $0.2T$. Si trovi il flusso magnetico attraverso la spira.
![[Pasted image 20241127161211.png|250]]
Per risolvere questo problema, dobbiamo applicare la legge di Faraday Neumann Lenz che lega fra loro f.e.m e flusso magnetico. Il flusso del campo magnetico attraverso la superficie è dato dal prodotto scalare tra il vettore $B$ e il vettore $A$.
$$
\begin{gather}
\Phi_{B} = \vec{B} \cdot \vec{A} \\
\Phi_{B} = \vec{B} \cdot \vec{A} = 0.1 \cdot 0.2 = 0.2Wb
\end{gather}
$$
$A$ è il vettore avente come modulo ilvalore della superficie e come direzionequella perpendicolare alla superficie.
## Legge di Faraday
$$
\varepsilon = -N \frac{\Delta \Phi_{B}}{\Delta t}
$$
Una FEM indotta in un avvolgimento di $N$ spire è dovuta al cambiamento del flusso.
- $\varepsilon$ forza elettromotrice indotta (volt).
- $\Phi_{B}$ flusso magnetico, definito come $\Phi_{B} = B \cdot A \cdot \cos \theta$.
	- $B$ intensità del campo magnetico.
	- $A$ area della superficie attraversata dal campo.
	- $\theta$ angolo tra la superficie e la direzione del campo magnetico.
- $\frac{\Delta \Phi_{B}}{\Delta t}$ variazione del flusso magnetico nel tempo.
Il segno **negativo** è determinato dalla **legge di Lenz**.
## Legge di Lenz
Il **segno negativo**(legge di Lenz) indica che la direzione della f.e.m. indotta è tale da generare una corrente che si oppone alla variazione di flusso.
**Esempio**:
Una spira di area $0.1m^{2}$ ha una resistenza di $10\Omega$ . Un campo magnetico $B$ normale alla spira ha inizialmente una intensità di $0.2T$ e viene ridotto a zero con una velocità uniforme in $10^{4}s$.
- Trovare la f.e.m. indotta e la corrente risultante.
$$
\varepsilon=-\frac{d\Phi_{B}}{dt}
$$
Calcoliamo il flusso magnetico all'istante iniziale:
$$
\Phi_{B}(t=0) = \vec{B} \cdot \vec{A} = |\vec{B}|\cdot |\vec{A}|\cos0 = 0.1 \cdot 0.2 Wb = 0.02Wb
$$
All'istante finale il flusso magnetico è nullo essendo il campo magnetico nullo.
$$
\Phi_{B}(t = 10^{4}s) = 0
$$
La FEM indotta sarà data:
$$
\varepsilon = -\frac{\Delta \Phi_{B}}{\Delta t} = - \frac{\Phi_{B}(t=10^{-4} s)-\Phi_{B}(t=0)}{\Delta t} = \frac{0.02}{10^{4}}V = 2 \cdot 10^{2}V 
$$
Calcoliamo adesso il verso della corrente indotta che circola nel circuito. Dalla legge di Lenz questa corrente deve opporsi alla variazione di flusso.
$$
I_{\text{ind}} = \frac{\varepsilon}{R} = \frac{2 \cdot 102V}{10\Omega}=20A
$$
**Esempio**:
Se il campo magnetico in una regione varia col tempo secondo il grafico qui sotto.
- Trova il modulo della FEM indotta in una singola spira durante I seguenti intervalli di tempo:
	- $a: 0-2.0ms$;
	- $b: 2.0 - 4.0ms$;
	- $c: 4.0-8.0ms$.
La spira ha area $0.500m^{2}$ e il piano della spira è perpendicolare a $B$.
![[Pasted image 20241127163033.png|250]]
Usa la legge di Faraday:
$$
\varepsilon = -\left( \frac{\Delta \Phi_{B}}{\Delta t} \right) = -A\left( \frac{\Delta B}{\Delta t} \right) \quad \longleftarrow \text{pendenza del grafico di }B \text{ sul tempo}
$$
$a$ nell'intervallo $0.0-2.0ms$:
$$
|\varepsilon| = |-A\left( \frac{\Delta B}{\Delta t} \right)| = |(0.500m^{2})\left( \frac{0.50T-0.00T}{2.0\times 10^{-3}s} \right)|= 125V
$$
$b$ nell'intervallo $2.0-4.0ms$:
$$
|\varepsilon| = |-A\left( \frac{\Delta B}{\Delta t} \right)| = |(0.500m^{2})\left( \frac{0.50T-0.50T}{2.0\times 10^{-3}s} \right)|= 0V
$$
$c$ nell'intervallo $4.0-8.0ms$:
$$
|\varepsilon| = |-A\left( \frac{\Delta B}{\Delta t} \right)| = |(0.500m^{2})\left( \frac{0.00T-0.50T}{4.0\times 10^{-3}s} \right)|= 62.5V
$$
## Autoinduzione
L'autoinduzione è il fenomeno per cui una variazione di corrente in un circuito induce una *forza elettromotrice(f.e.m.)* nel circuito stesso, opponendosi alla variazione della corrente.
**FEM indotta**:
$$
\varepsilon = -L \frac{\Delta I}{\Delta t} = -\frac{\Delta \Phi_{B}}{\Delta t} = B \cdot l \cdot v
$$
- $\varepsilon$ forza elettromotrice indotta.
- $L$ induttanza del circuito in henry (H).
- $\frac{\Delta I}{\Delta t}$ variazione della corrente nel tempo.
# Onde elettromagnetiche
## Campo elettrici e magnetici prodotti da cariche elettriche accelerate
Abbiamo studiato il campo *elettrico prodotto* da una *carica ferma* (legge di Gauss dell’elettrostatica) e il campo elettrico(non conservativo) prodotto da un campo magnetico variabile nel tempo (legge di Faraday).
La legge Ampère consente di calcolare il *campo magnetico* prodotto da una *corrente costante* nel tempo (magnetostatica), che chiameremo “corrente di conduzione”.
Nel seguito esploreremo che caratteristiche hanno *i campi elettrico e magnetico* generati da *cariche accelerate*. Questo ambito di fenomeni richiede una modifica della legge di Ampère così come l’abbiamo formulata in magnetostatica.
## Legge di Ampere-Maxwell
Consideriamo un lungo filo rettilineo di raggio $R$ percorso da una corrente continua $I$. Ad un certo punto il filo ha una interruzione. Le superfici di questa interruzione agiscono da piastre di un condensatore. Se la corrente scorre verso l’alto sulla faccia inferiore si accumulano cariche positive:
$$
\Delta Q(t) = I\Delta t
$$
mentre sull'altra superficie del filo si accumula una $-\Delta Q(t)$.
Applichiamo la legge di Ampère al cammino circolare $\gamma$. La circuitazione di $B$ deve essere proporzionale alla corrente che attraversa qualunque superficie che si appoggia alla linea $\gamma$. Per la superficie $S_{1}$ otteniamo il campo magnetico di un filo rettilineo percorso da corrente. Se invece prendiamo la superficie $S_{2}$, la superficie non viene attraversata da nessuna corrente, dunque il campo magnetico dovrebbe essere nullo. Tuttavia attraverso la superficie S2 c’è un flusso di campo elettrico non nullo che aumenta man mano che si accumulano cariche:
$$
E = \frac{\sigma}{\varepsilon_{0}} = \frac{\Delta Q}{\varepsilon_{0}\pi R^{2}}
$$
- $\sigma = \frac{\Delta Q}{\pi R^{2}}$
Quindi:
$$
\frac{\Delta \Phi_{E}}{\Delta t} = \frac{\pi R^{2}}{\Delta t} \frac{\Delta Q}{\varepsilon_{0}\pi R^{2}} = \frac{I}{\varepsilon_{0}}
$$
Se invece moltiplichiamo $\frac{\Delta \Phi_{E}}{\Delta t}$ per $\varepsilon_{0}$ troviamo una corrente.
![[Pasted image 20241127165333.png|150]]
In base a queste considerazioni e anche da considerazioni di simmetria del ruolo di $E$ e $B$ nelle leggi dell’elettromagnetismo, Maxwell intuì che la legge di Ampère doveva essere generalizzata ad includere situazioni *dipendenti dal tempo*.
$$
\oint B \cdot dL = \mu_{0}\left( I+\varepsilon_{0}\frac{\Delta\Phi_{E}}{\Delta t} \right)
$$
Dunque il campo magnetico può essere generato sia dalle *correnti elettriche di conduzione*($I$) che dai *campi elettrici variabili nel tempo*($\varepsilon_{0}\frac{\Delta \Phi_{E}}{\Delta t}$. Il secondo termine in parentesi a secondo membro è chiamata “corrente di spostamento”.
Le linee di $B$ sono sempre chiuse e sono concatenate o *ad una corrente*, o *ad un campo elettrico* variabile o *ad una combinazione dei due*.
## Equazioni di Maxwell
### Legge di Gauss per l'elettrostatica
I campi elettrostatici sono generati dalle cariche elettriche.
$$
\oint \vec{E} \cdot \vec{\Delta A} = \frac{q}{\varepsilon_{0}}
$$
### Legge di Gauss per il magnetismo
Non esistono monopoli magnetici.
$$
\oint \vec{E} \cdot \vec{\Delta A} = 0
$$
### Legge di Faraday
Un campo magnetico variabile produce un campo elettrico.
$$
\oint \vec{E} \cdot \vec{\Delta s} = - \frac{\Delta \Phi_{B}}{\Delta t}
$$
- $\Delta \Phi_{B}$ è la forza elettromotrice indotta dalla variazione di flusso di campo magnetico.
### Legge di Ampère-Maxwell
Una corrente elettrica o un campo elettrico variabile generano un campo magnetico.
$$
\oint \vec{B} \cdot \vec{\Delta s} = \mu_{0}I + \varepsilon_{0}\mu_{0}\frac{\Delta \Phi_{E}}{\Delta t}
$$

### Corrente di Spostamento
James Clerk Maxwell introdusse il concetto di **corrente di spostamento** per estendere la legge di Ampère ai fenomeni in cui il campo elettrico varia nel tempo. La corrente di spostamento rappresenta il contributo di un campo elettrico variabile alla creazione di un campo magnetico, anche in assenza di corrente conduttrice.
Modifichiamo quindi la **legge di Ampère**:
$$
\oint_{C} B \cdot \Delta I = \mu_{0}\left( I + \varepsilon_{0} \frac{\Delta \Phi_{E}}{\Delta t} \right)
$$
- $\varepsilon_{0}$ è la costante **dielettrica** nel vuoto ($\varepsilon_{0} \approx 8.85 \times 10^{-12} F/m$ (Farad per metro)).
- $\frac{\Delta \Phi_{E}}{\Delta t}$ la variazione del **flusso del campo elettrico**.
Nel vuoto, in assenza di cariche e correnti di condizione $(q=0, I=0)$, le quattro equazioni di Maxwell nelle incognite $E$ e $B$ sono *simmetriche*:
$$
\begin{align}
\Phi(\vec{E}) = 0 \\
\Phi(\vec{B}) = 0
\end{align}
$$
quindi:
$$
\begin{gather}
\oint_{C} \vec{E} \cdot \vec{\Delta s} = -\frac{\Delta \Phi(B)}{\Delta t} \\
\oint_{C} \vec{E} \cdot \vec{\Delta s} = \mu_{0}\varepsilon_{0}\frac{\Delta \Phi(E)}{\Delta t}
\end{gather}
$$
Combinandole opportunamente è possibile ottenere due equazioni, una per $E$ e una per $B$, della stessa forma (*equazione delle onde*):
$$
\frac{d^{2}E}{dy^{2}} = \mu_{0}\varepsilon_{0}\frac{d^{2}E}{dt^{2}} \quad\quad\quad\quad \frac{d^{2}B}{dy^{2}}=\mu_{0}\varepsilon_{0}\frac{d^{2}B}{dt^{2}}
$$
L’equazione ammette *due soluzioni* per la coppia di campi $(E,B)$
*I vettori $E$ e $B$ soluzione delle equazioni delle onde* sono *perpendicolari tra loro, funzioni del tempo*, e *variano nello spazio* mantenendosi *perpendicolari alla direzione di propagazione $y$*.
$$
E = E(y,t) \quad\quad B=B(y,t)
$$
In ogni punto:
$$
\vec{E} \perp \vec{B}
$$
Entrambi sono funzioni periodiche sinusoidali di $y$ e $t$.
## Onde periodiche
![[Pasted image 20241101152834.png|500]]
$$
v = \lambda f 
$$
- $v$ velocità di propagazione dell'onda.
- $f$ la frequenza.
- $\lambda$ la lunghezza d'onda.
$\frac{\lambda}{T} = v$
$f = \frac{1}{T}$
Le due soluzioni per la coppia di campi sono onde periodiche sinusoidali di tipo “seno” o “coseno”.
Per esempio, per la soluzione di tipo “seno” i moduli dei due campi variano nello spazio e nel tempo in modo periodico secondo la legge:
$$
E_{z} = E_{max} \sin(\varphi(y, t)) \quad B_{x} = B_{max} \sin(\varphi(y,t))
$$
coseno:
$$
E = E_{max}\cos(ky-\omega t) \quad\quad B = B_{max}\cos(ky-\omega t)
$$
$k = \frac{2\pi}{\lambda}$(numero d'onda), $\omega=\frac{23\pi}{T}$(frequenza angolare) e vale la relazione: $\frac{\omega}{k}=c$
![[Pasted image 20241127174754.png|250]]
Esplicitando $\varphi(y,t)$:
![[Pasted image 20241101153203.png|500]]
Dalle equazioni di Maxwell si ricava anche la relazione matematica che lega i moduli di $E$ e $B$:
$$
E = cB
$$
- $c$ velocità di propagazione dell'onda.
- $B$ forza campo magnetico.
E’ possibile dimostrare che l’onda EM trasporta energia, acquisita dalla sorgente che l’ha emessa e questa energia si distribuisce per metà tra $E$ e $B$.
In una *situazione dipendente dal tempo, dunque, l’un campo non può esistere senza l’altro*.
Chiamiamo **onda elettromagnetica** l’insieme dei due campi.
## Velocità di propagazione delle onde EM
Le onde EM si propagano sia nel vuoto che in un mezzo.
Maxwell calcolò teoricamente la velocità di propagazione delle onde EM *nel vuoto* ottenendo il seguente risultato:
$$
\begin{align}
C &= \frac{1}{\sqrt{ \varepsilon_{0} \mu_{0}}} \\
&= \frac{1}{\sqrt{ (8.85 \times 10^{-12} C^{2}/Nm^{2}) (4\pi \times 10^{-7} Tm/A)}} \\
&= 3.00 \times 10^{8} m/s
\end{align}
$$
Indipendente dalla frequenza! Inoltre in un mezzo $v<c$.
**Velocità della luce**:
$$
c \approx 3.00 \times 10^{8} m/s 
$$
*Come si produce un'onda EM?* Applicando una ddp variabile nel tempo in modo periodico ad una *antenna a dipolo elettrico oscillante*.
![[Pasted image 20241127175932.png|250]]
Le due barre metalliche sono alimentate, alle estremità centrali, da una corrente alternata. Per metà del ciclo una estremità acquista carica $+$ e l’altra estremità carica $-$, generando un *dipolo elettrico*. Poichè la corrente è alternata il dipolo cambierà la sua polarità con la stessa frequenza della corrente. Se la carica oscilla con frequenza $f$, l’onda EM risultante varierà nel tempo con la stessa frequenza $f$.
![[Pasted image 20241127180538.png|500]]
## Rivelazione del campo elettrico dell’onda EM: l’antenna
![[Pasted image 20241127180711.png|500]]
Il campo elettrico dell’onda EM si rivela mettendo in moto le cariche di una antenna allineata al campo elettrico dell’onda EM. Nell’antenna ricevente si genera così una corrente alternata.
## Rivelazione del campo magnetico dell’ondaEM: la spira
**Come si misura un campo magnetico?**
Con la legge di Faraday: il campo magnetico di una onda EM è rivelabile collocando una spira di material conduttore perpendicolarmente a $B$. Si genererà così un flusso di $B$ variabile nel tempo attraverso la spira e, di conseguenza, si misurerà una corrente indotta.
![[Pasted image 20241127180903.png|250]]
## Lo spettro EM
Possono esistere onde EM di qualsiasi frequenza.
![[Pasted image 20241127181004.png|600]]
# Fisica moderna
## Il successo della fisica classica
- Meccanica di Newton
	- La forza di gravità svelata
- L'elettromagnetismo di Maxwell&co
	- Le onde elettromagnetiche e la natura fisica della luce
## Grandezze continue e quantizzate
Una grandezza fisica si dice *continua* se i possibili valori che essa può assumere sono distribuiti in modo continuo in un intervallo di valori. Ad esempio, la velocità di una particella accelerata dalla forza gravitazionale.
Una grandezza fisica si dice *quantizzata* se i possibili valori che essa può assumere sono limitati ad un insieme discreto. Ad esempio, la carica elettrica è quantizzata:
$$
Q = Nq
$$
In fisica classica ci sono alcuni esempi di grandezza quantizzate. Per esempio le frequenze sono onde che si possono eccitare su una corda che vibra mantenendo gli estremi fissati(la corda di una chitarra).
## Le particelle atomiche
**Elettoroni**: scoperti come raggi catodici nel 1860 da William Crookes, sono accelerati e deviati dal campo elettrico.
Thomson nel 1896 determina il rapporto carica/massa.
Millikan nel 1909 ne determina la carica elettrica.
## Il modello di Rutherford
Rutherford realizzò un esperimento in cui fasci di nuclei di He(elio) venivano focalizzati su una lastra di oro praticamente monoatomica.
L'interpretazione dei dati dell'esperimento portò alla conclusione che *l'atomo ha un nucleo molto piccolo di carica positiva*($10^{-5}$ volte più piccolo della dimensione dell'atomo) che contiene praticamente tutta la massa dell'atomo, e che *questo nucleo è circondato dagli elettroni*.
**Problema**:
Secondo le leggi della fisica classica gli elettroni sulle loro orbite dovrebbero emettere energia(in quanto cariche accelerate). Questo comporterebbe una riduzione progressiva del raggio dell'orbita, fino al collasso degli elettroni sul nucleo. Gli atomi quindi non sarebbero stabili, che è ovviamente falso.
## Spettroscopia di emissione/assorbimento di gas e solidi
Un gas portato ad alta temperatura emette luce secondo uno spettro a righe(righe luminose su fondo nero). Ogni elemento ha il suo proprio insieme di righe spettrali.
Un solido portato ad alta temperatura emette, invece, luce con spettro continuo.
**Esempio di spettri di emissione**
![[Pasted image 20241127200728.png|450]]
Questa è la luce che emette un gas di atomi eccitati.
**Problema**:
Secondo le leggi della fisica classica gli elettroni sulle loro orbite dovrebbero emettere o assorbire energia in modo continuo. Non si spiega quindi la presenza di righe negli spettri atomici.
## Effetto fotoelettrico
In certe circostanza una radiazione EM che colpisce un metallo estrae elettroni dal metallo. Questo effetti si chiama *effetto fotoelettrico*.
 ![[Pasted image 20241127201001.png|250]]
Gli esperimento mostrano che:
1. La frequenza della lice incidente deve essere maggiore di una frequenza di sogli che dipende dal tipo di metallo utilizzato, In caso contrario non si misurano elettroni emessi.
2. Nel caso in cui gli elettroni siano estratti maggiore è l'intensità luminosa maggiore è il numero di elettroni emessi.
![[Pasted image 20241127201138.png|350]]
3. La massima energia cinetica degli elettroni estratti dipende dalla frequenza(e NON dalla intensità) della luce incidente.
4. Gli elettroni vengono emessi senza osservabile tempo di ritardo rispetto all'illuminazione, indipendentemente dall'intensità.
# La nuova fisica
## L'ipotesi di Einstein
La luce trasporta energia sotto forma di quanti di energia:
$$
E = hf
$$
$h = 6.62607004 \times 10^{-34}Js$
$f = 4.136\times 10^{-15}eVs$
E attraverso l'interazione fotone-elettrone che spiega l'effetto fotoelettrico.
Se il fotone ha energia inferiore a quella di richiesta dall'atomo per liberare un elettrone non viene assorbito e l'elettrone non viene emesso.
Se il fotone ha energia uguale o maggiore a quella richiesta dall'atomo per liberare un elettrone, si ha l'emissione di un elettrone a seguito dell'assorbimento del fotone.
La massima energia cinetica dell'elettrone emesso risulta così essere data da:
$$
KE_{max} = kf - \phi
$$
$hf$ energia del fotone incidente.
$\phi$ energia di ionizzazione o *funzione lavoro* di cui è fatto il nostro metallo, rappresenta l'energia richiesta per rompere il legame tra l'elettrone e il metallo.
$KE_{max}$ energia cinetica massima con cui gli elettroni escono dal nostro atomo.
La frequenza di soglia per effetto fotoelettrico risulta quindi legata alla funzione lavoro dalla condizione:
$$
\begin{align}
&hf_{\text{threshold}} - \phi = 0 \\
&f_{\text{threshold}} = \frac{\phi}{h}
\end{align}
$$
Nella teoria corpuscolare un fascio di luce più intensa è composto da più fotoni. Se i fotoni hanno la frequenza "giusta", ogni fotone dà luogo all'emissione di un elettrone.
*Maggio quindi è il numero di fotoni che colpisce il metallo, maggiore sarà la corrente di fotoelettroni*.
L'energia cinetica dei fotoelettroni è invece *indipendente* dall'intensità della luce incidente.
Mentre nella teoria classica si prevede che debba passare un po' di tempo prima che l'elettrone assorba dalla luce energia sufficiente per sfuggire dal metallo, nella teoria corpuscolare il processo avviene senza alcun ritardo se:
$$
f > f_{\text{threshold}}
$$
## Il modello di Bohr per l'atomo di Idrogeno
Gli elettroni si muovono su orbite circolari sotto l'azione della forza elettrica di attrazione dei nuclei, come nel modello di Rutherford.
Non tutte le orbite sono però stabili: solo su certi stati di fissata energia e raggio, chiamati *stati stazionari*. Negli stati stazionari sono quantizzati l'energia e il raggio dell'orbita.
![[Pasted image 20241128121947.png|500]]
L'elettrone può passare da uno stato stazionario ad un altro assorbendo o emettendo energia pari alla differenza di energia tra gli stati stazionari di arrivo e partenza.
La condizione di quantizzazione di Bohr che identifica gli stati stazionari è la seguente:
$$
mv_{n}2\pi r_{n} = hn
$$
- $n$ un intero positivo.
- $h = 6.63 \times 10^{-34} Js$ costante universale di Planck.
I raggi delle orbite stazionarie per l'elettrone dell'atomo di idrogeno sono:
$$
\begin{align}
&r_{n \text{ orbita}} = a_{0}n^{2} \\
&a_{0}=5.3 \times 10^{-11} m(0.53 \times 10^{-10} Å)
\end{align}
$$
- $a_{0}$ è chiamato raggio di Bohr, raggio dello stato a più bassa energia.
![[Pasted image 20241128123941.png|350]]
Le energie degli stati stazionari sono:
$$
\begin{align}
&E_{n} = \frac{E_{1}}{n^{2}} \\
&E_{1} = -13.6eV
\end{align}
$$
- $E_{1}$ *l'energia dello stato fondamentale* dell'atomo di idrogeno, la più bassa possibile.
- $n$ numero quantico principale.
Se $n>1$ l'elettrone è in uno stato eccitato. L'intero $n$ è detto *numero quantico principale*.
## Spettri di assorbimento ed emissione dell'idrogeno
## Energie permesse nei solidi
Un atomo isolato può emettere soltanto fotoni di energia $E$ corrispondente alla differenza di energia tra due diversi livelli atomici.
Quando due atomi interagiscono i livelli energetici atomici si differenziano.
## Atomi interagenti
In un solido, a motivo dell'interazione tra un grande numero $N$ di atomi, i livelli atomici diventano *bande* di $N$ energie molto vicine in valore, tanto da essere considerabili come un *continuo di energie*. Se due bande successive non si sovrappongono si formano dei *gap* di energia, cioè degli intervalli di energie non permesse agli elettroni.
![[Pasted image 20241128132532.png|350]]
## Gli spettri continui  nei solidi
Un atomo isolato emette uno spettro discreto di righe. La luce emessa corrisponde a fotoni di energia pari alla differenza di energia tra due livelli atomici.
Un solido emette uno spettro continuo a causa delle transizioni elettroniche tra stati della stessa banda o di bande diverse.
![[Pasted image 20241128132940.png|250]]
Un materiale è un *conduttore* se l'ultima banda piena a $T = 0$ lo è parzialmente, oppure se l'ultima banda piena si sovrappone alla prima vuota.
![[Pasted image 20241128133117.png|150]]![[Pasted image 20241128133145.png|150]]![[Pasted image 20241128133203.png|150]]
Quello che cambia è il *valore del Gap*. Negli *isolanti* $\sim 10eV$.
Nei *semiconduttori*:
- *Si*: $1.2eV$
- *Ge*: $0.6eV$
- *GaAs*: $1.4eV$
Considerando che a $T = 20°C(300°K)KT \sim 25meV$ è facile intuire che solo pochi “fortunati” elettroni possono acquistare dal bagno termico energia sufficiente per attraversare la gap.
## Elettroni e lacune
![[Pasted image 20241205112817.png|350]]
Un elettrone, per eccitazione termica, può acquistare energia sufficiente a liberarsi dal legame chimico tra gli atomi e, quindi, muoversi liberamente nel cristallo.
Sull’atomo abbandonato dall’elettrone di valenza si determina una carica in eccesso positiva: la **lacuna**.
In altri termini, un elettrone viene promosso dalla banda di valenza alla banda di conduzione, lasciando una lacuna in quest’ultima.
![[Pasted image 20241205113012.png|200]]
Sotto l’azione di un campo elettrico l’elettrone in banda di conduzione può muoversi liberamente.
In banda di valenza gli elettroni che, sotto l’azione del campo elettrico, premono per muoversi, fanno muovere la lacuna in verso opposto. La lacuna viene accelerata dal campo proprio come una carica positiva.
![[Pasted image 20241205113134.png|350]]
## Isolanti - Conduttori - Semiconduttori
Nei semiconduttori, a basse temperature la *banda di valenza è interamente piena e quella di conduzione è vuota*. Esse sono separate da un gap di energia vietata di larghezza $\Delta\varepsilon$ *confrontabile* con l’energia termica $k_{B}T$.
A temperature ordinarie un certo numero di elettroni viene promosso in banda di conduzione.
Così, nei semiconduttori (intrinseci) si ha una conducibilità, minore di quella dei metalli, dovuta a cariche sia negative (elettroni), che positive (lacune).
## Stati donori e accettori
Nel silicio (esempio, ma importante) ogni atomo ha quattro elettroni di valenza, che mette in condivisione con gli atomi vicini per completare il legame.
- Se un atomo di silicio (gruppo IV) viene sostituito da uno di arsenico, che ha cinque elettroni esterni, cioè uno in più di quelli necessari al legame chimico, questo quinto elettrone è tenuto nel suo posto solo dalla attrazione coulombiana, molto più debole del legame chimico. La sua energia è di poco inferiore a quella della banda superiore (di conduzione). Così l’elettrone può facilmente lasciare il suo atomo e diventare un elettrone di conduzione. Lo stato dell’elettrone in eccesso attorno al suo atomo si dice stato **donore**.
- Similmente, se un atomo di silicio viene sostituito da uno di boro, che ha tre elettroni esterni, cioè uno in meno di quelli necessari al legame chimico, si determina uno stato elettronico la cui energia è di poco superiore a quello della banda di valenza (per la repulsione coulombiana). Così un altro elettrone può facilmente lasciare il suo atomo e prendere il posto dell’elettrone mancante al legame, lasciando una lacuna libera di muoversi. Lo stato (vuoto) dell’elettrone mancante necessario al legame chimico si dice stato **accettore**.
### Conducibilità vs temperatura
- All’aumentare della temperatura, *nei metalli* il numero di elettroni, portatori della carica, è praticamente costante mentre aumenta l’agitazione termica del cristallo che comporta maggior attrito: la conducibilità diminuisce.
- All’aumentare della temperatura, *nei semiconduttori* aumenta molto il numero di elettroni e/o lacune, termicamente eccitati nelle rispettive bande, portatori della carica, e questo effetto è dominante rispetto all’aumento dell’attrito prodotto dall’agitazione termica: la conducibilità aumenta.
Il **drogaggio** aumenta di ordini di grandezza Le proprietà di conduzione dei semiconduttori.
## Dispositivi a giunzione
### La giunzione PN
La **giunzione PN** è il risultato del contatto tra due materiali semiconduttori drogati in modo diverso:
- **P (positivo)**: drogato con atomi accettori (es. boro, gruppo III), che introducono **lacune** come portatori di carica maggioritari.
- **N (negativo)**: drogato con atomi donori (es. arsenico, gruppo V), che introducono **elettroni** come portatori di carica maggioritari.
### Formazione della Giunzione:
1. **Diffusione iniziale**:  
    Quando i due materiali vengono messi a contatto:
    - Gli **elettroni** dal lato N tendono a diffondersi verso il lato P, riempiendo le lacune.
    - Le **lacune** dal lato P si spostano verso il lato N, catturando elettroni.
2. **Regione di svuotamento (o depletion)**:
    - Si forma una zona al confine tra P e N, **priva di portatori liberi**, chiamata **regione di svuotamento**.
    - Gli ioni fissi lasciati dagli atomi dopanti (negativi nel lato P e positivi nel lato N) creano un **campo elettrico interno**.
3. **Barriera di potenziale**:
    - Il campo elettrico nella regione di svuotamento impedisce ulteriore diffusione di portatori di carica.
    - La differenza di potenziale generata si chiama **barriera di potenziale** (tipicamente circa 0.7 V per il silicio).
### Applicazioni:
- **Diodi**: componenti elettronici basati sulla giunzione PN, permettono il passaggio di corrente in un solo verso.
- **Fotodiodi e LED**: sfruttano il comportamento della giunzione PN per convertire luce in corrente (fotodiodi) o corrente in luce (LED).
- **Transistor**: dispositivi più complessi che utilizzano più giunzioni PN per amplificare o commutare segnali.
## Transistor a semiconduttore
**Transistore bipolare a giunzione (BJT)**
- **Bipolare** perché la corrente è dovuta a entrambi i tipi di carica (elettroni e lacune).
- **Doppia giunzione (npn o pnp)**: ciascuna delle tre zone viene collegata ad un elettrodo metallico. Le regioni estreme della struttura vengono chiamate «emettitore» e «collettore». La zona interna alle due giunzioni prende il nome di «base».
Due diodi accostati e 3 contatti: uno controlla la corrente che può passare tra gli altri due. Vediamo lo schema di funzionamento di un BJT npn.
![[Pasted image 20241205115108.png|100]]
![[Pasted image 20241205115133.png|400]]
**Transistore a effetto di campo (MOS-fet)**
- MOS-FET = Metal Oxide Semiconductor - Field Effect Transistor
Il "corpo" (body) del transistor, è costituito da semiconduttore drogato, su cui viene depositato uno spessore di ossido isolante e uno strato di metallo (gate). Due terminali, detti source e drain, composti da semiconduttore, drogato però in maniera opposta al body, vengono creati alle estremità del dispositivo.
![[Pasted image 20241205115259.png|200]]
Dunque disponiamo di 4 terminali. Controllando la tensione applicata al gate è possibile regolare il flusso di corrente fra source e drain. Il transistore ad effetto di campo prende il nome dall’effetto fisico su cui è basato: **il controllo della conduzione nel canale avviene tramite l’applicazione di un campo elettrico al gate che funziona così come elettrodo di controllo**. La conduzione avviene tramite un solo tipo di portatori di carica (lacune o elettroni), perciò il FET prende anche il nome di transistore unipolare. La tecnologia di realizzazione dei FET più utilizzata è basata sulla struttura Metallo–Ossido–Semiconduttore, da cui il nome MOS-fet.
Il passaggio di corrente dal drain al source è regolato dalla tensione applicata all’elettrodo di gate. L’esempio in figura mostra un transistore n-MOS. All’aumentare di una tensione positiva $V_{GS}$ tra il gate e il source si produce dapprima uno svuotamento di lacune nel substrato sottostante l’ossido, poi un progressivo arricchimento elettroni, che possono generare una corrente tra source e drain con l’applicazione di un opportuno potenziale $V_{SD}$.
L’ossido di gate serve per impedire agli elettroni di uscire dal gate e sottrarre portatori alla corrente tra source e drain. Notate che trasversalmente alla direzione di conduzione elettrica si forma un condensatore, di cui l’ossido di gate costituisce l’isolante.
## Optoelettronica
### Fotoconduzione
L’energia trasportata dalla luce è distribuita in quanti indivisibili, detti fotoni, di valore proporzionale alla frequenza dell’onda.
$$
E = hv
$$
Se su un semiconduttore si invia della luce di frequenza opportuna (energia dei fotoni maggiore del gap) elettroni vengono eccitati dalla banda di valenza a quella di conduzione. Così aumenta la conducibilità del materiale.
### Fotodiodo
Polarizzato in inversa, il diodo non conduce. Se arriva luce nella zona di carica spaziale, la luce crea coppie di elettroni e lacune. Le cariche vengono separate ed accelerate dal campo di giunzione verso i contatti e il diodo conduce, tanto più quanto più intensa è la luce.
### Fototransistor
Anche in questo caso la luce arriva nella zona di carica spaziale, cioè nella base, e, rispetto al fotodiodo, il suo effetto è aumentato dalla amplificazione del transistor.
### Celle Fotovoltaiche
Le celle fotovoltaiche trasformano energia luminosa in energia elettrica.
La luce crea coppie di elettroni e lacune in una giunzione polarizzata in inversa e si comporta come un generatore di corrente che scorre in verso opposto a quella che circola nel diodo in polarizzazione diretta. Applicando un carico alla cella in esso circola una corrente $I = I_{s} - I_{d}$.
In figura si vede che nella curva nel quarto quadrante la corrente e il potenziale hanno segno opposto. Questo significa che la potenza dissipata è negativa: le cariche, separate dal campo elettrico, generano una corrente che può essere usata da un utilizzatore esterno.
![[Pasted image 20241205115705.png|350]]
## Diodi emettitori di luce
### LED (Light Emitting Diods)
In una giunzione polarizzata in diretta cariche di segno opposto si annichilano nei pressi della giunzione. Se il diodo è di silicio o di germanio, l’energia liberata nella ricombinazione si trasforma in calore. Se invece il diodo è costruito con altri semiconduttori (es: GaP e molti altri composti binari) questa energia viene emessa sotto forma di luce alla frequenza data dal gap del semiconduttore.
## Emissione spontanea e stimolata
Quando un elettrone passa da uno stato di più alta energia a uno di energia minore in genere emette un fotone, cioè un pacchetto d’onde della frequenza corrispondente al salto di energia.
![[Pasted image 20241205120057.png|500]]
Questa transizione può avvenire spontaneamente o, se è già presente luce della giusta frequenza, può essere stimolata dall’onda presente.
Nell’emissione stimolata il nuovo fotone è in perfetta coerenza con quello originale: stessa frequenza, stessa direzione, stessa fase.
## Il laser
La luce “normale” è formata dalla sovrapposizione di innumerevoli “pacchetti d’onda” disposti disordinatamente nello spazio.
La luce laser è formata dalla sovrapposizione di innumerevoli “pacchetti d’onda” ottenuti con emissione stimolata, disposti ordinatamente nello spazio, tutti con la stessa direzione e frequenza e fasi coerenti.
Quindi la luce laser è monocromatica (un solo colore = una sola frequenza) e fortemente collimata.
### Laser a semiconduttore
Per avere l’effetto LASER in un semiconduttore bisogna ottenere una situazione in cui siano presenti due livelli di energia, con molti più elettroni in quello superiore, cosicché la transizione di uno determini a cascata la transizione degli altri.
Nel diodo laser esiste una giunzione polarizzata direttamente come nel LED. Facce piatte, parallele e lisce funzionano da specchi in modo da formare una cavità risonante che favorisce la cascata di ricombinazioni di elettroni e lacune, pompati dalla corrente.








