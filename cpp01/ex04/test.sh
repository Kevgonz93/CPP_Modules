#!/bin/sh
# test.sh — Suite de tests para CPP01/ex04 (Sed is for losers)
# Uso: ./test.sh
# Requisitos: sh, make, diff

set -u

BIN=./ex04
BUILD_NEEDED=0
PASS=0
FAIL=0
TMPDIR="./_tests_tmp"

# Colores (opcionales; si no soporta, se verá sin color)
GREEN="$(printf '\033[32m')"
RED="$(printf '\033[31m')"
YELLOW="$(printf '\033[33m')"
BOLD="$(printf '\033[1m')"
RESET="$(printf '\033[0m')"

cleanup() {
  rm -rf "$TMPDIR"
}
trap cleanup EXIT

ensure_binary() {
  if [ ! -x "$BIN" ]; then
    echo "${YELLOW}[*] Compilando con make...${RESET}"
    if ! make; then
      echo "${RED}[!] Error: make falló${RESET}"
      exit 1
    fi
    BUILD_NEEDED=1
  fi
}

run_case() {
  # $1 = case_id (nombre corto, sin espacios)
  # $2 = s1
  # $3 = s2
  # (los contenidos de input y expected vendrán por aquí-doc)
  case_id="$1"; s1="$2"; s2="$3"
  in="$TMPDIR/${case_id}.txt"
  exp="$TMPDIR/${case_id}.expected"
  out="${in}.replace"

  # Leer stdin hasta línea que contenga solo "--EXPECTED--"
  # Primero contenido de entrada, luego contenido esperado
  # shellcheck disable=SC2162
  input_content=""
  expected_content=""
  mode="in"
  while IFS= read line; do
    [ "$line" = "--EXPECTED--" ] && mode="exp" && continue
    if [ "$mode" = "in" ]; then
      input_content="${input_content}${line}
"
    else
      expected_content="${expected_content}${line}
"
    fi
  done

  # Crear ficheros
  mkdir -p "$TMPDIR"
  # Evitar última línea extra al final: usar printf %s
  printf %s "$input_content"   > "$in"
  printf %s "$expected_content" > "$exp"

  # Ejecutar binario
  "$BIN" "$in" "$s1" "$s2" >/dev/null 2>&1

  # Comprobar existencia de salida
  if [ ! -f "$out" ]; then
    echo "${RED}[FAIL]${RESET} $case_id  ${YELLOW}(no se generó ${case_id}.txt.replace)${RESET}"
    FAIL=$((FAIL+1))
    return
  fi

  # Comparar
  if diff -u "$exp" "$out" >/dev/null 2>&1; then
    echo "${GREEN}[PASS]${RESET} $case_id"
    PASS=$((PASS+1))
  else
    echo "${RED}[FAIL]${RESET} $case_id"
    echo "${YELLOW}--- diff ---${RESET}"
    diff -u "$exp" "$out" || true
    FAIL=$((FAIL+1))
  fi
}

summary() {
  echo
  echo "${BOLD}Resultados:${RESET}  ${GREEN}${PASS} PASS${RESET}, ${RED}${FAIL} FAIL${RESET}"
  [ $FAIL -eq 0 ] || exit 1
}

main() {
  ensure_binary

  echo "${BOLD}===> Ejecutando tests...${RESET}"
  echo

  # 1) Caso simple (varias apariciones)
  run_case "simple" "hola" "adios" <<'EOF'
hola mundo
hola a todos
hola de nuevo
--EXPECTED--
adios mundo
adios a todos
adios de nuevo
EOF

  # 2) Repetidos y pegados
  run_case "repetidos" "42" "💫" <<'EOF'
42 42 42 es genial
424242 también contiene 42
--EXPECTED--
💫 💫 💫 es genial
💫💫💫 también contiene 💫
EOF

  # 3) Reemplazo por vacío (eliminar)
  run_case "eliminar" "borrame" "" <<'EOF'
borrame, por favor, borrame
no dejes rastros de borrame
--EXPECTED--
, por favor, 
no dejes rastros de 
EOF

  # 4) Mayúsculas/minúsculas (sensible a case)
  run_case "mayus" "con" "***" <<'EOF'
Con mayúscula
con minúscula
COn mezcla
--EXPECTED--
Con mayúscula
*** minúscula
COn mezcla
EOF

  # 5) Caracteres especiales + saltos de línea
  run_case "especial" "prueba" "TEST" <<'EOF'
línea1
línea2 🧠 prueba
línea3 prueba prueba
última línea
--EXPECTED--
línea1
línea2 🧠 TEST
línea3 TEST TEST
última línea
EOF

  # 6) s1 no aparece (salida idéntica)
  run_case "no_hit" "xyz" "ABC" <<'EOF'
nada que ver aquí
otra línea sin match
--EXPECTED--
nada que ver aquí
otra línea sin match
EOF

  # 7) s1 == s2 (copia tal cual)
  run_case "igual" "mismo" "mismo" <<'EOF'
esto es lo mismo, mismo texto
mismo por todas partes
--EXPECTED--
esto es lo mismo, mismo texto
mismo por todas partes
EOF

  summary
}

main "$@"
