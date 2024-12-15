public class Main {
    public static void main(String[] args) {
        // Simulazione del dispositivo di input
        IntegerInputStream dispositivo = new IntegerInputStream();

        // Creazione degli oggetti
        L lettoreBase = new L(dispositivo);  // Oggetto di tipo L (Lettore base)
        Lcache lettoreCache = new Lcache(dispositivo);  // Oggetto di tipo Lcache (Lettore con cache)

        // Comportamento polimorfico: il tipo di riferimento è L, ma l'oggetto è di tipo Lcache
        L lettorePolimorfico = new Lcache(dispositivo);

        // Lettura dei valori
        System.out.println("Lettura da lettoreBase: " + lettoreBase.read());
        System.out.println("Lettura da lettoreCache: " + lettoreCache.read());
        System.out.println("Lettura polimorfica: " + lettorePolimorfico.read());

        // Continuazione delle letture
        System.out.println("Lettura successiva da lettorePolimorfico: " + lettorePolimorfico.read());
    }
}
