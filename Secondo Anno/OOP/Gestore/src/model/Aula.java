package model;

import java.lang.reflect.Array;

public abstract class Aula {
    public int n_aula;
    private int capienza;
    private String tipo;
    // boolean[] accessori;

    public Aula(int numero, int capienza, String didattica) {
        this.n_aula = numero;
        this.capienza = capienza;
        this.tipo = didattica;
    }

    public int getN_aula() {
        return n_aula;
    }

    public int getCapienza() {
        return capienza;
    }

    public String getTipo() {
        return tipo;
    }

    public abstract String getAccessori();

    @Override
    public String toString() {
        return "Aula " + n_aula + " (Capienza: " + capienza + ", Tipo: " + tipo + ")";
    }

}
