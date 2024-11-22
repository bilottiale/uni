public class Main {
    public static void main(String[] args) {

        long startTime = System.nanoTime();
        
        // rubrica1
        RubricaArrList rubrica1 = new RubricaArrList();
        Contatto contatto11 = new Contatto("Mario", "Rossi", "Via Roma 1", "1234567890");
        Contatto contatto12 = new Contatto("Luigi", "Verdi", "Via Roma 2", "0987654321");
        Contatto contatto13 = new Contatto("Giovanni", "Bianchi", "Via Roma 3", "6789012345");
        
        // aggiungi contatti rubrica1
        rubrica1.aggiungiContatto(contatto11);
        rubrica1.aggiungiContatto(contatto12);
        rubrica1.aggiungiContatto(contatto13);
        rubrica1.StampaRubrica();
        
        // input cognome da cercare dalla console
        // System.out.println("Scrivi un contatto da cercare:");
        // String cognome = System.console().readLine();
        // Contatto contatto = rubrica1.cercaContatto(cognome);
        // if (contatto != null) {
        //     System.out.println("Contatto trovato: " + contatto);
        // } else {
        //     System.out.println("Contatto non trovato");
        // }
        
        // rimuovi contatto rubrica1
        rubrica1.rimuoviContatto(contatto11);
        rubrica1.StampaRubrica();
        
        // cancella tutto rubrica1
        rubrica1.cancellaTutto();
        rubrica1.StampaRubrica();

        long endTime = System.nanoTime();
        long DTime1 = endTime - startTime;
        System.out.println("Tempo impiegato: " + DTime1 + " nanosecondi");
        startTime = System.nanoTime();

        // rubrica2
        RubricaList rubrica2 = new RubricaList();
        Contatto contatto21 = new Contatto("Mario", "Rossi", "Via Roma 1", "1234567890");
        Contatto contatto22 = new Contatto("Luigi", "Verdi", "Via Roma 2", "0987654321");
        Contatto contatto23 = new Contatto("Giovanni", "Bianchi", "Via Roma 3", "6789012345");

        // aggiungi contatti rubrica2
        rubrica2.aggiungiContatto(contatto21);
        rubrica2.aggiungiContatto(contatto22);
        rubrica2.aggiungiContatto(contatto23);

        // rimuovi contatto rubrica2
        rubrica2.rimuoviContatto(contatto21);
        rubrica2.StampaRubrica();

        // cancella tutto rubrica2
        rubrica2.cancellaTutto();
        rubrica2.StampaRubrica();

        endTime = System.nanoTime();
        long DTime2 = endTime - startTime;
        System.out.println("Tempo impiegato: " + DTime2 + " nanosecondi");

        System.out.println("Differenza di tempo: " + (DTime1 - DTime2) + " nanosecondi");
    }
}