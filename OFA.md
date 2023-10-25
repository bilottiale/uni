* [[#Proprietà delle potenze]]
	* Scomposizione fattori primi
* Calcolo letterale:
	* [[#Calcolo letterale|Monomi]] e [[#polinomi]]
	* [[#Prodotti notevoli]]
	* Scomposizione polinomi
	* [[#Divisione tra polinomi]]
		* Ruffini
		* Colonna
		* Teorema del resto
	* Frazioni algebriche
* Equazioni e disequazioni di 1° grado:
	* Intere
	* Fratte
* Valore Assoluto o Modulo
* Sistemi di disequazioni
* Intro funzioni matematiche:
	* Definizione
	* Dominio/codominio
	* Funzioni pari e dispari
	* Crescenza e decrescenza
	* Funzioni inverse
	* Funzioni invertibile
	* Suriettiva
	* Biettiva
* Funzione lineare
	* Retta nel piano cartesiano
		* $y = mx + q$
* Sistemi di equazioni di 1° grado
* Calcoli con radicali:
	* Numerici
		* Letterali
* Parabola nel piano cartesiano
	* Equazioni di secondo grado
		* $y = Ax^{2} + Bx + C$
	* Disequazioni di secondo grado
		* Intere
		* Fratte
		* Parametriche
* Funzione esponenziale
	* Equazioni
	* Disequazioni
* Funzione logaritmica
	* Equazioni
	* Disequazioni
* Goniometria
* Trigonometria

# Proprietà delle potenze
Il prodotto di due potenze aventi la stessa base
$$A^{\textcolor{green}{x}} \cdot A^{\textcolor{green}{y}} = A^{\textcolor{green}{x}+\textcolor{green}{y}}$$
$$\textcolor{blue}{2^{3}} \textcolor{green}{\cdot 2^{2}} = \textcolor{blue}{2 \cdot  2 \cdot  2} \cdot  \textcolor{green}{2 \cdot  2}$$
Il quoziente di due potenze aventi la stessa base
$$A^{\textcolor{green}{x}} : A^{\textcolor{green}{y}} = A^{\textcolor{green}{x}-\textcolor{green}{y}}$$
$$\textcolor{blue}{2^{5}} \textcolor{green}{\cdot 2^{3}} = \frac{\textcolor{blue}{2^{5}}}{\textcolor{green}{2^{3}}} = \frac{\textcolor{blue}{2 \cdot  2 \cdot  \not2 \cdot \not2 \cdot \not2}} {\textcolor{green}{\not2 \cdot  \not2 \cdot \not2}} = 2^{\textcolor{blue}{5}-\textcolor{green}{3}} = 2^{2}$$
$$\text{con} \quad A \neq 0$$
In caso di potenza di potenza gli esponenti si moltiplicano
$$(A^{\textcolor{green}{x}})^{\textcolor{green}{y}} = A^{{\textcolor{green}{x}+\textcolor{green}{y}}}$$
$$(\textcolor{blue}{2^{3}})^{\textcolor{green}{2}} = \textcolor{blue}{2^{3}\cdot 2^{3}} = \textcolor{blue}{2 \cdot 2 \cdot  2 \cdot  2 \cdot  2 \cdot  2} = 2^{\textcolor{blue}{3} \cdot \textcolor{green}{2}} = 2^{6}$$
Prodotto stesso esponente base diversa
$$\textcolor{green}{A}^{x} \cdot \textcolor{green}{A}^{x} = (\textcolor{green}{AB})^{x}$$
$$\textcolor{blue}{2^{3}} \cdot \textcolor{green}{3^{3}} = \textcolor{blue}{ 2 \cdot  2 \cdot  2} \cdot \textcolor{green}{3 \cdot 3 \cdot  3} = 6 \cdot 6 \cdot 6 = 6^{3}$$
 Quoziente stesso esponente base diversa
 $$\textcolor{green}{A}^{x} : \textcolor{green}{A}^{x} = (\textcolor{green}{A:B})^{x}$$
$$\textcolor{blue}{10^{3}} : \textcolor{green}{5^{3}} = \frac{\textcolor{blue}{10^{3}}}{\textcolor{green}{5^{3}}} = \frac{\textcolor{blue}{10 \cdot 10 \cdot 10}}{\textcolor{green}{5 \cdot 5 \cdot 5}} = (\frac{10}{5})^{3} = 2^{3}$$
$$\text{con} \quad B \neq 0$$

# Calcolo letterale
Un *monomio* è un'espressione algebrica in cui compaiono solo moltiplicazioni tra numeri e lettere, eventualmente elevate ad esponente naturale.

Un monomio si dice scritto in *forma normale* quando è scritto come prodotto fra un numero e una o più lettere, diverse fra loro, eventualmente elevate a potenza.

Il *grado* di un monomio è la somma degli esponenti delle lettere che compaiono moltiplicate nel monomio mentre il *grado rispetto ad una lettera* è l'esponente a cui la lettera è elevata nel monomio.

Due monomi si dicono *simili* se hanno la stessa parte letterale.

La *somma algebrica* di 2 o più *monomi simili* è un monomio che ha la stessa parte letterale dei monomi sommati e per coefficiente la somma algebrica dei coefficienti.
$$2xy + 3xy = 5xy$$

Il *prodotto* di 2 o più monomi è un monomio in cui il coefficiente è il prodotto dei coefficienti e nella parte letterale ogni lettera ha per esponente la somma degli esponenti con cui compare nei fattori.
$$3a^{2}b \cdot 2a^{3}b^{7} = 6a^{5}b^{8}$$

Per calcolare la *potenza* con esponente $n(naturale)$ di un monomio basta elevare alla $n$ il coefficiente e moltiplicare per $n$ ognuno degli esponenti delle sue lettere.
$$(2xy^{2})^{3} = 8x^{3}y^{6}$$
#nb La potenza con esponente 1 di un monomio è uguale al monomio stesso.
$$(3ab)^{1} = 3ab$$
Elevare alla 0 un monomio nullo da come risultato 1.
$$(3ab)^{0} = 1$$
## Divisione tra monomi, mcm, MCD
Un monomio(dividendo) *è divisibile* per un altro monomio(divisore) se e solo se nel dividendo compaiono tutte le lettere del divisore elevate ad un esponente maggiore o uguale a quello che possiedono nel divisore. In questo caso il *quoziente* è un monomio che ha per coefficiente il quoziente dei coefficienti e in cui, nella parte letterale, ciascuna lettera ha per esponente la differenza tra l'esponente a cui è elevata nel dividendo e quello che possiede nel divisore.
$$6x^{3}y^{2} : (2xy) = 3x^{2}y$$

Il *minimo comune divisore*(mcm) di due o più monomi è un monomio che ha come coefficiente:
* l'mcm dei valori assoluti dei coefficienti, se i coefficienti sono interi
* il numero 1 se almeno uno dei coefficienti non è intero
e come parte letterale il prodotto di tutte le lettere presenti in almeno uno dei monomi, ciascuna presa una sola volta con l'esponente più grande disponibile.
$$3x^{2}y \quad 6xyz^{2} \quad -2x^{4}y^{3} \longrightarrow mcm: 6x^{4}y^{3}z^{2}$$
Il *massimo comune divisore*(MCD) di due o più monomi è un monomio che ha come coefficiente:
* l'MCD dei valori assoluti dei coefficienti, se i coefficienti sono interi
* il numero 1 se almeno uno dei coefficienti non è intero
e come parte letterale il prodotto delle sole lettere presenti in tutti i monomi, ciascuna presa una sola volta e con l'esponente più piccolo disponibile.
$$4x^{2}y \quad -6xyz^{2} \quad 2x^{4}y^{3} \longrightarrow MCD: 2xy$$

# Polinomi
Un *polinomio* è una somma algebrica di monomi.

Un polinomio si dice *ridotto in forma normale* se non compaiono monomi simili.

Il *grado* di un polinomio è il grado maggiore fra i gradi dei suoi termini.

La *somma* di due o più polinomi è il polinomio che he per termini tutti i termini dei polinomi addendi.
$$3x^{2}-7x+2 \textcolor{blue}{+} x^{2}-6x-4 = 4x^{2}- 13x - 2 $$

La *differenza* di due o più polinomi è il polinomio che si ottiene sommando al primo l'opposto del secondo.
$$3x^{2}-7x+2 \textcolor{blue}{-} (x^{2}-6x-4) = 2x^{2} - x + 6$$

Il *prodotto* di due polinomi è il polinomio che si ottiene moltiplicando ogni termine del primo polinomio per ciascun termine del secondo e sommando tutti i prodotti ottenuti.
$$(A+B)(C+D) = AC + AD + BC + BD$$

# Prodotti notevoli
*Quadrato di un binomio*
$$(A+B)^{2} = (A+B)(A+B) = A^{2}+AB+AB+B^{2}=A^{2}+2AB+B^{2}$$
*Somma per differenza*
$$(A+B)(A-B) = A^{2}-AB+AB+B^{2}=A^{2}+B^{2}$$
*Quadrato del trinomio*
$$(A+B+C)^{2} = (A+B+C)(A+B+C) =$$
$$A^{2}+AB+AC+AB+B^{2}+BC+AC+BC+C^{2}=$$
$$A^{2}+B^{2}+C^{2}+2AB+2AC+2BC$$

*Cubo del binomio*
$$(A+B)^{3} = (A+B)^{2}(A+B) = (A^{2}+2AB+B^{2})(A+B) =$$
$$(A^{3}+3A^{2}B+3AB^{2}+B^{3})$$

# Divisione tra polinomi
$$\textcolor{blue}{7}:\textcolor{green}{2} = \textcolor{yellow}{3} \quad \text{resto} \quad \textcolor{purple}{1}$$
Svolgere la divisione tra il polinomio $A(x)$ e il polinomio $B(x)$ (di grado $\leq$ del precedente) significa trovare due polinomi $Q(x)$ e $R(x)$ tali che:
$$\textcolor{blue}{A(x)} = \textcolor{green}{B(x)} \cdot \textcolor{yellow}{Q(x)} + \textcolor{purple}{R(x)}$$
Si può dimostrare che:
- il grado di $\textcolor{yellow}{Q(x)}$ è la differenza tra il grado di $\textcolor{blue}{A(x)}$ e quello di $\textcolor{green}{B(x)}$
- il grado di $\textcolor{purple}{R(x)}$ è minore del grado di $\textcolor{green}{B(x)}$

## Regola di Ruffini
L'algoritmo della divisione tra polinomi può essere semplificato quando il divisore è del tipo $x+b$. La versione semplificata dell'algoritmo, in cui si lavora solo sui coefficienti dei polinomi, è nota come *Regola di Ruffini*.

## Teorema di Ruffini e Teorema del Resto

## Scomposizione di polinomi
Ogni polinomio $P(x)$ a coefficienti reali è irriducibile o si può scrivere come *prodotto di polinomi di primo e di secondo grado eventualmente ripetuti*.

*Raccoglimento totale*:
$$x(x+3) = x \cdot x + x \cdot 3 = x^{2}+3x \quad x^{2}+3 = \textcolor{blue}{x} \cdot x + \textcolor{blue}{x} \cdot 3 = \textcolor{blue}{x}(x+3)$$

*Raccoglimento parziale*:
$$x^{3}+x^{2}+2x+2 = x^{2}\textcolor{blue}{(x+1)}+2\textcolor{blue}{(x+1)} = (x+1)(x^{2}+2)$$

## Scomposizione: prodotti notevoli e trinomio di II grado
*Prodotti notevoli*:

