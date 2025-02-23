# Moti in campi elettrostatici 
## Potenziale elettrostatico
*Le forze elettrostatiche sono conservative.*
Una carica $q_{0}$ in $\vec{r}$, in presenza di altre cariche $q_{1},\dots,q_{N}$ poste a $\vec{r}_{1},\dots \vec{r}_{N}$, è soggetta ad un'energia potenziale:
$$
U_{0}(\vec{r}) = q_{0}\sum_{k=1}^{N} \frac{1}{4\pi \varepsilon_{0}} \frac{q_{k}}{|\vec{r} - \vec{r_{k}}|}
$$
L'energia potenziale è proporzionale alla carica $q_{0}$, definiamo una quantità indipendente da $q_{0}$ per una descrizione più generale. Definiamo il *potenziale elettrostatico* come $\Phi(\vec{r}) = \frac{U_{0}(\vec{r})}{q_{0}}$:
$$
\Phi(\vec{r}) = \frac{1}{4\pi\varepsilon_{0}}\sum_{k=1}^{N} \frac{q_{k}}{|\vec{r} - \vec{r_{k}}|}
$$
L'unità di misura è il Volt (V). 1 Volt è la differenza di potenziale che produce una variazione di energia di 1 Joule ad una carica elettrica di 1 Coulomb:
$$
1 V = 1 J/C
$$
Ricordiamo che $\vec{F} = q \vec{E}$ e $U(\vec{r}) = q\Phi(\vec{r})$, possiamo costruire una relazione:
![[Pasted image 20241125153856.png]]
Il lavoro fatto dal campo $\vec{E}$ su $q$ si può scrivere come:
$$
W_{es}(A\to B) = q\int_{A}^{B} \vec{E}\cdot d \vec{r} = q[\Phi(A) - \Phi(B)] dx
$$
# Moto in un campo magnetico
Su una carica puntiforme $q$ che si muove a velocità $\vec{v}$ può essere descritta quantitativamente una legge:
$$
\vec{F_{L}} = q \vec{v} \times \vec{B}
$$
nota come *forza di Lorentz*. Il vettore $\vec{B}$ in generale è una funzione della posizione della carica $q$. L'equazione può essere usata come definizione del campo magnetico $\vec{B}$: misurando la forza agente su diverse cariche che passano per un punto con diverse velocità e direzioni, si possono misurare le componenti di $\vec{B}$ in quel punto.
![[Pasted image 20241125154752.png|500]]
L'unità di misura del campo magnetico è il Testla ($T = N s C^{-1}m^{-1}$).
Dall'equazione sappiamo che $\vec{F_{L}}$ è ortogonale al piano, quindi l'accelerazione non ha componente tangenziale: è puramente *centripeta*, il modulo della velocità è costante:
$$
\frac{\Delta v}{\Delta t} = \frac{\Delta |\vec{v}|}{\Delta t} = 0
$$
Detto $\theta$ l'angolo tra i vettori $\vec{v}$ e $\vec{B}$ il suo modulo è:
$$
|\vec{F_{L}}| = |qvB\sin \theta|
$$
quindi nullo se $\vec{v}$ è parallelo a $\vec{B}$, massimo se $\vec{v}$ è ortogonale a $\vec{B}$.
## Moto in un campo magnetico uniforme
Consideriamo il moto di una particella in un campo magnetico $\vec{B}$ uniforme. Scomponiamo la velocità $\vec{v}$ in $\vec{v_{\parallel}}$ e $\vec{v_{\perp}}$, parallela e ortogonale a $\vec{B}$:
$$
\frac{\Delta \vec{v_{\parallel}}}{\Delta t} + \frac{\Delta \vec{v_{\perp}}}{\Delta t} = \frac{q}{m}(\vec{v_{\parallel}} + \vec{v_{\perp}}) \times \vec{B} = \frac{q}{m}\vec{v_{\perp}} \times \vec{B}
$$
$\vec{v_{\perp}} \times \vec{B}$ è ortogonale a $\vec{B}$, le equazioni del moto possono essere separate nella direzione di $\vec{B}$ e nel piano ortogonale:
$$
\begin{gather}
\frac{\Delta \vec{v_{\parallel}}}{\Delta t} = 0 \\
\frac{\Delta \vec{v_{\perp}}}{\Delta t} = \frac{q}{m} \vec{v_{\perp}} \times \vec{B}
\end{gather}
$$
La prima descrive un moto rettilineo uniforme nella direzione di $\vec{B}$.
Analizziamo la seconda. Sappiamo che $v_{\perp} = |\vec{v_{\perp}}|$ non cambia nel tempo. Dall'accelerazione centripeta possiamo calcolare il raggio di curvatura $R$:
$$
\frac{q}{m}\vec{v_{\perp}} = a_{n} = \frac{\vec{v_{\perp}}}{qB}
$$
da cui:
$$
R = \frac{mv_{\perp}}{qB} = \frac{p_{\perp}}{qB}
$$
Possiamo anche ricavare la velocità angolare: $\omega = \frac{v_{\perp}}{R}$, quindi:
$$
\omega = \frac{qB}{m}
$$
Ragioniamo sulle singole componenti cartesiane: prendiamo l'asse $z$ parallelo a $\vec{B}$, cosicché $\vec{B} = B_{z}\hat{z}$. L' equazione diventa:
$$
\begin{gather}
\frac{\Delta v_{x}}{\Delta t} = \frac{q}{m}(v_{y}B_{z} - v_{z}B_{y}) = \frac{qB}{m}v_{y} \\
\frac{\Delta v_{y}}{\Delta t} = \frac{q}{m}(v_{z}B_{x} - v_{x}B_{z}) = -\frac{qB}{m}v_{x} \\
\frac{\Delta v_{z}}{\Delta t} = \frac{q}{m}(v_{x}B_{y} - v_{yB_{x}}) = 0
\end{gather}
$$
La terza ci dice che $v_{z}$ è costante nel tempo. Le prime due hanno per soluzione:
$$
\begin{gather}
v_{x} = v_{0}\sin\left( \frac{qB}{m}t + \Phi \right) \\
v_{y} = v_{0}\cos\left( \frac{qB}{m}t + \Phi \right)
\end{gather}
$$
Qui $v_{0}$ è una costante di integrazione. Poiché $\sin^{2} + \cos^{2} = 1$, abbiamo che $\sqrt{ v^{2}_{x} + v_{y}^{2}} = v_{0}$, quindi $v_{0}$ è il modulo della velocità sul piano $(x,y)$.
Le conclusioni che si traggono sono:
- moto rettilineo lungo l'asse $z$;
- moto circolare uniforme sul piano $(x,y)$, con velocità $v_{0}$, raggio $R=\frac{mv_{0}}{qB}$ e velocità angolare $\omega=\frac{qB}{m}$.

