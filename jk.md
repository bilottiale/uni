Dimostrare che: $\forall n\geq 0$ se $X$ è l'insieme di $n$ elementi, allora ha $2^{n}$ sottoinsiemi
$$\forall n\geq 0\quad (\forall X(|X|=n\to|Q(X)|=2^{n}))$$
Con $|Q(x)|=\{A|A\subseteq X\}$
***Dimostrazione***
Per *induzione* su $n\geq 0$:
- *Base induttiva* ($n=0$), bisogna dimostrare che:
$$|X|=0\to|P(X)|=2^{0}=1$$
Per fare ciò utilizziamo una *dimostrazione diretta*:
$$|X|=0 \text{ allora } X=\{\ \}=\varnothing$$
> [Principio di estensionalità]
> Infatti per qualsiasi $A,B \ \ \ A=B$ se e solo se $\forall X(X\in A\leftrightarrow X\in B)$

Quindi:
$$|P(\varnothing)| = |\{\varnothing\}|=1$$
- *Passo induttivo*:
Si prende l'enunciato $(\forall X(|X|=n\to|Q(X)|=2^{n}))=Q(n)$
Quindi dobbiamo dimostrare in *modo diretto*:
$$\forall n\geq 0\quad (Q(n)\to Q(n+1))$$
Sia $n\geq 0$ generico, assumiamo $Q(n)$, cioè
$$\forall x(|X|=n\to|P(X)|=2^{n})\longleftarrow\text{ipotesi induttiva}$$
Dimostriamo $Q(n+1)$:
$$\forall X(|X|=n+1\to|P(X)|=2^{n+1})$$
Quindi se $|X|=1$ vediamo che:
$$Y\cup\{*\}$$
> $*$ è l'elemento "$+1$" che aggiungiamo incrementando

Dove $|Y|=n, *\not\in Y$
Quindi $Y=X-\{*\}$
Per *ipotesi induttiva*:
$$|P(X)|=2^{n},\text{ perché }|Y|=n$$
Prendiamo ciascuna $A\subseteq Y$ e aggiungiamo $*$, prendiamo $A\cup\{*\}\subseteq X$.
Questo crea $2^{n}$ sottoinsiemi di $X$, che sono *tutti* i sottoinsiemi di $X$ che contengono $*$,
$$P(X)=\underbrace{P(Y)\cup\{A\cup\{*\}|A\in P(Y)\}}_{2^{n}+2^{n}=2^{n+1}}$$
Quindi $|P(X)| = |P(Y)\cup\{A\cup\{*\}|A\in P(Y)\}|$
Questo conclude la dimostrazione del *passo induttivo* par un'applicazione del principio di induzione. Possiamo concludere:
$$\forall n\geq 0\quad(\forall X(|X|=n\to|Q(X)|=2^{n}))$$