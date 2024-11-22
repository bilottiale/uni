import javax.swing.table.AbstractTableModel;

public class RubricaTableModel extends AbstractTableModel {
    private String[] colonne = {"Nome", "Cognome", "Indirizzo", "Telefono"};
    private Contatto[] contatti;

    // Costruttore
    public RubricaTableModel(Contatto[] contatti) {
        this.contatti = contatti;
    }

    @Override
    public int getRowCount() {
        return contatti.length;
    }

    @Override
    public int getColumnCount() {
        return colonne.length;
    }

    @Override
    public String getColumnName(int column) {
        return colonne[column];
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        Contatto contatto = contatti[rowIndex];
        switch (columnIndex) {
            case 0: return contatto.getNome();
            case 1: return contatto.getCognome();
            case 2: return contatto.getIndirizzo();
            case 3: return contatto.getTelefono();
            default: return null;
        }
    }
}

