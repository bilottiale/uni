package model;

import java.util.EnumSet;
import java.util.List;
import java.util.stream.Collectors;

public class AulaDidattica extends Aula {
    private EnumSet<AccessorioDidattica> accessori;

    public AulaDidattica(int n_aula, int capienza, EnumSet<AccessorioDidattica> accessori) {
        super(n_aula, capienza, TipoAula.DIDATTICA);
        this.accessori = accessori != null ? accessori : EnumSet.noneOf(AccessorioDidattica.class);
    }

    @Override
    public EnumSet<AccessorioDidattica> getAccessori() {
        return accessori;
    }

    public void setAccessori(EnumSet<AccessorioDidattica> accessori) {
        this.accessori = accessori;
    }

    public List<Integer> getAccessoriAsListInt() {
        return List.of(
                this.accessori.contains(AccessorioDidattica.LAVAGNA) ? 1 : 0,
                this.accessori.contains(AccessorioDidattica.PROIETTORE) ? 1 : 0
        );
    }

    @Override
    public String toString() {
        return String.format("Aula Didattica: nAula=%d, capienza=%d, accessori=%s",
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
                "tipo": "Aula Didattica",
                "accessori": [%s]
            }
            """, getNumeroAula(), getCapienza(), accessoriJson);
    }
}
