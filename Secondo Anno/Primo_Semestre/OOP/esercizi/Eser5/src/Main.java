public class Main {
    public static void main(String[] args) {
        // Navigatore senza traffico
        TF navigatore1 = new TF(80, 0);
        double tempo1 = navigatore1.calcolaTempo(160); // 160 km con 80 km/h e traffico 0%
        System.out.println("Tempo di percorrenza (senza traffico): " + tempo1 + " ore");

        // Navigatore con traffico
        TF navigatore2 = new TF(100, 25); // Velocità 100 km/h, traffico +25%
        double tempo2 = navigatore2.calcolaTempo(200); // 200 km
        System.out.println("Tempo di percorrenza (con traffico): " + tempo2 + " ore");

        // Modifica del traffico
        navigatore2.modificaTempoUlteriore(50); // Cambia il traffico a +50%
        double tempo3 = navigatore2.calcolaTempo(200); // 200 km
        System.out.println("Tempo di percorrenza (con traffico aggiornato): " + tempo3 + " ore");

        // Navigatore con valori di default
        TF navigatore3 = new TF();
        double tempo4 = navigatore3.calcolaTempo(120); // 120 km, 60 km/h, traffico 0%
        System.out.println("Tempo di percorrenza (default)!!: " + tempo4 + " ore");

        // Tentativo di impostare un tempo ulteriore non valido
        navigatore3.modificaTempoUlteriore(10.5); // Errore
        double tempo5 = navigatore3.calcolaTempo(120);
        System.out.println("Tempo ulteriore attuale: " + navigatore3.getTempoUlteriore() + "%");
        System.out.println("Tempo di percorrenza (+traffico: 10.5%): " + tempo5 + " ore");
    }
}
