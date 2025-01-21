import controller.GestoreAule;
import model.AulaDidattica;
import model.Laboratorio;
import model.Prenotazione;
import util.FileManager;
import controller.GestorePrenotazioni;
import view.InterfacciaGrafica;

import java.time.LocalDate;
import java.time.LocalTime;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        new InterfacciaGrafica();

        // Creazione di una prenotazione
        Prenotazione prenotazione = new Prenotazione(LocalDate.now(), LocalTime.of(8, 0), LocalTime.of(10, 0), "Mario Rossi", "Lezione di informatica", new AulaDidattica(1, 50, true, true));
        System.out.println(prenotazione.toString());

        // Controllo della prenotazione
        System.out.println(GestorePrenotazioni.controllaPrenotazione(prenotazione));

        // Aggiunta di una prenotazione al file
        FileManager.addPrenotazione(prenotazione);

        // Stampa delle prenotazioni
        FileManager.getPrenotazioni();

        // Creazione di un'aula didattica
        AulaDidattica aula1 = new AulaDidattica(1, 50, true, true);
        System.out.println(aula1.getTipo());

        Laboratorio aula2 = new Laboratorio(2, 20, false, true);
        System.out.println(aula2.getTipo());

        // Stampa degli accessori dell'aula
        System.out.println(aula1.getAccessori());

        // creazione file se non esistenti
        FileManager.createFiles();

        GestoreAule.aulaToString(aula1);

        // aggiunta aula al file
        FileManager.addAula(aula1);

        // stampa aule
        FileManager.getAule();

        // aggiunta Lab al file
        FileManager.addAula(aula2);

        // stampa aule
        FileManager.getAule();

        // rimuovi aula dal file
        FileManager.deleteAula(2);

        // stampa aule
        FileManager.getAule();
    }
}