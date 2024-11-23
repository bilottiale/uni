public class Quadrato extends Rettangolo {

  public Quadrato(double lato) {
    super(lato, lato);
  }

  public double getLato() {
    return getBase();
  }

  public void setLato(double lato) {
    setBase(lato);
    setAltezza(lato);
  }
}
