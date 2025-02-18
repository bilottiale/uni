package utils;

import model.*;
import com.google.gson.*;
import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;

public class PrenotazioneUtils {
    private static final String FILE_PATH = "data/prenotazioni.json";

    // print the file
    public static void stampaPrenotazioni() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String json = reader.lines()
                    .map(String::trim)
                    .reduce("", String::concat);

            System.out.println(json);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
