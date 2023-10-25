### Prof. Reto Buzano
reto.buzano@unito.it
[testo](https://people.dm.unipi.it/martelli/Alg%20Lin.pdf)
[moodle]()

### Info esame
2 esami:
* 1 Matematica discreta
* 1 Algebra lineare
	* 10 scelta multipla (6/10 sufficienza)


[[README]]
[[Simbologia]]
[[Lettere]]
[[Matematica Discreta]]
# Indice
[[Algebra#Numeri reali|Numeri reali]]

# Numeri reali
[[Matematica Discreta#Insiemistica|Vedi insiemi]]
## Costruzione dei numeri reali
$Def:$ *Successione di Cauchy*: una successione $(a_{n})_{n}$ è di Cauchy se per ogni $\epsilon > 0$ esiste un intero positivo $N$ tale che ogni coppia di numeri interi positivi $n, m > N$ si ha che $|x_{n} - x_{m}| < \epsilon$.
## Criterio di convergenza di Cauchy
Il **criterio di convergenza di Cauchy** asserisce che una successione $\{a_{n}\}$di numeri reali ha limite finito se e solo se è [di Cauchy](https://it.wikipedia.org/wiki/Successione_di_Cauchy "Successione di Cauchy"). In altre parole, se e solo se per ogni $\epsilon > 0$ esiste $N$ tale che $|a_{n} - a_{m} | < \epsilon$ per ogni $n, m > N$.

#Esempio 1.5.5

$$a_{n} = (1 + \frac{1}{n})^{n} \space \text{con} \space n \geq 1$$
$$a_{1} = 2 \quad a_{2} = \left(\frac{3}{2}^{2}\right) = \frac{9}{4} = 2,25 \quad a_{3} = (\frac{4}{3})^{3} = \frac{64}{27} = 2,\overline{370}$$
È una [[Algebra#Costruzione dei numeri reali|successione di Cauchy]] che non converge a un numero razionale

Con questa interpretazione, un numero reale che abbia sviluppo decimale:
$$723, 1291851\dots$$
Corrisponde ad una [[Algebra#Costruzione dei numeri reali|successione di Cauchy]] $(a_{n})$ di numeri razionali.
$$a_{1} = 723,1$$
$$a_{2} = 723,12$$
$$a_{3} = 723,129$$
$$a_{4} = 723,1291$$
$$\dots$$
$Def:$ Siano $a, b$ due numeri reali rappresentati da due [[Algebra#Costruzione dei numeri reali|successioni di Cauchy]] $(a_{n})$ e $(b_{n})$ di numeri razionali
La *somma* $a + b$ ed il *prodotto* $a \cdot b$ sono le [[Algebra#Costruzione dei numeri reali|successioni di Cauchy]] $(a_{n} + b_{n})$ e $(a_{n}b_{n})$.

## Numeri irrazionali
Esistono numeri in $\mathbb{R}\setminus\mathbb{Q}$ detti [[Algebra#Numeri irrazionali|numeri irrazionali]].

#proposizione 1.1.1. Il numero $\sqrt{2}$ non è razionale.

$Dimostrazione$: supponiamo, per assurdo, che $\sqrt{2}$ sia razionale.
Allora $\sqrt{2} = \frac{a}{b}$ dove $\frac{a}{b}$ è una frazione ridotta ai minimi termini.
$$2 = \frac{a^{2}}{b^{2}} \Rightarrow a^{2} = 2b^{2}$$
$\Rightarrow a^{2}$ è pari $\Rightarrow a$ è pari $\Rightarrow a = 2k$ per qualunque $k \in \mathbb{Z} \Rightarrow a^{2} = 4k^2$
$\Rightarrow b^{2}$ è pari $\Rightarrow b$ è pari
$\Rightarrow \frac{a}{b}$ non è semplificato ai minimi termini

$\mathbb{N, Z, Q, R}$ sono insiemi *ordinati*: esiste una notazione di maggiore o minore fra i numeri:
* $a = b$
* $a < b$
* $b < a \quad (a > b)$

