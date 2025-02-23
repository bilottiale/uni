public class IfStatements {
    public static void main(String[] args) {
        int x = 5;
        int y = 10;

        if (x < y) {
            System.out.println("x is less than y");
        }
        else if (x > y) {
            System.out.println("x is greater than y");
        }
        else if (x <= y) {
            System.out.println("x is less than or equal to y");
        }
        else if (x >= y) {
            System.out.println("x is greater than or equal to y");
        }
        else if (x == y) {
            System.out.println("x is equal to y");
        }
        else if (x != y) {
            System.out.println("x is not equal to y");
        }
        else {
            System.out.println("Invalid comparison");
        }
    }
}