La traiettoria dlla particella apparirà come in figura $(b,c)$: se $\vec{v_{\parallel}} = 0$ la traiettoria è circolare, altrimenti è *elicoidale*. Il raggio della curvatura è dato da $R=\frac{mv_{\parallel}}{qB} = \frac{p_{\parallel}}{qB}$. Nel caso di traiettoria elicoidale, il passo dell’elica è calcolabile così: in un tempo $T = \frac{2\pi}{\omega}$ la particella carica descrive un giro completo intorno all’asse dell’elica; nello stesso tempo lo spostamento nella direzione assiale è dato da $\lambda = v_{\parallel}T$, ovvero una delle seguenti formule equivalenti:
$$
\lambda = \frac{2\pi v_{\parallel}}{\omega} = \frac{2\pi mv_{\parallel}}{qB} = 2\pi R \frac{v_{\parallel}}{v_{\perp}} = 2\pi R \frac{p_{\parallel}}{p_{\perp}}
$$
# Acceleratori circolari
Le particelle cariche vengono accelerate da una forza accelerante prodotta da un campo elettrico $\vec{E}$ diretto nella direzione del moto delle particelle:
$$
\vec{F_{acc}} = q\vec{E}
$$
Le particelle sono mantenute su un'orbita circolare da un campo magnetico $\vec{B}$, che produce una forza centripeta:
$$
\vec{F_{L}} = q\vec{v} \times \vec{B}
$$
Come esempio, descriviamo il *ciclotrone*.
L’apparato è costituito da due strutture semicircolari cave (dette “le $D$”) all’interno delle quali c'è un campo magnetico uniforme $\vec{B}$, perpendicolare.
Tra le due "$D$" c'è una zona ("gap") di larghezza $h$ in cui viene generato un campo elettrico $\vec{E}$, pilotato da un generatore oscillante di frequenza $v$. Per fissare le idee, scegliamo un riferimento cartesiano con l’asse $\hat{z}$ verticale e l'asse $\hat{y}$ nella direzione del campo elettrico. Quindi, i campi elettrico e magnetico sono:
$$
\vec{E} = E_{0}\cos(2\pi vt)\hat{y} \quad ; \quad \vec{B}=-B\hat{z}
$$
Le particelle vengono iniettate nel gap al centro della struttura, a $t=0$, dove sentono la forza accelerante $\vec{F_{acc}}=q\vec{E}$, che agisce per tutta la larghezza $h$, quindi produce un lavoro $W_{gap} = qE_{0}h$. Le particelle subiscono un aumento di energia cinetica:
$$
\Delta \varepsilon_{gap} = qE_{0}h
$$
Il campo magnetico $\vec{B}$ imprime una traiettoria ad arco sulle particelle, con raggio di curvatura:
$$
\rho = \frac{p}{qB}
$$
e velocità angolare:
$$
\omega=\frac{q}{m}B
$$
quindi il tempo per percorrere un'intero giro è:
$$
T=\frac{2\pi}{\omega} = 2\pi \frac{m}{qB}
$$
Dopo un tempo $\frac{T}{2}$ le particelle hanno completato mezzo giro e ri-attraversato il gap, in direzione opposta. Affinché ricevano ancora un’accelerazione, occorre che anche il campo elettrico abbia invertito l’orientamento. Dopo un altro intervallo di tempo $\frac{T}{2}$ esse riattraversano ancora il gap, nella direzione originaria, quindi occorre che anche il campo elettrico sia tornato all’orientamento iniziale.
Quindi il campo elettrico deve oscillare con una frequenza $f = \frac{1}{T} = \frac{\omega}{2\pi}$.
$\omega$ non ha subito variazioni, poiché dipende solo da $q,m,B$, la frequenza del generatore non deve essere “aggiustata” durante l’accelerazione.
L’energia raggiungibile con un ciclotrone è limitata dalle caratteristiche costruttive: il particolare dall’intensità $B$ del campo magnetico e dal raggio $R$ della regione in cui esso è presente. Infatti ovviamente $\rho <R$, quindi $p < qBR$; scrivendo $\varepsilon= \frac{p^{2}}{m}$ troviamo:
$$
\varepsilon_{max} = \frac{(qBR)^{2}}{2m}
$$
