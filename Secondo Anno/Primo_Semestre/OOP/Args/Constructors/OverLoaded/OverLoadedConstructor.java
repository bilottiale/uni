public class OverLoadedConstructor {
    public static void main(String[] args) {
        
        // overloaded constructor = multiple constructors within a class with the same name,
        //                          but have different parameters
        //                          name + parameter list = signature

        Pizza pizza1 = new Pizza("thick crust", "tomato", "mozzarella", "pepperoni");
        System.out.println("Here are the ingredients of your pizza:");
        System.out.println(pizza1.bread);
        System.out.println(pizza1.sauce);
        System.out.println(pizza1.cheese);
        System.out.println(pizza1.topping);

        System.out.println();

        Pizza pizza2 = new Pizza("thick crust", "tomato", "mozzarella");
        System.out.println("Here are the ingredients of your pizza:");
        System.out.println(pizza2.bread);
        System.out.println(pizza2.sauce);
        System.out.println(pizza2.cheese);
        System.out.println(pizza2.topping);

        System.out.println();

        Pizza pizza3 = new Pizza("thick crust", "tomato");
        System.out.println("Here are the ingredients of your pizza:");
        System.out.println(pizza3.bread);
        System.out.println(pizza3.sauce);
        System.out.println(pizza3.cheese);
        System.out.println(pizza3.topping);

        System.out.println();

        Pizza pizza4 = new Pizza("thick crust");
        System.out.println("Here are the ingredients of your pizza:");
        System.out.println(pizza4.bread);
        System.out.println(pizza4.sauce);
        System.out.println(pizza4.cheese);
        System.out.println(pizza4.topping);
    }
}
