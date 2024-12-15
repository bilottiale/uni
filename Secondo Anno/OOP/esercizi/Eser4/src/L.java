import java.io.IntegerInputStream;

// Classe L che implementa un lettore da un dispositivo
public class L {
    private IntegerInputStream dispositivo;  // Riferimento al dispositivo di input

    // Costruttore che inizializza la classe con un riferimento al dispositivo
    public L(IntegerInputStream dispositivo) {
        this.dispositivo = dispositivo;
    }

    // Metodo di lettura che restituisce il valore intero letto dal dispositivo
    public int read() {
        return dispositivo.read();  // Legge un intero dal dispositivo
    }
}
