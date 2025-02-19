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

public class JsonUtils {
    // Path to JSON files
    private static final String AULE_FILE_PATH = "data/aule.json";
    private static final String PRENOTAZIONI_FILE_PATH = "data/prenotazioni.json";

    public static List<Aula> leggiAuleDaJson() {
        return leggiDaJson(AULE_FILE_PATH, Aula[].class);
    }

    public static List<Prenotazione> leggiPrenotazioniDaJson(String filePath) throws IOException {
        return leggiDaJson(filePath, Prenotazione[].class);
    }

    private static <T> List<T> leggiDaJson(String filePath, Class<T[]> classOfT) {
        try (FileReader reader = new FileReader(filePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(Aula.class, new AulaAdapter())
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

    public void scriviAuleSuJson(List<Aula> aule) {
        scriviSuJson(AULE_FILE_PATH, aule);
    }

    public void scriviPrenotazioniSuJson(String filePath, List<Prenotazione> prenotazioni) throws IOException {
        scriviSuJson(filePath, prenotazioni);
    }

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

    public static boolean valida(Prenotazione prenotazione) {
        // Validation logic
        if (prenotazione.getNome().isEmpty() || prenotazione.getMotivazione().isEmpty()) {
            return false;
        }

        Aula.TipoAula tipoAula = prenotazione.getTipoAula(prenotazione.getnAula());
        LocalTime inizio = prenotazione.getOraInizio();
        LocalTime fine = prenotazione.getOraFine();

        int durataOre = fine.getHour() - inizio.getHour();
        if (inizio.getMinute() != 0 || fine.getMinute() != 0) {
            return false;
        }

        if (tipoAula == Aula.TipoAula.DIDATTICA) {
            return durataOre >= 1 && durataOre <= 8;
        } else if (tipoAula == Aula.TipoAula.LABORATORIO) {
            return durataOre == 2 || durataOre == 4;
        }
        return false;
    }
}