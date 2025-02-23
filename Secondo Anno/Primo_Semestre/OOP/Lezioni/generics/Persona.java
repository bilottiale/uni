public class Persona {
  private String nome, cognome;
  private int eta;

  public Persona(String nome, String cognome, int eta) {
    this.nome = nome;
    this.cognome = cognome;
    this.eta = eta;
  }

  public String toString() {
    return nome + " " + cognome + " " + eta;
  }
}
