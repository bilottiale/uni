public class Professore extends Persona {

  private String materia;

  public Professore(String nome, String cognome, int eta, String materia) {
    super(nome, cognome, eta);
    this.materia = materia;
  }

  public String getMateria() {
    return materia;
  }
}
