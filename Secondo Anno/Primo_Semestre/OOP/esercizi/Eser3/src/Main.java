public class Main {
    public static void main(String[] args) {
        // Creazione di oggetti delle classi T e Tmax
        T termometro1 = new T(25.5);  // Oggetto di tipo T
        Tmax termometro2 = new Tmax(20.0, 30.0);  // Oggetto di tipo Tmax

        // Comportamento polimorfico: il tipo di riferimento è T, ma l'oggetto è di tipo Tmax
        T termometroPolimorfico = new Tmax(15.0, 35.0);

        // Uso del metodo setTemperatura (polimorfismo in azione)
        termometro1.setTemperatura(27.0);
        termometro2.setTemperatura(32.0);
        termometroPolimorfico.setTemperatura(40.0);  // Questo aggiorna anche la temperatura massima in Tmax

        // Stampa i risultati
        System.out.println("Temperatura del termometro1: " + termometro1.getTemperatura());
        System.out.println("Temperatura massima di termometro2: " + termometro2.getMaxTemperatura());
        System.out.println("Temperatura massima di termometroPolimorfico: " + ((Tmax) termometroPolimorfico).getMaxTemperatura());
    }
}
