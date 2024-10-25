import java.util.ArrayList;

public class ArrayLists {
    
    public static void main(String[] args) {
        // ArrayList = a resizable array
        //             Elements can be added and removed after compilation phase
        //             Store reference data types
        ArrayList<String> food = new ArrayList<String>();
        
        food.add("pizza");
        food.add("hamburger");
        food.add("hotdog");

        for (int i = 0; i < food.size(); i++) {
            System.out.println(food.get(i));
        }

        // Modify elements

        food.set(0, "sushi");
        food.remove(2);
        System.out.println();
        
        for (int i = 0; i < food.size(); i++) {
            System.out.println(food.get(i));
        }

        // Clear the ArrayList
        food.clear();
    }
}
