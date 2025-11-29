public class Cerchio extends Figura {
  private double raggio;

  public Cerchio(double raggio) {
    this.raggio = raggio;
  }

  // setters
  public void setRaggio(double raggio) {
    this.raggio = raggio;
  }

  // getters
  public double getRaggio() {
    return raggio;
  }


  @Override
  public double getPerimetro() {
    return 2 * Math.PI * raggio;
  }

  @Override
  public double getArea() {
    return Math.PI * raggio * raggio;
  }
}
