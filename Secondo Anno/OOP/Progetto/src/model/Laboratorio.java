package model;

public class Laboratorio extends Aula {
    private boolean pc;
    private boolean preseElettriche;

    public Laboratorio(int id, int capienza, String tipoAula, boolean pc, boolean preseElettriche) {
        super(id, capienza, tipoAula);
        this.pc = pc;
        this.preseElettriche = preseElettriche;
    }

    // Getters
    public boolean hasPc() {
        return pc;
    }

    public boolean haspreseElettriche() {
        return preseElettriche;
    }

    // Setters
    public void setPc(boolean pc) {
        this.pc = pc;
    }

    public void setpreseElettriche(boolean preseElettriche) {
        this.preseElettriche = preseElettriche;
    }

    @Override
    public String toString() {
        return "Laboratorio " + getIdAula() + ", capienza=" + getCapienza() + ", tipoAula='" + getTipoAula() + '\'' +
                ", pc=" + pc + ", prese elettriche=" + preseElettriche;
    }
}
