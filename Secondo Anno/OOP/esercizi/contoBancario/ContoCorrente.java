import java.util.ArrayList;

public class ContoCorrente {
  private int numeroCC; // Numero del conto corrente
  private int saldo; // Saldo attuale
  private ArrayList<Integer> movimenti; // Lista dei movimenti
  private int contatoreMovimenti; // Contatore dei movimenti

  // Costruttore: inizializza numero di CC e saldo
  public ContoCorrente(int numeroCC, int saldoIniziale) {
    this.numeroCC = numeroCC;
    this.saldo = saldoIniziale;
    this.movimenti = new ArrayList<>();
    this.contatoreMovimenti = 0;
  }

  // Metodo per prelevare un importo
  public void prelievo(int importo) {
    if (importo > 0 && importo <= saldo) {
      saldo -= importo;
      movimenti.add(-importo); // Registra il prelievo come negativo
      contatoreMovimenti++;
    } else {
      System.out.println("Errore: importo non valido o saldo insufficiente.");
    }
  }

  // Metodo per versare un importo
  public void versamento(int importo) {
    if (importo > 0) {
      saldo += importo;
      movimenti.add(importo); // Registra il versamento come positivo
      contatoreMovimenti++;
    } else {
      System.out.println("Errore: l'importo del versamento deve essere positivo.");
    }
  }

  // Metodo per restituire il saldo
  public int restituisciSaldo() {
    return saldo;
  }

  // Metodo per stampare la lista dei movimenti
  public void stampaMovimenti() {
    System.out.println("Lista dei movimenti per il conto " + numeroCC + ":");
    for (int movimento : movimenti) {
      System.out.println(movimento > 0 ? "+ " + movimento : "- " + Math.abs(movimento));
    }
    System.out.println("Totale movimenti: " + contatoreMovimenti);
  }
}
