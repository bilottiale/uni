public class Main {
    public static void main(String[] args) {
        // Dichiarazione di un array di tipo P
        P[] particelle = new P[2];

        // Creazione di oggetti di tipo P e PQ
        particelle[0] = new P(300_000); // Oggetto della classe base P
        particelle[1] = new PQ(200_000, 30.0); // Oggetto della classe derivata PQ

        // Simulazione del calcolo della distanza per un tempo di 2 secondi
        double tempo = 2.0;

        for (P particella : particelle) {
            // Comportamento polimorfico: chiama il metodo calcolaDistanza della classe effettiva
            double distanza = particella.calcolaDistanza(tempo);
            System.out.println("Distanza percorsa: " + distanza + " km (" + particella.getClass().getSimpleName() + ")");
        }
    }
}
