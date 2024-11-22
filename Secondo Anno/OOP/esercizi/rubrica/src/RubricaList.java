import java.util.*;

// with gui
public class RubricaList{
    private ArrayList<Contatto> rubrica = new ArrayList<Contatto>();

    public void aggiungiContatto(Contatto contatto) {
        rubrica.add(contatto);
    }

    public void rimuoviContatto(Contatto contatto) {
        rubrica.remove(contatto);
    }

    public void cancellaTutto() {
        rubrica.clear();
    }

    public Contatto cercaContatto(String cognome) {
        for (Contatto contatto : rubrica) {
            if (contatto.getCognome().equals(cognome)) {
                return contatto;
            }
        }
        return null;
    }

    public void StampaRubrica() {
        for (Contatto contatto : rubrica) {
            System.out.println(contatto);
        }
    }
}
