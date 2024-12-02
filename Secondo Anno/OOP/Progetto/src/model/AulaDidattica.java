package model;

public class AulaDidattica extends Aula {
    private boolean lavagna;
    private boolean proiettore;

    public AulaDidattica(int id, int capienza, String tipoAula, boolean lavagna, boolean proiettore) {
        super(id, capienza, tipoAula);
        this.lavagna = lavagna;
        this.proiettore = proiettore;
    }

    // Getters
    public boolean hasLavagna() {
        return lavagna;
    }

    // Setters
    public void setLavagna(boolean lavagna) {
        this.lavagna = lavagna;
    }

    @Override
    public String toString() {
        return "AulaDidattica " + getIdAula() + ", capienza=" + getCapienza() + ", tipoAula='" + getTipoAula() + '\'' +
                ", lavagna=" + lavagna + ", proiettore=" + proiettore;
    }
}
