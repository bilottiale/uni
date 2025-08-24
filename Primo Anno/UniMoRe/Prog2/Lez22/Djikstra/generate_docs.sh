#!/bin/bash
# Script per generare la documentazione Doxygen

# Vai alla directory dello script
cd "$(dirname "$0")"

# Controlla se doxygen è installato
if ! [ -x "$(command -v doxygen)" ]; then
  echo 'Errore: doxygen non è installato.' >&2
  echo 'Installalo con "brew install doxygen" o il gestore di pacchetti del tuo sistema.' >&2
  exit 1
fi

# Rimuove la vecchia documentazione se esiste
if [ -d "doxygen_output" ]; then
  echo "Rimozione della vecchia documentazione..."
  rm -rf doxygen_output
fi

echo "Generazione della documentazione Doxygen..."

# Esegue Doxygen
doxygen Doxyfile

# Controlla se la documentazione è stata generata
if [ -d "doxygen_output/html" ]; then
  echo "Documentazione generata con successo nella directory 'doxygen_output/html'."
  echo "Puoi aprire 'doxygen_output/html/index.html' nel tuo browser."
else
  echo "Errore durante la generazione della documentazione." >&2
fi
