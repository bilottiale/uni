package model;

import java.util.EnumSet;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Represents a {@code Laboratorio} classroom, extends {@link Aula} class and implementing
 * {@link AulaInterface}. This class encapsulates properties specific to a {@code Laboratorio},
 */
public class Laboratorio extends Aula implements AulaInterface {
    /** The set of accessories available in the laboratory. */
    private final EnumSet<AccessorioLaboratorio> accessori;

    /**
     * Constructs a new {@code Laboratorio} instance with the specified parameters.
     * <p>
     * Initializes the laboratory with a number, capacity, and a set of laboratory accessories.
     * If the provided accessories set is {@code null}, an empty set is used instead.
     * The classroom type is set to {@code LABORATORIO}.
     * </p>
     *
     * @param n_aula The unique identifier number of the laboratory classroom.
     * @param capienza The maximum capacity of the laboratory in terms of people it can accommodate.
     * @param accessori An {@code EnumSet} of {@link AccessorioLaboratorio} representing the accessories
     *                  available in the laboratory, or {@code null} for an empty set.
     */
    public Laboratorio(int n_aula, int capienza, EnumSet<AccessorioLaboratorio> accessori) {
        super(n_aula, capienza, TipoAula.LABORATORIO);
        this.accessori = accessori != null ? accessori : EnumSet.noneOf(AccessorioLaboratorio.class);
    }

    /**
     * Retrieves the set of accessories available in this classroom.
     *
     * @return An {@code EnumSet} of {@link AccessorioLaboratorio} representing the accessories.
     */
    @Override
    public EnumSet<AccessorioLaboratorio> getAccessori() {
        return accessori;
    }

    /**
     * Retrieves the accessories in the laboratory as a list of integers.
     * <p>
     * Returns a list where each element corresponds to the presence (1) or absence (0) of specific
     * accessories: index 0 for {@code PC} and index 1 for {@code PRESE}.
     * </p>
     *
     * @return A {@code List} of integers representing the presence of accessories.
     */
    @Override
    public List<Integer> getAccessoriAsListInt() {
        return List.of(
                this.accessori.contains(AccessorioLaboratorio.PC) ? 1 : 0,
                this.accessori.contains(AccessorioLaboratorio.PRESE) ? 1 : 0
        );
    }

    /**
     * Returns a string representation of this {@code Laboratorio} classroom.
     *
     * @return A formatted string containing the classroom number, capacity, and accessories.
     */
    @Override
    public String toString() {
        return String.format("Laboratorio: nAula=%d, capienza=%d, accessori=%s",
                getNumeroAula(), getCapienza(), accessori);
    }

    /**
     * Converts this {@code Laboratorio} classroom to a JSON string.
     * <p>
     * The JSON includes the classroom number, capacity, type ("Laboratorio"), and a list of
     * accessories represented as integers (1 for present, 0 for absent).
     * </p>
     *
     * @return A formatted JSON string representing this {@code Laboratorio}.
     */
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