package model;

import java.util.EnumSet;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Represents an {@code AulaDidattica}, extends {@link Aula} class and implementing
 * {@link AulaInterface}. This class encapsulates properties specific to an {@code AulaDidattica}.
 */
public class AulaDidattica extends Aula implements AulaInterface {
    /** The set of accessories available in the classroom. */
    private final EnumSet<AccessorioDidattica> accessori;

    /**
     * Constructs a new {@code AulaDidattica} instance with the specified parameters.
     * <p>
     * Initializes the classroom with a number, capacity, and a set of didactic accessories.
     * If the provided accessories set is {@code null}, an empty set is used instead.
     * The classroom type is set to {@code DIDATTICA}.
     * </p>
     *
     * @param n_aula The unique identifier number of the classroom.
     * @param capienza The maximum capacity of the classroom.
     * @param accessori An {@code EnumSet} of {@link AccessorioDidattica} representing the accessories
     *                  available in the {@code AulaDidattica}, or {@code null} for an empty set.
     */
    public AulaDidattica(int n_aula, int capienza, EnumSet<AccessorioDidattica> accessori) {
        super(n_aula, capienza, TipoAula.DIDATTICA);
        this.accessori = accessori != null ? accessori : EnumSet.noneOf(AccessorioDidattica.class);
    }

    /**
     * Retrieves the set of accessories available in this classroom.
     *
     * @return An {@code EnumSet} of {@link AccessorioDidattica} representing the accessories.
     */
    @Override
    public EnumSet<AccessorioDidattica> getAccessori() {
        return accessori;
    }

    /**
     * Retrieves the accessories in the classroom as a list of integers.
     * <p>
     * Returns a list where each element corresponds to the presence (1) or absence (0) of a specific accessories.
     * accessories: index 0 for {@code LAVAGNA} and index 1 for {@code PROIETTORE}.
     * </p>
     *
     * @return A {@code List} of integers representing the presence of accessories.
     */
    @Override
    public List<Integer> getAccessoriAsListInt() {
        return List.of(
                this.accessori.contains(AccessorioDidattica.LAVAGNA) ? 1 : 0,
                this.accessori.contains(AccessorioDidattica.PROIETTORE) ? 1 : 0
        );
    }

    /**
     * Returns a string representation of this {@code AulaDidattica}.
     *
     * @return A formatted string containing the classroom number, capacity, and accessories.
     */
    @Override
    public String toString() {
        return String.format("Aula Didattica: nAula=%d, capienza=%d, accessori=%s",
                getNumeroAula(), getCapienza(), accessori);
    }

    /**
     * Converts this {@code AulaDidattica} to a JSON string.
     * <p>
     * The JSON includes the classroom number, capacity, type ("Aula Didattica"), and a list of
     * accessories represented as integers (1 for present, 0 for absent).
     * </p>
     *
     * @return A formatted JSON string representing this {@code AulaDidattica}.
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
                "tipo": "Aula Didattica",
                "accessori": [%s]
            }
            """, getNumeroAula(), getCapienza(), accessoriJson);
    }
}