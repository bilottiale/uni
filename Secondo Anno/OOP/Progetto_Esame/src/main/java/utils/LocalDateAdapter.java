package utils;

import com.google.gson.*;
import java.lang.reflect.Type;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

/**
 * Custom Gson adapter for serializing and deserializing {@link LocalDate} to and from JSON file.
 * <p>
 * Uses the "yyyy-MM-dd" format (e.g., "2025-01-01") for representing dates in JSON.
 * </p>
 */
public class LocalDateAdapter implements JsonSerializer<LocalDate>, JsonDeserializer<LocalDate> {
    /** The date formatter for parsing and formatting dates in the "yyyy-MM-dd" format. */
    private final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

    /**
     * Serializes a {@link LocalDate} into a JSON string.
     * <p>
     * Formats the date as "yyyy-MM-dd" (e.g., "2023-12-25") using the predefined {@link DateTimeFormatter}.
     * </p>
     *
     * @param src The {@link LocalDate} object to serialize.
     * @param typeOfSrc The type of the source object (expected to be {@code LocalDate}).
     * @param context The JSON serialization context.
     * @return A {@link JsonPrimitive} containing the formatted date string.
     */
    @Override
    public JsonElement serialize(LocalDate src, Type typeOfSrc, JsonSerializationContext context) {
        return new JsonPrimitive(src.format(formatter));
    }

    /**
     * Deserializes a JSON element into a {@link LocalDate} object.
     * <p>
     * Parses the JSON string using the "yyyy-MM-dd" format (e.g., "2023-12-25") to create a {@link LocalDate} instance.
     * </p>
     *
     * @param json The JSON element containing the date string to deserialize.
     * @param typeOfT The type of the target object (expected to be {@code LocalDate}).
     * @param context The JSON deserialization context.
     * @return The deserialized {@link LocalDate} object.
     * @throws JsonParseException if the JSON string cannot be parsed into a valid {@link LocalDate}.
     */
    @Override
    public LocalDate deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        return LocalDate.parse(json.getAsString(), formatter);
    }
}