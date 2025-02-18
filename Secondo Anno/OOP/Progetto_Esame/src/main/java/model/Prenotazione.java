package model;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

import static utils.JsonUtils.*;

public class Prenotazione {

    private int nAula;
    private LocalDate data;
    private LocalTime inizio;
    private LocalTime fine;
    private String nome;
    private String motivazione;
    public Aula.TipoAula tipoAula;

    // getTipoAula da nAula

    public Prenotazione(int nAula, LocalDate data, LocalTime inizio, LocalTime fine, String nome, String motivazione) {
        // Controlla che l'orario di inizio sia prima di quello di fine
        if (inizio.isAfter(fine)) {
            throw new IllegalArgumentException("L'orario di inizio deve essere prima di quello di fine.");
        }

        // Controlla che le prenotazioni siano tra le 08:00 e le 18:00
        if (inizio.isBefore(LocalTime.of(8, 0)) || fine.isAfter(LocalTime.of(18, 0))) {
            throw new IllegalArgumentException("Le prenotazioni devono essere tra le 08:00 e le 18:00.");
        }

        // Aggiungi la logica di validazione per la durata della prenotazione
        int durataOre = fine.getHour() - inizio.getHour();
        if (durataOre <= 0) {
            throw new IllegalArgumentException("La durata della prenotazione deve essere maggiore di zero ore.");
        }

        // Ottieni il tipo di aula in base al numero di aula
        this.tipoAula = getTipoAula(nAula);

        // Validazione in base al tipo di aula
        if (tipoAula == Aula.TipoAula.DIDATTICA) { // Aula Didattica: durata da 1 a 8 ore
            if (durataOre > 8 || fine.getMinute() - inizio.getMinute() != 0) {
                throw new IllegalArgumentException("Un'Aula Didattica può essere prenotata da 1 a 8 ore con incrementi di 1 ora.");
            }
        } else if (tipoAula == Aula.TipoAula.LABORATORIO) { // Laboratorio: durata 2 o 4 ore
            if (durataOre != 2 && durataOre != 4) {
                throw new IllegalArgumentException("Un Laboratorio può essere prenotato solo per 2 ore o 4 ore consecutive.");
            }
        } else {
            throw new IllegalArgumentException("Tipo di aula sconosciuto: " + tipoAula);
        }

        // Se tutto è valido, assegniamo i valori
        this.nAula = nAula;
        this.data = data;
        this.inizio = inizio;
        this.fine = fine;
        this.nome = nome;
        this.motivazione = motivazione;
    }

    // Getters e Setters
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

    public LocalTime getOraInizio() {
        return inizio;
    }

    public void setOraInizio(LocalTime inizio) {
        this.inizio = inizio;
    }

    public LocalTime getOraFine() {
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

    public Aula getAula() {
        List<Aula> aule = utils.JsonUtils.leggiAuleDaJson("data/aule.json");
        for (Aula aula : aule) {
            if (aula.getNumeroAula() == this.nAula) {
                return aula;
            }
        }
        return null;
    }

    public String getDescrizione() {
        return nome + " - " + motivazione + " (" + inizio + " - " + fine + ")";
    }

    public Aula.TipoAula getTipoAula(int nAula) {
        List<Aula> aule = leggiAuleDaJson("data/aule.json");
        for (Aula aula : aule) {
            if (aula.getNumeroAula() == nAula) {
                return aula.getTipo();
            }
        }
        return null;
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
                }
                """,
                nAula, data.format(dateFormatter), inizio.format(timeFormatter),
                fine.format(timeFormatter), nome, motivazione);
    }

    @Override
    public String toString() {
        return toJson();
    }

}
