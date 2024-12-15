public class Main {
    public static void main(String[] args) {
        // Dichiarazione di un array di tipo C
        C[] conti = new C[2];

        // Creazione di oggetti di tipo C e Ct
        conti[0] = new C(); // Oggetto della classe base C
        conti[1] = new Ct(15.0); // Oggetto della classe derivata Ct con tasse al 15%

        // Aggiunta di acquisti ai conti
        for (C conto : conti) {
            conto.aggiungiSpesa(100.0); // Aggiunge un acquisto di 100 a ogni conto
        }

        // Lettura dei conti
        for (C conto : conti) {
            // Comportamento polimorfico: chiama il metodo getContoParziale della classe effettiva
            System.out.printf("Conto parziale: %.2f € (%s)%n", conto.getContoParziale(), conto.getClass().getSimpleName());
        }
    }
}
