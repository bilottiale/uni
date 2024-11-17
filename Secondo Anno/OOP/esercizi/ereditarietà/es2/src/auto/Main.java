package auto;

import auto.Automobile;
import auto.Optional;
import motori.MotoreBenzina;
import motori.MotoreDiesel;

public class Main {
    public static void main(String[] args) {
        // Creazione dei motori
        MotoreDiesel motoreDiesel = new MotoreDiesel(2000, 4);
        MotoreBenzina motoreBenzina = new MotoreBenzina(1600, 4);

        // Creazione delle automobili
        Automobile auto1 = new Automobile("AB123CD", "Fiat", "Panda", motoreDiesel);
        Automobile auto2 = new Automobile("EF456GH", "BMW", "Serie 1", motoreBenzina);

        // Aggiunta di optional
        auto1.aggiungiOptional(new Optional("OP001", "Climatizzatore", 800));
        auto1.aggiungiOptional(new Optional("OP002", "Vernice metallizzata", 500));
        auto2.aggiungiOptional(new Optional("OP003", "Cerchi in lega", 1000));
        auto2.aggiungiOptional(new Optional("OP004", "Sistema di navigazione", 1500));

        // Stampa delle informazioni
        auto1.stampaDettagli();
        System.out.println();
        auto2.stampaDettagli();
    }
}

