[CmdletBinding()]
param(
    [string]$ConfigurePreset = "windows-mingw",
    [string]$BuildPreset = "",
    [string]$InstallPrefix = "",
    [switch]$Clean
)

$ErrorActionPreference = "Stop"

if (-not $env:QT_ROOT) {
    Write-Error "QT_ROOT is not set. Example: `$env:QT_ROOT='C:/Qt/6.10.1/mingw_64'"
}

$rootDir = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
if (-not $BuildPreset) {
    $BuildPreset = "$ConfigurePreset-debug"
}
if (-not $InstallPrefix) {
    $InstallPrefix = Join-Path $rootDir "dist/$ConfigurePreset"
}

$installPrefix = [System.IO.Path]::GetFullPath($InstallPrefix)
$buildDir = Join-Path $rootDir "build/$ConfigurePreset"

if ($Clean) {
    Remove-Item -Recurse -Force $buildDir -ErrorAction SilentlyContinue
    Remove-Item -Recurse -Force $installPrefix -ErrorAction SilentlyContinue
}

cmake --preset $ConfigurePreset
cmake --build --preset $BuildPreset
cmake --install $buildDir --prefix $installPrefix

Write-Host "Installed to: $installPrefix"
