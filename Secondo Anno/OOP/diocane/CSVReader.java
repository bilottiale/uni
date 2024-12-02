import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;

public class CSVReader {
    public static void main(String[] args) {
        String fileName = "fifi.csv";

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

// Classe Prenotazione
class Prenotazione {
    private int idAula;
    private LocalDate data;
    private LocalTime oraInizio;
    private LocalTime oraFine;
    private String nomePrenotante;
    private String motivazione;

    public Prenotazione(int idAula, LocalDate data, LocalTime oraInizio, LocalTime oraFine, String nomePrenotante, String motivazione) {
        this.idAula = idAula;
        this.data = data;
        this.oraInizio = oraInizio;
        this.oraFine = oraFine;
        this.nomePrenotante = nomePrenotante;
        this.motivazione = motivazione;
    }

    @Override
    public String toString() {
        return "Prenotazione{" +
                "idAula=" + idAula +
                ", data=" + data +
                ", oraInizio=" + oraInizio +
                ", oraFine=" + oraFine +
                ", nomePrenotante='" + nomePrenotante + '\'' +
                ", motivazione='" + motivazione + '\'' +
                '}';
    }
}
