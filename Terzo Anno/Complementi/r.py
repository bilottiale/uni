from abc import ABC, abstractmethod

# ---------------------------
# Decoratore personalizzato simile a @property (solo getter)
# ---------------------------
def mio_property(func):
    class Descriptor:
        def __get__(self, instance, owner):
            return func(instance)
    return Descriptor()

# ---------------------------
# Descriptor per l'attributo malato
# ---------------------------
class MalatoDescriptor:
    def __get__(self, instance, owner):
        if instance.spavaldo:
            return False
        return instance._malato

    def __set__(self, instance, value):
        instance._malato = value

# ---------------------------
# Classe astratta Animale
# ---------------------------
class Animale(ABC):
    def __init__(self, eta=0):
        self.eta = eta

    def muovi(self):
        print("Mi sto muovendo...")

    @abstractmethod
    def fai_verso(self):
        pass

# ---------------------------
# Classe Cane
# ---------------------------
class Cane(Animale):
    numero_cani = 0

    malato = MalatoDescriptor()  # descriptor

    def __init__(self, sesso, eta=0):
        super().__init__(eta)
        self.sesso = sesso
        self.zampe = 4
        self.coda = True
        self._malato = False
        self.spavaldo = False
        Cane.numero_cani += 1

    # ---------------------------
    # Metodi di classe
    # ---------------------------
    @classmethod
    def quante_istanze(cls):
        return cls.numero_cani

    # ---------------------------
    # Metodi generali
    # ---------------------------
    def abbaia(self):
        print("Bau Bau!")

    def cammina(self):
        print("Sto camminando...")

    def corri(self):
        print("Sto correndo velocemente!")

    # ---------------------------
    # Property
    # ---------------------------
    @property
    def spavaldo(self):
        return self._spavaldo

    @spavaldo.setter
    def spavaldo(self, valore):
        self._spavaldo = valore

    # ---------------------------
    # Override metodo astratto
    # ---------------------------
    def fai_verso(self):
        self.abbaia()

    # ---------------------------
    # Operatore +
    # ---------------------------
    def __add__(self, altro):
        if self.sesso != altro.sesso and self.eta > 1 and altro.eta > 1:
            return Cane(sesso="maschio" if self.sesso=="femmina" else "femmina", eta=0)
        else:
            print("Non è possibile avere un cucciolo!")
            return None

# ---------------------------
# Classe Gatto
# ---------------------------
class Gatto(Animale):
    def __init__(self, eta=0):
        super().__init__(eta)

    def fai_verso(self):
        print("Miao Miao!")

# ---------------------------
# Esempio di utilizzo
# ---------------------------
if __name__ == "__main__":
    # Creazione cani
    cane1 = Cane("maschio", eta=3)
    cane2 = Cane("femmina", eta=4)

    print("Numero di cani:", Cane.quante_istanze())

    # Metodi
    cane1.abbaia()
    cane1.cammina()
    cane1.corri()

    # Operatore +
    cucciolo = cane1 + cane2
    if cucciolo:
        print(f"È nato un cucciolo di sesso {cucciolo.sesso}")

    # Attributi privati con descriptor
    cane1.spavaldo = True
    cane1.malato = True
    print("Cane1 malato?", cane1.malato)  # → False perché spavaldo=True

    # Classe astratta e metodi fai_verso
    gatto = Gatto(eta=2)
    gatto.fai_verso()

    # Decoratore personalizzato simile a @property
    class Prova:
        def __init__(self, valore):
            self._valore = valore

        @mio_property
        def valore(self):
            return self._valore

    p = Prova(42)
    print("Valore decoratore personalizzato:", p.valore)

#                ┌───────────────────┐
#                │     Animale       │  <-- Classe astratta
#                ├───────────────────┤
#                │ - eta              │
#                ├───────────────────┤
#                │ + muovi()          │
#                │ + fai_verso()      │  # astratto
#                └───────────────────┘
#                        ▲
#                        │
#        ┌──────────────┴───────────────┐
#        │                              │
#    ┌───────────────┐             ┌───────────────┐
#    │     Cane      │             │     Gatto     │
#    ├───────────────┤             ├───────────────┤
#    │ - sesso       │             │                │
#    │ - zampe=4     │             │                │
#    │ - coda=True   │             │                │
#    │ - _malato     │             │                │
#    │ - _spavaldo   │             │                │
#    │ + numero_cani │             │                │
#    ├───────────────┤             ├───────────────┤
#    │ + abbaia()    │             │ + fai_verso() │  # Miao Miao!
#    │ + cammina()   │             │                │
#    │ + corri()     │             │                │
#    │ + fai_verso() │             │                │
#    │ + __add__(Cane)│            │                │
#    │ + quante_istanze()│          │                │
#    │ + malato (descriptor) │      │                │
#    │ + spavaldo (property) │       │                │
#    └───────────────┘             └───────────────┘
