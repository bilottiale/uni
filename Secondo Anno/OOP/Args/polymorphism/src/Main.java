public class Main {
    public static void main(String[] args) throws Exception {

        // polymorphism = greek wrord for poly-"many", morph-"form".
        //                The ability of an object to identify as more than one type

        Car car = new Car();
        Bicycle bicycle = new Bicycle();
        Boat boat = new Boat();

        // Car[] racers = {car, boat, bicycle}; // This will not work because the array is of type Car
        Vehicle[] racers = {car, boat, bicycle}; // This will work because the array is of type Vehicle

        for (Vehicle x : racers) {
            x.go();
        }
    }
}
