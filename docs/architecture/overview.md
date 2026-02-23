# System Overview

## Architectural goals

1. Deterministic outputs for identical seed + parameters.
2. Clear separation between generation, editing, rendering, and persistence.
3. Incremental evolution toward advanced post-MVP simulation layers.

## High-level components

1. `Generation Core`
- Produces terrain, water, and biome layers from seed and generation settings.

2. `World State`
- Canonical in-memory representation of map layers and metadata.

3. `Editor`
- Applies user-driven modifications (landmass, river, biome edits) as reversible operations.

4. `Renderer`
- Converts layers into viewport and export-ready raster outputs.

5. `Persistence`
- Loads/saves native `.infm` format and exports `.jpeg`.

6. `Desktop UI`
- Hosts map canvas, tool panels, and generation controls.

## Data flow

1. User chooses seed and generation parameters.
2. `Generation Core` creates `World State`.
3. `Renderer` displays layers in UI.
4. `Editor` mutates `World State` through tools.
5. `Persistence` serializes/deserializes state and exports images.

## Non-functional requirements

1. Seed determinism.
2. Cross-platform compatibility (C++17 + CMake).
3. Stable serialization versioning for `.infm`.
4. Test coverage for generation and IO regression.
