import java.util.ArrayList;
import java.util.List;

public class ArrList {
    public static void main(String[] args) {
        // Dichiarazione con Generics
        List<Integer> al = new ArrayList<>();
        
        // Aggiunta di elementi con autoboxing
        al.add(10); 
        al.add(25); 
        al.add(13); 
        al.add(7);

        // Stampa della lista
        System.out.println(al); // [10, 25, 13, 7]

        // Iterazione usando for-each
        for (int i : al) {
            System.out.println(i); // Stampa ogni elemento della lista
        }

        // Accesso diretto a un elemento
        System.out.println(al.get(2)); // 13
    }
}
