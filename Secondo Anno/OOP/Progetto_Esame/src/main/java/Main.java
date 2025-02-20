import view.MainView;

import javax.swing.*;

/**
 * The main class for the application.
 */
public class Main {

    /**
     * Main method for the application.
     * @param args The command line arguments.
     */
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        SwingUtilities.invokeLater(MainView::new);
    }
}