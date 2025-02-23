package package1;
import package2.*;

public class A {

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        C c = new C();
        System.out.println(c.publicMessage);
        // System.out.println(c.protectedMessage); // protected access modifier allows access to the class itself, subclasses, and classes in the same package
        // System.out.println(c.privateMessage); // private access modifier allows access to the class itself
        // System.out.println(c.defaultMessage); // default access modifier allows access to the class itself and classes in the same package
    }
}
