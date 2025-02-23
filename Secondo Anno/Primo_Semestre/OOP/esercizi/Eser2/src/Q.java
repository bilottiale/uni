public class Q extends R {

    public Q(int lato) {
        super(lato, lato); // Non c'è più il problema con il controllo in R
    }

    public Q() {
        super(0, 0);
    }

    @Override
    public void modificaLati(int lato1, int lato2) {
        if (lato1 != lato2) {
            System.out.println("Error: For a square, both sides must be equal.");
        } else if (lato1 >= 0 && lato2 >= 0) {
            this.lunghezza = lato1;
            this.larghezza = lato2;
        } else {
            System.out.println("Unexpected value: values must be positive.");
        }
    }

    public void modificaLato(int lato) {
        if (lato >= 0) {
            this.lunghezza = lato;
            this.larghezza = lato;
        } else {
            System.out.println("Unexpected value: value must be positive.");
        }
    }
}
