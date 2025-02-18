import model.*;
import utils.*;
import view.MainView;

import javax.swing.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.EnumSet;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        AulaDidattica aulaDidattica = new AulaDidattica(1, 100, EnumSet.of(AccessorioDidattica.LAVAGNA, AccessorioDidattica.PROIETTORE));
        System.out.println(aulaDidattica);

        Laboratorio laboratorio = new Laboratorio(2, 50, EnumSet.of(AccessorioLaboratorio.PC));
        System.out.println(laboratorio);

        System.out.println("---------AULE---------");

        List<Aula> aule = JsonUtils.leggiAuleDaJson("data/aule.json");
        for (Aula aula : aule) {
            System.out.println(aula.getTipo());
            System.out.println(aula.getAccessori());
        }
        //jsonUtils.scriviAuleSuJson(aule);

        System.out.println("---------PRENOTAZIONI---------");

        List<Prenotazione> prenotazioni = JsonUtils.leggiPrenotazioniDaJson("data/prenotazioni.json");
        for (Prenotazione prenotazione : prenotazioni) {
            System.out.println(prenotazione);
        }

        Prenotazione prenotazione = new Prenotazione(1, LocalDate.now(), LocalTime.of(12, 0), LocalTime.of(14, 0), "Mario Rossi", "Lezione");
        System.out.println(prenotazione);

        System.out.println("---------VIEW---------");
        SwingUtilities.invokeLater(MainView::new);
    }
}
