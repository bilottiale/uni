public class MainContoCorrente {
  public static void main(String[] args) {
    // Creazione di un vettore di 3 conti correnti
    ContoCorrente[] conti = new ContoCorrente[3];
    conti[0] = new ContoCorrente(1001, 5000);
    conti[1] = new ContoCorrente(1002, 3000);
    conti[2] = new ContoCorrente(1003, 10000);

    // Operazioni sui conti
    // Versamenti
    conti[0].versamento(2000);
    conti[1].versamento(1500);
    conti[2].versamento(500);

    // Prelievi
    conti[0].prelievo(1000);
    conti[1].prelievo(2000);
    conti[2].prelievo(700);

    // Stampa dei saldi
    System.out.println("Saldi finali:");
    for (ContoCorrente conto : conti) {
      System.out.println("Conto " + conto.restituisciSaldo());
    }

    // Stampa dei movimenti
    System.out.println("\nMovimenti dettagliati:");
    for (ContoCorrente conto : conti) {
      conto.stampaMovimenti();
    }
  }
}
