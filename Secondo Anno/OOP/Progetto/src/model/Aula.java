package model;

public abstract class Aula {
    private int id;
    private int capienza;
    private String tipoAula;

    public Aula(int id, int capienza, String tipoAula) {
        this.id = id;
        this.capienza = capienza;
        this.tipoAula = tipoAula;
    }

    // Getters
    public int getIdAula() {
        return id;
    }

    public int getCapienza() {
        return capienza;
    }

    public String getTipoAula() {
        return tipoAula;
    }

    // Setters
    public void setIdAula(int id) {
        this.id = id;
    }

    public void setCapienza(int capienza) {
        this.capienza = capienza;
    }

    public void setTipoAula(String tipoAula) {
        this.tipoAula = tipoAula;
    }

    @Override
    public String toString() {
        return "Aula{" +
                "id=" + id +
                ", capienza=" + capienza +
                ", tipoAula='" + tipoAula + '\'' +
                '}';
    }
}
