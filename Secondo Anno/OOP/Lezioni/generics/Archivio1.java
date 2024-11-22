import java.util.ArrayList;

public class Archivio1 {
    private ArrayList<Persona> persone;

    public Archivio1() {
        persone = new ArrayList<>();
    }

    public void aggiungi(Persona p) {
        persone.add(p);
    }

    public void rimuovi(Persona p) {
        persone.remove(p);
    }

    public Persona getPersona(int index) {
        return persone.get(index);
    }

    public int size() {
        return persone.size();
    }
}
