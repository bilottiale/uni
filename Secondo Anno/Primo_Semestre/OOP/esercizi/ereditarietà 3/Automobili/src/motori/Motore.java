package motori;

public abstract class Motore {
  int cilindrata;
  int cilindri;

  public Motore(int cilindrata, int cilindri) {
    this.cilindrata = cilindrata;
    this.cilindri = cilindri;
  }

  public int getCilindrata() {
    return cilindrata;
  }

  public int getCilindri() {
    return cilindri;
  }

  public abstract boolean isDiesel();

  public abstract int maxRPM();

  public double getPotenza() {
    return cilindrata * cilindri * (isDiesel() ? 0.6 : 0.75);
  }
}
