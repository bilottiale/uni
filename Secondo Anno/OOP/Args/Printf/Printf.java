public class Printf {
    public static void main(String[] args) {
        
        // printf() = an optional method to control, format, and display text to the console window
        //            two arguments = format string + (object/variable/value)
        //            % [flags] [precision] [width] [conversion-character]

        boolean myBoolean = true;
        char myChar = '@';
        String myString = "Abc";
        int myInt = 50;
        double myDouble = 1000;

        System.out.printf("%b\n", myBoolean);
        System.out.printf("%c\n", myChar);
        System.out.printf("%s\n", myString);
        System.out.printf("%d\n", myInt);
        System.out.printf("%f\n", myDouble);

        // [width]
        // minimum number of characters to be written as output
        System.out.printf("Hello |%10s\n", myString);
        System.out.printf("Hello %-10s|\n", myString);

        // [precision]
        // adds a restriction on number of characters
        // - : left-justify
        // + : output a plus ( + ) or minus ( - ) sign for a numerical value
        // 0 : numeric values are zero-padded
        // , : comma grouping separator if numbers > 1000

        System.out.printf("You have this much money: |%20f\n", myDouble);
        System.out.printf("You have this much money: %-20f|\n", myDouble);
        System.out.printf("You have this much money: %+f\n", myDouble);
        System.out.printf("You have this much money: %.2f\n", myDouble);
        System.out.printf("You have this much money: %,.2f\n", myDouble);
    }
}
