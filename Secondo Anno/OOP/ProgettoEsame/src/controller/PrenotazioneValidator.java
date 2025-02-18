package controller;

import java.time.Duration;
import java.time.LocalTime;
import java.util.List;
import model.Aula;
import model.Aula.TipoAula;
import model.Prenotazione;
import utils.AulaUtils;

public class PrenotazioneValidator {
    private static final int AULA_DIDATTICA_MIN_ORE = 1;
    private static final int AULA_DIDATTICA_MAX_ORE = 8;
    private static final int LABORATORIO_SLOT_ORE = 2;
    private static final int LABORATORIO_MAX_ORE = 4;

    public static ValidationResult validatePrenotazione(Prenotazione prenotazione) {
        // First, find the room and its type from aula.json
        Aula aula = findAulaByNumber(prenotazione.getnAula());
        if (aula == null) {
            return new ValidationResult(false, "Aula numero " + prenotazione.getnAula() + " non trovata");
        }

        // Get booking duration in hours
        LocalTime inizio = prenotazione.getInizio();
        LocalTime fine = prenotazione.getFine();
        long orePrenotate = Duration.between(inizio, fine).toHours();

        // Validate basic time constraints
        if (!isValidStartTime(inizio) || !isValidStartTime(fine)) {
            return new ValidationResult(false, "Le prenotazioni devono iniziare e finire all'ora esatta");
        }

        if (!fine.isAfter(inizio)) {
            return new ValidationResult(false, "L'ora di fine deve essere successiva all'ora di inizio");
        }

        // Check for overlapping bookings
        ValidationResult overlapCheck = checkForOverlappingPrenotazioni(aula, inizio, fine);
        if (!overlapCheck.isValid()) {
            return overlapCheck;
        }

        // Apply room-specific validation
        if (aula.getTipo() == TipoAula.LABORATORIO) {
            return validateLaboratorio(orePrenotate);
        } else {
            return validateAulaDidattica(orePrenotate);
        }
    }

    /**
     * Checks if there are overlapping bookings for the specified room and time.
     * 
     * @param aula   The room to check
     * @param inizio The start time of the new booking
     * @param fine   The end time of the new booking
     * @return ValidationResult indicating if there's an overlap
     */
    private static ValidationResult checkForOverlappingPrenotazioni(Aula aula, LocalTime inizio, LocalTime fine) {
        List<Prenotazione> prenotazioni = AulaUtils.getPrenotazioniByAula(aula.getNumeroAula()); // Assuming a method to get bookings for the room

        for (Prenotazione p : prenotazioni) {
            // If the new booking starts before the existing one ends and ends after the
            // existing one starts, there's an overlap
            if ((inizio.isBefore(p.getFine()) && fine.isAfter(p.getInizio()))) {
                return new ValidationResult(false,
                        "La prenotazione dell'aula " + aula.getNumeroAula() + " sovrappone un'altra prenotazione.");
            }
        }

        return new ValidationResult(true, null);
    }

    /**
     * Finds an Aula object by its room number from aula.json
     */
    private static Aula findAulaByNumber(int numeroAula) {
        List<Aula> aule = AulaUtils.leggiAule();
        return aule.stream()
                .filter(a -> a.getNumeroAula() == numeroAula)
                .findFirst()
                .orElse(null);
    }

    /**
     * Validates laboratory booking rules:
     * - Must be in 2-hour slots
     * - Maximum 4 hours consecutive
     */
    private static ValidationResult validateLaboratorio(long ore) {
        if (ore <= 0 || ore > LABORATORIO_MAX_ORE) {
            return new ValidationResult(false,
                    "La prenotazione del laboratorio deve essere tra 2 e 4 ore");
        }

        if (ore % LABORATORIO_SLOT_ORE != 0) {
            return new ValidationResult(false,
                    "La prenotazione del laboratorio deve essere in slot di 2 ore");
        }

        return new ValidationResult(true, null);
    }

    /**
     * Validates didactic room booking rules:
     * - Between 1 and 8 hours
     * - Must be in 1-hour increments
     */
    private static ValidationResult validateAulaDidattica(long ore) {
        if (ore < AULA_DIDATTICA_MIN_ORE || ore > AULA_DIDATTICA_MAX_ORE) {
            return new ValidationResult(false,
                    "La prenotazione dell'aula didattica deve essere tra 1 e 8 ore");
        }

        if (ore != Math.floor(ore)) {
            return new ValidationResult(false,
                    "La prenotazione deve essere in incrementi di 1 ora");
        }

        return new ValidationResult(true, null);
    }

    /**
     * Checks if a time is at the start of an hour (no minutes/seconds)
     */
    private static boolean isValidStartTime(LocalTime time) {
        return time.getMinute() == 0 && time.getSecond() == 0;
    }

    /**
     * Class to hold validation results with a status and optional error message
     */
    public static class ValidationResult {
        private final boolean isValid;
        private final String errorMessage;

        public ValidationResult(boolean isValid, String errorMessage) {
            this.isValid = isValid;
            this.errorMessage = errorMessage;
        }

        public boolean isValid() {
            return isValid;
        }

        public String getErrorMessage() {
            return errorMessage;
        }
    }
}