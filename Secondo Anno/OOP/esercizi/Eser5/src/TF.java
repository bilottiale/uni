public class TF extends T {
    private double tempoUlteriore;

    // Costruttore che accetta velocità media e percentuale del traffico
    public TF(double velocitaMedia, double tempoUlteriore) {
        super(velocitaMedia);
        if (tempoUlteriore >= 0) {
            this.tempoUlteriore = tempoUlteriore;
        } else {
            throw new IllegalArgumentException("La percentuale del traffico deve essere non negativa.");
        }
    }

    // Costruttore che inizializza con valori di default: velocità 60 km/h e nessun traffico
    public TF() {
        this(60, 0);
    }

    // Sovrascrive il metodo calcolaTempo per includere il traffico
    @Override
    public double calcolaTempo(int distanza) {
        double tempo = super.calcolaTempo(distanza);
        return tempo * (1 + tempoUlteriore/100);
    }

    // Metodo per modificare la percentuale di traffico
    public void modificaTempoUlteriore(double nuovoTempoUlteriore) {
        if(nuovoTempoUlteriore >= 0) {
            this.tempoUlteriore = nuovoTempoUlteriore;
        } else {
            System.out.println("Tempo ulteriore non valido.");
        }
    }

    public double getTempoUlteriore() {
        return tempoUlteriore;
    }
}