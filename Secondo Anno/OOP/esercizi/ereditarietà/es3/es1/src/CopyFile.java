import java.io.*;

public class CopyFile {
  public static void main(String[] args) {
    // Verifica dei parametri dalla linea di comando
    if (args.length != 2) {
      System.out.println("Uso: java FileCopier <fileSorgente> <fileDestinazione>");
      return;
    }

    String fileSorgente = args[0];
    String fileDestinazione = args[1];

    try (
        FileInputStream inputStream = new FileInputStream(fileSorgente);
        FileOutputStream outputStream = new FileOutputStream(fileDestinazione)) {
      // Buffer per la copia
      byte[] buffer = new byte[1024];
      int bytesRead;

      // Copia del contenuto del file
      while ((bytesRead = inputStream.read(buffer)) != -1) {
        outputStream.write(buffer, 0, bytesRead);
      }

      System.out.println("File copiato con successo da " + fileSorgente + " a " + fileDestinazione);
    } catch (IOException e) {
      System.err.println("Errore durante la copia del file: " + e.getMessage());
    }
  }
}
