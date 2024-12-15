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

        // CheckPrenotazione p = new CheckPrenotazione();
        // System.out.println(p.toString());
    }

    
}
