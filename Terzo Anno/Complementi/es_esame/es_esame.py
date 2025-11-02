import json
import sys

class Attivita:
    def __init__(self, nome, data_prevista, stato="Da fare"):
        self.nome = nome
        self.data_prevista = data_prevista
        self.stato = stato

    def modifica_stato(self, nuovo_stato):
        if nuovo_stato in ["Da fare", "In corso", "Completata"]:
            self.stato = nuovo_stato
        else:
            print("Stato non valido")

    def to_dict(self):
        return {
            "nome": self.nome,
            "data_prevista": self.data_prevista,
            "stato": self.stato
        }

    @staticmethod
    def from_dict(d):
        return Attivita(d["nome"], d["data_prevista"], d["stato"])


class Progetto:
    def __init__(self, nome, data_inizio, data_scadenza):
        self.nome = nome
        self.data_inizio = data_inizio
        self.data_scadenza = data_scadenza
        self.attivita = []

    def aggiungi_attivita(self, attivita):
        if attivita.data_prevista > self.data_scadenza:
            print("Errore: data prevista oltre la scadenza del progetto")
        else:
            self.attivita.append(attivita)

    def riepilogo(self):
        print(f"\nProgetto: {self.nome}")
        for a in self.attivita:
            print(f"- {a.nome} | Prevista: {a.data_prevista} | Stato: {a.stato}")

    def to_dict(self):
        return {
            "nome": self.nome,
            "data_inizio": self.data_inizio,
            "data_scadenza": self.data_scadenza,
            "attivita": [a.to_dict() for a in self.attivita]
        }

    @staticmethod
    def from_dict(d):
        p = Progetto(d["nome"], d["data_inizio"], d["data_scadenza"])
        p.attivita = [Attivita.from_dict(x) for x in d["attivita"]]
        return p


class Utente:
    def __init__(self, nome):
        self.nome = nome
        self.progetti = []

    def aggiungi_progetto(self, progetto):
        self.progetti.append(progetto)

    def get_progetto(self, nome):
        for p in self.progetti:
            if p.nome == nome:
                return p
        return None

    def to_dict(self):
        return {
            "nome": self.nome,
            "progetti": [p.to_dict() for p in self.progetti]
        }

    @staticmethod
    def from_dict(d):
        u = Utente(d["nome"])
        u.progetti = [Progetto.from_dict(x) for x in d["progetti"]]
        return u


class Archivio:
    FILE = "backup.json"

    def __init__(self):
        self.utenti = []
        self.carica()

    def carica(self):
        try:
            with open(self.FILE, "r") as f:
                data = json.load(f)
                self.utenti = [Utente.from_dict(x) for x in data]
        except FileNotFoundError:
            self.utenti = []

    def salva(self):
        with open(self.FILE, "w") as f:
            json.dump([u.to_dict() for u in self.utenti], f, indent=2)

    def get_utente(self, nome):
        for u in self.utenti:
            if u.nome == nome:
                return u
        return None

    def crea_utente(self, nome):
        u = Utente(nome)
        self.utenti.append(u)
        return u


def esporta_progetto(utente_nome, progetto_nome, file_output):
    arch = Archivio()
    utente = arch.get_utente(utente_nome)
    if not utente:
        print("Utente non trovato")
        return
    progetto = utente.get_progetto(progetto_nome)
    if not progetto:
        print("Progetto non trovato")
        return

    with open(file_output, "w") as f:
        f.write(f"Progetto: {progetto.nome}\n")
        f.write(f"Inizio: {progetto.data_inizio}\n")
        f.write(f"Scadenza: {progetto.data_scadenza}\n\n")
        f.write("Attività:\n")
        for a in progetto.attivita:
            f.write(f"- {a.nome} | {a.data_prevista} | Stato: {a.stato}\n")
    print("Esportazione completata")


def menu():
    arch = Archivio()
    nome = input("Inserisci nome utente: ")
    utente = arch.get_utente(nome) or arch.crea_utente(nome)

    while True:
        print("\n1. Crea nuovo progetto")
        print("2. Aggiungi attività")
        print("3. Modifica stato attività")
        print("4. Riepilogo progetto")
        print("5. Salva ed esci")
        scelta = input("> ")

        if scelta == "1":
            nome_p = input("Nome progetto: ")
            di = input("Data inizio (YYYY-MM-DD): ")
            ds = input("Data scadenza (YYYY-MM-DD): ")
            utente.aggiungi_progetto(Progetto(nome_p, di, ds))

        elif scelta == "2":
            nome_p = input("Progetto: ")
            p = utente.get_progetto(nome_p)
            if not p:
                print("Progetto non trovato")
                continue
            nome_a = input("Nome attività: ")
            dp = input("Data prevista (YYYY-MM-DD): ")
            p.aggiungi_attivita(Attivita(nome_a, dp))

        elif scelta == "3":
            nome_p = input("Progetto: ")
            p = utente.get_progetto(nome_p)
            if not p:
                print("Progetto non trovato")
                continue
            nome_a = input("Nome attività: ")
            for a in p.attivita:
                if a.nome == nome_a:
                    stato = input("Nuovo stato (Da fare/In corso/Completata): ")
                    a.modifica_stato(stato)
                    break

        elif scelta == "4":
            nome_p = input("Progetto: ")
            p = utente.get_progetto(nome_p)
            if p:
                p.riepilogo()

        elif scelta == "5":
            arch.salva()
            print("Dati salvati. Uscita.")
            break


if __name__ == "__main__":
    if len(sys.argv) == 4:
        _, utente, progetto, file_output = sys.argv
        esporta_progetto(utente, progetto, file_output)
    else:
        menu()
