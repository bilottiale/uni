import unittest
import os
import json
from es_esame import Attivita, Progetto, Utente, Archivio

class TestGestioneProgetti(unittest.TestCase):

    def test_creazione_attivita(self):
        a = Attivita("Task1", "2025-06-01")
        self.assertEqual(a.nome, "Task1")
        self.assertEqual(a.stato, "Da fare")

    def test_aggiunta_attivita_a_progetto(self):
        p = Progetto("Prova", "2025-01-01", "2025-12-31")
        a = Attivita("Task1", "2025-02-01")
        p.aggiungi_attivita(a)
        self.assertEqual(len(p.attivita), 1)
        self.assertEqual(p.attivita[0].nome, "Task1")

    def test_modifica_stato(self):
        a = Attivita("Task1", "2025-05-01")
        a.modifica_stato("Completata")
        self.assertEqual(a.stato, "Completata")

    def test_salvataggio_e_caricamento(self):
        arch = Archivio()
        arch.utenti = []
        u = arch.crea_utente("Mario")
        p = Progetto("Progetto1", "2025-01-01", "2025-12-31")
        a = Attivita("TaskA", "2025-03-01")
        p.aggiungi_attivita(a)
        u.aggiungi_progetto(p)
        arch.salva()

        self.assertTrue(os.path.exists("backup.json"))
        with open("backup.json") as f:
            data = json.load(f)
        self.assertEqual(data[0]["nome"], "Mario")

        arch2 = Archivio()
        utente_caricato = arch2.get_utente("Mario")
        self.assertIsNotNone(utente_caricato)
        self.assertEqual(utente_caricato.nome, "Mario")

if __name__ == "__main__":
    unittest.main()
