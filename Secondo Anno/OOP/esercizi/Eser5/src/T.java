public class T {
    private double velocitaMedia; // velocità media in km/h

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

    // Metodo per calcolare il tempo di percorrenza
    public double calcolaTempo(double distanza) {
        if (distanza <= 0) {
            throw new IllegalArgumentException("La distanza deve essere maggiore di zero.");
        }
        return distanza / velocitaMedia; // tempo = distanza / velocità
    }

    // Metodo per modificare la velocità media
    public void setVelocitaMedia(double nuovaVelocita) {
        if (nuovaVelocita > 0) {
            this.velocitaMedia = nuovaVelocita;
        } else {
            throw new IllegalArgumentException("La velocità media deve essere maggiore di zero.");
        }
    }

    // Metodo per ottenere la velocità media attuale
    public double getVelocitaMedia() {
        return velocitaMedia;
    }
}