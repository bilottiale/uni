public class Main {
  public static void main(String[] args) {
    Figura[] figure = new Figura[5];

    figure[0] = new Triangolo(3, 4, 5);
    figure[1] = new TriangoloRettangolo(6, 8);
    figure[2] = new Rettangolo(5, 10);
    figure[3] = new Quadrato(4);
    figure[4] = new Cerchio(7);

    for (Figura figura : figure) {
      System.out.println(figura.getClass().getSimpleName() + ":");
      figura.stampaInfo();
      System.out.println();
    }
  }
}
