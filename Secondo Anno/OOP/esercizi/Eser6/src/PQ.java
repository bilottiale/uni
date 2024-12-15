public class PQ extends P {
    public double percentualeProb;

    public PQ(double vMedia, double percentualeProb) {
        super(vMedia);
        if(percentualeProb > 0 && percentualeProb < 100) {
            this.percentualeProb = percentualeProb;
        } else {
            throw new IllegalArgumentException("La percentuale deve essere compresa tra 0 e 100.");
        }
    }

    public PQ() {
        super();
        this.percentualeProb = 50.00;
    }

    @Override
    public double calcolaDistanza(double tempo){
        double r = Math.random();
        if(r < this.percentualeProb / 100.00) {
            return super.calcolaDistanza(tempo);
        } else {
            return 0.00;
        }
    }

    public void setPercentualeProb(double nuovaProb) {
        if(nuovaProb > 0 && nuovaProb < 100) {
            this.percentualeProb = nuovaProb;
        } else {
            throw new IllegalArgumentException("La percentuale deve essere compresa tra 0 e 100.");
        }
    }
}
