# Conduttori elettrici
Esistono materiali in cui alcune particelle portatrici di carica elettrica non sono strettamente vincolate a posizioni precise, ma hanno una certa libertà di movimento.
- *Metalli*: ogni atomo contiene molti elettroni, questi elettroni sono detti elettroni di conduzione, e ciascuno porta una carica elettrica $−e$.
- *Semiconduttori*: sono materiali con struttura cristallina in cui si distinguono elettroni di conduzione, liberi di muoversi, ed elettroni di valenza, legati agli atomi per formare il reticolo cristallino. A causa dell'agitazione termica, alcuni elettroni di valenza possono liberarsi, diventando elettroni di conduzione e lasciando una lacuna (carica positiva). Questo crea due tipi di portatori di carica nel semiconduttore: elettroni ($-e$) e lacune ($+e$).
- *Soluzioni ioniche*: I materiali cristallini sono aggregati da legami ionici, che in acqua si spezzano formando ioni. In questo caso gli stessi ioni fungono da portatori di carica.
L'unità elementare di carica è:
$$
e = 1.602 \times 10^{-19}C
$$
# Corrente elettrica
Consideriamo un conduttore filiforme, di sezione traversa $\Sigma$, cui viene applicato un campo elettrico $\vec{E}$ parallelo al conduttore. In esso, i portatori di carica acquisiscono una velocità di deriva $\vec{u}= \sigma \vec{E}$, anch'essa parallela al conduttore. Quindi attraverso la sezione $\Sigma$ c'è un flusso netto di cariche elettriche.
![[Pasted image 20241125172121.png]]
Si definisce *corrente elettrica* in un conduttore una quantità $I$ pari al rapporto fra la quantità di carica elettrica $\Delta Q$ che attraversa la sezione $\Sigma$, ed il tempo $\Delta t$ in cui questo passaggio avviene:
$$
I = \frac{\Delta Q}{\Delta t}
$$
Calcoliamo quanta carica elettrica $\Delta Q$ attraversa $\Sigma$ in un tempo infinitesimo $\Delta t$. Poiché il conduttore è filiforme $\vec{E}, \vec{u}, \vec{J}$ hanno tutti orientamento uniforme lungo il conduttore. Il problema diventa quindi unidimensionale, possiamo omettere la notazione vettoriale.
Consideriamo un piccolo tratto di conduttore di lunghezza $\Delta s = u\Delta t$, subito prima di $\Sigma$. Tutti i portatori che si trovano in esso attraverseranno la sezione $\Sigma$ entro il tempo $\Delta t$. Detta $n$ la loro densità in volume, e $\Delta V = \Sigma \Delta s$ il volume del trattino di conduttore, il numero dei portatori che attraversano $\Sigma$ nel tempo $\Delta t$ è $\Delta N = n\Delta V = n\Sigma \Delta s=n\Sigma u\Delta t$, quindi la carica elettrica totale che passa è:
$$
\Delta Q=q\Delta N=nqu\Sigma \Delta t=J\cdot \Sigma \Delta t
$$
ne segue che:
$$
I = J\cdot \Sigma
$$
# La legge di Ohm
Stabilisce una relazione semplice tra tensione ($\Delta V$), corrente ($I$) e resistenza ($R$) in un circuito elettrico.
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

