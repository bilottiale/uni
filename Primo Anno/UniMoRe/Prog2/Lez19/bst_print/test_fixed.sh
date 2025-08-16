#!/bin/bash
# Test della versione corretta

echo "=== TEST BST FIXED ==="

# Input automatico
(
    echo "10"
    echo "primo"
    echo "5" 
    echo "secondo"
    echo "15"
    echo "terzo"
    echo "0"
) | ./bst_fixed

echo ""
echo "=== FINE TEST ==="
