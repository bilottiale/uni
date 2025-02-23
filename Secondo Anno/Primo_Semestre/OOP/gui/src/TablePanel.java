import java.util.Vector;
import javax.swing.*;
import javax.swing.table.*;

public class TablePanel extends JPanel {
    public TablePanel() {
        // Create a vector of books
        Vector<Book> v = new Vector<>();
        Book b1 = new Book("Le avventure di Pinocchio", "Collodi", 40, 14.50F);
        Book b2 = new Book("La fattoria degli animali", "Orwell", 20, 12.90F);
        Book b3 = new Book("Signor Malaussene", "Pennac", 15, 9.00F);
        v.add(b1);
        v.add(b2);
        v.add(b3);

        // Create the table model
        Tabella tableModel = new Tabella(v);

        // Create a JTable using the model
        JTable table = new JTable(tableModel);

        // Add the table to the panel
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(new JScrollPane(table));
    }
}
