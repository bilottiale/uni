public class Tmax extends T {
    private double maxTemperatura;

    public Tmax(double temperatura, double maxTemperatura) {
        super(temperatura);
        this.maxTemperatura = maxTemperatura;
    }

    public Tmax() {
        super();
        this.maxTemperatura = 0.0;
    }

    public double getMaxTemperatura() {
        return maxTemperatura;
    }

    public void resetMaxTemperatura() {
        this.maxTemperatura = getTemperatura();
    }

    @Override
    public void setTemperatura(double newTemperatura) {
        super.setTemperatura(newTemperatura);  // Imposta sempre la nuova temperatura
        if (newTemperatura > this.maxTemperatura) {  // Se la nuova temperatura è maggiore della massima
            this.maxTemperatura = newTemperatura;  // Aggiorna la temperatura massima
        }
    }
}
