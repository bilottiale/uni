#!/bin/bash
# Test script per BST

echo "=== TEST BST INPUT RAPIDO ==="

# Input: 10 primo 20 secondo 0
(
    echo "10"
    echo "primo"
    echo "20" 
    echo "secondo"
    echo "0"
) | ./bst_print

echo ""
echo "=== FINE TEST ==="
