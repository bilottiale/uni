package motori;

public class MotoreBenzina extends Motore {
  public MotoreBenzina(int cilindrata, int cilindri) {
    super(cilindrata, cilindri);
  }

  @Override
  public boolean isDiesel() {
    return false;
  }

  @Override
  public int maxRPM() {
    return 6500;
  }
}
