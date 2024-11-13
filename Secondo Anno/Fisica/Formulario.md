## Costanti
$$
\begin{gather}
\text{Accelerazione di gravità} = g = 9.81 \frac{m}{s^{2}} \\
\text{Costante gravitazionale} = G = 6.673 \cdot 10^{-11} \frac{Nm^{2}}{kg^{2}} \\
\text{Masssa della Terra} = M_{T} = 5.974 \cdot 10^{24} kg \\
\text{Massa della Luna} = M_{L} = 7.348 \cdot 10^{22} kg \\
\text{Raggio della Luna} = R_{L} = 1.738 \cdot 10^{6} m \\
\text{Distanza Terra-Luna} = R_{TL} = 3.844 \cdot 10^{8} m
\end{gather}
$$
## Fattori di conversione
$$
\begin{gather}
1 \ mile = 1609,34m \\
1 \ inch(pollice) = 2.54 cm \\
\text{radianti} \to \text{gradi} = g° = \frac{r^{rad}\times 180°}{\pi} \\
\text{gradi} \to \text{radianti} = r^{rad} = \frac{g° \times \pi}{180°} \\

\end{gather}
$$
## Cinematica
$$
\begin{gather}
\text{Velocità: }\vec{v} = \frac{\Delta \vec{v}}{\Delta t} \\
\text{Accelerazione: } \vec{a} = \frac{\Delta \vec{v}}{\Delta t}
\end{gather}
$$
## Moto uniformemente accelerato
$$
\begin{gather}
v - v_{0} = a \cdot t \\
x - x_{0} = v_{0} \cdot t + \frac{1}{2}at^{2} \\
x - x_{0} = \frac{1}{2}(v_{0}+v_{x})t \\
v_{x}^{2} - v_{0}^{2} = 2a(x - x_{0})
\end{gather}
$$
### Corpo in caduta libera
$$
\begin{gather}
v = \sqrt{ 2gh } \\
t = \sqrt{ \frac{2h}{g} }
\end{gather}
$$
## Moto del proiettile
$$
\begin{gather}
y = x \cdot \tan \theta - \frac{g}{2v_{0}^{2}\cos^{2}\theta}x^{2} \\
h_{max} = \frac{v_{0}^{2}\sin^{2}\theta}{2g} \\
x_{max} = \frac{v_{0}^{2}\sin(2\theta)}{g}
\end{gather}
$$
## Moto circolare
$$
\begin{gather}
\text{Velocità angolare} = \omega = \frac{2\pi}{T} \\
\text{Periodo} = T = \frac{2\pi}{\omega} \\
v_{tangenziale} = \omega r = \frac{2\pi r}{T}\\
a_{centripeta} = \frac{v^{2}}{r} = \omega r^{2} \\
\end{gather}
$$
## Moto circolare uniformemente accelerato
$$
\begin{gather}
\Delta \text{velocità angolare} = \omega - \omega_{0} = a \cdot t \\
\text{Spostamento angolare} = \theta - \theta_{0} = \omega_{0} \cdot t + \frac{1}{2}at^{2} \\
\text{Relazione tra velocità angolare e posizione angolare} = \omega^{2} = \omega_{0}^{2}+2a(\theta-\theta_{0})
\end{gather}
$$
## Moto curvilineo
$$
\begin{gather}
\text{Accelerazione totale} = a = \sqrt{ a_{tang}^{2} + a_{centripeta}^{2} } = a_{T}\theta + a_{centripeta} \hat{r} = \frac{\Delta v}{\Delta t}\theta - \frac{v^{2}}{r}\hat{r} \\
\text{Centro della traiettoria} = \hat{r}
\end{gather}
$$
# Forze, Lavoro ed Energia
$$
\begin{gather}
\text{Legge di Newton} = \vec{F} = m \vec{a} \\
\text{Momento della forza} = \vec{\tau} = \vec{r} \times \vec{F} = |\vec{r}| |\vec{F}| \sin \theta \\
\text{Vettore posizione dal punto di rotazione al punto di applicazione della forza} = \vec{r} \\
\text{Vettore forza} = \vec{F} \\
\text{Angolo tra } \vec{r} \text{ e } \vec{F} = \theta
\end{gather}
$$
### Forze fondamentali
$$
\begin{gather}
\text{Forza peso} = F_{g} = mg \\
\text{Forza elastica} = F_{el} = -k(x-l_{0}) \\
\text{Gravità} = \vec{F_{g}} = -G \frac{Mm}{r^{2}}\hat{r} \\
\text{Elettrostaticità} = \vec{F_{e}} = \frac{1}{4\pi \varepsilon_{0}} \frac{q_{1}q_{2}}{r^{2}}\hat{r} \\
\text{Tensione di un filo con un corpo} = T = m \frac{v^{2}}{r} = F_{peso}\cos(\alpha) + F_{centripeta} \ (\text{qualsiasi punto}) \\
\text{Tensione di un filo con due corpi} T = m_{1}a = \frac{m_{1}}{m_{1}+m_{2}}F \\
\text{Forza centripeta} = F_{c} = ma_{c} = m\frac{v^{2}}{r} = m\omega^{2}r 
\end{gather}
$$
## Forze di attrito
$$
\begin{gather}
\text{Statico} = |\vec{F_{S}}| \leq |\mu_{S}\vec{N}| \\
\text{Dinamico} = \vec{F_{D}} = -\mu_{D}|\vec{N}|\hat{v}
\end{gather}
$$
## Lavoro
$$
\begin{gather}
\text{Forza costante} = L = \vec{F} \cdot \vec{\Delta s} = F \times \Delta s \times \cos\theta \\
\text{Forza elastica} = L = -\frac{1}{2}k(x_{f}-l_{0})^{2}+ \frac{1}{2}k (x_{i}-l_{0})^{2} \\
\text{Forza peso} = L = -mgh \\
\text{Gravità} = L = Gm_{1}m_{2}\cdot \left( \frac{1}{r_{f}} - \frac{1}{r_{i}} \right) \\
\text{Elettrostatica} = L = \frac{q_{1}q_{2}}{4\pi\varepsilon_{0}} \cdot \left( \frac{1}{r_{i}} - \frac{1}{r_{f}} \right) \\
\text{Potenza} = L = \frac{\Delta L}{\Delta t} = \vec{F} \cdot \vec{v} = \tau \omega
\end{gather}
$$
## Energia
$$
\begin{gather}
\text{Cinetica} = K = \frac{1}{2}mv^{2} \\
\text{Rotazione} = K = \frac{1}{2}mv^{2}_{CM} + \frac{1}{2}I_{CM}\omega^{2} \\
\text{Potenziale} = U = -L
\end{gather}
$$
### En. potenziale forze fondamentali
$$
\begin{gather}
\text{Forza peso} = U(h) = mgh \\
\text{Forza elastica} = U(x) = \frac{1}{2}k(x-l_{0})^{2} \\
\text{Gravità} = U(r) = -G\frac{m_{1}m_{2}}{r} \\
\text{Elettrostatica} = U(r) = \frac{1}{4\pi\varepsilon_{0}} \cdot \frac{q_{1}q_{2}}{r}
\end{gather}
$$
## Impulso e Momento Angolare
$$
\begin{gather}
\text{Quantità di moto} = \vec{p} = m \vec{v} \\
\text{Impulso} = \vec{J} = \vec{F} \Delta t = \Delta \vec{p} = m \Delta \vec{v} \\
\text{Momento angolare} = \vec{L} = \vec{r} \times \vec{p} = \vec{r} \times m \vec{v} \\
\text{Intorno ad un asse fisso} = |\vec{L}| = I_{asse} \cdot \omega
\end{gather}
$$
## Moto armonico
$$
\begin{gather}
\text{Posizione in funzione del tempo} = x(t) = A\cos(\omega t + t_{0}) \\
\text{Velocità in funzione del tempo} = v(t) = -A\omega \sin(\omega t + t_{0}) \\
\text{Accelerazione in funzione del tempo} = a(t) = -A\omega^{2} \cos(\omega t + t_{0}) = -\omega^{2}x(t) \\
\text{Frequenza angolare e frequenza} = \omega = 2\pi f = \frac{2\pi}{T} \\
\text{Energia totale del sistema} = E = \frac{1}{2}m\omega^{2}A^{2} \\
\text{Energia potenziale} = E_{pot} = \frac{1}{2}kx^{2} \\
\text{Energia cinetica} = E_{cinetica} = \frac{1}{2}mv^{2}
\end{gather}
$$
## 




