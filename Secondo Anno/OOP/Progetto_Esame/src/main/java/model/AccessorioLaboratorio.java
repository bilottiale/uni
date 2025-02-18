package model;

import java.util.EnumSet;
import java.util.List;

public enum AccessorioLaboratorio {
    PC, PRESE;

    public static EnumSet<AccessorioLaboratorio> fromStringList(List<String> accessoriList) {
        EnumSet<AccessorioLaboratorio> accessori = EnumSet.noneOf(AccessorioLaboratorio.class);
        if (accessoriList != null) {
            for (String accessorio : accessoriList) {
                if ("LAVAGNA".equalsIgnoreCase(accessorio)) {
                    accessori.add(PC);
                } else if ("PROIETTORE".equalsIgnoreCase(accessorio)) {
                    accessori.add(PRESE);
                }
            }
        }
        return accessori;
    }
}
