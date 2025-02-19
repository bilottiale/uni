import view.MainView;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        SwingUtilities.invokeLater(MainView::new);
    }
}