public class Main {
    public static void main(String[] argv) {
        Studente s1 = new Studente("Luca", "Ferrari", 26, 41191);
        Studente s2 = new Studente("Santi", "Caballe", 29, 21192);
        Studente s3 = new Studente("James", "Gosling", 50, 41193);
        Professore p1 = new Professore("Silvia", "Rossi", 27, "Analisi");
        Professore p2 = new Professore("Simon", "Ritter", 40, "OOP");

        Archivio1 archivioProf = new Archivio1();
        Archivio1 archivioStud = new Archivio1();

        archivioProf.aggiungi(p1);
        archivioProf.aggiungi(p2);
        // archivioProf.aggiungi(s1); // Errore in compilazione

        archivioStud.aggiungi(s1);
        archivioStud.aggiungi(s2);
        archivioStud.aggiungi(s3);
        // archivioStud.aggiungi(p1); // Errore in compilazione

        Archivio2<Professore> archivioProf2 = new Archivio2<Professore>();
        Archivio2<Studente> archivioStud2 = new Archivio2<Studente>();

        archivioProf2.aggiungi(p1);
        archivioProf2.aggiungi(p2);
        // archivioProf2.aggiungi(s1); // Errore in compilazione

        archivioStud2.aggiungi(s1);
        archivioStud2.aggiungi(s2);
        archivioStud2.aggiungi(s3);
        // archivioStud2.aggiungi(p1); // Errore in compilazione

        //! archivioProf
        // Stampa professori
        for (int i = 0; i < archivioProf.size(); i++) {
            Professore p = (Professore) archivioProf.getPersona(i);
            System.out.println("Professore " + i + ": " + p + ", Materia: " + p.getMateria());
        }

        //! archivioStud
        // Stampa studenti
        for (int i = 0; i < archivioStud.size(); i++) {
            Studente s = (Studente) archivioStud.getPersona(i);
            System.out.println("Studente " + i + ": " + s + ", Matricola: " + s.getMatricola());
        }

        System.out.println();

        //! archivioProf2
        // Stampa professori
        for (int i = 0; i < archivioProf2.size(); i++) {
            Professore p = archivioProf2.get(i);
            System.out.println("Professore " + i + ": " + p + ", Materia: " + p.getMateria());
        }

        //! archivioStud2
        // Stampa studenti
        for (int i = 0; i < archivioStud2.size(); i++) {
            Studente s = archivioStud2.get(i);
            System.out.println("Studente " + i + ": " + s + ", Matricola: " + s.getMatricola());
        }
    }
}
