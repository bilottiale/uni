public class Main {
    public static void main(String[] args) {
        Libro libro1 = new Libro("Stephen King", "It", 3);
        Libro libro2 = new Libro("J.K. Rowling", "Harry Potter", 2);

        
        System.out.println("Libro 1: " + libro1.autore + " - " + libro1.titolo + " - " + libro1.nCopie);
        System.out.println("Libro 2: " + libro2.autore + " - " + libro2.titolo + " - " + libro2.nCopie);

        System.out.println();
        
        System.out.println("Prestito libro 1: " + libro1.prestitoLibro());
        System.out.println("Prestito libro 1: " + libro1.prestitoLibro());

        System.out.println();
        
        System.out.println("Prestito libro 2: " + libro2.prestitoLibro());
        System.out.println("Prestito libro 2: " + libro2.prestitoLibro());

        System.out.println();
        
        System.out.println("Restituzione libro 1: " + libro1.restituzioneLibro());
        System.out.println("Restituzione libro 2: " + libro2.restituzioneLibro());

        System.out.println();

        System.out.println("Libro 1: " + libro1.autore + " - " + libro1.titolo + " - " + libro1.nCopie);
        System.out.println("Libro 2: " + libro2.autore + " - " + libro2.titolo + " - " + libro2.nCopie);
    }
}