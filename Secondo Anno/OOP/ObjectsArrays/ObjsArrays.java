public class ObjsArrays {
    public static void main(String[] args) {

        // int[] numbers = new int[5];
        // char[] characters = new char[5];
        // String[] strings = new String[5];

        // Food[] refrigerator = new Food[3];

        Food food1 = new Food("pizza", "12/12/2020");
        Food food2 = new Food("sushi", "12/12/2020");
        Food food3 = new Food("salad", "12/12/2020");

        Food[] refrigerator = {food1, food2, food3};

        for (int i = 0; i < refrigerator.length; i++) {
            System.out.println(refrigerator[i].name);
        }
    }
}
