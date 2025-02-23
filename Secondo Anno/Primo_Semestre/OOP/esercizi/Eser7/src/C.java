public class C {
    private double contoParziale;

   public C() {
       this.contoParziale = 0.0;
   }

   public double getContoParziale() {
       return contoParziale;
   }

   public void aggiungiSpesa(double costo) {
       if(costo > 0) {
           this.contoParziale += costo;
       } else {
           throw new IllegalArgumentException("Costo non valido");
       }
   }

   public void azzeraConto() {
       contoParziale = 0.0;
   }
}
