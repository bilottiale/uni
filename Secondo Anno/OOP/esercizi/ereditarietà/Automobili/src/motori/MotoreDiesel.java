package motori;

public class MotoreDiesel extends Motore {
  public MotoreDiesel(int cilindrata, int cilindri) {
    super(cilindrata, cilindri);
  }

  @Override
  public boolean isDiesel() {
    return true;
  }

  @Override
  public int maxRPM() {
    return 4500;
  }
}
