import java.util.*;

public class ForEach {
    public static void main(String[] args) {
        
        // for-each = traversing technique to iterate through the elements in an array/collection
        //            less steps, more readable
        //            less flexible

        String[] animals = {"cat", "dog", "rat", "bird"};

        for(String i : animals) {
            System.out.println(i);
        }

        // or
        System.out.println();

        ArrayList<String> animalss = new ArrayList<String>();

        animalss.add("cat");
        animalss.add("dog");
        animalss.add("rat");
        animalss.add("bird");

        for(String i : animalss) {
            System.out.println(i);
        }
    }
}
