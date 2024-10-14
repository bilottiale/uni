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
## Moto dei proiettili
Un aereo vola alla quota di $1050 m$ alla velocità di $115 m/s$. Ad un certo istante lancia una cassa contenente generi di pronto soccorso. A quale distanza dal punto di lancio la cassa colpirà il suolo?
![[Pasted image 20241013174440.png]]



