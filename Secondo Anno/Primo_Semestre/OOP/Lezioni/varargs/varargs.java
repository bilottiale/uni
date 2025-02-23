public class varargs {
  public void mvar(String... pars) {
    System.out.println("With for:");
    for (int i = 0; i < pars.length; i++) {
      System.out.println("Parameter " + i + " is " + pars[i]);
    }
  }

  public void mvar2(String... pars) {
    System.out.println("With foreach:");
    for (String s : pars) {
      System.out.println(s);
    }
  }

  public static void main(String argv[]) {
    varargs v = new varargs();
    v.mvar("ALFA", "BETA", "GAMMA");

    System.out.println("---------------------");

    v.mvar2("ALFA", "BETA", "GAMMA");
  }
}
