/*
 * test_inserisci_persona.c
 * 
 * Programma di test per popolare automaticamente il file people.dat
 * con dati di esempio per testare tutte le funzionalità.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 30
#define FILENAME "people.dat"

typedef struct {
    char cognome[MAX_NOME + 1];
    char nome[MAX_NOME + 1];
    char sesso;
    int anno_nascita;
} Persona;

// Dati di test
Persona persone_test[] = {
    {"Rossi", "Mario", 'M', 1990},
    {"Bianchi", "Anna", 'F', 1985},
    {"Verdi", "Luigi", 'M', 1978},
    {"Neri", "Giulia", 'F', 1992},
    {"Ferrari", "Marco", 'M', 1988},
    {"Romano", "Laura", 'F', 1995},
    {"Russo", "Alessandro", 'M', 1982},
    {"Conti", "Francesca", 'F', 1991},
    {"De Santis", "Paolo", 'M', 1975},
    {"Ricci", "Martina", 'F', 1998},
    {"Marino", "Giovanni", 'M', 1987},
    {"Greco", "Valentina", 'F', 1994},
    {"Bruno", "Stefano", 'M', 1983},
    {"Gallo", "Chiara", 'F', 1996},
    {"Costa", "Roberto", 'M', 1979},
    {"Fontana", "Elena", 'F', 1993},
    {"Esposito", "Davide", 'M', 1986},
    {"Barbieri", "Silvia", 'F', 1989},
    {"Rizzo", "Andrea", 'M', 1981},
    {"Silva", "Morgan", 'N', 1990}  // Persona con sesso non specificato
};

void crea_file_test() {
    FILE* file = fopen(FILENAME, "wb");  // Sovrascrive il file esistente
    if (!file) {
        perror("❌ Errore apertura file");
        return;
    }
    
    int num_persone = sizeof(persone_test) / sizeof(Persona);
    
    printf("🎯 CREAZIONE FILE DI TEST\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("📁 File: %s\n", FILENAME);
    printf("👥 Persone da inserire: %d\n", num_persone);
    printf("📊 Dimensione record: %zu bytes\n", sizeof(Persona));
    printf("💾 Dimensione totale: %zu bytes\n", num_persone * sizeof(Persona));
    
    // Scrivi tutti i record
    size_t scritti = fwrite(persone_test, sizeof(Persona), num_persone, file);
    
    if (scritti == num_persone) {
        printf("✅ File creato con successo!\n");
        printf("📊 %zu record scritti\n", scritti);
    } else {
        printf("❌ Errore: scritti solo %zu record su %d\n", scritti, num_persone);
    }
    
    fclose(file);
}

void verifica_file() {
    FILE* file = fopen(FILENAME, "rb");
    if (!file) {
        printf("❌ File non trovato!\n");
        return;
    }
    
    printf("\n🔍 VERIFICA FILE CREATO\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    
    Persona p;
    int count = 0;
    int maschi = 0, femmine = 0, non_spec = 0;
    
    printf("%-3s %-15s %-15s %-5s %-6s %-4s\n", 
           "N°", "COGNOME", "NOME", "SESSO", "NASCITA", "ETÀ");
    printf("-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "\n");
    
    while (fread(&p, sizeof(Persona), 1, file) == 1) {
        count++;
        int eta = 2025 - p.anno_nascita;
        printf("%-3d %-15s %-15s %-5c %-6d %-4d\n", 
               count, p.cognome, p.nome, p.sesso, p.anno_nascita, eta);
        
        // Conta per sesso
        switch (p.sesso) {
            case 'M': maschi++; break;
            case 'F': femmine++; break;
            case 'N': non_spec++; break;
        }
    }
    
    printf("-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "-" "\n");
    printf("📊 Totale: %d persone\n", count);
    printf("👨 Maschi: %d (%.1f%%)\n", maschi, (maschi * 100.0) / count);
    printf("👩 Femmine: %d (%.1f%%)\n", femmine, (femmine * 100.0) / count);
    printf("❓ Non specificato: %d (%.1f%%)\n", non_spec, (non_spec * 100.0) / count);
    
    fclose(file);
}

void info_dimensioni() {
    FILE* file = fopen(FILENAME, "rb");
    if (!file) {
        printf("❌ File non trovato!\n");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int num_record = file_size / sizeof(Persona);
    
    printf("\n📏 ANALISI DIMENSIONI FILE\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("📁 File: %s\n", FILENAME);
    printf("📏 Dimensione file: %ld bytes\n", file_size);
    printf("📦 Dimensione record: %zu bytes\n", sizeof(Persona));
    printf("👥 Numero record: %d\n", num_record);
    printf("💾 Efficienza: %.1f%% (senza overhead filesystem)\n", 
           ((double)(num_record * sizeof(Persona)) / file_size) * 100);
    
    // Confronto con file di testo ipotetico
    long testo_stimato = num_record * 80;  // Stima ~80 char per record in formato testo
    printf("\n📊 CONFRONTO con FILE DI TESTO (stimato):\n");
    printf("💾 Binario: %ld bytes\n", file_size);
    printf("📝 Testo:   %ld bytes (stimato)\n", testo_stimato);
    printf("⚡ Risparmio: %ld bytes (%.1f%%)\n", 
           testo_stimato - file_size, 
           ((double)(testo_stimato - file_size) / testo_stimato) * 100);
    
    fclose(file);
}

int main() {
    printf("🧪 TEST AUTOMATICO - INSERISCI PERSONA\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    
    crea_file_test();
    verifica_file();
    info_dimensioni();
    
    printf("\n🎯 PROSSIMI PASSI:\n");
    printf("1. Esegui './inserisci_persona' per gestire interattivamente il file\n");
    printf("2. Prova tutte le funzioni: visualizza, cerca, statistiche\n");
    printf("3. Aggiungi nuove persone al file esistente\n");
    
    return 0;
}
