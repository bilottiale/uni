import java.util.*;

class MapExample {

    public static void main(String args[])
    {
        // Creating an empty HashMap
        Map<String, Integer> hm = new HashMap<String, Integer>();

        // Inserting pairs in above Map
        // using put() method
        hm.put("a", 10);
        hm.put("b", 20);
        hm.put("c", 30);

        // Traversing through Map using for-each loop
        for (Map.Entry<String, Integer> me : hm.entrySet()) {
            // Printing keys
            System.out.print(me.getKey() + ":");
            System.out.println(me.getValue());
        }
    }
}