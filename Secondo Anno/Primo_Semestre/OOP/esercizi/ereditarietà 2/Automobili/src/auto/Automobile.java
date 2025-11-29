package auto;

import motori.Motore;
import java.util.ArrayList;
import java.util.List;

public class Automobile {
  private String targa, marca, modello;
  private Motore motore;
  private List<Optional> optionalList; // Lista degli optional

  public Automobile(String targa, String marca, String modello, Motore motore) {
    this.targa = targa;
    this.marca = marca;
    this.modello = modello;
    this.motore = motore;
    this.optionalList = new ArrayList<>();
  }

  public void aggiungiOptional(Optional optional) {
    optionalList.add(optional);
  }

  public void stampaDettagli() {
    System.out.println("Automobile:");
    System.out.println("Targa: " + targa);
    System.out.println("Marca: " + marca);
    System.out.println("Modello: " + modello);
    System.out.println("Motore: ");
    System.out.println("  Cilindrata: " + motore.getCilindrata() + "cc");
    System.out.println("  Cilindri: " + motore.getCilindri());
    System.out.println("  Potenza: " + motore.getPotenza() + " CV");
    System.out.println("  Tipo: " + (motore.isDiesel() ? "Diesel" : "Benzina"));
    System.out.println("  RPM Max: " + motore.maxRPM());
    System.out.println("Optional:");
    for (Optional opt : optionalList) {
      System.out.println("  " + opt);
    }
  }
}
