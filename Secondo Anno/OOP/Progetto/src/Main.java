import data.*;
import model.*;

public class Main {
    public static void main(String[] args) {
        Aula nn = new Laboratorio(1 , 30, "Informatica", true, true);

        System.out.println(nn);

        for(Prenotazione p : CSVReader.readPrenotazioni("./data/prenotazioni.csv")) {
            System.out.println(p);
        }

        System.out.println("oK");

        for(Aula a : CSVReader.readAule("./data/aule.csv")) {
            System.out.println(a);
        }

        // aggiungi prenotazione
        // Prenotazione p = new Prenotazione(1, LocalDate.of(2023, 10, 1), LocalTime.of(9, 0), LocalTime.of(10, 0), "John Doe", "Meeting");
        // CSVReader.aggiungiPrenotazione("./data/prenotazioni.csv", p);
    }

    
}
