## Cinematica
### 1
Un’auto che viaggia a 28 m/s viene decelerata fino ad un completo arresto in 4 s. Trovare la decelerazione media durante la frenata.
$$
\text{Dati }v_{i}=28m/s,v_{f}=0m/s,\text{ e }\Delta t=4s
$$
$$
a_{av}=\frac{\Delta v}{\Delta t} = \frac{0-28m/s}{4s}=-7m/s^{2}
$$
### 2
All’inizio di un viaggio di 3 ore stai viaggiando verso nord a 192 km/h. Alla fine viaggi a 240 km/h a 45° a ovest della direzione nord.
- Disegnare i vettori velocità iniziale e finale.
- Trovare il vettore $\Delta v$.
- Qual è l’accelerazione media durante il viaggio?

1.
![[Pasted image 20241013142745.png|250]]
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
## Gravità
### 1
Qual è la forza di attrazione gravitazionale tra due persone di 50 Kg e 75 Kg ad una distanza di 50 cm?
$$
F=G\frac{M_{1}M_{2}}{r^{2}}
$$
Sostituendo otteniamo:
$$
F= 6.67\times 10^{-11}Nm^{2}{kg^{2}} \frac{50kg \times 75kg}{50^{2}cm}
$$
$$
F= 1\times 10^{-6}N
$$
### 2
Il centro della Luna dista dal centro della Terra $3.9\times105 km$. La massa del Sole è di $2.0\times1030 kg$ e la massa della Terra è di $6.0\times1024 kg$. La distanza della Luna dal Sole è di $1.5\times108 km$. Si trovi il rapporto tra la forza esercitata sulla Luna dalla Terra e dal Sole.

Facendo il rapporto tra le due forze coinvolte:
$$
\frac{F_{tl}}{F_{sl}}=\frac{m_{T}}{m_{S}} \frac{d^{2}_{LS}}{d^{2}_{TL}}=0,44
$$
Sia $M_{E}$ la masse della Terra.
$$
F=(\frac{GM_{E}}{r^{2}})M_{2}
$$
$F$ è la forza che la Terra esercita sulla massa $M_{2}$. Questa forza si chiama peso, $w$.
$$
w=(\frac{GM_{E}}{r^{2}})M_{2}=gM_{2}
$$
$$
M_{E}=5.98\times 10^{24}kg
$$
$$
r_{E}=6400km
$$
dove $g=\frac{GM_{e}}{r^{2}_{E}}=9.8N/kg=9.8m/s^{2}$ vicino la superficie della Terra.

Qual’è il peso di un astronauta di massa $100 kg$ sulla superficie della Terra? Come cambia il peso se l’astronauta si trova in orbita a circa $300 km$ dalla superficie della Terra?
- Sulla Terra: $w=mg=980N$
- In orbita: $w=mg(r_{o})=m(\frac{GM_{E}}{(R_{E}+h)^{2}})=890N$
Il peso è ridotto di circa $10\%$.
### 3
L’intensità del campo gravitazionale sulla Luna è circa $1/6$ di quello alla superficie della terra. Se $m$ and $w$ sono la massa e il peso di una persona sulla terra, quanto varranno le stesse quantità sulla luna?
$$
m,\frac{1}{6}w
$$
La massa non cambia, il peso sì.
## Forze di contatto
### 1
Uno scatolone pieno di libri è appoggiato su un pavimento di legno. La forza normale che il pavimento esercita sullo scatolone è di $250 N$. Spingendo orizzontalmente con una forza di $120 N$ lo scatolone non si sposta. Cosa si può dire riguardo al coefficiente di attrito statico tra lo scatolone e il pavimento? Con una forza di $150 N$ lo scatolone comincia a spostarsi. Cosa si può dire riguardo al coefficiente di attrito statico tra lo scatolone e il pavimento? Una volta in movimento, basta spingere lo scatolone con una forza di $120 N$. Cosa si può dire riguardo al coefficiente di attrito dinamico tra lo scatolone e il pavimento?

1. Spingi orizzontalmente la scatola con una forza di $120 N$, ma questa non si muove. Che cosa puoi dire riguardo al coefficiente di attrito tra la scatola e il pavimento?
![[Pasted image 20241013152859.png|250]]
$$
F=f_{s}=\mu_{s}N \Longrightarrow \mu_{s} = \frac{F}{N}=0.48
$$
Questo è il valore minimo di $\mu_{s}$, quindi $\mu_{s}>0.48$.

2. Se devi spingere orizzontalmente la scatola con una forza di $150 N$ affinchè si metta in movimento, qual è il coefficiente di attrito statico?
$$
F=f_{s}=\mu_{s}N \Longrightarrow = \frac{F}{N}=0.60
$$

3. Una volta che la scatola si muove, devi spingere solo con una forza di $120 N$ per mantenerla in movimento. Qual è il coefficiente d’attrito dinamico?
$$
F=f_{k}=\mu_{k}N \Longrightarrow \frac{F}{N} = \frac{120N}{250N} = 0.48
$$

