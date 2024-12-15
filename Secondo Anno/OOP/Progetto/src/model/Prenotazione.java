package model;

import java.time.LocalDate;
import java.time.LocalTime;

public class Prenotazione {
    private int idAula;
    private LocalDate data;
    private LocalTime oraInizio;
    private LocalTime oraFine;
    private String nomePrenotante;
    private String motivazione;
    

    // Costruttore che accetta LocalDate e LocalTime
    public Prenotazione(int idAula, LocalDate data, LocalTime oraInizio, LocalTime oraFine, String nomePrenotante, String motivazione) {
        this.idAula = idAula;
        this.data = data;
        this.oraInizio = oraInizio;
        this.oraFine = oraFine;
        this.nomePrenotante = nomePrenotante;
        this.motivazione = motivazione;
    }

    // Getters
    public int getIdAula() {
        return idAula;
    }

    public LocalDate getData() {
        return data;
    }

    public LocalTime getOraInizio() {
        return oraInizio;
    }

    public LocalTime getOraFine() {
        return oraFine;
    }

    public String getNomePrenotante() {
        return nomePrenotante;
    }

    public String getMotivazione() {
        return motivazione;
    }

    // Setters
    public void setIdAula(int idAula) {
        this.idAula = idAula;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public void setOraInizio(LocalTime oraInizio) {
        this.oraInizio = oraInizio;
    }

    public void setOraFine(LocalTime oraFine) {
        this.oraFine = oraFine;
    }

    public void setNomePrenotante(String nomePrenotante) {
        this.nomePrenotante = nomePrenotante;
    }

    public void setMotivazione(String motivazione) {
        this.motivazione = motivazione;
    }

    @Override
    public String toString() {
        return "Prenotazione{" +
                "idAula=" + idAula +
                ", data=" + data +
                ", oraInizio=" + oraInizio +
                ", oraFine=" + oraFine +
                ", nomePrenotante='" + nomePrenotante + '\'' +
                ", motivazione='" + motivazione + '\'' +
                '}';
    }
}
