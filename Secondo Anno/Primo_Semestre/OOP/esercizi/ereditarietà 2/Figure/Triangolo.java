public class Triangolo extends Figura {
  private double latoA, latoB, latoC;

  public Triangolo(double latoA, double latoB, double latoC) {
    this.latoA = latoA;
    this.latoB = latoB;
    this.latoC = latoC;
  }

  // setters
  public void setLatoA(double latoA) {
    this.latoA = latoA;
  }

  public void setLatoB(double latoB) {
    this.latoB = latoB;
  }

  public void setLatoC(double latoC) {
    this.latoC = latoC;
  }

  // getters
  public double getLatoA() {
    return latoA;
  }

  public double getLatoB() {
    return latoB;
  }

  public double getLatoC() {
    return latoC;
  }

  @Override
  public double getPerimetro() {
    return latoA + latoB + latoC;
  }

  @Override
  public double getArea() {
    double semiPer = getPerimetro() / 2;
    // formula di Erone
    return Math.sqrt(semiPer * (semiPer - latoA) * (semiPer - latoB) * (semiPer - latoC));
  }
}
