package model;

public class Laboratorio extends Aula {
    private boolean haPC;
    private boolean haPreseElettriche;

    public Laboratorio(int n_aula, int capienza, boolean haPC, boolean haPreseElettriche) {
        super(n_aula, capienza, "Laboratorio");
        this.haPC = haPC;
        this.haPreseElettriche = haPreseElettriche;
    }

    @Override
    public String getTipo() {
        return "Laboratorio";
    }

    public boolean hasPC() {
        return haPC;
    }

    public boolean hasPreseElettriche() {
        return haPreseElettriche;
    }

    @Override
    public String getAccessori() {
        return haPC + "," + haPreseElettriche;
    }
}
