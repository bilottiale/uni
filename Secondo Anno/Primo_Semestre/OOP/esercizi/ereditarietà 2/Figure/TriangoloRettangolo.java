public class TriangoloRettangolo extends Triangolo {
  private double base, altezza;

  public TriangoloRettangolo(double base, double altezza) {
    super(base, altezza, Math.sqrt(base * base + altezza * altezza));
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
    return base + altezza + Math.sqrt(base * base + altezza * altezza);
  }

  @Override
  public double getArea() {
    return (base * altezza) / 2;
  }
}
