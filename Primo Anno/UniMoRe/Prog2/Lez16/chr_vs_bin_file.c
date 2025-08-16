/*
 * CHARACTER FILE vs BINARY FILE - Dimostrazione Pratica
 * 
 * Questo programma dimostra le differenze fondamentali tra:
 * - File di TESTO (Character/Text File)
 * - File BINARI (Binary File)
 * 
 * Caratteristiche:
 * 1. Modalità di apertura diverse
 * 2. Formato di memorizzazione
 * 3. Leggibilità umana
 * 4. Efficienza di spazio
 * 5. Portabilità tra sistemi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struttura di esempio per dimostrare la scrittura binaria
typedef struct {
    int id;
    char nome[20];
    float voto;
    int eta;
} Studente;

void stampa_separatore(const char* titolo) {
    printf("\n" "=" "=" "=" "=" " %s " "=" "=" "=" "=" "\n", titolo);
}

void esempio_file_carattere() {
    stampa_separatore("FILE DI CARATTERE (TEXT)");
    
    FILE* file_text = fopen("studenti_text.txt", "w");
    if (!file_text) {
        perror("Errore apertura file testo");
        return;
    }
    
    // Scrittura in formato TESTO (leggibile dall'uomo)
    fprintf(file_text, "ID: %d\n", 1001);
    fprintf(file_text, "Nome: %s\n", "Mario Rossi");
    fprintf(file_text, "Voto: %.2f\n", 28.50);
    fprintf(file_text, "Eta: %d\n", 22);
    fprintf(file_text, "---\n");
    
    fprintf(file_text, "ID: %d\n", 1002);
    fprintf(file_text, "Nome: %s\n", "Anna Bianchi");
    fprintf(file_text, "Voto: %.2f\n", 30.00);
    fprintf(file_text, "Eta: %d\n", 21);
    
    fclose(file_text);
    
    printf("✅ File di testo creato: studenti_text.txt\n");
    printf("📄 Contenuto leggibile con qualsiasi editor di testo\n");
    printf("📊 Dimensione: maggiore (ogni carattere = 1 byte)\n");
    
    // Lettura e visualizzazione del file testo
    file_text = fopen("studenti_text.txt", "r");
    if (file_text) {
        printf("\n📖 Contenuto del file di testo:\n");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file_text)) {
            printf("   %s", buffer);
        }
        fclose(file_text);
    }
}

void esempio_file_binario() {
    stampa_separatore("FILE BINARIO (BINARY)");
    
    FILE* file_bin = fopen("studenti_binary.dat", "wb");
    if (!file_bin) {
        perror("Errore apertura file binario");
        return;
    }
    
    // Creazione di strutture dati
    Studente studenti[2] = {
        {1001, "Mario Rossi", 28.50, 22},
        {1002, "Anna Bianchi", 30.00, 21}
    };
    
    // Scrittura BINARIA (formato macchina)
    fwrite(studenti, sizeof(Studente), 2, file_bin);
    fclose(file_bin);
    
    printf("✅ File binario creato: studenti_binary.dat\n");
    printf("🔒 Contenuto NON leggibile con editor di testo\n");
    printf("⚡ Dimensione: minore (dati in formato macchina)\n");
    printf("🚀 Velocità: lettura/scrittura più rapida\n");
    
    // Lettura dal file binario
    file_bin = fopen("studenti_binary.dat", "rb");
    if (file_bin) {
        printf("\n📊 Lettura dal file binario:\n");
        Studente buffer;
        while (fread(&buffer, sizeof(Studente), 1, file_bin) == 1) {
            printf("   ID: %d, Nome: %s, Voto: %.2f, Età: %d\n", 
                   buffer.id, buffer.nome, buffer.voto, buffer.eta);
        }
        fclose(file_bin);
    }
}

void confronto_dimensioni() {
    stampa_separatore("CONFRONTO DIMENSIONI FILE");
    
    FILE* text_file = fopen("studenti_text.txt", "r");
    FILE* bin_file = fopen("studenti_binary.dat", "rb");
    
    if (text_file && bin_file) {
        // Calcola dimensione file di testo
        fseek(text_file, 0, SEEK_END);
        long text_size = ftell(text_file);
        fclose(text_file);
        
        // Calcola dimensione file binario
        fseek(bin_file, 0, SEEK_END);
        long bin_size = ftell(bin_file);
        fclose(bin_file);
        
        printf("📏 File di testo:  %ld bytes\n", text_size);
        printf("📏 File binario:   %ld bytes\n", bin_size);
        printf("💾 Risparmio:      %ld bytes (%.1f%%)\n", 
               text_size - bin_size, 
               ((float)(text_size - bin_size) / text_size) * 100);
    }
}

void esempio_numeri_formato() {
    stampa_separatore("FORMATO NUMERI: TESTO vs BINARIO");
    
    int numero = 12345;
    float decimale = 98.76;
    
    printf("🔢 Numero intero: %d\n", numero);
    printf("📝 In file di testo: '%d' (5 caratteri = 5 bytes)\n", numero);
    printf("💾 In file binario: 4 bytes fissi (sizeof(int))\n");
    
    printf("\n🔢 Numero decimale: %.2f\n", decimale);
    printf("📝 In file di testo: '%.2f' (5 caratteri = 5 bytes)\n", decimale);
    printf("💾 In file binario: 4 bytes fissi (sizeof(float))\n");
    
    // Dimostrazione pratica
    FILE* f_text = fopen("numero_text.txt", "w");
    FILE* f_bin = fopen("numero_bin.dat", "wb");
    
    if (f_text && f_bin) {
        fprintf(f_text, "%d", numero);
        fwrite(&numero, sizeof(int), 1, f_bin);
        
        fclose(f_text);
        fclose(f_bin);
        
        // Confronta dimensioni
        f_text = fopen("numero_text.txt", "r");
        f_bin = fopen("numero_bin.dat", "rb");
        
        fseek(f_text, 0, SEEK_END);
        long text_size = ftell(f_text);
        fseek(f_bin, 0, SEEK_END);
        long bin_size = ftell(f_bin);
        
        printf("\n✅ Verifica pratica:\n");
        printf("   📄 Testo: %ld bytes\n", text_size);
        printf("   💾 Binario: %ld bytes\n", bin_size);
        
        fclose(f_text);
        fclose(f_bin);
    }
}

void confronto_caratteristiche() {
    stampa_separatore("CONFRONTO CARATTERISTICHE");
    
    printf("╔════════════════╦═══════════════════╦═══════════════════╗\n");
    printf("║ CARATTERISTICA ║    FILE TESTO     ║   FILE BINARIO    ║\n");
    printf("╠════════════════╬═══════════════════╬═══════════════════╣\n");
    printf("║ Leggibilità    ║ ✅ Leggibile      ║ ❌ Non leggibile   ║\n");
    printf("║ Dimensione     ║ ❌ Maggiore       ║ ✅ Minore          ║\n");
    printf("║ Velocità I/O   ║ ❌ Più lenta      ║ ✅ Più veloce      ║\n");
    printf("║ Portabilità    ║ ✅ Più portabile  ║ ⚠️  Meno portabile ║\n");
    printf("║ Editing        ║ ✅ Facilmente     ║ ❌ Difficile       ║\n");
    printf("║ Precisione     ║ ⚠️  Perdita dati  ║ ✅ Preserva dati   ║\n");
    printf("║ Modalità       ║ 'r', 'w', 'a'     ║ 'rb', 'wb', 'ab'  ║\n");
    printf("╚════════════════╩═══════════════════╩═══════════════════╝\n");
}

void esempio_modalita_apertura() {
    stampa_separatore("MODALITÀ DI APERTURA FILE");
    
    printf("📝 FILE DI TESTO:\n");
    printf("   • 'r'  - Lettura\n");
    printf("   • 'w'  - Scrittura (sovrascrive)\n");
    printf("   • 'a'  - Append (aggiunge alla fine)\n");
    printf("   • 'r+' - Lettura e scrittura\n");
    
    printf("\n💾 FILE BINARIO:\n");
    printf("   • 'rb' - Lettura binaria\n");
    printf("   • 'wb' - Scrittura binaria (sovrascrive)\n");
    printf("   • 'ab' - Append binario\n");
    printf("   • 'rb+' o 'r+b' - Lettura e scrittura binaria\n");
    
    printf("\n⚠️  IMPORTANTE:\n");
    printf("   Su sistemi Windows la 'b' è cruciale!\n");
    printf("   Su Unix/Linux la 'b' è opzionale ma consigliata.\n");
}

void pulizia_file() {
    // Rimuove i file di esempio creati
    remove("studenti_text.txt");
    remove("studenti_binary.dat");
    remove("numero_text.txt");
    remove("numero_bin.dat");
}

int main() {
    printf("🎯 DIMOSTRAZIONE: CHARACTER FILE vs BINARY FILE\n");
    printf("================================================\n");
    
    esempio_file_carattere();
    esempio_file_binario();
    confronto_dimensioni();
    esempio_numeri_formato();
    confronto_caratteristiche();
    esempio_modalita_apertura();
    
    printf("\n" "=" "=" "=" "=" " CONCLUSIONI " "=" "=" "=" "=" "\n");
    printf("📋 USA FILE DI TESTO per:\n");
    printf("   • Configurazioni\n");
    printf("   • Log files\n");
    printf("   • Dati da leggere/modificare manualmente\n");
    printf("   • Interscambio tra sistemi diversi\n");
    
    printf("\n📋 USA FILE BINARI per:\n");
    printf("   • Database\n");
    printf("   • Immagini, video, audio\n");
    printf("   • Grandi quantità di dati numerici\n");
    printf("   • Quando la velocità è cruciale\n");
    
    printf("\n🧹 Rimuovo file di esempio...\n");
    pulizia_file();
    printf("✅ File di esempio rimossi.\n");
    
    return 0;
}