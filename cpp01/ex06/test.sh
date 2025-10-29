#!/bin/bash

# Nombre del ejecutable
EXEC="./harlFilter"

# Compila antes de probar
make re > /dev/null 2>&1
if [ ! -f "$EXEC" ]; then
    echo "❌ Error: no se generó el ejecutable $EXEC"
    exit 1
fi

# Colores para salida
GREEN="\033[1;32m"
RED="\033[1;31m"
CYAN="\033[1;36m"
RESET="\033[0m"

# Niveles de prueba
LEVELS=("DEBUG" "INFO" "WARNING" "ERROR" "random")

echo -e "${CYAN}=== HARL FILTER TEST SCRIPT ===${RESET}\n"

for lvl in "${LEVELS[@]}"; do
    echo -e "${GREEN}▶ Argumento: '$lvl'${RESET}"
    $EXEC "$lvl"
    echo -e "-----------------------------\n"
done

echo -e "${CYAN}=== TESTS COMPLETADOS ===${RESET}"
