package utils;

import com.google.gson.*;
import java.lang.reflect.Type;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

/**
 * Custom Gson adapter for serializing and deserializing {@link LocalTime} to and from a JSON file.
 * <p>
 * Uses the "HH:mm" format (e.g., "14:30") for representing time.
 * </p>
 */
public class LocalTimeAdapter implements JsonSerializer<LocalTime>, JsonDeserializer<LocalTime> {
    /** The time formatter for parsing and formatting times in the "HH:mm" format. */
    private final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");

    /**
     * Serializes a {@link LocalTime} into a JSON string.
     * <p>
     * Formats the time as "HH:mm" (e.g., "14:30") using the predefined {@link DateTimeFormatter}.
     * </p>
     *
     * @param src The {@link LocalTime} object to serialize.
     * @param typeOfSrc The type of the source object (expected to be {@code LocalTime}).
     * @param context The JSON serialization context.
     * @return A {@link JsonPrimitive} containing the formatted time string.
     */
    @Override
    public JsonElement serialize(LocalTime src, Type typeOfSrc, JsonSerializationContext context) {
        return new JsonPrimitive(src.format(formatter));
    }

    /**
     * Deserializes a JSON element into a {@link LocalTime} object.
     * <p>
     * Parses the JSON string using the "HH:mm" format (e.g., "14:30") to create a {@link LocalTime} instance.
     * </p>
     *
     * @param json The JSON element containing the time string to deserialize.
     * @param typeOfT The type of the target object (expected to be {@code LocalTime}).
     * @param context The JSON deserialization context.
     * @return The deserialized {@link LocalTime} object.
     * @throws JsonParseException if the JSON string cannot be parsed into a valid {@link LocalTime}.
     */
    @Override
    public LocalTime deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        return LocalTime.parse(json.getAsString(), formatter);
    }
}