import java.io.*;

public class fileCopy {
  public static void main(String[] args) {

    if (args.length != 2) {
      System.out.println("Use: java fileCopy <sourceFile> <outputFile>");
      return;
    }

    String sourceFile = args[0];
    String outputFile = args[1];

    try (FileInputStream fileInput = new FileInputStream(sourceFile);
        FileOutputStream fileOutput = new FileOutputStream(outputFile)) {
      int readByte;
      while ((readByte = fileInput.read()) != -1) {
        fileOutput.write(readByte);
      }
      System.out.println("Copying from " + sourceFile + " to " + outputFile);
    } catch (IOException e) {
      System.err.println("Error while copying: " + e.getMessage());
    }
  }
}
