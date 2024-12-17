public class R {
    protected int lunghezza;
    protected int larghezza;

    public R(int lunghezza, int larghezza) {
        if (lunghezza >= 0 && larghezza >= 0) {
            this.lunghezza = lunghezza;
            this.larghezza = larghezza;

            if (lunghezza == larghezza) {
                System.out.println("Warning: The values make a square.");
            }
        } else {
            System.out.println("Unexpected value: values must be positive.");
        }
    }

    public R() {
        this(0, 0);
    }

    public void modificaLati(int nuovaLunghezza, int nuovaLarghezza) {
        if (nuovaLunghezza >= 0 && nuovaLarghezza >= 0) {
            this.lunghezza = nuovaLunghezza;
            this.larghezza = nuovaLarghezza;

            if (nuovaLunghezza == nuovaLarghezza) {
                System.out.println("Warning: The values make a square.");
            }
        } else {
            System.out.println("Unexpected value: values must be positive.");
        }
    }

    public int calcolaPerimetro() {
        return 2 * (this.lunghezza + this.larghezza);
    }

    public void stampaDettagli() {
        System.out.println("Rettangolo - Lunghezza: " + lunghezza + ", Larghezza: " + larghezza);
        System.out.println("Perimetro: " + calcolaPerimetro());
    }
}
