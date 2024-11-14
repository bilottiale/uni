public class SubC extends C {

  // Costruttore che inizializza SubC con un valore specifico
  public SubC(int valore) {
    super(valore); // Chiama il costruttore della classe base (C)
  }

  // Costruttore che inizializza SubC al valore di default 0
  public SubC() {
    super(); // Chiama il costruttore di default della classe base (C)
  }

  // Sovrascrittura del metodo addizione per segnalare errore con valori negativi
  @Override
  public void addizione(int valore) {
    if (valore < 0) {
      System.out.println("Errore: non è possibile sommare un valore negativo.");
    } else {
      super.addizione(valore); // Chiama il metodo addizione della classe base se il valore è positivo
    }
  }

  // Metodo per sottrarre un valore dal risultato memorizzato
  public void sottrazione(int valore) {
    modificaRisultato(leggiRisultato() - valore);
  }
}
