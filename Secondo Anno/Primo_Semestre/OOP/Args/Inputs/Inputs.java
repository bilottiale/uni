import java.util.Scanner;

public class Inputs {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter your name: ");
        String name = scanner.nextLine(); // next() reads a string until a space is encountered
        System.out.println("Hello " + name);

        System.out.println("Enter a number: ");
        int number = scanner.nextInt(); // nextInt() reads an integer
        System.out.println("You entered: " + number);

        scanner.close();
    }
}