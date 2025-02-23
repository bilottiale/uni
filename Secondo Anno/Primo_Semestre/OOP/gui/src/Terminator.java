import java.awt.event.*;
import javax.swing.*;

public class Terminator implements WindowListener {
    public void windowClosed(WindowEvent e) {
    }

    public void windowClosing(WindowEvent e) {
        // codice da eseguire prima della chiusura
        int ret = JOptionPane.showConfirmDialog(null, "Salvare il lavoro?");
        switch (ret) {
            // Salvataggio
            case 0: System.exit(0);
            // no
            case 1: System.exit(0);
            // cancel
            case 2: System.exit(0);
        }
    }

    public void windowOpened(WindowEvent e) {
    }

    public void windowIconified(WindowEvent e) {
    }

    public void windowDeiconified(WindowEvent e) {
    }

    public void windowActivated(WindowEvent e) {
    }

    public void windowDeactivated(WindowEvent e) {
    }
}