public class TF extends T {
    private double percentualeTraffico; // Percentuale del tempo ulteriore dovuto al traffico

    // Costruttore che accetta velocità media e percentuale del traffico
    public TF(double velocitaMedia, double percentualeTraffico) {
        super(velocitaMedia);
        if (percentualeTraffico >= 0) {
            this.percentualeTraffico = percentualeTraffico;
        } else {
            throw new IllegalArgumentException("La percentuale del traffico deve essere non negativa.");
        }
    }

    // Costruttore che inizializza con valori di default: velocità 60 km/h e nessun traffico
    public TF() {
        super();
        this.percentualeTraffico = 0.0;
    }

    // Sovrascrive il metodo calcolaTempo per includere il traffico
    @Override
    public double calcolaTempo(double distanza) {
        double tempoBase = super.calcolaTempo(distanza); // Tempo senza traffico
        double tempoConTraffico = tempoBase * (1 + percentualeTraffico / 100);
        return tempoConTraffico;
    }

    // Metodo per modificare la percentuale di traffico
    public void setPercentualeTraffico(double nuovaPercentuale) {
        if (nuovaPercentuale >= 0) {
            this.percentualeTraffico = nuovaPercentuale;
        } else {
            throw new IllegalArgumentException("La percentuale del traffico deve essere non negativa.");
        }
    }

    // Metodo per ottenere la percentuale attuale del traffico
    public double getPercentualeTraffico() {
        return percentualeTraffico;
    }
}