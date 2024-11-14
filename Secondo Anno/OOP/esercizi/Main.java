public class Main {
  public static void main(String[] args) {
    // Creazione di un oggetto di tipo C
    C calcolatriceBase = new C(10);

    // Creazione di un oggetto di tipo SubC, ma riferito come tipo C
    C calcolatriceSpecializzata = new SubC(10);

    // Comportamento dell'addizione nella classe C
    calcolatriceBase.addizione(5); // Somma 5 a 10, risultato atteso: 15
    System.out.println("Risultato calcolatriceBase(C) dopo addizione di 5: " + calcolatriceBase.leggiRisultato());

    // Comportamento dell'addizione nella classe SubC
    calcolatriceSpecializzata.addizione(-3); // Genera un errore perché è un oggetto SubC
    System.out.println("Risultato calcolatriceSpecializzata(SubC) dopo tentativo di addizione di -3: "
        + calcolatriceSpecializzata.leggiRisultato());

    // Addizione di un valore positivo a calcolatriceSpecializzata
    calcolatriceSpecializzata.addizione(5); // Somma 5 a 10, risultato atteso: 15
    System.out.println("Risultato calcolatriceSpecializzata(SubC) dopo addizione di 5: "
        + calcolatriceSpecializzata.leggiRisultato());
  }
}
