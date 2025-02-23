public class While {
    public static void main(String[] args) {
        int x = 1;

        while (x <= 5) {
            System.out.println("x is: " + x);
            x++;
        }

        do {
            System.out.println("x is: " + x);
            x++;
        } while (x <= 10);
    }
}
