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
import model.Prenotazione;

public class JsonUtils {
//    static final String auleFilePath = "data/aule.json";

    public static List<Aula> leggiAuleDaJson(String auleFilePath) {
        try (FileReader reader = new FileReader(auleFilePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(Aula.class, new AulaAdapter())
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())
                    .setPrettyPrinting()
                    .create();
            Aula[] auleArray = gson.fromJson(reader, Aula[].class);
            return new ArrayList<>(List.of(auleArray));
        } catch (IOException e) {
            e.printStackTrace();
            return List.of();
        }
    }

    public void scriviAuleSuJson(String auleFilePath, List<Aula> aule) {
        try (FileWriter writer = new FileWriter(auleFilePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())  // Registra l'adattatore per LocalDate
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())  // Registra l'adattatore per LocalTime
                    .setPrettyPrinting()
                    .create();
            gson.toJson(aule, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<Prenotazione> leggiPrenotazioniDaJson(String filePath) {
        try (FileReader reader = new FileReader(filePath)) {
            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())  // Registra l'adattatore per LocalDate
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())  // Registra l'adattatore per LocalTime
                    .create();
            Prenotazione[] prenotazioniArray = gson.fromJson(reader, Prenotazione[].class);
            return new ArrayList<>(List.of(prenotazioniArray));
        } catch (IOException e) {
            e.printStackTrace();
            return List.of();
        }
    }

    public static boolean valida(Prenotazione prenotazione) {
        Aula.TipoAula tipoAula = prenotazione.getTipoAula(prenotazione.getnAula());
        LocalTime inizio = prenotazione.getOraInizio();
        LocalTime fine = prenotazione.getOraFine();

        int durataOre = fine.getHour() - inizio.getHour();
        int durataMinuti = fine.getMinute() - inizio.getMinute();
        if (durataMinuti != 0) {
            return false;
        }
        if (tipoAula == Aula.TipoAula.DIDATTICA) {
            return durataOre >= 1 && durataOre <= 8;
        } else if (tipoAula == Aula.TipoAula.LABORATORIO) {
            return durataOre == 2 || durataOre == 4;
        }
        return false;
    }

    public void scriviPrenotazioniSuJson(String filePath, Prenotazione prenotazione) {
        try (FileWriter writer = new FileWriter(filePath, true)) {  // true per aggiungere a fine file
            // Prima validiamo la prenotazione
            boolean isValida = valida(prenotazione);  // Chiamata corretta alla funzione valida
            if (!isValida) {
                throw new IllegalArgumentException("Prenotazione non valida");
            }

            Gson gson = new GsonBuilder()
                    .registerTypeAdapter(LocalDate.class, new LocalDateAdapter())
                    .registerTypeAdapter(LocalTime.class, new LocalTimeAdapter())
                    .setPrettyPrinting()
                    .create();

            gson.toJson(prenotazione, writer);
        } catch (IOException | IllegalArgumentException e) {
            e.printStackTrace();
        }
    }

}
