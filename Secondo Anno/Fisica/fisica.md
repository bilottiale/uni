# Forze
La **meccanica** si occupa di studiare le interazioni tra corpi.
Una interazione tra due corpi può essere descritta in termini  di **due forze**, ogniuna esercitata su ciascuno dei due corpi.
### Forze a lungo raggio
#### Forze fondamentali
- **Forza di gravità**: agente trad eu masse è la più debole.
- **Forza elettromagnetica**: agente tra le particelle cariche.
### Forze "a contatto"
## Come si misura una forza?
Appendendo masse diverse ad una molla otteniamo che l'allungamento della molla rappresenta la forza applicata.
Le forze sono **grandezze vettoriali**.
L'unità di misura della forza nel SI è il *Newton(N)*.

Un **vettore** è una grandezza definita attraverso una intensità e una direzione(la forza):
- Vettore: $\mathbf{F} \text{ or } \check{F}$
- Intensità o modulo di un vettore: $F \text{ or }|\mathbf{F}| \text{ or } |\check{F}|$
- Direzione orientata di un vettore: "20° rispetto all'asse x"
- Rappresentazione grafica: $\nearrow$
Uno **scalare** è una grandezza definita da un numero(la massa di un oggetto).
- $m$
# Cinematica
## Posizione e spostamento
La **posizione** $r$ di un oggetto descrive la sua collocazione rispetto ad una *origine*.
$$
\Delta r = r_{f}-r_{i}
$$
Lo **spostamento** rappresenta la variazione della posizione di un oggetto. Dipende solo dalle posizioni iniziale e finale.
## Velocità
La **velocità** è un vettore che misura quanto rapidamente e in quale direzione orientata un oggetto puntiforme si muove.
*Velocità media*:
$$
v_{av}=\frac{\Delta r}{\Delta t}
$$
**Velocità istantanea = derivata temporale dello spostamento**
$$
\vec{v}=\lim_{ \Delta t \to 0 }\frac{\Delta \vec{s}}{\Delta t} = \frac{d\vec{s}}{dt}
$$
$$
\vec{s} = \int \vec{v} \, dt
$$
In un grafico di posizione vs tempo la **velocità media** è rappresentata dalla pendenza della corda:
![[Pasted image 20241011172450.png|400]]
Average velocity $= v_{av,x}=\frac{x_{2}-x_{1}}{t_{2}-t_{1}}$.
In un grafico di posizione vs tempo la **velocità istantanea** è rappresentata dalla pendenza della tangente alla curva $x(t)$ all'istante considerato:
![[Pasted image 20241011172733.png|400]]
## Accelerazione media e istantanea
*Accelerazione media*:
$$
\vec{a}_{av} = \frac{\Delta \vec{v}}{\Delta t}
$$
*Accelerazione istantanea*:
$$
\vec{a} = \lim_{ \Delta t \to 0 } \frac{\Delta \vec{v}}{\Delta t} = \frac{d\vec{v}}{dt} = \frac{d^{2}\vec{s}}{dt^{2}}
$$
[[Esempi#Cinematica|Esempi]]
# Le forze
### Prima legge della dinamica (o principio di inerzia)
Se un corpo puntiforme non è soggetto a forze o è soggetto a forze con risultante nulla, allora la sua velocità non cambia nel tempo.
**L'inerzia** è una misura della resistenza di un corpo a cambiamenti del suo stato di moto.
### Terza legge della dinamica (o principio di azione e reazione)
Quando due corpi interagiscono, le forze esercitate l'uno sull'altro sono sempre uguali in modulo e opposte in direzione orientata.
$$
\text{Matematicamente: }F_{21}=-F_{12}
$$
## Gravità
$$
F=\frac{GM_{1}M_{2}}{r^{2}}
$$
$r$ è la distanza tra le due masse $M_{1}$ e $M_{2}$ e $G=6.67\times 10^{-11}Nm^{2}/kg^{2}$.
![[Pasted image 20241013145758.png]]
### Il campo gravitazionale
$$
g=\frac{F}{m}
$$
È la forza gravitazionale per unità di massa. Questa quantità si chiama intensità sul corpo gravitazionale o "accelerazione" dovuta alla gravità.
$g$ dipende solo dalla massa della Terra.
Il peso dipende sia da $g$ che dalla massa "partner" dell'attrazione gravitazionale.
[[Esempi#Gravità|Esempi]]
## Forze di contatto
Agisce in direzione perpendicolare alla superficie di contatto. 
### Attrito
**È una forza di contatto parallela alla superficie di contatto tra due corpi.**
- **Attrito statico**: impedisce agli oggetti di scivolare.
- **Attrito dinamico**: rallenta il moto degli oggetti.
#### Forza di attrito statico
$$
f_{s}\leq \mu_{s}N
$$
$\mu_{s}$ è il coefficiente di attrito **statico** ed $N$ è la forza normale.
#### Forza di attrito dinamico
$$
f_{k}=\mu_{k}N
$$
$\mu_{k}$ è il coefficiente di attrito **dinamico** ed $N$ la forza normale.
### La tensione
È la forza trasmessa attraverso una fune da un estremo all’altro.
Una fune ideale ha massa trascurabile non si deforma e mantiene la stessa tensione lungo tutta la lunghezza.
### La forza elastica
In assenza di attrito la forza elastica genera un moto periodico.
$$
F=-kx
$$
![[Pasted image 20241013155355.png|400]]
## Seconda legge di Newton
Si chiama **somma risultante** la somma vettoriale $\sum \mathbf{F}$ di tutte le forze applicate ad un corpo.
La forza risultante agente su un corpo è direttamente proporzionale all’ accelerazione del corpo. La costante di proporzionalità è chiamata **massa** (inerziale) del corpo.
$$
\sum \mathbf{F} = m\mathbf{a}
$$
$$
1N = 1kg \ m/s^{2}
$$
Se $\mathbf{a}=0$, allora $\sum\mathbf{F}=0$, in questo caso:
- $v=0$ *equilibrio statico*, $\mathbf{o}$.
- $v\neq 0\text{ (costante)}$ *equilibrio dinamico*.
[[Esempi#Seconda legge di Newton|Esempi]]
### Composizione delle velocità
![[Pasted image 20241013162008.png|500]]
[[Esempi#Composizione delle velocità]]
### Quantità di moto
La quantità vettoriale $p = mv$ è chiamata quantità di moto o “*momento lineare*”.
La sua unità di misura è $kg \ m/s$.
La seconda legge della dinamica per una particella di massa m costante si può scrivere in termini della quantità di moto:
$$
\mathbf{F}=m\mathbf{a}=m \ \frac{\Delta \mathbf{v}}{\Delta t}= \frac{\Delta \mathbf{p}}{\Delta t}
$$
## Teorema dell'impulso
*Se la risultante delle forze applicate al corpo è nulla la quantità di moto si conserva.*
Per un sistema di particelle in cui le forze sono solo interne (cioè esercitate da particelle del sistema su altre particelle del sistema) la risultante delle forze applicate al corpo è nulla per la terza legge della dinamica e la quantità di *moto TOTALE* si conserva.
# Moti unidimensionali
## Moto rettilineo e uniforme
Formule in notazione di Leibniz:
- $v$ è costante ($a=0$ in ogni istante).
- Al tempo $t=0$ il corpo parte dalla posizione $x_{0}:x(t=0)=x_{0}$.
$$
v=\frac{dx}{dt} \quad \int_{x}^{x} 1dx' = v\int_{0}^{t}1dt' 
$$
$$
x-x_{0}=v\cdot(t-0)=vt
$$
### Moto rettilineo con velocità costante (uniforme)
- $\mathbf{v}$ costante
- $x=vt+x_{0} \quad a=0$
![[Pasted image 20241013164257.png|400]]
### Moto rettilineo con accelerazione costante
Formule in notazione di Leibniz:
- Sia $v_{0}$ la velocità a $t=0$.
- Sia $x_{0}$ la posizione del corpo a $t=0$.
$$
\begin{align}
a=\frac{dv}{dt} \quad &dv=adt \rightarrow \int_{v_{0}}^{v(t)} dv'=\int_{0}^{t} dt'a \\
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
*Se l’accelerazione è costante le equazioni cinematiche sono:*
![[Pasted image 20241013165630.png]]
### Caduta libera
Un sasso è lanciato dalla cima di una collina. Trascurando la resistenza dell’aria solo la forza di gravità agisce sul sasso. Diciamo che iI sasso è in **caduta libera**.
il diagramma di corpo libero del sasso è:
![[Pasted image 20241013171752.png|200]]
Applicando la seconda legge di Newton:
$$
\begin{align}
\sum F_{y}&=-w=mg=ma \\
a&=-g-9.8N/kg \\
&=-9.8m/s^{2}
\end{align}
$$
#### Resistenza dell'aria
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
## Moto armonico semplice
### Moto armonico semplice
Un corpo si muove di **moto armonico semplice** quando al corpo è applicata una **forza di richiamo**, cioè una forza sempre diretta verso un *punto di equilibrio stabile*, **direttamente proporzionale allo spostamento** del corpo dalla posizione di equilibrio.

Il moto di una massa su un piano orizzontale privo di attrito collegata ad una molla, trascurando la resistenza dell’aria, è un esempio di moto armonico semplice.
![[Pasted image 20241013172151.png|500]]
Il modulo della forza esercitata sull’estremo libero della molla è:
$$
F_{x}=-kx
$$
$F_{x}$ è la forza di richiamo di questo moto.
$x$ è la lunghezza dello spostamento e $k$ è la costante elastica; caratteristica della molla, le sua unità di misura sono $N/m$.
Se la superficie d’appoggio è senza attrito:
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
![[Pasted image 20241013172647.png]]
$$
\omega = \sqrt{ \frac{k}{m} }
$$
![[Pasted image 20241013172744.png]]
$$
\begin{align}
&x(t)=A\cos \omega t \\
&v(t)=\frac{\Delta x}{\Delta t}=-A\omega \sin \omega t \\
&a(t)=\frac{\Delta v}{\Delta t}=-A\omega^{2}\cos \omega t
\end{align}
$$
Cosa significa $\omega=\sqrt{ \frac{k}{m} }$?
Se $T$ è il tempo necessario una oscillazione completa ($T=$periodo) allora $\omega T=2\pi$ cioè:
$$
\omega=\frac{2\pi}{T}
$$
$\omega$ è la **frequenza** angolare delle oscillazioni.
$A$ è l'**ampiezza** del moto, cioè il massimo spostamento dalla posizione di equilibrio.
Inoltre $A\omega=v_{max}$ e $A\omega^{2}=a_{max}$.
La velocità si annulla agli estremi dell’oscillazione ed è massima quando il corpo passa per la posizione di equilibrio.
### Oscillazioni smorzate
Quando l’attrito non è trascurabile l’ampiezza delle oscillazioni diminuisce nel tempo:
![[Pasted image 20241013173206.png|500]]
## Moto dei proiettili
Un aereo vola alla quota di $1050 m$ alla velocità di $115 m/s$. Ad un certo istante lancia una cassa contenente generi di pronto soccorso. A quale distanza dal punto di lancio la cassa colpirà il suolo?
![[Pasted image 20241013174440.png]]
# Moti 2d circolari
**La variabile angolare**:
$$
\begin{gather}
\theta = \text{coordinata angolare} \\
\theta = \frac{s}{r}
\end{gather}
$$
$\theta$ è misurato in *radianti*, è il rapporto tra due lunghezze.
Gli angoli misurati in senso antiorario sono positivi.
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
Varia in modulo, direzione e verso, generando una accelerazione $\neq 0$.
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
## Accelerazione
### Modulo
$$
\frac{\Delta v}{v} \sim \frac{v\Delta t}{r} \rightarrow \frac{\Delta v}{\Delta t} \sim \frac{v^{2}}{r}
$$
Il modulo dell’accelerazione radiale è costante e vale:
$$
a_{r} = \frac{v^{2}}{r} = r\omega^{2} = \omega v
$$
### Direzione orientata
L’accelerazione istantanea in un moto circolare uniforme è diretta lungo la direzione radiale e orientata verso il centro della traiettoria circolare.
![[Pasted image 20241016170359.png|350]]
## Forza centripeta
La forza che tiene il corpo in rotazione uniforme è, quindi, costante in modulo e diretta *verso il centro*, ed è chiamata **forza centripeta**.
# Lavoro ed energia
## Lavoro
Quando una forza non nulla sposta un corpo viene compiuto **LAVORO**. Se la forza $F$ è costante e ha la direzione orientate dello spostamento:
$$
W = Fs
$$
L’unità di misura della forza è il Joule ($J$).
$$
1J = 1Nm = 1kg \ m^{2}/s^{2}  
$$
Il lavoro compiuto da una forza costante non parallela allo spostamento è definito come:
$$
W = Fs \ \cos \theta
$$
Dove $F$ è l'intensità della forza, $s$ la lunghezza dello spostamento, e $\theta$ l'angolo tra $F$ e $s$.
![[Pasted image 20241022113529.png]]
### Prodotto scalare tra due vettori
Il **prodotto scalare** di due vettori $a$ e $b$ è una grandezza scalare.
$$
\overrightarrow{a} \cdot \overrightarrow{b} = ab\cos \alpha
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
**Esercizio**:

> [!NOTE] Esercizio
> Una scatola di massa m viene trascinata a velocità costante su un piano privo di attrito. La forza applicata $F$ è parallela al piano. Calcolare il lavoro totale compiuto sulla scatola.

Velocità costante, quindi accelerazione$a = 0$.
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
F = mg \sin \theta
$$
La scatola percorre lungo la rampa una distanza $\Delta x$, il lavoro della forza $F$ è:
$$
W_{F} = F\Delta x\cos0° = mg\Delta x\sin \theta
$$
Il lavoro della gravità è:
$$
W_{g} = w\Delta x\cos(\theta + 90°) = -mg\Delta x\sin \theta
$$
Il lavoro della forza normale è:
$$
W_{N} = N\Delta x\cos90° = 0
$$
Il lavoro netto compiuto sulla scatola è:
$$
\begin{align}
W_{net} &= W_{F} + W_{g} + W_{N} \\
&= mg\Delta x\sin \theta - mg\Delta x\sin \theta + 0 \\
&= 0
\end{align}
$$

> [!NOTE] Esercizio
> Qual è il lavoro totale sulla scatola dell’esercizio precedente se la scatola non è tirata a velocità costante?

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

> [!NOTE] Esercizio
> Una molla ideale ha $k = 20,0 N/m$. Qual’è il lavoro compiuto da un agente esternoper deformare la molla di $0.40 m$ partendo dalla molla non deformata?

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
$$
W = mg \cdot |\Delta h| \cdot \cos \theta = (mg h_{f} - mg h_{i})
$$
## Lavoro ed energia potenziale gravitazionale
$$
\begin{gather}
W_{if} = -(E_{Pf}-E_{\Pi}) \\
E_{P} = m \cdot g \cdot h
\end{gather}
$$
$m =$ massa, $g=$ forza di gravità e $h=$ altezza.

Una forza è **conservativa** quando il lavoro compiuto NON dipende dal particolare cammino seguito per andare dalla posizione iniziale a quella finale, ma solo dalla posizione iniziale e finale. Per questa categoria di forze:
$$
W_{cons} = -\Delta U
$$
Ci sono quindi diverse forme di energia potenziale.
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
**La forza elastica è una forza conservativa**
## Energia potenziale elastica
Il lavoro della forza elastica, come quello della forza peso, *non dipende dalla traiettoria*,  ma solo dalla posizione iniziale e finale.
Introducendo la funzione $U(x) = \left( \frac{1}{2} \right)kx^{2}$ il lavoro è dato da:
$$
L = \frac{1}{2} kx_{A}^{2} - \frac{1}{2}kx_{B}^{2}  = U(A) - U(B) = -\Delta U
$$
La funzione $U(x)$ è detta *energia potenziale elastica* ed è una grandezza scalare associata alla *posizione* in cui si trova il punto.
La funzione $U(x)$ è definita a meno di una costante: se si pone $U(x) = \left( \frac{1}{2} \right) kx^{2}+c$ vale sempre la relazione $L = -\Delta U$.
L’energia meccanica di una massa m collegata ad una molla è:
$$
E(t) = K(t) + U(t) = \frac{1}{2} mv(t)^{2} + \frac{1}{2} kx(t)^{2}  
$$
Quando non ci sono forze di natura non conservativa l’energia meccanica di un sistema fisico si conserva, cioè:
$$
E_{i} = E_{f}
$$
equivalmente:
$$
\Delta K = -\Delta U
$$
## Potenza
La potenza è il **tasso di trasferimento dell'energia**:
$$
\text{Potenza media} \ P_{av} = \frac{\Delta E}{\Delta}
$$
$$
\text{Potenza istantanea} \ P = Fv\cos \theta
$$
Unità di misura è il Watt. $1 Watt = 1J/s = 1W$.
# Elettrostaticità
## Conduttori e isolanti
Un **conduttore** è formato da un materiale che consente alle cariche elettriche di muoversi attraverso esso in modo facile.
Un **isolante** è formato da un materiale che non consente alle cariche elettriche di muoversi facilmente attraverso esso.
Ci sono due tipi di carica elettrica: *positiva* e *negativa*.
L’unità elementare di carica è $$e = 1.602 \times 10^{-19}C$$
La carica dell’elettrone è $-1e$.
La carica del protone è $+1e$.
La carica del neutrone è $0e$.
Un oggetto può diventare **polarizzato** se le cariche al suo interno possono essere separate.
![[Pasted image 20241028093013.png|500]]
## Carica puntiforme e Legge di Coulomb
Il modulo della forza tra due cariche puntiformi è:
$$
F = \frac{k|q_{1}||q_{2}|}{r^{2}}
$$
dove $q_{1}$ e $q_{2}$ sono le cariche e $r$ è la distanza tra le due cariche.
$$
k = 8.99 \times 10^{9} Nm^{2}/C^{2}   
$$
![[Pasted image 20241028095336.png|500]]
**Esempio**:
Qual’ è il rapporto tra la forza elettrica e quella gravitazionale tra un protone e un elettrone separati da $5.3 \times 10^{11}$m (il raggio di un atomo di idrogeno)?
$$
\begin{align}
&F_{e} = \frac{k|q_{1}||q_{2}|}{r^{2}} && |q_{1}|=|q_{2}|=e \\
&F_{g} = \frac{Gm_{1}m_{2}}{r^{2}} && m_{1} = m_{p} = 1.67 \times 1^{-27}kg \\
& && m_{2} = m_{e} = 9,11 \times 10^{-31}kg 
\end{align}
$$
Il rapporto tra le due forze è:
$$
\frac{F_{e}}{F_{g}} = \frac{k|q_{1}||q_{2}|}{Gm_{1}m_{2}} = \frac{ke^{2}}{Gm_{e}m_{p}} = 2.3 \times 10^{39} 
$$
## Il campo elettrico
$F_{g} = m\mathbf{g}$ dove $\mathbf{g}$ è l'accelerazione di gravità.
$F_{e} = q\mathbf{E}$ similmente per le forze elettriche possiamo definire il modulo del campo elettrico $\mathbf{E}$.
Per una carica puntiforme $Q$, il modulo della forza per unità di carica alla distanza $r$ (il campo elettrico) è:
$$
E = \frac{F_{e}}{q} = \frac{k|Q|}{r^{2}}
$$
Il campo elettrico in un punto dello spazio si trova sommando tutti i campi elettrici presenti in quel punto:
$$
\mathbf{E}_{net} = \sum_{i} \mathbf{E}_{i} \quad \text{Attenzione! Il campo elettrico è un vettore!}
$$
### Linee di Campo Elettrico
Le linee di campo elettrico sono un modo utile per rappresentare il modulo e la direzione di un campo elettrico nello spazio.
1. La direzione del campo $E$ è tangente alle linee di campo in ciascun punto dello spazio.
2. Il campo è intenso nelle regioni dove sono presenti molte linee di campo e debole dove ce ne sono poche.
3. Le linee di campo partono dalle cariche $+$ e terminano sulle cariche $–$ .
4. Le linee di campo non si incrociano mai.
![[Pasted image 20241028103016.png|500]]
## Legge di Gauss
Circonda una carica puntiforme $+Q$ con una sfera immaginaria.
Le linee del campo $E$ escono dalla sfera.
![[Pasted image 20241028103342.png|250]]
Ricorda
$$
E \propto \frac{\text{number of field lines}}{A}
$$
cosicché $\text{number of field lines} \propto EA$.
Il **flusso** è una quantità scalare correlate al numero di linee di campo che attraversano la superficie:
$$
\text{flux} = \Phi_{e} = E_{\perp}A = (E\cos \theta)A
$$
$\text{flux} > 0$ quando le linee di campo escono dalla superficie.
$\text{flux} < 0$ quando entrano nella superficie.
**Esempio**:
Trova il flusso del campo elettrico attraverso ciascuna faccia di una cubo di spigolo a immerso in un campo elettrico uniforme di intensità $E$.
![[Pasted image 20241028104313.png|250]]
Il cubo ha sei facce: le linee di campo entrano in una faccia ed escono attraverso la faccia opposta. Qual’ è il flusso attraverso ciascuna delle altre quattro facce?
- Il flusso attraverso la faccia sinistra è $–EA$.
- Il flusso attraverso la faccia destra è $+EA$.
- il flusso netto attraverso il cubo è *nullo*.
Il flusso attraverso una superficie chiusa dipende quindi dalla quantità di carica all’interno della superficie chiusa stessa.
**Legge di Gauss**:
$$
\Phi_{e} = \frac{Q_{inside}}{\epsilon_{0}}
$$
Calcolo dell’integrale a primo membro su una superficie sferica avente centro nella posizione della carica $Q$:
$$
\begin{gather}
\int_{\text{sfera di raggio }R} \overrightarrow{E} \cdot d\overrightarrow{A} = \\ \\
\frac{Q}{4\pi \epsilon_{0}} \int_{\text{sfera di raggio }R} \frac{1}{r^{2}} dA = \\ \\
\frac{Q}{4\pi \epsilon_{0}} \frac{1}{R^{2}} \int_{\text{sfera di raggio }R} dA = \\ \\
\frac{Q}{4\pi \epsilon_{0}} \frac{1}{R^{2}} 4\pi R^{2} = \frac{Q}{\epsilon_{0}} 
\end{gather}
$$
### Calcolo del campo elettrico a partire dalla legge di Gauss
Densità di carica:
$$
p = \frac{Q}{V} = \frac{Q}{\frac{4}{3}\pi R^{3}} = \frac{3Q}{4\pi R^{3}}
$$
Per $r < R$:
$$
\int_{\text{sfera di raggio }r} \overrightarrow{E} \cdot d\overrightarrow{A} = \frac{Q_{in}}{\epsilon_{0}}
$$
Primo membro:
$$
E(r)4\pi r^{2}
$$
Secondo membro:
$$
\frac{p}{\epsilon_{0}} \frac{r}{3} \pi r^{3}
$$
Quindi:
$$
E(r) = \frac{p}{\epsilon_{0}} \frac{r}{3} = \frac{Q}{4\pi \epsilon_{0}R^{3}} r = kr
$$
Per $r \geq R$:
$$
\int_{\text{sfera di raggio }r} \overrightarrow{E} \cdot d\overrightarrow{A} = \frac{Q_{in}}{\epsilon_{0}}
$$
Primo membro:
$$
E(r)4\pi r^{2} 
$$
secondo membro:
$$
Q_{in} = Q
$$
Quindi:
$$
\begin{gather}
E(r)4\pi r^{2} = Q \\
E(r) = \frac{Q}{4\pi \epsilon_{0}r^{2}}
\end{gather}
$$
### Moto di una carica puntiforme in un campo elettrico uniforme
Una regione di spazio in cui è presente un campo elettrico $E$ uniforme contiene una particella di carica $q$ ($q>0$) e massa $m$.
Applica la seconda legge di Newton e risolviamo per l'accelerazione:
$$
\begin{align}
\sum F_{x} &= F_{e} = ma \\
F_{e} &= qE = ma \\
a &= \frac{q}{m} E
\end{align}
$$
![[Pasted image 20241028110211.png|350]]
**Esempio**:
Qual è l’intensità del campo elettrico necessaria per mantenere un elettrone sospeso in aria?
![[Pasted image 20241028110259.png|200]]
Seconda legge di Newton:
$$
\begin{align}
\sum F_{y} &= F_{e}-w = 0 \\
F_{e} &= w \\
qE &= eE = mg \\
E &= \frac{mg}{e} = 5.6\times 10^{-11} N/C 
\end{align}
$$
## Energia potenziale elettrica
L'*energia potenziale elettrica* $U_{e}$ è l'energia posseduta da una carica $q$ in un punto di un campo elettrico generato da altre cariche.
Per una carica $q$ posizionata a una distanza $r$ da un'altra carica $Q$. l'energia potenziale elettrica $U_{e}$ è:
$$
U_{e} = \frac{k \cdot Q \cdot q}{r}
$$
- $k$ è la costante di Coulomb ($8,99 \times 10^{9} Nm^{2}/C^{2}$).
- $Q$ e $q$ le cariche in gioco.
- $r$ la distanza tra le du cariche.
## Potenziale elettrico
Il **potenziale elettrico** $V_{e}$​ in un punto dello spazio, generato da una distribuzione di cariche, è definito come l'energia potenziale elettrica $U_{e}$ di una carica di prova $q$ in quel punto divisa per il valore della carica di prova stessa:
$$
V_{e} = \frac{U_{e}}{q} = \frac{k \cdot Q}{r}
$$
- $V_{e}$ dipende SOLO dal punto.
- $V_{e} =0$ dove $U_{e}=0$ (per esempio a $r = \infty$).
- $k$ è la costante di Coulomb ($8,99 \times 10^{9} Nm^{2}/C^{2}$).
- $Q$ la carica che genera il potenziale,
- $r$ la distanza tra le du cariche.
**Esempio**
Un protone e un elettrone, inizialmente separati da una distanza r, vengono avvicinati. Come cambia l’energia potenziale di questo sistema di cariche?
$$
U_{e} = - \frac{k \cdot e^{2}}{r}
$$
Avvicinare le cariche significa diminuire $r$:
$$
\Delta U_{e} = U_{ef} - U_{ei} < 0
$$
Come cambierebbe l’energia potenziale elettrica se entrambe le particelle avessero carica positiva (o negativa)?
Quando $q_{1}$ e $q_{2}$ hanno lo stesso segno $\Delta U_{e} > 0$.
### Differenze tra $V_{e}$ e $U_{e}$

- **Potenziale Elettrico** ($V_{e}$​): Energia per unità di carica.
- **Energia Potenziale Elettrica** ($U_{e}$​): Energia totale posseduta dalla carica $q$, calcolabile con $U_{e} = V_{e} \cdot q$.
## Cariche in movimento in campi elettrostatici
Quando una **carica** si muove in un **campo elettrostatico** e agiscono solo **forze elettriche**, la sua **energia meccanica totale** si conserva. Questo è dovuto al fatto che la forza elettrica è una forza conservativa.
### Conservazione dell'Energia Meccanica
Se agiscono solo forze elettriche, l’energia meccanica totale $E=K+U_{e}​$ della carica si conserva:
$$
K_{i} + U_{e,i} = K_{f} + U_{e,f}
$$
## Superfici Equipotenziali
- **Definizione**: Superfici in cui il potenziale elettrico è costante.
- **Forma**: Per una carica puntiforme, le superfici equipotenziali sono sfere concentriche con centro nella carica $Q$.
- **Caratteristiche**:
    - Il potenziale è lo stesso in ogni punto della superficie.
    - Non è necessario compiere lavoro per spostarsi su una superficie equipotenziale.
    - Perpendicolari alle linee del campo elettrico.
## Condensatori
Un **condensatore** è un dispositivo progettato per **immagazzinare energia potenziale elettrica** accumulando cariche positive e negative su due conduttori separati, noti come **piastre** del condensatore. Quando il condensatore è caricato, una piastra accumula carica positiva ($+Q$) e l’altra accumula una carica uguale e opposta ($-Q$).
### Principio di Funzionamento del Condensatore
- **Separazione delle Cariche**: Per immagazzinare energia, occorre separare le cariche positive e negative sulle due piastre del condensatore. Questo processo richiede un **lavoro** per superare la forza di attrazione tra le cariche opposte.
- **Energia Potenziale Elettrica**: L’energia potenziale elettrica accumulata nel condensatore è proporzionale alla quantità di carica immagazzinata e alla differenza di potenziale $V$ tra le piastre.
- **Capacità**: $C$ del condensatore misura la sua capacità di immagazzinare carica per una data differenza di potenziale e si esprime come:
$$
C = \frac{Q}{V}
$$
- $C$ capacità in Farad ($F$).
- $Q$ la carica immagazzinata sulle piastre.
### Condensatori
Un **condensatore** è un dispositivo elettrico che immagazzina energia potenziale elettrica separando cariche positive e negative su due conduttori (piastre).
#### Funzionamento
- **Separazione delle Cariche**: Per caricare un condensatore, è necessario compiere un lavoro per separare le cariche opposte sulle piastre.
- **Energia Potenziale Elettrica**: L'energia potenziale accumulata è proporzionale alla carica immagazzinata e alla differenza di potenziale tra le piastre.
#### Capacità
- **Formula della Capacità**:
  $C = \frac{Q}{V}$
  dove $C$ è la capacità in farad (F), $Q$ è la carica, e $V$ è la differenza di potenziale.
#### Energia Immagazzinata
- **Formula dell'Energia**:
  $U_e = \frac{1}{2} C V^2$
  L'energia immagazzinata può anche essere espressa in termini di carica:
  $U_e = \frac{Q^2}{2C} = \frac{1}{2} Q V$
#### Condensatore a Facce Piane Parallele
1. **Struttura**:
   - Due piastre conduttrici parallele separate da una distanza \( d \) con area \( A \).
   - Cariche opposte sulle piastre (+Q e -Q).
2. **Campo Elettrico**:
   - Uniforme e perpendicolare alle piastre:
   $E = \frac{V}{d}$
3. **Capacità**:
   - Formula per la capacità:
   $C = \frac{\varepsilon_0 \cdot A}{d}$
   dove  $\varepsilon_0$ è la costante dielettrica nel vuoto. Con un dielettrico, si ha:
   $C = \frac{\varepsilon \cdot A}{d}$
   con $\varepsilon = \varepsilon_0 \cdot \kappa$.
4. **Energia Immagazzinata**:
   - L’energia nel condensatore può essere espressa in base alla capacità e alla differenza di potenziale.
**Esercizio:**
Un condensatore a facce piane parallele è formato da due armature quadrate di 10.0 cm di lato, separate da un’intercapedine di aria di 0.75 mm.
(a) Qual è la carica sul condensatore quando la differenza di potenziale è di 150 volts?
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
La **corrente elettrica** è il flusso di cariche elettriche che si muovono attraverso un conduttore a causa di una differenza di potenziale. Si misura in **ampere (A)**.
$$
I = \frac{Q}{t}
$$
- $I$ corrente (A).
- $Q$ corrente elettrica (C).
- $t$ tempo (s).
#### Tipi di Corrente Elettrica
1. **Corrente Continua (DC)**: Fluisce in una sola direzione (es. batterie).
2. **Corrente Alternata (AC)**: Cambia direzione periodicamente (es. rete elettrica domestica).
#### Caratteristiche della Corrente
- **Intensità**: Quantità di carica che passa in un punto del circuito.
- **Tensione (V)**: Forza che spinge le cariche; misura in volt (V).
- **Resistenza (R)**: Opposizione al flusso di corrente; misura in ohm (Ω).
- **Legge di Ohm**:
$$
V=I⋅R
$$
## Circuiti Elettrici, Resistenza e Resistività
- **Circuiti in Serie**: Corrente costante; tensione totale = somma delle tensioni.
- **Circuiti in Parallelo**: Tensione costante; corrente varia nei rami.
### Resistenza (R)
- **Definizione**: Misura della difficoltà al passaggio della corrente elettrica; espressa in **ohm (Ω)**:
$$
R = \frac{V}{I}
$$
- $V$ tensione.
- $I$ corrente.
- **Fattori che Influenzano la Resistenza**:
    1. **Materiale**: Tipo di materiale conduttore o isolante.
    2. **Lunghezza**: La resistenza aumenta con l'aumentare della lunghezza.
    3. **Sezione Trasversale**: La resistenza diminuisce con un'area maggiore.
    4. **Temperatura**: La resistenza può aumentare all'aumentare della temperatura.
## Legge di OHM
stabilisce una relazione semplice tra tensione ($\Delta V$), corrente ($I$) e resistenza ($R$) in un circuito elettrico.
$$
\Delta V = I \cdot R
$$
- $\Delta V$ differenza di potenziale elettrico (tensione) in volt (V).
- $I$ corrente elettrica in ampere (A).
- $R$ resistenza in ohm (Ω).
**Esempio**:
Se hai un circuito con una resistenza di $5\ohm$ e una tensione applicata di $10V$, puoi calcolare la corrente utilizzando la legge di Ohm:
$$
I = \frac{\Delta V}{R} = \frac{10V}{5\ohm} = 2A
$$
### Resistività ($\rho$)
- **Definizione**: Proprietà intrinseca di un materiale che misura l'opposizione al passaggio di corrente; espressa in **ohm-metri (Ω·m)**.
$$
R = \rho \frac{L}{A}
$$
- $R$ resistenza ($\ohm$).
- $\rho$ resistenza del materiale ($\ohm \cdot m$).
- $L$ lunghezza ($m$).
- $A$ area della sezione trasversale($m^{2}$).
**Esempio**:
Se hai un conduttore di rame lungo $2m$ e con un'area di sezione trasversale di $1mm^{2}$ (equivale a $1 \times 10^{-6} m^{2}$), e conosci la resistività del rame ($\rho \approx 1.68 \times 10^{-8} \ohm \cdot m$), calcola la resistenza:
$$
R = 1.68 \times 10^{-8} \ohm \cdot m \times \frac{2m}{1 \times 10^{-6} m^{2}} = 3.36 \ohm
$$
## Potenza e Energia nei Circuiti
- La **potenza** elettrica è la quantità di energia trasferita per unità di tempo. Si misura in **watt (W)**
$$P = V \cdot I$$
  - $P$ potenza (W)
  - $V$ tensione (V)
  - $I$ corrente (A)
#### Tipi di Potenza
- **Potenza Attiva ($P$)**: È la potenza reale consumata nel circuito, misurata in watt (W). È responsabile per il lavoro utile svolto.
- **Potenza Reattiva ($Q$)**: È la potenza immagazzinata e restituita nei circuiti AC, misurata in volt-ampere reattivi (VAR).
- **Potenza Apparente ($S$)**: È la combinazione di potenza attiva e reattiva, misurata in volt-ampere (VA). È data da:
$$S = V \cdot I$$
### Legge di Joule
La potenza dissipata da un resistore è data dalla legge di Joule:
$$P = I^2 R$$oppure
$$P = \frac{V^2}{R}$$
  - $R$ resistenza (Ω).
### Energia
- L'**energia elettrica** è la quantità totale di lavoro svolto in un certo periodo di tempo e si misura in **joule (J)** o **kilowattora (kWh)**.
$$E = P \cdot t$$
 - $E$ energia (J o kWh).
 - $P$ potenza (W).
 - $t$ tempo (s o ore).
## Principi di Kirchhoff
### Legge delle Correnti di Kirchhoff (KCL)
**Legge dei nodi**.
- La somma algebrica delle correnti che entrano e escono da un nodo è sempre zero.
  $$\sum I_{\text{entranti}} = \sum I_{\text{uscenti}}$$
- **Significato**: La corrente totale che entra in un nodo è uguale a quella che esce, basata sulla conservazione della carica elettrica.
#### Esempio KCL
Se entrano 3 A e 2 A in un nodo, allora esce:
$$3 \, A + 2 \, A = 5 \, A$$
### Legge delle Tensioni di Kirchhoff (KVL)
**Legge delle maglie**.
- La somma algebrica delle tensioni in un circuito chiuso è sempre zero.
 $$ \sum V = 0$$
- **Significato**: Quando si percorre un circuito chiuso, la somma delle tensioni deve risultare zero, basata sulla conservazione dell'energia.
#### Esempio KVL
In una maglia con una sorgente di 12 V e due resistori (4 Ω e 2 Ω) con una corrente di 2 A:
- Sorgente: +12 V
- Tensione sul resistore da 4 Ω: \( 8 \, V \)
- Tensione sul resistore da 2 Ω: \( 4 \, V \)
Applicando KVL:
$$12 \, V - 8 \, V - 4 \, V = 0$$
# Circuiti in serie e parallelo
## Resistenza
### Resistenze in serie
**Resistenza Totale**: è data dalla somma delle resistenze individuali:
$$
R_{tot} = R_{1}+R_{2}+R_{3}+\dots
$$
### Resistenze in parallelo
**Resistenza Totale**: è calcolata usando la formula:
$$
\frac{1}{R_{tot}} = \frac{1}{R_{1}} + \frac{1}{R_{2}} + \frac{1}{R_{3}} + \dots
$$
## Condensatori
### Condensatori in serie
**Capacitance Totale**: è data dalla formula:
$$
\frac{1}{C_{tot}} = \frac{1}{C_{1}} + \frac{1}{C_{2}} + \frac{1}{C_{3}} + \dots
$$
### Condensatori in parallelo
**Capacitance Totale**: è data dalla somma delle capacità individuali:
$$
C_{tot} = C_{1} + C_{2} + C_{3} +\dots
$$
# Elettromagnetismo
I magneti esercitano una forza uno sull'altro.
Poli "opposti" si attraggono, poli "uguali" si respingono.
### Magneti
Il dipolo magnetico genera un campo, tutti i magneti presentano un polo Nord e un polo Sud. Le linee di polo escono dal Nord ed entrano nel Sud (sono linee chiuse).
Se un magnete viene diviso si ottengono due magneti, entrambe con polo Nord e polo Sud come dimostra la **Legge di Gauss per il Magnetismo**.
## Legge di Gauss per il Magnetismo
La **Legge di Gauss per il magnetismo** afferma che non esistono monopoli magnetici, i campi magnetici non hanno sorgenti isolate.
$$
\oint_{\partial V} \mathbf{B} \cdot d\mathbf{A} = 0
$$
- $\oint_{\partial V}$ integrale di superficie chiusa.
- $\mathbf{B}$ campo magnetico.
- $d\mathbf{A}$ vettore area infinitesimale.
## Forza magnetica su una carica puntiforme (forza di Lorentz)
La **forza di Lorentz** è la forza esercitata su una carica elettrica *in movimento* all'interno di un campo elettrico e/o magnetico. È un concetto fondamentale nella fisica dell'elettromagnetismo.
**Forza di Lorentz**
$$
F_{B} = q(v \times B)
$$
- $F$ forza totale che agisce sulla carica.
- $q$ la carica elettrica (in Coulomb).
- $v$ la velocità della carica (in metro/secondo).
- $B$ il campo magnetico (in tesla, $1T = 1 N/Am$, 1 Tesla = 1 Newton/Ampere\*metro).
- $\times$ denota il prodotto vettoriale.
#### Comportamento della Forza di Lorentz
- **Direzione**: La forza magnetica è sempre perpendicolare sia alla velocità della carica sia alla direzione del campo magnetico. Ciò significa che la forza non compie lavoro sulla carica, cambiando solo la sua direzione e non la sua energia cinetica.
- **Caso di una Carica in Movimento**: Se una carica si muove in una direzione perpendicolare a un campo magnetico, la forza magnetica raggiunge il suo massimo valore:
$$
F_{B} = qvB
$$
- **Se la Carica è Ferma**: Se la carica è ferma ($v= 0$), non c'è forza magnetica ($F=0$).
Il **modulo** di $F$ è:
$$
F_{B} = qB (v \sin \theta)
$$
- $v \sin \theta$ è la componente della velocità perpendicolare alla direzione del campo magnetico. $\theta$ rappresenta l'angolo tra $v$ e $B$.
## Cariche in campo magnetico uniforme
### Caso $v \not\perp B$
Il moto della carica diventa una **spirale elicoidale**.
#### Componenti della Velocità
1. **Componente Perpendicolare**($v⊥$​):
    
    - Responsabile del **moto circolare** attorno al campo magnetico.
    - **Raggio di Larmor** $r = \frac{mv_{\perp}}{qB}$.
    - **Frequenza di ciclotrone** $\omega = \frac{qB}{m}$.
2. **Componente Parallela** ($v_{\parallel}$):
    - Non subisce l'influenza del campo magnetico e resta costante.
    - Causa un **moto rettilineo** lungo il campo magnetico.
#### Risultante: Moto Elicoidale
- **Traiettoria**: combinazione di un moto circolare (attorno a $B$) e un moto rettilineo (lungo $B$).
- **Passo dell’elica** (distanza tra due giri consecutivi):
$$
Passo = \frac{2\pi mv}{qB}
$$
## Forza magnetica su un filo percorso da corrente
$$
F = I(L \times B)
$$
- $I$ corrente elettrica che scorre nel filo.
- $L$ vettore lunghezza del filo.
- $B$ vettore campo magnetico.
- $\times$ denota il prodotto vettoriale.
**Modulo**:
$$
F = ILB \sin \theta
$$

**Casi particolari**:
1. *Filo perpendicolare al campo magnetico* ($\theta = 90°$):
	1. La forza è massima: $F = ILB$.
2. *Filo parallelo al campo magnetico* ($\theta = 0°$ o $180°$):
	1. La forza è nulla: $F = 0$.
## Campo magnetico dovuto a una corrente
### Caso del filo rettilineo di corrente
Un filo rettilineo percorso da corrente genera un **campo magnetico circolare** attorno a sé. Questo campo magnetico è descritto dalla **legge di Ampère** o dalla formula di Biot-Savart per fili infiniti.
Il modulo del campo magnetico $B$ a una distanza $r$ da un filo rettilineo infinito percorso da una corrente $I$ è:
$$
B =\frac{\mu_{0}I}{2\pi r}
$$
- $\mu_{0}$ è la **permeabilità del vuoto** ($\mu_{0} \approx 4\pi \times 10^{-7}N/A^{2}$).
- $I$ corrente nel filo (Ampere).
- $r$ distanza dal filo al punto in cui si misura $B$ (metri).
**Direzione del Campo Magnetico**:
La direzione del campo magnetico attorno a un filo rettilineo si determina usando la **regola della mano destra**:
1. Punta il pollice nella direzione della corrente II lungo il filo.
2. Le dita arrotolate attorno al filo indicano la direzione del campo magnetico $B$.
### Caso della spira
Un **solenoide** è una bobina lunga formata da molte spire circolari avvolte strettamente l’una accanto all’altra, e percorso da una corrente elettrica. Il campo magnetico generato all'interno del solenoide è **quasi uniforme** e ha intensità:
$$
B = \mu_{0}nI
$$
- $\mu_{0}$ permeabilità del vuoto ($\mu_{0}\approx_{4}\pi \times 10^{-7} N/A^{2}$).
- $n$ densità di spire, cioè il numero di spire per unità di lunghezza ($n = \frac{N}{L}$, con $N$ numero totale di spire e $L$ lunghezza del solenoide).
- $I$ corrente che scorre nel solenoide.
## La legge di Ampère
La **legge di Ampère** descrive la relazione tra la corrente elettrica e il campo magnetico che essa genera. La legge stabilisce che il **campo magnetico lungo un percorso chiuso** è proporzionale alla corrente totale che attraversa la superficie delimitata dal percorso.
$$
\oint_{c} B \cdot dl = \mu_{0}I_{tot}
$$
- $\oint_{c}B \cdot dl$ è l'integrale di linea del campo magnetico $B$ lungo un percorso chiuso $C$.
- $\mu_{0}$ la permeabilità del vuoto ($\mu_{0}\approx 4\pi \times 10^{-7} N/A^{2}$).
- $I_{tot}$ la corrente totale che attraversa la superficie delimitata dal percorso chiuso di $C$.
**Forma discreta**:
$$
\oint_{c} B \cdot dl = \lim_{ N \to \infty } \sum_{1}^{N} B \cdot dl_{i}
$$
#### Interpretazione
- La legge di Ampère implica che il campo magnetico generato attorno a un conduttore è proporzionale alla corrente in esso.
- Per un filo rettilineo infinito, ad esempio, il campo magnetico BB a distanza rr dal filo è:
$$
B = \frac{\mu_{0}I}{2\pi r}
$$
## Legge di Oersted
Afferma che un filo percorso da corrente genera un campo magnetico attorno a sé. Questa scoperta, fatta da Hans Christian Oersted nel 1820, ha dimostrato per la prima volta che le correnti elettriche possono influenzare gli oggetti magnetici.
**Connessione con la Legge di Ampère**:
La legge di Ampère descrive quantitativamente come la corrente produce un campo magnetico. Possiamo derivare la legge di Oersted dalla legge di Ampère considerando un filo rettilineo percorso da corrente.
*FIlo rettilineo*
$$
B = \frac{\mu_{0}I}{2\pi r}
$$
*Applicazione legge di Ampère*
$$
\oint_{C}B \cdot dl = B \cdot (2\pi r) = \mu_{0}I
$$
da cui otteniamo la formula per il campo magnetico $B$ attorno a un filo rettilineo.
### Calcoliamo l’intensità della forza
Due fili paralleli che giacciono su un piano orizzontale trasportano le correnti $I_{1}$ e $I_{2}$ verso destra. I fili sono lunghi entrambi $L$ e sono separate da una distanza $d$.
1. Scriviamo il modulo e la direzione del campo $B$ generato dal filo $1$ nella posizione del filo:
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
reciprocamente, scriviamo il modulo e verso del campo $B$ generato dal filo $2$ nella posizione del filo:
$$
B_{2} = \frac{\mu_{0}I_{2}}{2\pi d}
$$
Infine, il modulo della forza magnetica sul filo $1$ dovuto al $2$ è:
$$
\begin{align}
F_{12} &= I_{1}LB_{2}\sin \theta \\
&= I_{1}LB_{2} = \frac{\mu_{0}I_{1}I_{2}L}{w\pi d}
\end{align}
$$
Dunque:
- correnti parallele si attraggono.
- correnti antiparallele si respingono.
## Forza elettromotrice indotta
Considera un conduttore in un campo $B$ in moto verso destra.
![[Pasted image 20241101142653.png|300]]
$$
F_{B} = q(v \times B)
$$
Un elettrone nel conduttore sperimenta una forza verso il basso.
![[Pasted image 20241101142907.png|200]]
Ciò crea nella sbarra un campo elettrico e una differenza di potenziale tra l'apice e il fondo della sbarra.
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
Stabilisce che la f.e.m. indotta genera una corrente che crea un campo magnetico opposto alla variazione di flusso che la causa. Questo principio riflette la **conservazione dell’energia**.
Il **segno negativo** (legge di Lenz) indica che la direzione della f.e.m. indotta è tale da generare una corrente che si oppone alla variazione di flusso.
## Autoinduzione
L'autoinduzione è il fenomeno per cui una variazione di corrente in un circuito induce una forza elettromotrice (f.e.m.) nel circuito stesso, opponendosi alla variazione della corrente.
**FEM indotta**:
$$
\varepsilon = -L \frac{\Delta I}{\Delta t}
$$
- $\varepsilon$ forza elettromotrice indotta.
- $L$ induttanza del circuito in henry (H).
- $\frac{\Delta I}{\Delta t}$ variazione della corrente nel tempo.
## Campo elettrici e magnetici prodotti da cariche elettriche accelerate
Quando una carica è in movimento rettilineo e uniforme, genera solo un **campo elettrico statico** e un **campo magnetico costante**.
Quando una carica accelera, si crea una perturbazione nei campi elettrico e magnetico che si propaga lontano dalla carica. Questa perturbazione è un’**onda elettromagnetica**.
## Legge di Ampère-Maxwell
**magnetostatica**, la **legge di Ampère** stabilisce che il campo magnetico $B$ circolante attorno a un circuito chiuso è proporzionale alla corrente elettrica $I$ che attraversa la superficie racchiusa dal circuito:
$$
\oint_{C} B \cdot \Delta I = \mu_{0} I_{tot}
$$
Quando una carica accelera o cambia velocità, il campo elettrico variabile genera un **campo magnetico variabile**. Questa condizione, che non era presente in situazioni statiche, richiede un termine aggiuntivo nella legge di Ampère.
### Corrente di Spostamento
James Clerk Maxwell introdusse il concetto di **corrente di spostamento** per estendere la legge di Ampère ai fenomeni in cui il campo elettrico varia nel tempo. La corrente di spostamento rappresenta il contributo di un campo elettrico variabile alla creazione di un campo magnetico, anche in assenza di corrente conduttrice.
Modifichiamo quindi la **legge di Ampère**:
$$
\oint_{C} B \cdot \Delta I = \mu_{0}\left( I + \varepsilon_{0} \frac{\Delta \Phi_{E}}{\Delta t} \right)
$$
- $\varepsilon_{0}$ è la costante **dielettrica** nel vuoto ($\varepsilon_{0} \approx 8.85 \times 10^{-12} F/m$ (Farad per metro)).
- $\frac{\Delta \Phi_{E}}{\Delta t}$ la variazione del **flusso del campo elettrico**.
## Equazioni di Maxwell
### Legge di Gauss per il Campo Elettrico
$$
\oint_{S} \vec{E} \cdot \Delta \vec{A} = \frac{Q_{int}}{\varepsilon_{0}}
$$
La legge di Gauss per il campo elettrico afferma che il flusso del campo elettrico $\vec{E}$ attraverso una superficie chiusa è proporzionale alla carica totale $Q_{int}$ contenuta all'interno della superficie.
### Legge di Gauss per il Campo Magnetico
$$
\oint_{S} \vec{B} \cdot \Delta \vec{A} = 0
$$
La legge di Gauss per il magnetismo afferma che il flusso del campo magnetico $\vec{B}$ attraverso una superficie chiusa è zero.
### Legge di Faraday sull'induzione Elettromagnetica
$$
\oint_{C} \vec{B} \cdot \Delta \vec{l} = \frac{\Delta \Phi_{B}}{\Delta t}
$$
La legge di Faraday indica che una variazione nel tempo del flusso magnetico $\Phi_{B}$​ attraverso una superficie induce un campo elettrico circolare lungo il contorno $C$ della superficie.
### Legge di Ampère-Maxwell
$$
\oint_{C} \vec{B} \cdot \Delta \vec{l} = \mu_{0}(I_{tot}) + \varepsilon_{0}\frac{\Delta \Phi_{E}}{\Delta t}
$$
La legge di Ampère, estesa da Maxwell, afferma che il campo magnetico circolante attorno a un circuito è generato dalla corrente totale $I_{tot}$​ e dalla variazione nel tempo del flusso del campo elettrico $\Phi_{E}$.
## Onde periodiche
![[Pasted image 20241101152834.png]]
$$
v = \lambda f 
$$
- $v$ velocità di propagazione dell'onda.
- $f$ la frequenza.
- $\lambda$ la lunghezza d'onda.
Le due soluzioni per la coppia di campi sono onde periodiche sinusoidali di tipo “seno” o “coseno”.
Per esempio, per la soluzione di tipo “seno” i moduli dei due campi variano nello spazio e nel tempo in modo periodico secondo la legge:
$$
E_{z} = E_{max} \sin(:\varphi(y, t)) \quad B_{x} = B_{max} \sin(\varphi(y,t))
$$
Esplicitando $\varphi(y,t)$:
![[Pasted image 20241101153203.png]]
Dalle equazioni di Maxwell si ricava anche la relazione matematica che lega i moduli di $E$ e $B$:
$$
E = cB
$$
Chiamiamo **onda elettromagnetica** l’insieme dei due campi.
## Velocità di propagazione delle onde EM
Le onde EM si propagano sia nel vuoto che in un mezzo.
Maxwell calcolò teoricamente la velocità di propagazione delle onde EM nel vuoto ottenendo il seguente risultato:
$$
\begin{align}
C &= \frac{1}{\sqrt{ \varepsilon_{0} \mu_{0}}} \\
&= \frac{1}{\sqrt{ (8.85 \times 10^{-12} C^{2}/Nm^{2}) (4\pi \times 10^{-7} Tm/A)}} \\
&= 3.00 \times 10^{8} m/s
\end{align}
$$
### Valore della Velocità della Luce nel Vuoto
$$
c \approx 3.00 \times 10^{8} m/s 
$$
Indipendente dalla frequenza! Inoltre in un mezzo $v<c$.








