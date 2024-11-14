# Eventi indipendenti
Due eventi $( E, F \in \digamma )$ in uno spazio di probabilità $( (S, \digamma, \mathbb{P}) )$ sono *indipendenti* sotto $( \mathbb{P} )$ se:
$$
\mathbb{P}(E \cap F) = \mathbb{P}(E)\mathbb{P}(F)
$$
**Casi di indipendenza:**
1. **Indipendenza banale:** quando $( \mathbb{P}(E) = 0 )$ o $( \mathbb{P}(F) = 0 )$.
   - Per monotonia, $( \mathbb{P}(E \cap F) = 0 )$.
2. **Indipendenza significativa:** quando $( \mathbb{P}(E) > 0 )$ e $( \mathbb{P}(F) > 0 )$, e si ha:
   $$
   \mathbb{P}(E|F) = \mathbb{P}(E) \quad \text{e} \quad \mathbb{P}(F|E) = \mathbb{P}(F)
   $$
**Notazioni:**
- $( E \unicode{x2AEB} F )$: indica indipendenza tra $( E )$ e $( F )$.
- $( E \unicode{x2AEB}_{\mathbb{F}} F )$: indica indipendenza rispetto a una probabilità $( \mathbb{P} )$.
- $( E \not\unicode{x2AEB} F )$: indica dipendenza tra $( E )$ e $( F )$.
**Tipi di dipendenza:**
- **Dipendenza favorevole:** $( \mathbb{P}(E \cap F) > \mathbb{P}(E)\mathbb{P}(F) )$.
- **Dipendenza sfavorevole:** $( \mathbb{P}(E \cap F) < \mathbb{P}(E)\mathbb{P}(F) )$.
**Esempio: Lancio di un dado:**
Eventi $( A )$ ("primi") e $( B )$ ("pari"):
- $( \mathbb{P}(A) = \frac{1}{2} )$, $( \mathbb{P}(B) = \frac{1}{2} )$.
- $( \mathbb{P}(A \cap B) = \frac{1}{6} < \frac{1}{4} )$ ⟹ $( A \not\unicode{x2AEB} B )$ (dipendenza sfavorevole).
## Invarianza per negazione
- Se $( E \unicode{x2AEB} F )$, allora $( E \unicode{x2AEB} \overline{F} )$ e viceversa.
- Indipendenza tra due eventi è una relazione simmetrica.
 **Esempi di circuiti elettrici:**
- **Serie:** corrente passa se entrambi gli interruttori sono chiusi.
  - $( \mathbb{P}(C_1 \cap C_2) = p^2 )$.
- **Parallelo:** corrente passa se almeno un interruttore è chiuso.
  - $( \mathbb{P}(\text{corrente}) = 1 - (1 - p)^2 )$.
### Simulazione in R per la probabilità condizionata
Calcolo della probabilità condizionata per due dadi:
1. Stima di $( \mathbb{P}(A \cap B) )$ con simulazione.
2. Stima di $( \mathbb{P}(B) )$.
3. Probabilità condizionata: $( \mathbb{P}(A | B) = \mathbb{P}(A \cap B) / \mathbb{P}(B) )$.
```r
# Stima della probabilità che la somma dei dadi sia almeno 10 e almeno uno dei dadi sia un 6
eventAB <- replicate(10000, {
  dieRoll <- sample(1:6, 2, replace = TRUE)
  (sum(dieRoll) >= 10) && (6 %in% dieRoll)
})
probAB <- mean(eventAB)

# Stima della probabilità che almeno uno dei dadi sia un 6
eventB <- replicate(10000, {
  dieRoll <- sample(1:6, 2, replace = TRUE)
  6 %in% dieRoll
})
probB <- mean(eventB)

# Calcolo della probabilità condizionata
conditional_prob <- probAB / probB
conditional_prob
```
