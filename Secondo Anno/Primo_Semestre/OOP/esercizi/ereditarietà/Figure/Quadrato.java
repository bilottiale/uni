public class Quadrato extends Rettangolo {

  public Quadrato(double lato) {
    super(lato, lato);
  }

  // setters
  public void setLato(double lato) {
    setBase(lato);
    setAltezza(lato);
  }

  public double getLato() {
    return getBase();
  }

  @Override
  public double getArea() {
    return getBase() * getBase();
  }
}
