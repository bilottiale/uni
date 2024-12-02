package data;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import model.*;

public class CSVReader {
    public static void main(String[] args) {
        String fileName = "prenotazioni.csv";

        // Lista per memorizzare le prenotazioni lette
        List<Prenotazione> prenotazioni = readPrenotazioni(fileName);

        // Stampa le prenotazioni lette
        for (Prenotazione p : prenotazioni) {
            System.out.println(p);
        }
    }

    public static List<Prenotazione> readPrenotazioni(String fileName) {
        List<Prenotazione> prenotazioni = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            boolean firstLine = true;

            // Leggi il file riga per riga
            while ((line = br.readLine()) != null) {
                // Salta l'intestazione
                if (firstLine) {
                    firstLine = false;
                    continue;
                }

                // Dividi la riga in base alla virgola
                String[] parts = line.split(",");

                // Parsing dei dati
                int idAula = Integer.parseInt(parts[0]); // idAula
                LocalDate data = LocalDate.parse(parts[1]); // Formato YYYY-MM-DD
                LocalTime oraInizio = LocalTime.parse(parts[2]); // Formato HH:mm
                LocalTime oraFine = LocalTime.parse(parts[3]); // Formato HH:mm
                String nomePrenotante = parts[4];
                String motivazione = parts[5];

                // Crea un oggetto Prenotazione
                Prenotazione prenotazione = new Prenotazione(idAula, data, oraInizio, oraFine, nomePrenotante, motivazione);

                // Aggiungi alla lista
                prenotazioni.add(prenotazione);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return prenotazioni;
    }
}