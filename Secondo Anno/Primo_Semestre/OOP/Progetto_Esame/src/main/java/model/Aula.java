package model;

/**
 * Represents an abstract classroom with basic properties such as number, capacity, and type.
 * This class serves as a base for specific classroom types implementing {@link AulaInterface}.
 */
public abstract class Aula implements AulaInterface {
    /** The unique identifier number of the classroom. */
    private final int n_aula;
    /** The maximum capacity of the classroom in terms of people it can accommodate. */
    private final int capienza;
    /** The type of classroom, either {@code LABORATORIO} or {@code DIDATTICA}. */
    private final TipoAula tipo;

    /**
     * Creates a new Aula object with the specified parameters.
     *
     * @param n_aula The unique identifier number of the classroom.
     * @param capienza The maximum capacity of the classroom in terms of people it can accommodate.
     * @param tipo The type of classroom, either {@code LABORATORIO} or {@code DIDATTICA}.
     */
    public Aula(int n_aula, int capienza, TipoAula tipo) {
        this.n_aula = n_aula;
        this.capienza = capienza;
        this.tipo = tipo;
    }

    /**
     * Retrieves the unique identifier number of the classroom.
     *
     * @return The classroom number.
     */
    @Override
    public int getNumeroAula() {
        return n_aula;
    }

    /**
     * Retrieves the maximum capacity of the classroom.
     *
     * @return The capacity of the classroom in terms of people it can hold.
     */
    @Override
    public int getCapienza() {
        return capienza;
    }

    /**
     * Retrieves the type of the classroom.
     *
     * @return The classroom type as defined by {@link TipoAula}.
     */
    @Override
    public TipoAula getTipo() {
        return tipo;
    }

    /**
     * Retrieves the accessories available in the classroom.
     * <p>
     * This method must be implemented by concrete subclasses to return the specific accessories
     * appropriate to their type (e.g., {@code EnumSet<AccessorioDidattica>} for didactic classrooms
     * or {@code EnumSet<AccessorioLaboratorio>} for laboratories).
     * </p>
     *
     * @return An object representing the accessories, typically an {@code EnumSet} of accessory types.
     */
    public abstract Object getAccessori();

    /**
     * Returns a JSON string representation of the Aula object.
     *
     * @return A formatted JSON string containing the classroom number, capacity, and type.
     */
    @Override
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