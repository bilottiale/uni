package model;

import utils.JsonUtils;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

public class Prenotazione {

    private int nAula;
    private LocalDate data;
    private LocalTime inizio;
    private LocalTime fine;
    private String nome;
    private String motivazione;
    private final Aula.TipoAula tipoAula;

    /**
     * Constructor for Prenotazione class.
     *
     * @param nAula The classroom number for the booking.
     * @param data The date of the booking.
     * @param inizio The start time of the booking.
     * @param fine The end time of the booking.
     * @param nome The name of the person making the booking.
     * @param motivazione The reason or description for the booking.
     * @throws IllegalArgumentException if the booking data does not pass validation.
     */
    public Prenotazione(int nAula, LocalDate data, LocalTime inizio, LocalTime fine, String nome, String motivazione) {
        System.out.println("Constructor - Nome: " + nome + ", Motivazione: " + motivazione);
        System.out.println("Constructor - Inizio: " + inizio + ", Fine: " + fine);

        this.nome = nome != null ? nome : "";
        this.motivazione = motivazione != null ? motivazione : "";
        this.inizio = inizio;
        this.fine = fine;
        this.nAula = nAula;
        this.data = data;

        try {
            this.tipoAula = getTipoAula(nAula);
            if (!validateBooking(nAula, data, inizio, fine)) {
                throw new IllegalArgumentException(getValidationErrorMessage());
            }
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Errore nella creazione della prenotazione: " + e.getMessage());
        }
    }

    /**
     * Validates the booking details.
     *
     * @param nAula The classroom number.
     * @param data The date of the booking.
     * @param inizio The start time of the booking.
     * @param fine The end time of the booking.
     * @return true if the booking details are valid, false otherwise.
     */
    private boolean validateBooking(int nAula, LocalDate data, LocalTime inizio, LocalTime fine) {
        if (inizio == null || fine == null) {
            return false;
        }

        if (inizio.isAfter(fine)) {
            return false;
        }

        if (inizio.isBefore(LocalTime.of(8, 0)) || fine.isAfter(LocalTime.of(18, 0))) {
            return false;
        }

        if (inizio.getMinute() != 0 || fine.getMinute() != 0) {
            return false;
        }

        int durataOre = fine.getHour() - inizio.getHour();
        if (durataOre <= 0) {
            return false;
        }

        if (tipoAula == Aula.TipoAula.DIDATTICA) {
            return durataOre <= 8;
        } else if (tipoAula == Aula.TipoAula.LABORATORIO) {
            return durataOre == 2 || durataOre == 4;
        }
        return false;
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

    /**
     * Retrieves the Aula associated with this booking.
     *
     * @return The Aula object or null if not found.
     */
    public Aula getAula() {
        List<Aula> aule = JsonUtils.leggiAuleDaJson();
        for (Aula aula : aule) {
            if (aula.getNumeroAula() == this.nAula) {
                return aula;
            }
        }
        return null;
    }

    /**
     * Gets a simple description of the booking.
     *
     * @return A string combining name and motivation.
     */
    public String getDescrizione() {
        return nome + " - " + motivazione;
    }

    /**
     * Determines the type of classroom based on the classroom number.
     *
     * @param nAula The classroom number.
     * @return The type of the classroom.
     * @throws IllegalArgumentException if no matching classroom is found.
     */
    public Aula.TipoAula getTipoAula(int nAula) {
        List<Aula> aule = JsonUtils.leggiAuleDaJson();
        for (Aula aula : aule) {
            if (aula.getNumeroAula() == nAula) {
                return aula.getTipo();
            }
        }
        throw new IllegalArgumentException("Nessuna aula trovata per il numero: " + nAula);
    }

    /**
     * Checks if the booking is valid based on the current set parameters.
     *
     * @return true if the booking is valid, false otherwise.
     */
    public boolean isValid() {
        return validateBooking(nAula, data, inizio, fine);
    }

    /**
     * Generates an error message based on which validation rule failed.
     *
     * @return A string describing the validation error.
     */
    public String getValidationErrorMessage() {
        if (inizio == null || fine == null) {
            return "Orari di inizio o fine non possono essere null.";
        }
        if (inizio.isAfter(fine)) {
            return "L'orario di inizio deve essere prima di quello di fine.";
        }
        if (inizio.isBefore(LocalTime.of(8, 0)) || fine.isAfter(LocalTime.of(18, 0))) {
            return "Le prenotazioni devono essere tra le 08:00 e le 18:00.";
        }
        if (inizio.getMinute() != 0 || fine.getMinute() != 0) {
            return "L'orario di inizio e fine deve essere a minuti zero.";
        }
        int durataOre = fine.getHour() - inizio.getHour();
        if (durataOre <= 0) {
            return "La durata della prenotazione deve essere maggiore di zero ore.";
        }
        if (tipoAula == Aula.TipoAula.DIDATTICA) {
            if (durataOre > 8) {
                return "Un'Aula Didattica può essere prenotata da 1 a 8 ore.";
            }
        } else if (tipoAula == Aula.TipoAula.LABORATORIO) {
            if (durataOre != 2 && durataOre != 4) {
                return "Un Laboratorio può essere prenotato solo per 2 ore o 4 ore consecutive.";
            }
        }
        return "Tipo di aula sconosciuto: " + tipoAula;
    }

    /**
     * Converts the Prenotazione to a JSON string representation.
     *
     * @return A JSON string representing the booking.
     */
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