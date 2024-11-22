import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        // Dati di esempio
        Contatto[] contatti = {
            new Contatto("Mario", "Rossi", "Via Roma 1", "1234567890"),
            new Contatto("Luigi", "Verdi", "Via Milano 2", "0987654321"),
            new Contatto("Anna", "Bianchi", "Piazza Napoli 3", "5678901234")
        };

        // Crea il frame principale
        JFrame frame = new JFrame("Rubrica");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);

        // Aggiungi il pannello della rubrica
        frame.add(new RubricaPanel(contatti));

        // Mostra il frame
        frame.setVisible(true);
    }
}

