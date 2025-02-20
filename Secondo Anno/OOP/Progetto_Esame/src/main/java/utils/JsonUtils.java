package utils;

import com.google.gson.*;
import model.*;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

/**
 * Provides utility methods for reading and writing JSON data related to {@link Aula} and {@link Prenotazione}.
 * <p>
 * This class uses Gson for JSON serialization and deserialization, with custom adapters for handling
 * {@link AulaInterface}, {@link LocalDate}, and {@link LocalTime} objects. It supports reading and writing
 * lists of {@link AulaInterface} and {@link Prenotazione} objects to and from JSON files.
 * </p>
 */
public class JsonUtils {
    /**
     * The path to the JSON file containing classroom data.
     */
    private static final String AULE_FILE_PATH = "data/aule.json";

    /**
     * Reads classroom data from a predefined JSON file into a list of {@link AulaInterface} objects.
     * <p>
     * Uses the file path specified by {@link #AULE_FILE_PATH} ("data/aule.json") to load classroom data.
     * Returns an empty list if an {@link IOException} occurs during reading.
     * </p>
     *
     * @return A {@code List} of {@link AulaInterface} objects deserialized from the JSON file.
     */
    public static List<AulaInterface> leggiAuleDaJson() {
        return leggiDaJson(AULE_FILE_PATH, AulaInterface[].class);
    }

    /**
     * Reads booking data from a specified JSON file into a list of {@link Prenotazione} objects.
     *
     * @param filePath The path to the JSON file containing booking data.
     * @return A {@code List} of {@link Prenotazione} objects deserialized from the file.
     * @throws IOException If an I/O error occurs while reading the file.
     */
    public static List<Prenotazione> leggiPrenotazioniDaJson(String filePath) throws IOException {
        return leggiDaJson(filePath, Prenotazione[].class);
    }

    /**
     * Generic method to read JSON data from a file into a list of objects of type {@code T}.
     * <p>
     * Uses Gson with custom adapters for {@link AulaInterface}, {@link LocalDate}, and {@link LocalTime}
     * to deserialize the JSON content. Returns an empty list if an {@link IOException} occurs, logging the
     * error to the console.
     * </p>
     *
     * @param filePath The path to the JSON file to read.
     * @param classOfT The {@code Class} object representing the array type to deserialize into (e.g., {@code AulaInterface[].class}).
     * @param <T> The type of objects in the array, which must implement or extend the expected interface/class.
     * @return A {@code List} of objects of type {@code T} deserialized from the JSON file.
     */
    private static <T> List<T> leggiDaJson(String filePath, Class<T[]> classOfT) {
        try (FileReader reader = new FileReader(filePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(AulaInterface.class, new AulaAdapter())
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())
                    .setPrettyPrinting()
                    .create();
            T[] array = gson.fromJson(reader, classOfT);
            return new ArrayList<>(List.of(array));
        } catch (IOException e) {
            e.printStackTrace();
            return new ArrayList<>();
        }
    }

    /**
     * Writes a list of {@link Prenotazione} objects to a JSON file at the specified path.
     *
     * @param filePath The path to the JSON file where the bookings will be written.
     * @param prenotazioni The list of {@link Prenotazione} objects to serialize and save.
     * @throws IOException If an I/O error occurs while writing to the file.
     */
    public void scriviPrenotazioniSuJson(String filePath, List<Prenotazione> prenotazioni) throws IOException {
        scriviSuJson(filePath, prenotazioni);
    }

    /**
     * Generic method to write a list of objects of type {@code T} to a JSON file.
     * <p>
     * Uses Gson with custom adapters for {@link LocalDate} and {@link LocalTime} to serialize the objects
     * into a pretty-printed JSON format. Prints an error stack trace to the console if an {@link IOException}
     * occurs during writing.
     * </p>
     *
     * @param filePath The path to the JSON file where the objects will be written.
     * @param objects The list of objects to serialize and save.
     * @param <T> The type of objects in the list.
     */
    private <T> void scriviSuJson(String filePath, List<T> objects) {
        try (FileWriter writer = new FileWriter(filePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())
                    .setPrettyPrinting()
                    .create();
            gson.toJson(objects, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}