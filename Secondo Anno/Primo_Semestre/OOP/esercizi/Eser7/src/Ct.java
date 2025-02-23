public class Ct extends C{
    private double percentualeTasse;

    public Ct(double percentualeTasse) {
        if(percentualeTasse > 0 && percentualeTasse < 100) {
            this.percentualeTasse = percentualeTasse;
        } else {
            throw new IllegalArgumentException("La pecentuale tasse deve essere compresa tra 0 e 100");
        }
    }

    public Ct() {
        super();
        this.percentualeTasse = 21.0;
    }

    @Override
    public double getContoParziale() {
        return super.getContoParziale() * (1 + percentualeTasse / 100);
    }

    public void setTasse(double nuoveTasse) {
        if(nuoveTasse > 0 && nuoveTasse < 100) {
            this.percentualeTasse = nuoveTasse;
        } else {
            throw new IllegalArgumentException("La pecentuale tasse deve essere compresa tra 0 e 100");
        }
    }

    public double getTasse() {
        return percentualeTasse;
    }
}
