public class T {
    private double velocitaMedia;

    // Costruttore che imposta la velocità media passata come parametro
    public T(double velocitaMedia) {
        if (velocitaMedia > 0) {
            this.velocitaMedia = velocitaMedia;
        } else {
            throw new IllegalArgumentException("La velocità media deve essere maggiore di zero.");
        }
    }

    // Costruttore che imposta la velocità di default a 60 km/h
    public T() {
        this.velocitaMedia = 60.0;
    }

    // Metodo per modificare la velocità media
    public void setVelocitaMedia(double nuovaVelocita) {
        if (nuovaVelocita > 0) {
            this.velocitaMedia = nuovaVelocita;
        } else {
            throw new IllegalArgumentException("La velocità media deve essere maggiore di zero.");
        }
    }

    // Metodo per calcolare il tempo di percorrenza
    public double calcolaTempo(int distanza) {
        if (distanza <= 0) {
            throw new IllegalArgumentException("La distanza deve essere maggiore di zero.");
        }
        return (double)(distanza / velocitaMedia); // tempo = distanza / velocità
    }
}