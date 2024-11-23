public class Rettangolo extends Figura {
  private double base, altezza;

  public Rettangolo(double base, double altezza) {
    this.base = base;
    this.altezza = altezza;
  }

  // setters
  public void setBase(double base) {
    this.base = base;
  }

  public void setAltezza(double altezza) {
    this.altezza = altezza;
  }

  // getters
  public double getBase() {
    return base;
  }

  public double getAltezza() {
    return altezza;
  }

  @Override
  public double getPerimetro() {
    return 2 * (base + altezza);
  }

  @Override
  public double getArea() {
    return base * altezza;
  }
}
