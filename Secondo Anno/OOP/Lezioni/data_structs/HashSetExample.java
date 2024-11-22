import java.util.*;

public class HashSetExample {
    public static void main(String[] args) {
        // Creating a HashSet
        HashSet<String> hs = new HashSet<String>();

        // Adding elements into the HashSet
        // using add()
        hs.add("India");
        hs.add("Australia");
        hs.add("South Africa");

        // Adding the duplicate
        // element
        hs.add("India");

        // Displaying the HashSet
        System.out.println(hs);

        // Removing items from HashSet
        // using remove()
        hs.remove("Australia");
        System.out.println("Set after removing " + "Australia:" + hs);

        // Iterating over hash set items
        System.out.println("Iterating over set:");
        Iterator<String> i = hs.iterator();
        while (i.hasNext())
            System.out.println(i.next());
    }
}
