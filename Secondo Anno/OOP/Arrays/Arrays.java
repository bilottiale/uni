public class Arrays {
    public static void main(String[] args) {
        String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};

        for (int i = 0; i < cars.length; i++) {
            System.out.println(cars[i]);
        }

        String[] names = new String[4];

        names[0] = "John";
        names[1] = "Paul";
        names[2] = "George";
        names[3] = "Ringo";

        for (int i = 0; i < names.length; i++) {
            System.out.println(names[i]);
        }
    }
}
