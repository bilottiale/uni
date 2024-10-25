import java.util.Scanner;

public class LogicalOperators {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the temperature: ");
        int temp = scanner.nextInt();

        if(temp > 30){
            System.out.println("It's hot outside");
        }
        else if(temp >= 20 && temp <= 30){
            System.out.println("It's warm outside");
        }
        else{
            System.out.println("It's cold outside");
        }

        System.out.println("You are playing a game. Press q or Q to quit: ");
        String response = scanner.next();

        if(response.equals("q") || response.equals("Q")){
            System.out.println("You quit the game");
        }
        else{
            System.out.println("You are still playing the game");
        }        
    }
}