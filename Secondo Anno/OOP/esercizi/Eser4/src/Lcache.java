public class Lcache extends L {
    private int N;
    private int[] cache;
    private int contatore;

    public Lcache (IntegerInputStream dispositivo) {
        this (dispositivo, 256);
    }

    public Lcache (IntegerInputStream dispositivo, int N) {
        super(dispositivo);
        this.N = N;
        cache = new int[N];
        contatore = 0;
    }

    @Override
    public int lettura() {
        if (contatore == 0) {
            for (int i=0; i < N; i++) {
                cache[i] = super.lettura();
            }
            contatore ++;
            return cache [0];
        }
        else {
            int x = cache[contatore];
            if (contatore == N - 1) {
                cache = new int[N];
                contatore = 0;
            }
            return x;
        }
    }
}