### Tensione
Una carrucola è appesa al soffitto attraverso una corda. Un blocco di massa $M$ è sospeso attraverso un’altra corda che scorre sulla carrucola ed è attaccata alla parete. La corda fissata alla parete forma con la parete stessa un angolo retto. Trascurando le masse delle corde e della carrucola calcolare la tensione della corda che sostiene a carrucola e l’angolo $\theta$.
![[Pasted image 20241013154912.png|300]]![[Pasted image 20241013154935.png|235]]
$$
\sum F_{y}=T-w=0
$$
$$
T=w=Mg
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
## Seconda legge di Newton
### 1
Trovare la tensione che agisce sulla corda che collega i due blocchi in figura quando una forza di $10 N$ viene applicata al blocco di destra. Supporre trascurabile l’attrito. Le masse dei due blocchi sono $m_{1} = 3.00 kg$ e $m_{2} = 1.00 kg$.
![[Pasted image 20241013160342.png|500]]
Assumi che la corda rimanga tesa cosicchè entrambi i blocchi abbiano la stessa accelerazione.
![[Pasted image 20241013160441.png|500]]
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
### 2
Una scatola scivola su una superficie rugosa. Sapendo che il coefficiente di attrito dinamico è $0,3$ calcolare l’accelerazione della scatola.
![[Pasted image 20241013161302.png|300]]
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
Da $(1)$: $-F_{k}=-\mu_{k}N=-\mu_{k}mg=ma$
Risolvendo per $a$:
$$
a=-\mu_{k}g=-(0.3)(9.8m/s^{2})=-2.94m/s^{2}
$$
## Composizione delle velocità
Il motore di una barca la fa muovere rispetto all’acqua di una velocità $v_{ba}=4.0m/s$, secondo la direzione perpendicolare alla corrente. Se la velocità dell’acqua rispetto alla riva è $v_{ar} =2.0 m/s$, quanto vale la velocità $v_{br}$ della barca rispetto alla riva? Se il fiume è largo $1800m$, quanto tempo impiega la barca per attraversarlo?
![[Pasted image 20241013162157.png|300]]
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
da cui $\alpha=\arctan_{2}=63°$.

3. La seconda parte del problema chiede: ‘se il fiume è largo $1800m$, quanto tempo impiega la barca per attraversarlo?’.
Dalla velocità della barca si risale al tempo necessario per percorrere $1800 m$, infatti:
$$
\text{Sapendo che }v_{ba}=\frac{y}{t} \Longrightarrow t=\frac{y}{v_{ba}}=\frac{1800m}{4m/s}=450s
$$
## Moto rettilineo uniforme
Un cane che corre a $10 m/s$ è a $30 m$ dietro un coniglio che si muove a $5m/s$. Quando il cane raggiungerà il coniglio? Disegnare i diagrammi $x-t$ e $v-t$ per il moto del cane e del coniglio.
![[Pasted image 20241013164408.png]]
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
Risolvendo l'ultima rispetto al tempo si ottine:
$$
t=\frac{30m}{v_{cane}-v_{coniglio}}=6s
$$
3. ![[Pasted image 20241013164825.png|250]]
### Moto rettilineo con accelerazione costante
Si supponga di dover disegnare un sistema di air-bag che possa proteggere il guidatore nel caso di un urto frontale alla velocità di $100 Km/h$. Stimare quanto rapidamente si deve gonfiare l’air-bag per proteggere efficacemente il guidatore. Supporre che, in conseguenza dell’urto, l’auto si accartocci di $1 m$.
$$
\begin{align}
v_{i} = &100km/h = \frac{10^{2}\times10^{3}}{3.6\times 10^{3}} \frac{m}{s} = 0.28 \times 10^{2}m/s \\
v_{f} = &0 \\
\overline{a} = &\frac{v_{f}-v_{i}}{\Delta t} \\
\Delta x = &\frac{1}{2}\overline{a}\Delta t^{2}+v_{i}\Delta t=1m \\
&\frac{1}{2} \frac{\Delta v}{\Delta t}\Delta t^{2}+v_{i}\Delta t = 1m \\
&\left(\frac{1}{2}\Delta v+v_{i}\right)\Delta t=1m \\
&\Delta t = \frac{1m}{\frac{1}{2}(v_{f}+v_{i})}= \frac{1m}{\frac{1}{2}v_{f}-\frac{1}{2}v_{i}+v_{i}} \\
&=\frac{1m}{\frac{1}{2}(v_{f}+v_{i})}=\frac{1m}{\frac{1}{2}\cdot 0.28 \times 10^{2}} \\
&=7.14 \times 10^{-2}s = 0.07s
\end{align}
$$
### Resistenza dell'aria
Un paracadutista con indosso lo zaino del paracadute ha una massa di $120 kg$. La forza resistente dovuta all’attrito in aria è $F_{d} = bv^{2}$ con $b=0.14Ns^{2}/m^{2}$.
1. Nel momento in cui il paracadutista cade con velocità di $64 m/s$, quanto vale la forza resistente?
$$
F_{d}=bv^{2}=(0.14Ns^{2}/m^{2})(64m/s)^{2}=570N
$$
2. Quanto vale la sua accelerazione?
Applichiamo la seconda legge di Newton e risolviamo per a:
$$
\begin{gather}
\sum F_{y}=F_{d}-w=ma \\
a= \frac{F_{d}-mg}{m}=-5.1m/s^{2}
\end{gather}
$$
3. Quanto vale la velocità limite che il paracadutista raggiunge?
$$
\begin{gather}
\sum F_{y}=F_{d}-w=ma=0 \\
bv_{t}^{2}-mg=0 \\
v_{t} =\sqrt{ \frac{mg}{b} }=92m/s
\end{gather}
$$



