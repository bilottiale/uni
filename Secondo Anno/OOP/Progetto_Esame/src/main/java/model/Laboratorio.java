package model;

import java.util.EnumSet;
import java.util.List;
import java.util.stream.Collectors;

public class Laboratorio extends Aula {
    private EnumSet<AccessorioLaboratorio> accessori;

    public Laboratorio(int n_aula, int capienza, EnumSet<AccessorioLaboratorio> accessori) {
        super(n_aula, capienza, TipoAula.LABORATORIO);
        this.accessori = accessori != null ? accessori : EnumSet.noneOf(AccessorioLaboratorio.class);
    }

    @Override
    public EnumSet<AccessorioLaboratorio> getAccessori() {
        return accessori;
    }

    public void setAccessori(EnumSet<AccessorioLaboratorio> accessori) {
        this.accessori = accessori;
    }

    public List<Integer> getAccessoriAsListInt() {
        return List.of(
                this.accessori.contains(AccessorioLaboratorio.PC) ? 1 : 0,
                this.accessori.contains(AccessorioLaboratorio.PRESE) ? 1 : 0
        );
    }

    @Override
    public String toString() {
        return String.format("Laboratorio: nAula=%d, capienza=%d, accessori=%s",
                getNumeroAula(), getCapienza(), accessori);
    }

    @Override
    public String toJson() {
        String accessoriJson = getAccessoriAsListInt().stream()
                .map(String::valueOf)
                .collect(Collectors.joining(", "));
        return String.format("""
            {
                "nAula": %d,
                "capienza": %d,
                "tipo": "Laboratorio",
                "accessori": [%s]
            }
            """, getNumeroAula(), getCapienza(), accessoriJson);
    }
}
