public class ddArrays {
    public static void main(String[] args) {
        String[][] cars = new String[3][3];
        
        cars[0][0] = "Volvo";
        cars[0][1] = "BMW";
        cars[0][2] = "Ford";
        cars[1][0] = "Mazda";
        cars[1][1] = "Toyota";
        cars[1][2] = "Honda";
        cars[2][0] = "Chevy";
        cars[2][1] = "Dodge";
        cars[2][2] = "Jeep";

        // or
        // String[][] cars = {
        //                      {"Volvo", "BMW", "Ford"},
        //                      {"Mazda", "Toyota", "Honda"},
        //                      {"Chevy", "Dodge", "Jeep"}
        //                   };   

        for (int r = 0; r < cars.length; r++) {
            System.out.println();
            for (int c = 0; c < cars[r].length; c++) {
                System.out.print(cars[r][c]+" ");
            }
        }
    }
}
