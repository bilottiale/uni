import java.util.Vector;

public class ContoCorrente {
    private int numeroCC, saldo, contatoreMovimenti;
    private Vector<Integer> movimenti;

    public ContoCorrente(int numeroCC, int saldoIniziale) {
        this.numeroCC = numeroCC;
        this.saldo = saldoIniziale;
        this.movimenti = new Vector<>();
        this.contatoreMovimenti = 0;
    }

    // deposito
    public void deposito(int importo) {
        this.saldo += importo;
        this.movimenti.add(importo);
        this.contatoreMovimenti++;
        System.out.println("Deposito di " + importo + " effettuato con successo nel conto: " + numeroCC);
    }

    // prelievo
    public void prelievo(int importo) {
        if(importo > this.saldo) {
            System.out.println("Saldo insufficiente");
        } else {
            this.saldo -= importo;
            this.movimenti.add(-importo);
            this.contatoreMovimenti++;
            System.out.println("Prelievo di " + importo + " effettuato con successo dal conto: " + numeroCC);
        }
    }

    // getSaldo
    public int getSaldo() {
        return this.saldo;
    }

    // getNumeroCC
    public int getNumeroCC() {
        return this.numeroCC;
    }

    public void stampaMovimenti() {
        System.out.println("Movimenti del conto n " + numeroCC + ":");
        for(int movimento : movimenti) {
            System.out.println(movimento);
        }
    }
}