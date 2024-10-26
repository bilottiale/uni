package package2;
import package1.*;

public class C {

    public String publicMessage = "This is a public message";  // public access modifier allows access to the class itself, subclasses, classes in the same package, and classes in other packages
    protected String protectedMessage = "This is a protected message";  // protected access modifier allows access to the class itself, subclasses, and classes in the same package
    private String privateMessage = "This is a private message";  // private access modifier allows access to the class itself
    String defaultMessage = "This is a default message";  // default access modifier allows access to the class itself and classes in the same package
}
