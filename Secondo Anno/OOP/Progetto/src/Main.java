import data.*;
import model.*;

public class Main {
    public static void main(String[] args) {
        Aula nn = new Laboratorio(1 , 30, "Informatica", true, true);

        System.out.println(nn);

        for(Prenotazione p : CSVReader.readPrenotazioni("./data/prenotazioni.csv")) {
            System.out.println(p);
        }
    }
}
