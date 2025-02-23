public class T {
    private double temperatura;

    public T(double temperatura) {
        this.temperatura = temperatura;
    }

    public T() {
       this.temperatura = 0.0;
    }

    public double getTemperatura() {
        return temperatura;
    }

    public void setTemperatura(double newTemperatura) {
        this.temperatura = newTemperatura;
    }
}
