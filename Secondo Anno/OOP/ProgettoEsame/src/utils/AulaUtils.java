package utils;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import model.*;
import model.Aula.AccessorioDidattica;
import model.Aula.AccessorioLaboratorio;

public class AulaUtils {
    private static final String FILE_PATH = "data/aule.json";

    public static List<Aula> leggiAule() {
        List<Aula> aule = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String json = reader.lines()
                    .map(String::trim)
                    .reduce("", String::concat);

            // Basic JSON array parsing
            String[] objects = json.substring(json.indexOf('[') + 1, json.lastIndexOf(']'))
                    .split("\\},\\s*\\{");

            for (String obj : objects) {
                // Clean the object string
                obj = obj.trim();
                if (!obj.startsWith("{"))
                    obj = "{" + obj;
                if (!obj.endsWith("}"))
                    obj = obj + "}";

                // Extract values using simple string operations
                int nAula = extractInt(obj, "nAula");
                int capienza = extractInt(obj, "capienza");
                String tipo = extractString(obj, "tipo");
                List<String> accessori = extractArray(obj, "accessori");

                // Create appropriate aula type
                if (tipo.equalsIgnoreCase("Laboratorio")) {
                    EnumSet<AccessorioLaboratorio> accessoriLab = EnumSet.noneOf(AccessorioLaboratorio.class);
                    for (String acc : accessori) {
                        try {
                            accessoriLab.add(AccessorioLaboratorio.valueOf(acc.toUpperCase()));
                        } catch (IllegalArgumentException e) {
                            System.err.println("Accessorio laboratorio non riconosciuto: " + acc);
                        }
                    }
                    aule.add(new Laboratorio(nAula, capienza, accessoriLab));
                } else if (tipo.equalsIgnoreCase("Aula Didattica")) {
                    EnumSet<AccessorioDidattica> accessoriDid = EnumSet.noneOf(AccessorioDidattica.class);
                    for (String acc : accessori) {
                        try {
                            accessoriDid.add(AccessorioDidattica.valueOf(acc.toUpperCase()));
                        } catch (IllegalArgumentException e) {
                            System.err.println("Accessorio didattico non riconosciuto: " + acc);
                        }
                    }
                    aule.add(new AulaDidattica(nAula, capienza, accessoriDid));
                }
            }
        } catch (IOException e) {
            System.err.println("Errore nella lettura del file: " + e.getMessage());
        }
        return aule;
    }

    private static int extractInt(String json, String key) {
        String value = extractString(json, key);
        return Integer.parseInt(value);
    }

    private static String extractString(String json, String key) {
        int start = json.indexOf("\"" + key + "\"");
        if (start == -1)
            return "";

        start = json.indexOf(":", start) + 1;
        while (start < json.length() && Character.isWhitespace(json.charAt(start)))
            start++;

        boolean isQuoted = json.charAt(start) == '"';
        if (isQuoted)
            start++;

        int end = start;
        while (end < json.length()) {
            char c = json.charAt(end);
            if (isQuoted && c == '"')
                break;
            if (!isQuoted && (c == ',' || c == '}'))
                break;
            end++;
        }

        return json.substring(start, end).trim();
    }

    private static List<String> extractArray(String json, String key) {
        List<String> result = new ArrayList<>();
        int start = json.indexOf("\"" + key + "\"");
        if (start == -1)
            return result;

        start = json.indexOf("[", start) + 1;
        int end = json.indexOf("]", start);

        String arrayContent = json.substring(start, end);
        String[] elements = arrayContent.split(",");

        for (String element : elements) {
            element = element.trim().replace("\"", "");
            if (!element.isEmpty()) {
                result.add(element);
            }
        }

        return result;
    }

    // get prenotazioni by aula
    public static List<Prenotazione> getPrenotazioniByAula(int numeroAula) {
        List<Prenotazione> prenotazioni = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader("data/prenotazioni.json"))) {
            String json = reader.lines()
                    .map(String::trim)
                    .reduce("", String::concat);

            String[] objects = json.substring(json.indexOf('[') + 1, json.lastIndexOf(']'))
                    .split("\\},\\s*\\{");

            for (String obj : objects) {
                obj = obj.trim();
                if (!obj.startsWith("{"))
                    obj = "{" + obj;
                if (!obj.endsWith("}"))
                    obj = obj + "}";

                int nAula = extractInt(obj, "nAula");
                if (nAula == numeroAula) {
                    LocalDate data = LocalDate.parse(extractString(obj, "data"));
                    LocalTime inizio = LocalTime.parse(extractString(obj, "inizio"));
                    LocalTime fine = LocalTime.parse(extractString(obj, "fine"));
                    String nome = extractString(obj, "nome");
                    String motivazione = extractString(obj, "motivazione");
                    prenotazioni.add(new Prenotazione(nAula, data, inizio, fine, nome, motivazione));
                }
            }
        } catch (IOException e) {
            System.err.println("Errore nella lettura del file: " + e.getMessage());
        }
        return prenotazioni;
    }

    public static void stampaAule() {
        List<Aula> aule = leggiAule();
        for (Aula a : aule) {
            System.out.println("Aula: " + a.getNumeroAula());
            System.out.println("Capienza: " + a.getCapienza());
            System.out.println("Tipo: " + a.getTipo());
            System.out.println("Accessori: " + a.getAccessori());
            System.out.println("--------------------");
        }
    }
}