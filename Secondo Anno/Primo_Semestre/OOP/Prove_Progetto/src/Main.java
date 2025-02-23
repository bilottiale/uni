public class Main {
    public static void main(String[] args) {
        DatabaseHandler dbHandler = new DatabaseHandler("prenotazioni.db");
        dbHandler.creaTabella();

        // Aggiungere una prenotazione
        Prenotazione p1 = new Prenotazione(0, "Aula 101", "2024-12-20", "09:00", "11:00", "Mario Rossi");
        dbHandler.aggiungiPrenotazione(p1);

        // Visualizzare tutte le prenotazioni
        System.out.println("Elenco delle prenotazioni:");
        dbHandler.visualizzaPrenotazioni();

        dbHandler.checkPrenotazioni();

        System.out.println(dbHandler.isAulaOccupata("Aula 101", "2024-12-20", "08:00", "09:00"));
    }
}
