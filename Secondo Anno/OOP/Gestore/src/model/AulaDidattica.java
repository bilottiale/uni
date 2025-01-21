package model;

import java.lang.reflect.Array;

public class AulaDidattica extends Aula {
    private boolean lavagna;
    private boolean videoProiettore;

    public AulaDidattica(int n_aula, int capienza, boolean haLavagna, boolean haVideoproiettore) {
        super(n_aula, capienza, "Didattica");
        this.lavagna = haLavagna;
        this.videoProiettore = haVideoproiettore;
    }

    @Override
    public String getTipo() {
        return "Aula Didattica";
    }

    public boolean HasLavagna() {
        return lavagna;
    }

    public boolean HasVideoProiettore() {
        return videoProiettore;
    }

    @Override
    public String getAccessori() {
        return lavagna + "," + videoProiettore;
    }
}
