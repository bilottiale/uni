public class Constructor {
    public static void main(String[] args) {

        // constructor = special method that is called when an object is instantiated
        //               constructor has the same name as the class
        //               constructors have no return type

        
        Human human1 = new Human("Rick", 65, 1.75);
        System.out.println(human1.name);
        human1.eat();

        Human human2 = new Human("Morty", 16, 1.50);
        System.out.println(human2.name);
        human2.eat();
    }
}