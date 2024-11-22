public class Contatto {
  private String nome;
  private String cognome;
  private String indirizzo;
  private String telefono;

  // Costruttore
  public Contatto(String nome, String cognome, String indirizzo, String telefono) {
    this.nome = nome;
    this.cognome = cognome;
    this.indirizzo = indirizzo;
    this.telefono = telefono;
  }

  // Getters
  public String getNome() {
    return nome;
  }

  public String getCognome() {
    return cognome;
  }

  public String getIndirizzo() {
    return indirizzo;
  }

  public String getTelefono() {
    return telefono;
  }
}
