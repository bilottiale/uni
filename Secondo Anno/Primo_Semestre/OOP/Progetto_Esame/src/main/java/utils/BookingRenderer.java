package utils;

import view.MainView;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;

/** Custom renderer for table cells, applying colors and borders based on booking data. */
public class BookingRenderer extends DefaultTableCellRenderer {
    /**
     * Renders a table cell with booking-specific formatting.
     * <p>
     * Applies a background color based on the booking description, brightens it for multi-hour bookings,
     * and sets borders for the first and last cells of a booking block. Non-booking cells are white.
     * </p>
     *
     * @param table The {@link JTable} containing the cell.
     * @param value The value to render in the cell.
     * @param isSelected Whether the cell is selected.
     * @param hasFocus Whether the cell has focus.
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return The rendered {@link Component}.
     */
    @Override
    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
        Component comp = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

        if (comp instanceof JComponent) {
            ((JComponent) comp).setBorder(null);
        }

        if (column > 0 && value != null && !value.toString().isEmpty()) {
            Color color = ((MainView) table.getRootPane().getParent()).getColorForBooking(value.toString());
            comp.setBackground(color);

            if (isPartOfLargerBooking(table, row, column)) {
                comp.setBackground(color.brighter());
            }

            if (isFirstCellOfBooking(table, row, column)) {
                assert comp instanceof JComponent;
                ((JComponent) comp).setBorder(BorderFactory.createMatteBorder(1, 1, 0, 0, comp.getBackground()));
            } else if (isLastCellOfBooking(table, row, column)) {
                assert comp instanceof JComponent;
                ((JComponent) comp).setBorder(BorderFactory.createMatteBorder(0, 0, 1, 1, comp.getBackground()));
            } else {
                assert comp instanceof JComponent;
                ((JComponent) comp).setBorder(null);
            }

            setText(getBookingText(table, value, row, column));
        } else {
            comp.setBackground(Color.WHITE);
            setText(value != null ? value.toString() : "");
        }

        return comp;
    }

    /**
     * Retrieves the booking text to display in the cell, hiding duplicates in multi-hour bookings.
     * @param table The {@link JTable} containing the cell.
     * @param value The value to render in the cell.
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return The booking text to display in the cell.
     */
    private String getBookingText(JTable table, Object value, int row, int column) {
        if (row == 0 || !value.equals(table.getValueAt(row - 1, column))) {
            return value.toString();
        }
        return "";
    }

    /**
     * Checks if the current cell is part of a larger booking block.
     * @param table  The {@link JTable} containing the cell.
     * @param row    The row index of the cell.
     * @param column The column index of the cell.
     * @return {@code true} if the cell is part of a larger booking block, {@code false} otherwise.
     */
    private boolean isPartOfLargerBooking(JTable table, int row, int column) {
        Object value = table.getValueAt(row, column);
        if (row + 1 < table.getRowCount() && value.equals(table.getValueAt(row + 1, column))) {
            return true;
        }
        return row > 0 && value.equals(table.getValueAt(row - 1, column));
    }

    /**
     * Checks if the current cell is the first cell of a booking block.
     * @param table The {@link JTable} containing the cell.
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return {@code true} if the cell is the first cell of a booking block, {@code false} otherwise.
     */
    private boolean isFirstCellOfBooking(JTable table, int row, int column) {
        return row == 0 || !table.getValueAt(row - 1, column).equals(table.getValueAt(row, column));
    }

    /**
     * Checks if the current cell is the last cell of a booking block.
     * @param table The {@link JTable} containing the cell.
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return {@code true} if the cell is the last cell of a booking block, {@code false} otherwise.
     */
    private boolean isLastCellOfBooking(JTable table, int row, int column) {
        return row + 1 >= table.getRowCount() || !table.getValueAt(row + 1, column).equals(table.getValueAt(row, column));
    }
}