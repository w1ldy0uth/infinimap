#!/usr/bin/env bash
set -euo pipefail

if [[ -z "${QT_ROOT:-}" ]]; then
  echo "QT_ROOT is not set. Example: export QT_ROOT=/Users/<you>/Qt/6.10.1/macos"
  exit 1
fi

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
CLEAN=false
POSITIONAL=()
for arg in "$@"; do
  case "$arg" in
    --clean)
      CLEAN=true
      ;;
    *)
      POSITIONAL+=("$arg")
      ;;
  esac
done

PRESET="${POSITIONAL[0]:-macos-clang}"
BUILD_PRESET="${POSITIONAL[1]:-macos-clang-debug}"
INSTALL_PREFIX="${POSITIONAL[2]:-$ROOT_DIR/dist/$PRESET}"

cmake --preset "$PRESET"
cmake --build --preset "$BUILD_PRESET"
cmake --install "$ROOT_DIR/build/$PRESET" --prefix "$INSTALL_PREFIX"

if [[ "$CLEAN" == "true" ]]; then
  rm -rf "$ROOT_DIR/build"
fi

echo "Installed to: $INSTALL_PREFIX"
