import controller.PrenotazioneValidator;
import controller.PrenotazioneValidator.ValidationResult;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;
import model.Prenotazione;
import utils.AulaUtils;
import utils.PrenotazioneUtils;
import view.FinestraPrenotazioni;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        // window
        // MainView view = new MainView("TEST");
        // view.setVisible(true);

        // AulaDidattica aulaDidattica = new AulaDidattica(10, 30, EnumSet.of(Aula.AccessorioDidattica.LAVAGNA));
        // Laboratorio laboratorio = new Laboratorio(20, 20,
        // EnumSet.of(Aula.AccessorioLaboratorio.PC, Aula.AccessorioLaboratorio.PRESE));

        // System.out.println(aulaDidattica);
        // System.out.println(laboratorio);

        // AulaDidattica aula = new AulaDidattica(10, 30,
        // EnumSet.of(Aula.AccessorioDidattica.LAVAGNA));
        // System.out.println(aula.getTipo());

        // Prenotazione p = new Prenotazione(1, LocalDate.of(2025, 2, 12),
        // LocalTime.of(10, 0), LocalTime.of(12, 0),
        // "Mario Rossi", "Lezione di Informatica");
        // System.out.println(p);
        // System.out.println(p.getInizio());

        // System.err.println("\n");
        // System.err.println("--------------------");
        // System.err.println("\n");

        // // PrenotazioneUtils.checkFile();
        // // String fileContent = PrenotazioneUtils.readFile();
        // // System.out.println("Contenuto del file:\n" + fileContent);

        // PrenotazioneUtils.stampaPrenotazioni();

        System.err.println("----------OK----------");

        AulaUtils.stampaAule();

        // Prenotazione prenotazione = new Prenotazione(1, LocalDate.now(),
        //         LocalTime.of(9, 0), LocalTime.of(11, 0), "Mario Rossi", "Lezione");

        Prenotazione prenotazione2 = new Prenotazione(1, LocalDate.now(),
                LocalTime.of(12, 0), LocalTime.of(14, 0), "Mario Rossi", "Lezione");

        ValidationResult result = PrenotazioneValidator.validatePrenotazione(prenotazione2);
        if (result.isValid()) {
            System.out.println("Prenotazione valida!");
        } else {
            System.err.println("Errore: " + result.getErrorMessage());
        }

        // Window
        List<Prenotazione> prenotazioni = List.of(
            new Prenotazione(1, LocalDate.of(2025, 2, 12), LocalTime.of(10, 0), LocalTime.of(12, 0), "Mario Rossi", "Lezione di Informatica"),
            new Prenotazione(2, LocalDate.of(2025, 2, 13), LocalTime.of(14, 0), LocalTime.of(16, 0), "Luigi Bianchi", "Seminario di Matematica")
        );
        new FinestraPrenotazioni(prenotazioni);

        PrenotazioneUtils.caricaPrenotazioni("data/prenotazioni.json", AulaUtils.leggiAule());
    }
}
