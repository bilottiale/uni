import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Creazione di un vettore di 3 conti correnti
        Vector<ContoCorrente> contiCorrenti = new Vector<>();
        contiCorrenti.add(new ContoCorrente(1, 1000));
        contiCorrenti.add(new ContoCorrente(2, 2000));
        contiCorrenti.add(new ContoCorrente(3, 3000));

        // Deposito di 1000 euro nel conto 1
        contiCorrenti.get(0).deposito(1000);
        // Prelievo di 500 euro dal conto 2
        contiCorrenti.get(1).prelievo(500);
        // Deposito di 2000 euro nel conto 3
        contiCorrenti.get(2).deposito(2000);

        // Stampa dei movimenti di tutti i conti correnti
        for(ContoCorrente contoCorrente : contiCorrenti) {
            contoCorrente.stampaMovimenti();
        }

        // Stampa del saldo di tutti i conti correnti
        for(ContoCorrente contoCorrente : contiCorrenti) {
            System.out.println("Saldo del conto n " + contoCorrente.getNumeroCC() + ": " + contoCorrente.getSaldo());
        }
    }
}
