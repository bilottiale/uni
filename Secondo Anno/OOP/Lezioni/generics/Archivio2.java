import java.util.Vector;

public class Archivio2<E> {
    private Vector<E> persone;

    public Archivio2() {
        persone = new Vector<E>();
    }

    public void aggiungi(E p) {
        persone.add(p);
    }

    public void rimuovi(E p) {
        persone.remove(p);
    }

    public E get(int index) {
        return (E)persone.get(index);
    }

    public int size() {
        return persone.size();
    }
}