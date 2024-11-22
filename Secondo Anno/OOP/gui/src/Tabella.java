import java.util.Vector;
import javax.swing.table.AbstractTableModel;

public class Tabella extends AbstractTableModel {
    private Vector<Book> v; // Use generics for type safety

    private String[] colNames = { "Titolo", "Autore", "Anno", "Prezzo" };

    public Tabella(Vector<Book> v) {
        this.v = v;
    }

    public int getColumnCount() {
        return colNames.length;
    }

    public int getRowCount() {
        return v.size();
    }

    public void setValueAt(Object value, int row, int col) {
        Book b = v.elementAt(row);
        if (col == 2)
            b.quantity = (Integer) value; // Safe cast
        if (col == 3)
            b.price = (Float) value; // Safe cast
        fireTableDataChanged();
    }

    public Object getValueAt(int row, int col) {
        Book b = v.elementAt(row);
        switch (col) {
            case 0:
                return b.title;
            case 1:
                return b.author;
            case 2:
                return b.quantity;
            case 3:
                return b.price;
            default:
                return "";
        }
    }

    public String getColumnName(int col) {
        return colNames[col];
    }

    public Class<?> getColumnClass(int col) {
        return getValueAt(0, col).getClass();
    }

    public boolean isCellEditable(int row, int col) {
        return (col == 2 || col == 3);
    }
}
