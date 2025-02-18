package model;

import java.util.EnumSet;
import java.util.List;

public enum AccessorioDidattica {
    LAVAGNA, PROIETTORE;

    public static EnumSet<AccessorioDidattica> fromStringList(List<String> accessoriList) {
        EnumSet<AccessorioDidattica> accessori = EnumSet.noneOf(AccessorioDidattica.class);
        if (accessoriList != null) {
            for (String accessorio : accessoriList) {
                if ("LAVAGNA".equalsIgnoreCase(accessorio)) {
                    accessori.add(LAVAGNA);
                } else if ("PROIETTORE".equalsIgnoreCase(accessorio)) {
                    accessori.add(PROIETTORE);
                }
            }
        }
        return accessori;
    }
}
