package utils;

import model.*;
import org.json.JSONArray;
import org.json.JSONObject;
import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;

public class PrenotazioneUtils {
    public static void salvaPrenotazioni(String filename, List<Prenotazione> prenotazioni) {
        JSONArray jsonArray = new JSONArray();
        for (Prenotazione p : prenotazioni) {
            JSONObject jsonObject = new JSONObject();
            jsonObject.put("aula", p.getnAula());
            jsonObject.put("data", p.getData());
            jsonObject.put("oraInizio", p.getInizio());
            jsonObject.put("ore", p.getFine());
            jsonArray.put(jsonObject);
        }
        try (FileWriter file = new FileWriter(filename)) {
            file.write(jsonArray.toString(4));  // Salva con indentazione per leggibilità
        } catch (IOException e) {
            System.err.println("Errore nel salvataggio delle prenotazioni: " + e.getMessage());
        }
    }
    

    public static List<Prenotazione> caricaPrenotazioni(String filename, List<Aula> aule) {
        List<Prenotazione> prenotazioni = new ArrayList<>();
        File file = new File(filename);
        if (!file.exists()) return prenotazioni;
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            StringBuilder jsonString = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                jsonString.append(line);
            }
            
            JSONArray jsonArray = new JSONArray(jsonString.toString());
            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject obj = jsonArray.getJSONObject(i);
                String nomeAula = obj.getString("aula");
                Aula aula = aule.stream().filter(a -> a.getNumeroAula() == Integer.parseInt(nomeAula)).findFirst().orElse(null);
                if (aula == null) continue;
                
                String dataStr = obj.getString("data");
                LocalDate data = LocalDate.parse(dataStr);
                int oraInizio = obj.getInt("oraInizio");
                int ore = obj.getInt("ore");
                LocalTime inizio = LocalTime.of(oraInizio, 0);
                LocalTime fine = inizio.plusHours(ore);
                
                if (aula instanceof Laboratorio) {
                    if (ore % 2 != 0 || ore > 4) continue;
                } else if (aula instanceof AulaDidattica) {
                    if (ore < 1 || ore > 8) continue;
                }
                
                prenotazioni.add(new Prenotazione(aula.getNumeroAula(), data, inizio, fine, "NomePlaceholder", "MotivazionePlaceholder"));
            }
        } catch (IOException e) {
            System.err.println("Errore nel caricamento delle prenotazioni: " + e.getMessage());
        }
        return prenotazioni;
    }

    public static void aggiornaPrenotazione(List<Prenotazione> prenotazioni, int numeroAula, LocalDate nuovaData, LocalTime nuovaOraInizio, LocalTime nuovaOraFine, String nuovoNome, String nuovaMotivazione) {
        for (Prenotazione p : prenotazioni) {
            if (p.getnAula() == numeroAula && p.getData().equals(nuovaData) && p.getInizio().equals(nuovaOraInizio)) {
                p.setData(nuovaData);
                p.setInizio(nuovaOraInizio);
                p.setFine(nuovaOraFine);
                p.setNome(nuovoNome);
                p.setMotivazione(nuovaMotivazione);
                break;  // Prenotazione aggiornata, esci dal ciclo
            }
        }
    }
    
}
