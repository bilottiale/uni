public class Main {
    public static void main(String[] args) {
        // Dichiarazione di un array di tipo T
        T[] navigatori = new T[2];

        // Creazione di oggetti di tipo T e TF
        navigatori[0] = new T(100); // Oggetto della classe base T
        navigatori[1] = new TF(80, 30); // Oggetto della classe derivata TF

        // Calcolo del tempo di percorrenza per una distanza di 200 km
        double distanza = 200.0;

        for (T navigatore : navigatori) {
            // Comportamento polimorfico: chiama il metodo calcolaTempo della classe effettiva
            System.out.println("Tempo di percorrenza: " + navigatore.calcolaTempo(distanza) + " ore");
        }
    }
}
