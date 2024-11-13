public class Main {

    public static void main(String[] args) {
        
        // abstract = abstract classes cannot be instantiated, but they can have a subclass
        //            abstract methods are declared without an implementation
        //            abstract classes are meant to be extended
        //            abstract methods must be implemented by the subclass (inherited)
        
        // Vehicle2 vehicle = new Vehicle2(); // error: cannot instantiate the type Vehicle
        Car2 car = new Car2();
        
        car.go();
    }
}
