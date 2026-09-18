#!/bin/bash
# Compila un archivo .cpp y guarda el ejecutable en build/ (misma estructura).
# Uso: ./scripts/build.sh ruta/al/archivo.cpp

set -e

if [ $# -ne 1 ]; then
    echo "Uso: $0 <archivo.cpp>"
    exit 1
fi

SRC="$1"
if [ ! -f "$SRC" ]; then
    echo "Error: no existe el archivo '$SRC'"
    exit 1
fi

OUT="build/${SRC%.cpp}"
mkdir -p "$(dirname "$OUT")"

g++ -std=c++17 -Wall -Wextra "$SRC" -o "$OUT"
echo "OK -> $OUT"
echo "Ejecuta: ./$OUT"