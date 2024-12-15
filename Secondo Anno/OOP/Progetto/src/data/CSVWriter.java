package data;

import java.io.*;
import java.util.*;
import model.*;

public class CSVWriter {
    public static void writePrenotazioni(String filePrenotazioni, Prenotazione p) {
        System.out.println("Writing prenotazioni to file: " + filePrenotazioni);
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePrenotazioni, true))) {
            bw.write(p.toString());
            bw.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
