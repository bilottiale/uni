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
    
    public AulaDidattica(int n_aula, int capienza, List<Integer> accessoriList) {
        super(n_aula, capienza, TipoAula.DIDATTICA);
        this.accessori = EnumSet.noneOf(AccessorioDidattica.class);
        
        if(accessoriList != null && !accessoriList.isEmpty()) {
            if(accessoriList.get(0) == 1) {
                this.accessori.add(AccessorioDidattica.LAVAGNA);
            }
            if(accessoriList.size() > 1 && accessoriList.get(1) == 1) {
                this.accessori.add(AccessorioDidattica.PROIETTORE);
            }
        }
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
        return String.format("AulaDidattica [nAula=%d, capienza=%d, accessori=%s]",
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