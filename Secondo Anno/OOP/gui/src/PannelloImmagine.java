import javax.swing.*;
import java.awt.*;


public class PannelloImmagine extends JPanel {
  private Image im1;

  public PannelloImmagine() {
    Toolkit t = Toolkit.getDefaultToolkit();
    im1 = t.getImage("w.jpg");
    MediaTracker m = new MediaTracker(this);
    m.addImage(im1, 1);

  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g); // Ensure the panel is properly rendered
    g.drawImage(im1, 20, 20, null);
  }
}
