import java.util.*;

public class ddArrayLists {
    public static void main(String[] args) {
        ArrayList<ArrayList<String>> groceryList = new ArrayList<ArrayList<String>>();

        ArrayList<String> bakeryList = new ArrayList<String>();
        bakeryList.add("bread");
        bakeryList.add("cake");
        bakeryList.add("muffin");

        System.out.println(bakeryList);
        System.out.println(bakeryList.get(1));

        ArrayList<String> produceList = new ArrayList<String>();
        produceList.add("apple");
        produceList.add("banana");
        produceList.add("carrot");

        ArrayList<String> drinks = new ArrayList<String>();
        drinks.add("coffee");
        drinks.add("tea");

        System.out.println(drinks);

        groceryList.add(bakeryList);
        groceryList.add(produceList);
        groceryList.add(drinks);

        System.out.println(groceryList);
    }
}
