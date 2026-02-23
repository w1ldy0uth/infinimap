# Build

Requirements:

- CMake 3.24+
- C++20-compatible compiler
- Qt 6 (Core, Gui, Widgets)

## Configure Qt path

Example for Windows:
```powershell
$env:QT_ROOT="C:/Qt/6.10.1/mingw_64"
```

For Linux/macOS, set `QT_ROOT` to your Qt kit prefix (the directory that contains `lib/cmake/Qt6/Qt6Config.cmake`).

## Build with presets

GCC (any platform where `g++` is available in PATH):

```bash
cmake --preset gcc-native
cmake --build --preset gcc-native-debug
```

Windows (MinGW Qt kit):

```powershell
cmake --preset windows-mingw
cmake --build --preset windows-mingw-debug
```

Windows (MSVC):

```powershell
cmake --preset windows-msvc
cmake --build --preset windows-msvc-debug
```

Linux:

```bash
cmake --preset linux-gcc
cmake --build --preset linux-gcc-debug
```

macOS:

```bash
cmake --preset macos-clang
cmake --build --preset macos-clang-debug
```

## Install (with Qt deployment script)

Windows:

```powershell
$prefix = "$((Resolve-Path .).Path)/dist/<configure-preset-name>"
cmake --install build/<configure-preset-name> --prefix $prefix
```

Linux/macOS:

```bash
prefix="$(pwd)/dist/<configure-preset-name>"
cmake --install "build/<configure-preset-name>" --prefix "$prefix"
```

Use an absolute `--prefix` path. On Windows + Qt deploy tooling, a relative prefix may fail.

## Install scripts

Windows (`scripts/install-windows.ps1`):

```powershell
# Default: windows-mingw + windows-mingw-debug
.\scripts\install-windows.ps1

# MSVC
.\scripts\install-windows.ps1 -ConfigurePreset windows-msvc -BuildPreset windows-msvc-debug

# Optional: remove build/<preset> AFTER successful install
.\scripts\install-windows.ps1 -Clean
```

Linux (`scripts/install-linux.sh`):

```bash
# Default: linux-gcc + linux-gcc-debug
./scripts/install-linux.sh

# Custom presets
./scripts/install-linux.sh linux-gcc linux-gcc-debug

# Optional: remove build/<preset> AFTER successful install
./scripts/install-linux.sh linux-gcc linux-gcc-debug "$(pwd)/dist/linux-gcc" --clean
```

macOS (`scripts/install-macos.sh`):

```bash
# Default: macos-clang + macos-clang-debug
./scripts/install-macos.sh

# Custom presets
./scripts/install-macos.sh macos-clang macos-clang-debug

# Optional: remove build/<preset> AFTER successful install
./scripts/install-macos.sh macos-clang macos-clang-debug "$(pwd)/dist/macos-clang" --clean
```
