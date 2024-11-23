public class Triangolo extends Figura {
  private double latoA, latoB, latoC;

  public Triangolo(double latoA, double latoB, double latoC) {
    this.latoA = latoA;
    this.latoB = latoB;
    this.latoC = latoC;
  }

  @Override
  public double getPerimetro() {
    return latoA + latoB + latoC;
  }

  @Override
  public double getArea() {
    double semiPer = getPerimetro() / 2;
    return Math.sqrt(semiPer * (semiPer - latoA) * (semiPer - latoB) * (semiPer - latoC));
  }
}
