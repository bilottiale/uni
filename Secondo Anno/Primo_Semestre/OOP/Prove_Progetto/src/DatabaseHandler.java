import java.sql.*;

public class DatabaseHandler {
    private Connection conn;
    private Integer id;
    private String aula;

    public DatabaseHandler(String databasePath) {
        try {
            conn = DriverManager.getConnection("jdbc:sqlite:" + databasePath);
            System.out.println("Connessione al database riuscita!");
        } catch (SQLException e) {
            System.err.println("Errore di connessione: " + e.getMessage());
        }
    }

    // Metodo per creare la tabella 'prenotazioni'
    public void creaTabella() {
        String query = "CREATE TABLE IF NOT EXISTS prenotazioni (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "aula TEXT NOT NULL, " +
                "data DATE NOT NULL, " +
                "ora_inizio TIME NOT NULL, " +
                "ora_fine TIME NOT NULL, " +
                "utente TEXT NOT NULL)";
        try (Statement stmt = conn.createStatement()) {
            stmt.execute(query);
            System.out.println("Tabella 'prenotazioni' creata (se non esiste).");
        } catch (SQLException e) {
            System.err.println("Errore nella creazione della tabella: " + e.getMessage());
        }
    }

    // Metodo per aggiungere una prenotazione
    public void aggiungiPrenotazione(Prenotazione prenotazione) {
        String query = "INSERT INTO prenotazioni (aula, data, ora_inizio, ora_fine, utente) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement pstmt = conn.prepareStatement(query)) {
            pstmt.setString(1, prenotazione.getAula());
            pstmt.setString(2, prenotazione.getData());
            pstmt.setString(3, prenotazione.getOraInizio());
            pstmt.setString(4, prenotazione.getOraFine());
            pstmt.setString(5, prenotazione.getUtente());
            pstmt.executeUpdate();
            System.out.println("Prenotazione aggiunta con successo!");
        } catch (SQLException e) {
            System.err.println("Errore nell'aggiunta della prenotazione: " + e.getMessage());
        }
    }

    // Metodo per recuperare tutte le prenotazioni
    public void visualizzaPrenotazioni() {
        String query = "SELECT * FROM prenotazioni";
        try (Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id") +
                        ", Aula: " + rs.getString("aula") +
                        ", Data: " + rs.getString("data") +
                        ", Ora inizio: " + rs.getString("ora_inizio") +
                        ", Ora fine: " + rs.getString("ora_fine") +
                        ", Utente: " + rs.getString("utente"));
            }
        } catch (SQLException e) {
            System.err.println("Errore nella visualizzazione delle prenotazioni: " + e.getMessage());
        }
    }

    // controllo se una prenotazione già esiste nel database
    public void checkPrenotazioni() {
        String query = "SELECT * FROM prenotazioni";
        try (Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                aula = rs.getString("aula");
                System.out.println(aula);
            }
        } catch (SQLException e) {
            System.err.println("Errore nella visualizzazione delle prenotazioni: " + e.getMessage());
        }
    }

    public boolean isAulaOccupata(String aula, String data, String oraInizio, String oraFine) {
        String query = """
        SELECT COUNT(*) FROM prenotazioni
        WHERE aula = ? AND data = ?
        AND (
            (ora_inizio < ? AND ora_fine > ?) OR -- Sovrapposizione parziale
            (ora_inizio >= ? AND ora_inizio < ?) -- Sovrapposizione completa
        );
    """;

        try (PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, aula);
            stmt.setString(2, data);
            stmt.setString(3, oraFine);
            stmt.setString(4, oraInizio);
            stmt.setString(5, oraInizio);
            stmt.setString(6, oraFine);

            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return rs.getInt(1) > 0; // Se COUNT(*) > 0, allora è occupata
            }
        } catch (SQLException e) {
            System.err.println("Errore durante la verifica della disponibilità: " + e.getMessage());
        }
        return false; // In caso di errore, considera l'aula come disponibile
    }

}
