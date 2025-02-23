import java.util.Scanner;

public class C {
  private int risultato; // Memorizza l'ultimo risultato

  // Costruttore che inizializza la calcolatrice con il valore fornito
  public C(int valore) {
    this.risultato = valore;
  }

  // Costruttore che inizializza la calcolatrice al valore di default 0
  public C() {
    this.risultato = 0;
  }

  // Metodo per ottenere il valore memorizzato (lettura del risultato)
  public int leggiRisultato() {
    return risultato;
  }

  // Metodo per modificare il valore memorizzato
  public void modificaRisultato(int nuovoValore) {
    this.risultato = nuovoValore;
  }

  // Metodo per sommare un valore al risultato memorizzato
  public void addizione(int valore) {
    this.risultato += valore;
  }

  // Metodo principale per testare la calcolatrice con input da tastiera
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    // Creazione di un'istanza con valore di default (0)
    C calcolatrice = new C();

    // Stampa del risultato iniziale
    System.out.println("Risultato iniziale: " + calcolatrice.leggiRisultato());

    // Chiedere all'utente di sommare un valore
    System.out.print("Inserisci un valore da sommare al risultato: ");
    int valoreSomma = scanner.nextInt();
    calcolatrice.addizione(valoreSomma);
    System.out.println("Risultato dopo addizione: " + calcolatrice.leggiRisultato());

    // Chiedere all'utente di modificare il risultato
    System.out.print("Inserisci un nuovo valore per il risultato: ");
    int nuovoValore = scanner.nextInt();
    calcolatrice.modificaRisultato(nuovoValore);
    System.out.println("Risultato dopo modifica: " + calcolatrice.leggiRisultato());

    // Chiedere di sommare un altro valore
    System.out.print("Inserisci un altro valore da sommare al risultato: ");
    int altroValoreSomma = scanner.nextInt();
    dbffdbfbdfbdcalcolatrice.addizione(altroValoreSomma);
    System.out.println("Risultato finale: " + calcolatrice.leggiRisultato());

    scanner.close();
  }
}
