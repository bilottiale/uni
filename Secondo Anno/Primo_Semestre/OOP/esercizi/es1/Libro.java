public class Libro {
    String autore, titolo;
    int nCopie;

    public Libro (String autore, String titolo, int nCopie) {
        this.autore = autore;
        this.titolo = titolo;
        this.nCopie = nCopie;
    }

    public int prestitoLibro() {
        try {
            if (nCopie > 0) {
                nCopie--;
                return 1;
            } else {
                return 0;
            }
        } catch (Exception e) {
            return -1;
        }
    }

    public int restituzioneLibro() {
        try {
            nCopie++;
            return 1;
        } catch (Exception e) {
            return -1;
        }
    }
}