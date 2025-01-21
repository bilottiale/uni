package model;

import model.Aula;
import java.time.LocalDate;
import java.time.LocalTime;

public class Prenotazione {
    LocalDate data;
    LocalTime oraInizio;
    LocalTime oraFine;
    String prenotante;
    String motivazione;
    private Aula aula;

    // format time
    public Prenotazione(LocalDate data, LocalTime oraInizio, LocalTime oraFine, String prenotante, String motivazione, Aula aula) {
        this.data = data;
        this.oraInizio = oraInizio;
        this.oraFine = oraFine;
        this.prenotante = prenotante;
        this.motivazione = motivazione;
        this.aula = aula;
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
        return prenotante;
    }

    public String getMotivazione() {
        return motivazione;
    }

    public Aula getAula() {
        return aula;
    }

    @Override
    public String toString() {
        return "Prenotazione [Data: " + data + ", Ora inizio: " + oraInizio + ", Ora fine: " + oraFine + ", Nome: "
                + prenotante + ", Motivazione: " + motivazione + ", Aula: " + aula.toString() + "]";
    }
}
