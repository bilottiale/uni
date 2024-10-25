import java.util.Scanner;

public class Switch {
    public static void main(String[] args) {
        // user input a number
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int x = scanner.nextInt();

        switch (x) {
            case 1:
                System.out.println("x is 1");
                break;
            case 2:
                System.out.println("x is 2");
                break;
            case 3:
                System.out.println("x is 3");
                break;
            case 4:
                System.out.println("x is 4");
                break;
            case 5:
                System.out.println("x is 5");
                break;
            default:
                System.out.println("x is not 1, 2, 3, 4, or 5");
        }

        enum TrafficLight {
            RED, YELLOW, GREEN
        }

        // ask for a traffic light signal
        System.out.println("Enter a traffic light signal (RED, YELLOW, GREEN): ");
        
        TrafficLight light = TrafficLight.RED;
        
        switch (light) {
            case RED:
                System.out.println("Stop");
                break;
            case YELLOW:
                System.out.println("Caution");
                break;
            case GREEN:
                System.out.println("Go");
                break;
            default:
                System.out.println("Invalid signal");
        }
    }
}
