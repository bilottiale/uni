public class Lcache extends L {
    private final int N;
    private int cache [];
    private int contatore;
    public Lcache (IntegerInputStream dispositivo) {
        this (dispositivo, 256);
    }
    public Lcache (IntegerInputStream dispositivo, int N) {
        super(dispositivo);
        this.N = N;
        cache = new int [ N ];
        contatore = 0;
    }
    public int lettura ( ) {
//Se la cache è vuota
        if (contatore == 0)
        {
            for (int i=0; i < N; i++)
                cache [ i ] = super.lettura ( );
            contatore ++;
            return cache [0];
        }
        else
        {
            int x = cache [ contatore ];
//Se ho letto l’ultimo valore della cache
            if (contatore == N - 1) {
                cache = new int [N]; //Per svuotare la cache
                contatore = -1;
            }
            contatore ++;
            return x;
        }
    }
}