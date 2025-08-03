# Esempio Doxygen Standard - Doxyfile senza modifiche

Questo esempio dimostra l'uso di **Doxygen** con la configurazione standard generata da `doxygen -g`, senza alcuna modifica.

## 📁 File presenti

- `esempio_semplice.c` - Programma C di esempio con documentazione Doxygen
- `Doxyfile` - File di configurazione standard generato da `doxygen -g`
- `Makefile` - Makefile semplice per compilazione e generazione docs
- `html/` - Documentazione HTML generata (dopo `make docs`)
- `latex/` - Documentazione LaTeX generata (dopo `make docs`)

## 🚀 Come utilizzare

### 1. Compilazione ed esecuzione
```bash
make          # Compila il programma
make run      # Esegue il programma
```

### 2. Generazione documentazione
```bash
make docs     # Genera documentazione HTML e LaTeX
make open     # Genera e apre la documentazione nel browser
```

### 3. Pulizia
```bash
make clean    # Rimuove eseguibili e documentazione
```

## 📋 Configurazione Doxyfile Standard

Il file `Doxyfile` è stato generato con:
```bash
doxygen -g
```

**Configurazioni predefinite più importanti:**
- `PROJECT_NAME = "My Project"`
- `OUTPUT_DIRECTORY = "" (directory corrente)`
- `INPUT = . (directory corrente)`
- `RECURSIVE = NO`
- `EXTRACT_ALL = NO`
- `GENERATE_HTML = YES`
- `GENERATE_LATEX = YES`
- `SOURCE_BROWSER = NO`

## 🔍 Cosa viene documentato

Con la configurazione standard, Doxygen documenta:
- ✅ Funzioni con commenti `/** */`
- ✅ File con tag `@file`
- ❌ Funzioni senza documentazione (EXTRACT_ALL = NO)
- ❌ Codice sorgente navigabile (SOURCE_BROWSER = NO)

## 📚 Documentazione generata

La documentazione include:
- **html/index.html** - Pagina principale
- **html/files.html** - Lista dei file
- **html/globals.html** - Lista delle funzioni globali
- **html/esempio__semplice_8c.html** - Documentazione del file
- **latex/** - Versione LaTeX (per PDF)

## 🆚 Differenze con configurazione personalizzata

| Caratteristica | Standard | Personalizzata |
|----------------|----------|----------------|
| Nome progetto | "My Project" | Personalizzabile |
| Estrazione codice | Solo documentato | Tutto (EXTRACT_ALL) |
| Browser codice | Disabilitato | Abilitato |
| Lingua | Inglese | Configurabile |
| Output | HTML + LaTeX | Solo HTML |
| Ricerca | Disabilitata | Abilitata |

## 🎯 Quando usare la configurazione standard

**✅ Usa la configurazione standard quando:**
- Hai un progetto semplice
- Vuoi solo documentare le API pubbliche
- Non hai bisogno di personalizzazioni
- Vuoi iniziare velocemente

**❌ Personalizza quando:**
- Hai un progetto complesso
- Vuoi documentare tutto il codice
- Hai bisogno di funzionalità avanzate
- Vuoi un aspetto personalizzato

## 📖 Esempio di documentazione

Il file `esempio_semplice.c` mostra:

```c
/**
 * @file esempio_semplice.c
 * @brief Esempio semplice per testare Doxygen
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 */

/**
 * @brief Somma due numeri interi
 * @param a Primo numero
 * @param b Secondo numero
 * @return La somma di a e b
 */
int somma(int a, int b) {
    return a + b;
}
```

## 🛠️ Personalizzazioni possibili

Per personalizzare il Doxyfile:

1. **Cambia nome progetto:**
   ```
   PROJECT_NAME = "Il Mio Progetto"
   ```

2. **Estrai tutto il codice:**
   ```
   EXTRACT_ALL = YES
   ```

3. **Abilita browser codice:**
   ```
   SOURCE_BROWSER = YES
   ```

4. **Cambia lingua:**
   ```
   OUTPUT_LANGUAGE = Italian
   ```

5. **Disabilita LaTeX:**
   ```
   GENERATE_LATEX = NO
   ```

## 📚 Confronto con esempio completo

Nella cartella `../` (Lez8) trovi un esempio completo con:
- Doxyfile personalizzato
- Esempi avanzati di documentazione
- Makefile con più funzionalità
- Cheat sheet completo

---

**Esempio creato per dimostrare l'uso base di Doxygen**  
Data: 2 agosto 2025
