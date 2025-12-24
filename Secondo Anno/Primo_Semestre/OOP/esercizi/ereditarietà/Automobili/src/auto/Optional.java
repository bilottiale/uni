package auto;

public class Optional {
  private String codice, descrizione;
  private int valore;

  public Optional(String codice, String descrizione, int valore) {
    this.codice = codice;
    this.descrizione = descrizione;
    this.valore = valore;
  }

  @Override
  public String toString() {
    return "Codice: " + codice + ", Descrizione: " + descrizione + ", Valore: " + valore;
  }
}
