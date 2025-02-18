package utils;

import com.google.gson.*;
import model.*;

import java.lang.reflect.Type;

public class AulaAdapter implements JsonDeserializer<Aula> {
    @Override
    public Aula deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        JsonObject jsonObject = json.getAsJsonObject();
        String tipo = jsonObject.get("tipo").getAsString();

        Aula aula;
        if ("DIDATTICA".equals(tipo)) {
            aula = context.deserialize(json, AulaDidattica.class);
        } else if ("LABORATORIO".equals(tipo)) {
            aula = context.deserialize(json, Laboratorio.class);
        } else {
            throw new JsonParseException("Tipo aula sconosciuto: " + tipo);
        }

        // Imposta il tipo dell'aula correttamente
        aula.setTipo(Aula.TipoAula.valueOf(tipo));

        return aula;
    }
}
