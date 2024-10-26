public class Main {
    public static void main(String[] args) throws Exception {

        // Encapsulation = attributes of a class will be hidden or private,
        //                 can be accessed only through methods (getters & setters)
        //                 You should make attributes private if you don't have a reason to make them public/protected

        Car car1 = new Car("Chevrolet", "Impala", 2020);
        // Car car2 = new Car("Toyota", "Yaris", 2021);

        Car car2 = new Car(car1);

        System.out.println(car1);
        System.out.println(car2);

        System.out.println();

        System.out.println("car1:");
        System.out.println(car1.getMake());
        System.out.println(car1.getModel());
        System.out.println(car1.getYear());

        System.out.println();

        System.out.println("car2 is a copy of car1:");
        System.out.println(car2.getMake());
        System.out.println(car2.getModel());
        System.out.println(car2.getYear());

        System.out.println();

        car1.setMake("Ford");
        car1.setModel("Mustang");
        car1.setYear(2021);

        System.out.println("car1 changed:");
        System.out.println(car1.getMake());
        System.out.println(car1.getModel());
        System.out.println(car1.getYear());

        System.out.println();

        System.out.println("car2 still:");
        System.out.println(car2.getMake());
        System.out.println(car2.getModel());
        System.out.println(car2.getYear());

        // car2 = car1; // car2 is now pointing to the same object as car1
        // System.out.println(car1);
        // System.out.println(car2);

        // car2.copy(car1);
        // System.out.println(car1);
        // System.out.println(car2);
    }
}
