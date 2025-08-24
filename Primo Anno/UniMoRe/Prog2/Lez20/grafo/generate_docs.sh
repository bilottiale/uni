#!/bin/bash

# ==============================================================================
# 📚 Script di Generazione Documentazione Doxygen
# ==============================================================================
# Genera automaticamente la documentazione HTML per il modulo grafo
# usando Doxygen con configurazione personalizzata
# ==============================================================================

# 🎨 Colori per output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}📚 GENERAZIONE DOCUMENTAZIONE DOXYGEN${NC}"
echo -e "${BLUE}=====================================+${NC}"

# 🔍 Verifica presenza di Doxygen
if ! command -v doxygen &> /dev/null; then
    echo -e "${RED}❌ Doxygen non trovato!${NC}"
    echo -e "${YELLOW}💡 Installazione su macOS:${NC}"
    echo -e "   brew install doxygen"
    echo -e "${YELLOW}💡 Installazione su Ubuntu/Debian:${NC}"
    echo -e "   sudo apt-get install doxygen"
    exit 1
fi

echo -e "${GREEN}✅ Doxygen trovato: $(doxygen --version)${NC}"

# 📁 Verifica file necessari
required_files=("grafo_documented.h" "grafo.cc" "Doxyfile")
for file in "${required_files[@]}"; do
    if [[ ! -f "$file" ]]; then
        echo -e "${RED}❌ File richiesto non trovato: $file${NC}"
        exit 1
    fi
done

echo -e "${GREEN}✅ Tutti i file richiesti sono presenti${NC}"

# 🧹 Pulizia directory output precedente
if [[ -d "doxygen_output" ]]; then
    echo -e "${YELLOW}🧹 Rimozione documentazione precedente...${NC}"
    rm -rf doxygen_output
fi

# 🔨 Generazione documentazione
echo -e "${BLUE}🔨 Generazione documentazione...${NC}"
doxygen Doxyfile

# ✅ Verifica successo
if [[ $? -eq 0 ]]; then
    echo -e "${GREEN}✅ Documentazione generata con successo!${NC}"
    echo -e "${YELLOW}📂 Output directory: ./doxygen_output/html/${NC}"
    echo -e "${YELLOW}🌐 Apri nel browser: ./doxygen_output/html/index.html${NC}"
    
    # 🚀 Apertura automatica nel browser (opzionale)
    if [[ "$1" == "--open" || "$1" == "-o" ]]; then
        echo -e "${BLUE}🚀 Apertura nel browser...${NC}"
        if command -v open &> /dev/null; then
            # macOS
            open doxygen_output/html/index.html
        elif command -v xdg-open &> /dev/null; then
            # Linux
            xdg-open doxygen_output/html/index.html
        elif command -v start &> /dev/null; then
            # Windows (Git Bash)
            start doxygen_output/html/index.html
        else
            echo -e "${YELLOW}⚠️  Impossibile aprire automaticamente il browser${NC}"
        fi
    fi
    
    # 📊 Statistiche
    echo -e "${BLUE}📊 Statistiche documentazione:${NC}"
    html_files=$(find doxygen_output/html -name "*.html" | wc -l)
    echo -e "   📄 File HTML generati: $html_files"
    
    if [[ -f "doxygen_output/html/index.html" ]]; then
        size=$(du -h doxygen_output/html/index.html | cut -f1)
        echo -e "   📏 Dimensione index.html: $size"
    fi
    
else
    echo -e "${RED}❌ Errore durante la generazione della documentazione${NC}"
    exit 1
fi

echo ""
echo -e "${GREEN}🎉 Processo completato!${NC}"
echo -e "${YELLOW}💡 Suggerimenti:${NC}"
echo -e "   • Apri doxygen_output/html/index.html nel browser"
echo -e "   • Usa '$0 --open' per aprire automaticamente"
echo -e "   • Modifica Doxyfile per personalizzare l'output"
