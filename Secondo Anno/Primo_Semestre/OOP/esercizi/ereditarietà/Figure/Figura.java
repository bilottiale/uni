public abstract class Figura {

  public abstract double getPerimetro();

  public abstract double getArea();

  public void stampaInfo() {
    System.out.println("Perimetro:" + getPerimetro());
    System.out.println("Area:" + getArea());
  }
}
