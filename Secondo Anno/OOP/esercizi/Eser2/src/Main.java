public class Main {
    public static void main(String[] args) {
        // Creazione di un rettangolo
        R r = new R(10, 20);
        System.out.println("Dettagli del rettangolo:");
        r.stampaDettagli();

        // Creazione di un quadrato
        Q q = new Q(5);
        System.out.println("\nDettagli del quadrato:");
        q.stampaDettagli();

        // Modifica dei lati del rettangolo
        System.out.println("\nModifica dei lati del rettangolo:");
        r.modificaLati(12, 15);
        r.stampaDettagli();

        // Tentativo di modifica dei lati del quadrato con valori non validi
        System.out.println("\nTentativo di modifica dei lati del quadrato:");
        q.modificaLati(5, 7); // Errore: i lati devono essere uguali
        q.stampaDettagli();

        // Modifica del lato del quadrato con un valore valido
        System.out.println("\nModifica del lato del quadrato:");
        q.modificaLato(6);
        q.stampaDettagli();

        // Polimorfismo
        System.out.println("\nEsempio di polimorfismo:");
        R rettangoloPolimorfico = new Q(8); // Oggetto Q trattato come R
        rettangoloPolimorfico.stampaDettagli(); // Viene usato il metodo di R
    }
}
