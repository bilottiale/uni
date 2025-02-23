import java.util.Enumeration;
import java.util.Hashtable;

public class Archivio5<E, R> extends Archivio2<E> {
    private Hashtable<E, R> relazioni;

    public Archivio5() {
        super();
        relazioni = new Hashtable<>();
    }

    public void aggiungiRelazione(E p1, R p2) {
        relazioni.put(p1, p2);
    }

    public void stampaRelazioni() {
        Enumeration<E> chiavi = relazioni.keys();

        while(chiavi.hasMoreElements()) {
            E chiave = chiavi.nextElement();
            System.out.println(chiave + " -> " + relazioni.get(chiave));
        }
    }
}
