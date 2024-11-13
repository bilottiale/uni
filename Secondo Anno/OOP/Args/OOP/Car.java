import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.sound.sampled.*;
import java.io.IOException;

public class Car {
    String make = "Toyota";
    String model = "Yaris";
    int year = 2021;
    String color = "Red";
    double price = 20000.00;

    void drive() {
        System.out.println("You drive the car");

        // Play sound
        File f = new File("src/drive.wav"); // Use WAV format
        try {
            Clip clip = AudioSystem.getClip();
            clip.open(AudioSystem.getAudioInputStream(f));
            clip.start();
            clip.addLineListener(event -> {
                if (event.getType() == LineEvent.Type.STOP) {
                    clip.close();
                }
            });
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Display Image in Swing
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("I DRIVE");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setUndecorated(true); // Remove window borders

            // Get screen dimensions
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            int screenWidth = screenSize.width;
            int screenHeight = screenSize.height;

            BufferedImage img = null;

            try {
                img = ImageIO.read(new File("src/i-drive.png"));
                // Scale the image to full screen dimensions
                Image scaledImg = img.getScaledInstance(screenWidth, screenHeight, Image.SCALE_SMOOTH);
                ImageIcon icon = new ImageIcon(scaledImg);
                
                JLabel label = new JLabel(icon);
                frame.getContentPane().add(label);
            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }

            // Full-screen settings
            GraphicsEnvironment env = GraphicsEnvironment.getLocalGraphicsEnvironment();
            GraphicsDevice device = env.getDefaultScreenDevice();
            device.setFullScreenWindow(frame); // Set the frame to full screen
            
            frame.setVisible(true);
        });
    }

    void brake() {
        System.out.println("You step on the brakes");
        System.exit(0);
    }
}
