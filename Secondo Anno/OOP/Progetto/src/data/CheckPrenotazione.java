package data;

import model.*;

public class CheckPrenotazione {
    // Prenotazione = 5,2023-10-03,11:00,12:00,Jessica Davis,Presentation
    // laboratorio -> si può prenotare per un periodo che varia da 1 a 8 ore con
    // incrementi di 1 ora.
    // aula didattica -> si può prenotare solo a slot di 2 ore e al massimo per 4
    // ore consecutive.
    // public Prenotazione checkPrenotazione(Prenotazione p) {}
    //     Aula aula = p.getAula();
    //     if (aula instanceof Laboratorio) {
    //         if (p.getOraFine().getHour() - p.getOraInizio().getHour() < 1
    //                 || p.getOraFine().getHour() - p.getOraInizio().getHour() > 8) {
    //             throw new IllegalArgumentException(
    //                     "Un laboratorio può essere prenotato per un periodo che varia da 1 a 8 ore con incrementi di 1 ora.");
    //         }
    //     } else if (aula instanceof AulaDidattica) {
    //         if (p.getOraFine().getHour() - p.getOraInizio().getHour() != 2) {
    //             throw new IllegalArgumentException(
    //                     "Un'aula didattica può essere prenotata solo a slot di 2 ore e al massimo per 4 ore consecutive.");
    //         }
    //         // al massimo per 4 ore consecutive
    //         if (p.getOraFine().getHour() - p.getOraInizio().getHour() > 4) {
    //             throw new IllegalArgumentException(
    //                     "Un'aula didattica può essere prenotata solo a slot di 2 ore e al massimo per 4 ore consecutive.");
    //         }
    //     }
    //     return p;
    // }
}
