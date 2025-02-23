package model;

import utils.JsonUtils;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

/**
 * Represents a booking for a classroom, encapsulating details such as classroom number, date, time slot,
 * booker's name, and booking motivation. Validates the booking based on classroom type and time constraints.
 */
public class Prenotazione {
    /** The unique identifier number of the classroom to book. */
    private final int nAula;
    /** The date of the booking. */
    private final LocalDate data;
    /** The start time of the booking. */
    private final LocalTime inizio;
    /** The end time of the booking. */
    private final LocalTime fine;
    /** The name of the person making the booking. */
    private final String nome;
    /** The reason or description for the booking. */
    private final String motivazione;
    /** The type of classroom associated with the booking. */
    private final AulaInterface.TipoAula tipoAula;

    /**
     * Constructs a new {@code Prenotazione} instance with the specified booking details.
     * <p>
     * Initializes the booking with the provided parameters, ensuring that null values for {@code nome} and
     * {@code motivazione} are replaced with empty strings. The classroom type is determined based on the
     * classroom number, and the booking is validated against specific rules for didactic classrooms (1-8 hours)
     * and laboratories (2 or 4 hours).
     * </p>
     *
     * @param nAula The unique identifier number of the classroom to book.
     * @param data The date of the booking.
     * @param inizio The start time of the booking.
     * @param fine The end time of the booking.
     * @param nome The name of the person making the booking, or {@code null} for an empty string.
     * @param motivazione The reason or description for the booking, or {@code null} for an empty string.
     * @throws IllegalArgumentException if the booking data fails validation or no classroom is found for the given number.
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
     * Validates the booking details based on classroom type and time constraints.
     *
     * @param nAula The classroom number.
     * @param data The date of the booking (unused in current validation but included for future checks).
     * @param inizio The start time of the booking.
     * @param fine The end time of the booking.
     * @return {@code true} if the booking details are valid according to classroom-specific rules, {@code false} otherwise.
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

        if (tipoAula == AulaInterface.TipoAula.DIDATTICA) {
            return durataOre <= 8;
        } else if (tipoAula == AulaInterface.TipoAula.LABORATORIO) {
            return durataOre == 2 || durataOre == 4;
        }
        return false;
    }

    /**
     * Gets the date of the booking.
     *
     * @return The date of the booking.
     */
    public LocalDate getData() {
        return data;
    }

    /**
     * Gets the start time of the booking.
     *
     * @return The start time of the booking.
     */
    public LocalTime getOraInizio() {
        return inizio;
    }

    /**
     * Gets the end time of the booking.
     *
     * @return The end time of the booking.
     */
    public LocalTime getOraFine() {
        return fine;
    }

    /**
     * Gets the name of the person making the booking.
     *
     * @return The name of the booker, never {@code null}.
     */
    public String getNome() {
        return nome;
    }

    /**
     * Gets the reason or description for the booking.
     *
     * @return The motivation for the booking, never {@code null}.
     */
    public String getMotivazione() {
        return motivazione;
    }

    /**
     * Retrieves the classroom associated with this booking.
     *
     * @return The {@link AulaInterface} object representing the classroom, or {@code null} if not found.
     */
    public AulaInterface getAula() {
        List<AulaInterface> aule = JsonUtils.leggiAuleDaJson();
        for (AulaInterface aula : aule) {
            if (aula.getNumeroAula() == this.nAula) {
                return aula;
            }
        }
        return null;
    }

    /**
     * Gets a simple description of the booking.
     *
     * @return A string combining the booker's name and motivation, separated by " - ".
     */
    public String getDescrizione() {
        return nome + " - " + motivazione;
    }

    /**
     * Determines the type of classroom based on the classroom number.
     *
     * @param nAula The classroom number to look up.
     * @return The {@link AulaInterface.TipoAula} of the classroom.
     * @throws IllegalArgumentException if no classroom is found for the given number.
     */
    public AulaInterface.TipoAula getTipoAula(int nAula) {
        List<AulaInterface> aule = JsonUtils.leggiAuleDaJson();
        for (AulaInterface aula : aule) {
            if (aula.getNumeroAula() == nAula) {
                return aula.getTipo();
            }
        }
        throw new IllegalArgumentException("Nessuna aula trovata per il numero: " + nAula);
    }

    /**
     * Generates an error message based on which validation rule failed.
     *
     * @return A string describing the specific validation error encountered.
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
        if (tipoAula == AulaInterface.TipoAula.DIDATTICA) {
            if (durataOre > 8) {
                return "Un'Aula Didattica può essere prenotata da 1 a 8 ore.";
            }
        } else if (tipoAula == AulaInterface.TipoAula.LABORATORIO) {
            if (durataOre != 2 && durataOre != 4) {
                return "Un Laboratorio può essere prenotato solo per 2 ore o 4 ore consecutive.";
            }
        }
        return "Tipo di aula sconosciuto: " + tipoAula;
    }

    /**
     * Converts the booking to a JSON string representation.
     *
     * @return A formatted JSON string representing the booking details.
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

    /**
     * Returns a string representation of the booking in JSON format.
     *
     * @return The JSON string representation of the booking.
     */
    @Override
    public String toString() {
        return toJson();
    }
}