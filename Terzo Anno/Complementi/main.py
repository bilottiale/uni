# Classi e Funzioni in Python
def saluta(nome):
    print(f"Ciao, {nome}!")

class Persona:
    def __init__(self, nome):
        self.nome = nome

    def saluta(self):
        print(f"Ciao, {self.nome}!")

p = Persona("Luca")
p.saluta()  # Ciao, Luca!

# Funzioni e metodi di confronto
class Esempio:
    def normale(self):
        print("Metodo normale chiamato: ", self)

    @ classmethod
    def di_classe(cls):
        print("Metodo di classe chiamato: ", cls)

    @staticmethod
    def statico():
        print("Metodo statico chiamato")

Esempio.normale(Esempio())  # Metodo normale chiamato:  <__main__.Esempio object at ...>
Esempio.di_classe()    # Metodo di classe chiamato:  <class '__main__.Esempio'>
Esempio.statico()      # Metodo statico chiamato

# Le "classi" raggruppano le Funzioni
# Funzioni definite separatamente
def sposta_x(punto, dx):
    punto['x'] += dx
    return punto

def sposta_y(punto, dy):
    punto['y'] += dy
    return punto

# Funzioni raggruppate in una classe
class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self): # richimato automaticamente da print()
        return f"({self.x}, {self.y})"

    def __eq__(self, other): # richiamato automaticamente da ==
        return self.x == other.x and self.y == other.y

# Creazione di due punti
p1 = Punto(3, 4)
p2 = Punto(3, 4)
p3 = Punto(1, 2)

# Stampa dei punti
print(p1)   # (3, 4)
print(p2)
print(p3)   # (1, 2)

# Confronto di uguaglianza
print("p1 e p2 sono uguali? ", p1 == p2)  # True
print("p1 e p3 sono uguali? ", p1 == p3)  # False

# Ereditarietà e riuso di funzioni
def area_quadrato(lato):
    return lato * lato

class Rettangolo:
    def __init__(self, base, altezza):
        self.base = base
        self.altezza = altezza

    def area(self):
        return self.base * self.altezza

class Quadrato(Rettangolo):
    def __init__(self, lato):
        super().__init__(lato, lato)

# Proprietà e incapsulamento
# Funzioni "setter" e "getter" si implementano con decoratori @property
class Conto:
    def __init__(self, saldo):
        self._saldo = saldo  # attributo "privato"

    @property
    def saldo(self):
        return self._saldo

    @saldo.setter
    def saldo(self, valore):
        if valore < 0:
            raise ValueError("Il saldo non può essere negativo")
        self._saldo = valore

c1 = Conto(100)
c1.saldo = 150  # usa il setter
#c2 = Conto(200)
#c2.saldo = -100  # genera ValueError
print("Saldo c1:", c1.saldo)  # usa il getter

# Funzioni = comportamento singolo
# Classi = struttura dati + comportamento
# Oggetti = istanze concrete con uno stato

class Esempio1:
    def __init__(self, valore):
        self.valore = valore

    def __getattr__(self, nome):
        print(f"Accesso all'attributo inesistente: {nome}")
        return f"[Valore finto per '{nome}']"

obj = Esempio1(5)
print(obj.valore)     # → 5  (esiste)
print(obj.altro)      # → Accesso all'attributo inesistente: altro
                      #    [Valore finto per 'altro']















