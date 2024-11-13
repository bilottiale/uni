public class OOP {
    public static void main(String[] args) {

        Car myCar1 = new Car();

        System.out.println(myCar1.make);
        System.out.println(myCar1.model);

        myCar1.drive();
        // wait 5 seconds then stop
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        myCar1.brake();

        Car myCar2 = new Car();

        myCar2.drive();
        // wait 5 seconds then stop
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        myCar2.brake();
    }
}