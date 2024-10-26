# Java manual (i think)
## Programmazione ad oggetti

La programmazione orientata agli oggetti (Object-Oriented Programming, OOP) è un paradigma di programmazione basato sulla creazione di oggetti che rappresentano elementi del mondo reale o concetti astratti, organizzati attraverso classi. Questo paradigma consente di strutturare il codice in modo modulare, facilitando la manutenzione e il riutilizzo.

## Incapsulamento

Protezione e controllo dell'accesso ai dati, consentendo solo metodi specifici per interagire con essi.

```Java
public class ContoBancario {
    private double saldo; // Variabile privata, accessibile solo tramite metodi

    public ContoBancario(double saldoIniziale) {
        this.saldo = saldoIniziale;
    }

    // Metodo pubblico per depositare
    public void deposita(double importo) {
        if (importo > 0) saldo += importo;
    }

    // Metodo pubblico per ottenere il saldo
    public double getSaldo() {
        return saldo;
    }
}

```

Il saldo è protetto e può essere modificato solo tramite i metodi deposita() e `getSaldo()`. Questo previene accessi non controllati e garantisce che il saldo sia sempre valido.

## Ereditarietà

```java
public class Veicolo {
    protected String tipoCombustibile;

    public Veicolo(String tipoCombustibile) {
        this.tipoCombustibile = tipoCombustibile;
    }

    public void avvia() {
        System.out.println("Veicolo avviato!");
    }
}

public class Auto extends Veicolo {
    private int numeroDiPorte;

    public Auto(String tipoCombustibile, int numeroDiPorte) {
        super(tipoCombustibile); // Chiama il costruttore della classe base
        this.numeroDiPorte = numeroDiPorte;
    }

    public void apriTetto() {
        System.out.println("Tetto apribile aperto!");
    }
}
```

La classe `Auto` eredita da `Veicolo` e ne riutilizza attributi e metodi, aggiungendo funzionalità proprie come `apriTetto()`.

## Polimorfismo

```java
public class Animale {
    public void verso() {
        System.out.println("L'animale fa un verso.");
    }
}

public class Cane extends Animale {
    @Override
    public void verso() {
        System.out.println("Il cane abbaia.");
    }
}

public class Gatto extends Animale {
    @Override
    public void verso() {
        System.out.println("Il gatto miagola.");
    }
}

public class Main {
    public static void main(String[] args) {
        Animale mioAnimale = new Cane();
        mioAnimale.verso(); // Output: "Il cane abbaia."

        mioAnimale = new Gatto();
        mioAnimale.verso(); // Output: "Il gatto miagola."
    }
}
```

In questo esempio, sia Cane che `Gatto` ereditano da `Animale` e sovrascrivono il metodo `verso()`. Grazie al polimorfismo, possiamo usare una variabile di tipo `Animale` per chiamare il metodo `verso()` e ottenere il comportamento specifico di ogni sottoclasse.

## Astrazione

```java
public abstract class Forma {
    protected String colore;

    public Forma(String colore) {
        this.colore = colore;
    }

    // Metodo astratto: non è implementato qui, ma nelle sottoclassi
    public abstract double area();
}

public class Cerchio extends Forma {
    private double raggio;

    public Cerchio(String colore, double raggio) {
        super(colore);
        this.raggio = raggio;
    }

    @Override
    public double area() {
        return Math.PI * raggio * raggio;
    }
}
```

La classe `Forma` è astratta e definisce il metodo `area()` senza implementarlo. Le sottoclassi, come `Cerchio`, implementano `area() secondo le proprie regole specifiche.

