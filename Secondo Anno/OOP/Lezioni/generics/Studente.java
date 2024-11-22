public class Studente extends Persona {
  private int matricola;

  public Studente(String nome, String cognome, int eta, int matricola) {
    super(nome, cognome, eta);
    this.matricola = matricola;
  }

  public int getMatricola() {
    return matricola;
  }
}
