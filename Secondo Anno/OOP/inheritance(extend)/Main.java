public class Main {
    public static void main(String[] args) {

        // inheritance = the process where one class acquires,
        //               the attributes and methods of another.

        Car car = new Car();

        car.go();

        Bicycle bicycle = new Bicycle();

        bicycle.stop();

        System.out.println("Car speed: " + car.speed);
        System.out.println("Bicycle speed: " + bicycle.speed);

        System.out.println("Car wheels: " + car.wheels);
        System.out.println("Bicycle wheels: " + bicycle.wheels);

        System.out.println("Car doors: " + car.doors);
        System.out.println("Bicycle pedals: " + bicycle.pedals);
    }
}
