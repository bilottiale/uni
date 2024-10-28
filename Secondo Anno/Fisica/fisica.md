ù# Forze
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
Average velocity $= v_{av,x}=\frac{x_{2}-x_{1}}{t_{2}-t_{1}}$

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
# Moti 1D
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
# Elettromagnetismo
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











