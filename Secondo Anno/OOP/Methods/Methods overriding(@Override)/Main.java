public class Main {
        public static void main(String[] args) {

        // method overriding = defining a method in a subclass
        //                     that already exists in the parent class.
        //                     So done that a child class can give its own implementation
        //                     to a method which is already provided by its parent class.

        Dog dog = new Dog();
        dog.speak();

        Animal animal = new Animal();
        animal.speak();
    }
}
