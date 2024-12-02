package model;

public class Laboratorio extends Aula {
    private boolean pc;
    private boolean proiettore;

    public Laboratorio(int id, int capienza, String tipoAula, boolean pc, boolean proiettore) {
        super(id, capienza, tipoAula);
        this.pc = pc;
        this.proiettore = proiettore;
    }

    // Getters
    public boolean hasPc() {
        return pc;
    }

    public boolean hasProiettore() {
        return proiettore;
    }

    // Setters
    public void setPc(boolean pc) {
        this.pc = pc;
    }

    public void setProiettore(boolean proiettore) {
        this.proiettore = proiettore;
    }

    @Override
    public String toString() {
        return "Laboratorio " + getIdAula() + ", capienza=" + getCapienza() + ", tipoAula='" + getTipoAula() + '\'' +
                ", pc=" + pc + ", proiettore=" + proiettore;
    }
}
