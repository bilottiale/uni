import java.awt.*;
import java.util.Vector;

import javax.swing.*;

public class EsSwing1 {
  public static void main(String[] args) {
    // crea nuova finestra con nome "Esempio 1"
    JFrame f1 = new JFrame("Esempio 1");

    // imposta origine e dimensione
    f1.setBounds(200, 100, 300, 150);
    // mostra finestra
    f1.setVisible(true);

    JFrame f2 = new MyFrame("MyFrame");
    f2.setVisible(true);

    // creo un nuovo pannello
    JPanel panel1 = new JPanel();
    // aggiungo il pannello al MyFrame
    f1.add(panel1);

    MyPanel myPanel1 = new MyPanel();
    f2.add(myPanel1);
    f2.pack();

    PannelloImmagine imgPan = new PannelloImmagine();
    JFrame f3 = new JFrame();
    f3.add(imgPan);
    f3.setSize(320, 240);
    f3.setVisible(true);

    ColorsPanel colorsPanel = new ColorsPanel();
    JFrame f4 = new JFrame();
    f4.add(colorsPanel);
    f4.setSize(320, 240);
    f4.setVisible(true);

    TextPanel textPanel = new TextPanel();
    JFrame f5 = new JFrame();
    f5.add(textPanel);
    f5.setSize(320, 240);
    f5.setVisible(true);

    DocList docList = new DocList();
    JFrame f6 = new JFrame();
    f6.add(docList);
    f6.setBounds(300, 300, 300, 300);
    f6.setVisible(true);

    Vector<Book> books = new Vector<>();
    books.add(new Book("Book A", "Author A", 2020, 29.99f));
    books.add(new Book("Book B", "Author B", 2018, 19.99f));

    // Create the table model
    Tabella tableModel = new Tabella(books);

    // Create a JTable with the custom model
    JTable table = new JTable(tableModel);

    // Display the table in a JFrame
    JFrame frame = new JFrame("Book Table");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new JScrollPane(table));
    frame.pack();
    frame.setVisible(true);
  }
}
