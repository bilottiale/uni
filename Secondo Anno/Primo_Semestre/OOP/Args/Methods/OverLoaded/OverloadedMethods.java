public class OverloadedMethods {
    public static void main(String[] args) {
        
        // overloaded methods = methods that share the same name but have different parameters
        //                      method name + parameter list = method signature

        System.out.println(add(1, 2));

        System.out.println(add(1.0, 2.0));

        System.out.println(add(1.0, 2.0, 3));

    }

    static int add(int a, int b) {
        System.out.println("This is overloaded method #1");
        return a + b;
    }

    static double add(double a, double b) {
        System.out.println("This is overloaded method #2");
        return a + b;
    }

    static int add(double a, double b, int c) {
        System.out.println("This is overloaded method #3");
        return (int)(a + b + c);
    }
}
