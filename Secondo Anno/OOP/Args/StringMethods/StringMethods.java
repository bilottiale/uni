public class StringMethods {
    public static void main(String[] args){
        String name = "John Doe";

        System.out.println(name.length());
        System.out.println(name.toUpperCase());
        System.out.println(name.toLowerCase());
        System.out.println(name.indexOf("Doe"));
        System.out.println(name.charAt(3));
        System.out.println(name.isEmpty());
        System.out.println(name.equals("John Doe"));
        System.out.println(name.equalsIgnoreCase("john doe"));
        System.out.println(name.trim()); // removes leading and trailing white spaces
        System.out.println(name.replace("John", "Jane"));
    }
}
