import java.io.IntegerInputStream;

public class L {
    private IntegerInputStream dispositivo;

    public L(IntegerInputStream dispositivo) {
        this.dispositivo = dispositivo;
    }

    public int lettura() {
        return dispositivo.read();
    }
}
