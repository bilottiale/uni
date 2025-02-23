import javax.swing.*;

public class TerminatorMain {
    public static void main(String[] args) {
        JFrame f = new JFrame("Terminator");
        f.setBounds(100, 100, 200, 200);
        f.addWindowListener(new Terminator());
        f.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
        f.setVisible(true);
    }
}