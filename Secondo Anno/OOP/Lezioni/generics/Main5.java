public class Main5 {
    public static void main(String argv[]) {
        Studente s1 = new Studente("Luca", "Ferrari", 26, 41191);
        Studente s2 = new Studente("Santi", "Caballe", 29, 21192);
        Studente s3 = new Studente("James", "Gosling", 50, 41193);
        Professore pr1 = new Professore("Silvia", "Rossi", 27, "Analisi");
        Professore pr2 = new Professore("Simon", "Ritter", 40, "OOP");
        Archivio5<Studente, Professore> archivio = new Archivio5<Studente, Professore>();
        archivio.aggiungi(s1);
        archivio.aggiungi(s2);
        archivio.aggiungi(s3);
        archivio.aggiungiRelazione(s1, pr1);
        archivio.aggiungiRelazione(s2, pr2);
        archivio.stampaRelazioni();
    }
} // fine della classe
