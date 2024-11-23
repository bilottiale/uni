public class Cerchio extends Figura {
  private double raggio;

  public Cerchio(double raggio) {
    this.raggio = raggio;
  }

  @Override
  public double getPerimetro() {
    return 2 * Math.PI * raggio;
  }

  @Override
  public double getArea() {
    return Math.PI * raggio * raggio;
  }

  public double getRaggio() {
    return raggio;
  }

  public void setRaggio(double raggio) {
    this.raggio = raggio;
  }
}
