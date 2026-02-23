#!/usr/bin/env bash
set -euo pipefail

if [[ -z "${QT_ROOT:-}" ]]; then
  echo "QT_ROOT is not set. Example: export QT_ROOT=/opt/Qt/6.10.1/gcc_64"
  exit 1
fi

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PRESET="${1:-linux-gcc}"
BUILD_PRESET="${2:-linux-gcc-debug}"
INSTALL_PREFIX="${3:-$ROOT_DIR/dist/$PRESET}"
CLEAN_FLAG="${4:-}"

if [[ "$CLEAN_FLAG" == "--clean" ]]; then
  rm -rf "$ROOT_DIR/build/$PRESET" "$INSTALL_PREFIX"
fi

cmake --preset "$PRESET"
cmake --build --preset "$BUILD_PRESET"
cmake --install "$ROOT_DIR/build/$PRESET" --prefix "$INSTALL_PREFIX"

echo "Installed to: $INSTALL_PREFIX"
