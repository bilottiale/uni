package model;

public abstract class Aula {
    private int n_aula;
    private int capienza;
    private TipoAula tipo;

    public Aula(int n_aula, int capienza, TipoAula tipo) {
        this.n_aula = n_aula;
        this.capienza = capienza;
        this.tipo = tipo;
    }

    public enum AccessorioLaboratorio {
        PC, PRESE
    }

    public enum AccessorioDidattica {
        LAVAGNA, PROIETTORE
    }
    
    public enum TipoAula {
        LABORATORIO, DIDATTICA
    }

    public int getNumeroAula() {
        return n_aula;
    }

    public void setNumeroAula(int n_aula) {
        this.n_aula = n_aula;
    }

    public int getCapienza() {
        return capienza;
    }

    public void setCapienza(int capienza) {
        this.capienza = capienza;
    }

    public TipoAula getTipo() {
        return tipo;
    }

    public void setTipo(TipoAula tipo) {
        this.tipo = tipo;
    }

    // get accessori
    public abstract Object getAccessori();

    public String toJson() {
        return String.format("""
                {
                    "nAula": %d,
                    "capienza": %d,
                    "tipo": "%s"
                }
                """, getNumeroAula(), getCapienza(), getTipo());
    }

}