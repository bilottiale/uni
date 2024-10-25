import java.util.Scanner;

public class Methods {
    public static void main(String[] args) {
        
        // method = a block of code that is executed whenever it is called upon
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a name: John");
        // String name = scanner.nextLine();
        String name = "John";

        hello(name);

        int x = 3;
        int y = 4;

        System.out.println(add(x, y));
    }

    static void hello(String name) {
        System.out.println("Hello " + name);
    }

    static int add(int a, int b) {
        return a + b;
    }
}
