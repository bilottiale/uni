package controller;

import model.*;

public class GestorePrenotazioni {

    // Controlla se la prenotazione è valida
    public static boolean controllaPrenotazione(Prenotazione prenotazione) {
        // Calcolo della durata della prenotazione
        int oraInizio = prenotazione.getOraInizio().getHour();
        int oraFine = prenotazione.getOraFine().getHour();
        int durataPrenotazione = oraFine - oraInizio;

        // Controllo in base al tipo di aula
        if (prenotazione.getAula() instanceof AulaDidattica) {
            // Controlla se la durata è tra 1 e 8 ore
            return durataPrenotazione >= 1 && durataPrenotazione <= 8;
        } else if (prenotazione.getAula() instanceof Laboratorio) {
            // Controlla se la durata è di 2 ore o 4 ore e rispetta slot di 2 ore
            return (durataPrenotazione == 2 || durataPrenotazione == 4) &&
                    (oraInizio % 2 == 0); // Assicura che inizi in uno slot valido (es. 8:00, 10:00)
        }

        // Restituisci false per tipi di aula non gestiti
        return false;
    }

    // Prenotazione -> String
    public static String prenotazioneToString(Prenotazione prenotazione) {
        return prenotazione.getData() + "," + prenotazione.getOraInizio() + "," + prenotazione.getOraFine() + "," + prenotazione.getNomePrenotante() + "," + prenotazione.getMotivazione() + "," + prenotazione.getAula().getN_aula() + "\n";
    }
}
