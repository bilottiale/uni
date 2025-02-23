public class P {
    public double vMedia;

    public P(double vMedia) {
        if(vMedia > 0) {
            this.vMedia = vMedia;
        } else {
            throw new IllegalArgumentException("La velocità media deve essere maggiore di zero.");
        }
    }

    public P() {
        this.vMedia = 300.00;
    }

    public double calcolaDistanza(double tempo){
        if(tempo < 0) {
            throw new IllegalArgumentException("Il tempo deve essere maggiore di zero.");
        } else {
            return this.vMedia * tempo;
        }
    }

    public void setvMedia(double vMedia) {
        if(vMedia > 0) {
            this.vMedia = vMedia;
        } else {
            throw new IllegalArgumentException("");
        }
    }
}
