package utils;

import com.google.gson.*;
import model.AulaInterface;
import model.AulaDidattica;
import model.Laboratorio;

import java.lang.reflect.Type;

/**
 * Custom Gson adapter for deserializing JSON into {@link AulaInterface}.
 * <p>
 * This adapter determines the specific classroom type ({@link AulaDidattica} or {@link Laboratorio})
 * based on the "tipo" field in the JSON and deserializes accordingly.
 * </p>
 */
public class AulaAdapter implements JsonDeserializer<AulaInterface> {

    /**
     * Deserializes a JSON element into an {@link AulaInterface}.
     * <p>
     * Examines the "tipo" field in the JSON object to decide whether to create an {@link AulaDidattica}
     * or {@link Laboratorio} instance. Throws a {@link JsonParseException} if the type is unrecognized.
     * </p>
     *
     * @param json The JSON element representing the classroom data to deserialize.
     * @param typeOfT The type of the target object (expected to be {@code AulaInterface}).
     * @param context The JSON deserialization context used to deserialize the specific classroom type.
     * @return The deserialized {@link AulaInterface} object, either an {@link AulaDidattica} or {@link Laboratorio}.
     * @throws JsonParseException if the "tipo" field value is neither "{@code DIDATTICA}" nor "{@code LABORATORIO}".
     */
    @Override
    public AulaInterface deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        JsonObject jsonObject = json.getAsJsonObject();
        String tipo = jsonObject.get("tipo").getAsString();

        AulaInterface aula;
        if ("DIDATTICA".equals(tipo)) {
            aula = context.deserialize(json, AulaDidattica.class);
        } else if ("LABORATORIO".equals(tipo)) {
            aula = context.deserialize(json, Laboratorio.class);
        } else {
            throw new JsonParseException("Tipo aula sconosciuto: " + tipo);
        }

        return aula;
    }
}