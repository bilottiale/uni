import java.sql.Date;

public class Prenotazione {
    private int id;
    private String aula;
    private String data;
    private String oraInizio;
    private String oraFine;
    private String utente;

    // Costruttore
    public Prenotazione(int id, String aula, String data, String oraInizio, String oraFine, String utente) {
        this.id = id;
        this.aula = aula;
        this.data = data;
        this.oraInizio = oraInizio;
        this.oraFine = oraFine;
        this.utente = utente;
    }

    // Getter e Setter
    public int getId() { return id; }
    public String getAula() { return aula; }
    public String getData() { return data; }
    public String getOraInizio() { return oraInizio; }
    public String getOraFine() { return oraFine; }
    public String getUtente() { return utente; }
}
