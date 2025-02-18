package model;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Prenotazione {
    private int nAula;
    private LocalDate data;
    private LocalTime inizio;
    private LocalTime fine;
    private String nome;
    private String motivazione;

    public Prenotazione(int nAula, LocalDate data, LocalTime inizio, LocalTime fine, String nome, String motivazione) {
        // DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        // DateTimeFormatter timeFormatter = DateTimeFormatter.ofPattern("HH:mm");

        if (inizio.isAfter(fine)) {
            throw new IllegalArgumentException("L'orario di inizio deve essere prima di quello di fine.");
        }
        if (inizio.isBefore(LocalTime.of(8, 0)) || fine.isAfter(LocalTime.of(18, 0))) {
            throw new IllegalArgumentException("Le prenotazioni devono essere tra le 08:00 e le 18:00.");
        }
        this.nAula = nAula;
        this.data = data;
        this.inizio = inizio;
        this.fine = fine;
        this.nome = nome;
        this.motivazione = motivazione;
    }

    public int getnAula() {
        return nAula;
    }

    public void setnAula(int nAula) {
        this.nAula = nAula;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public LocalTime getInizio() {
        return inizio;
    }

    public void setInizio(LocalTime inizio) {
        this.inizio = inizio;
    }

    public LocalTime getFine() {
        return fine;
    }

    public void setFine(LocalTime fine) {
        this.fine = fine;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMotivazione() {
        return motivazione;
    }

    public void setMotivazione(String motivazione) {
        this.motivazione = motivazione;
    }

    public String toJson() {
        DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        DateTimeFormatter timeFormatter = DateTimeFormatter.ofPattern("HH:mm");

        return String.format("""
                {
                  "N_aula": %d,
                  "data": "%s",
                  "inizio": "%s",
                  "fine": "%s",
                  "nome": "%s",
                  "motivazione": "%s"
                }""",
                nAula, data.format(dateFormatter), inizio.format(timeFormatter),
                fine.format(timeFormatter), nome, motivazione);
    }

    @Override
    public String toString() {
        return toJson();
    }
}
