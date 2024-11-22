import javax.swing.*;
import java.awt.*;

public class StickmanPanel extends JPanel {

  public void paintComponent(Graphics g) {
    super.paintComponent(g);

    // Imposta il colore del disegno
    g.setColor(Color.BLACK);

    // Dimensioni base dell'omino
    int centerX = getWidth() / 2; // Centro orizzontale del pannello
    int headRadius = 40; // Raggio della testa
    int bodyLength = 100; // Lunghezza del corpo
    int armLength = 60; // Lunghezza di un braccio
    int legLength = 80; // Lunghezza di una gamba

    // Coordinate della testa
    int headX = centerX - headRadius; // Posizione X della testa
    int headY = 50; // Posizione Y della testa

    // Disegna la testa (cerchio)
    g.drawOval(headX, headY, headRadius * 2, headRadius * 2);

    // Coordinate del corpo
    int bodyStartX = centerX;
    int bodyStartY = headY + headRadius * 2;
    int bodyEndY = bodyStartY + bodyLength;

    // Disegna il corpo (linea verticale)
    g.drawLine(bodyStartX, bodyStartY, bodyStartX, bodyEndY);

    // Rotazione delle braccia
    int armStartY = bodyStartY + bodyLength / 4;
    double armAngle = Math.toRadians(45); // Angolo di rotazione delle braccia (45 gradi)

    // Calcolo dei punti per braccia ruotate
    int armLeftX = (int) (centerX - armLength * Math.cos(armAngle));
    int armLeftY = (int) (armStartY + armLength * Math.sin(armAngle));
    int armRightX = (int) (centerX + armLength * Math.cos(armAngle));
    int armRightY = (int) (armStartY + armLength * Math.sin(armAngle));

    // Disegna le braccia ruotate
    g.drawLine(centerX, armStartY, armLeftX, armLeftY); // Braccio sinistro
    g.drawLine(centerX, armStartY, armRightX, armRightY); // Braccio destro

    // Coordinate delle gambe
    int legStartY = bodyEndY;
    int legLeftX = centerX - armLength / 2;
    int legRightX = centerX + armLength / 2;
    int legEndY = bodyEndY + legLength;

    // Disegna le gambe
    g.drawLine(centerX, legStartY, legLeftX, legEndY);
    g.drawLine(centerX, legStartY, legRightX, legEndY);
  }

  // Metodo principale per visualizzare il pannello
  public static void main(String[] args) {
    JFrame frame = new JFrame("Stickman");
    StickmanPanel panel = new StickmanPanel();

    // Configura il frame
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(400, 400);
    frame.add(panel);
    frame.setVisible(true);
  }
}
