package model;

import java.util.List;

/**
 * Defines the contract for {@link Aula}, specifying methods to access basic properties
 * and accessories of a {@link Aula}. Implementations of this interface represent specific types
 * of {@link Aula} such as {@link AulaDidattica} or {@link Laboratorio}.
 */
public interface AulaInterface {

    /**
     * Retrieves the unique identifier number of the classroom.
     *
     * @return The classroom number.
     */
    int getNumeroAula();

    /**
     * Retrieves the maximum capacity of the classroom.
     *
     * @return The capacity of the classroom.
     */
    int getCapienza();

    /**
     * Represents the type of classroom, either a {@link Laboratorio} or a {@link AulaDidattica}.
     */
    enum TipoAula {
        /**
         * A {@link Laboratorio} classroom.
         */
        LABORATORIO,

        /**
         * A {@link AulaDidattica}.
         */
        DIDATTICA
    }

    /**
     * Gets the type of the classroom.
     *
     * @return The {@link TipoAula} indicating whether the classroom is a {@code LABORATORIO} or {@code DIDATTICA}.
     */
    TipoAula getTipo();

    /**
     * Retrieves the accessories in the classroom as a list of integers.
     * <p>
     * Each integer in the list represents the presence (1) or absence (0) of a specific accessory,
     * with the order and meaning defined by the implementing class (e.g., lavagna, proiettore for {@link AulaDidattica}).
     * </p>
     *
     * @return A {@code List} of integers representing the accessories.
     */
    List<Integer> getAccessoriAsListInt();

    /**
     * Retrieves the accessories available in the classroom.
     * <p>
     * The specific type of object returned depends on the implementing class (e.g.,
     * {@code EnumSet<AccessorioDidattica>} for {@link AulaDidattica} or
     * {@code EnumSet<AccessorioLaboratorio>} for {@link Laboratorio}).
     * </p>
     *
     * @return An object representing the set of accessories specific to the classroom type.
     */
    Object getAccessori();

    /**
     * Converts the classroom object to a JSON string representation.
     *
     * @return A formatted JSON string containing the classroom's properties, including number,
     *         capacity, type, and accessories.
     */
    String toJson();
}