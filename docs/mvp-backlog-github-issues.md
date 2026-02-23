# InfiniMap MVP Backlog (GitHub Issues Ready)

This backlog is derived from `InfiniMap.md` MVP scope only.
Final vision items (3D sphere, socio-political layers, plugins, etc.) are explicitly out of scope for MVP.

## Recommended Labels

- `type:feature`
- `type:tech-debt`
- `type:test`
- `type:docs`
- `area:generation`
- `area:hydrology`
- `area:climate`
- `area:biome`
- `area:editor`
- `area:gui`
- `area:io`
- `area:infra`
- `priority:P0`
- `priority:P1`
- `priority:P2`
- `status:blocked`
- `mvp`

## Milestones

- `M1 Core Generation`
- `M2 Simulation Basics`
- `M3 Editor + GUI`
- `M4 Formats + Stabilization`

## Issue List

### M1 Core Generation

1. **[P0] MVP scope freeze and non-goals document**
- Labels: `mvp`, `type:docs`, `area:infra`, `priority:P0`
- Estimate: `0.5d`
- Depends on: none
- Description: Convert MVP section of `InfiniMap.md` into a signed-off scope document and list explicit non-goals.
- Acceptance criteria:
- MVP feature list approved.
- Non-goals list approved (all Final vision items deferred).

2. **[P0] Core world data model**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P0`
- Estimate: `1.5d`
- Depends on: #1
- Description: Define in-memory model for map state: heightmap, water map, biome map, masks, seed, metadata.
- Acceptance criteria:
- Single `WorldState` model used by generator, renderer, and serializer.
- Data dimensions and coordinate conventions documented.

3. **[P0] Deterministic seed-based generation service**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P0`
- Estimate: `1d`
- Depends on: #2
- Description: Introduce generation entrypoint that produces identical output for same seed + params.
- Acceptance criteria:
- Same seed/params -> byte-identical output layers.
- Different seed -> visibly different map.

4. **[P0] Base terrain generator (noise + fBm + land/ocean mask)**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P0`
- Estimate: `3d`
- Depends on: #3
- Description: Build base elevation map with configurable octaves/persistence/lacunarity and continent shaping mask.
- Acceptance criteria:
- Land/ocean ratio is controllable.
- Continents and global ocean appear in generated maps.

5. **[P1] Elevation redistribution and mountain pass**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P1`
- Estimate: `2d`
- Depends on: #4
- Description: Improve elevation realism with redistribution curve and mountain/ridge enhancement.
- Acceptance criteria:
- Elevation histogram is non-uniform and realistic.
- Mountains concentrate into ranges, not random spikes.

6. **[P1] Coastline refinement (islands, archipelagos, fjord-like cuts)**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P1`
- Estimate: `2d`
- Depends on: #4
- Description: Post-process coastlines for richer shoreline detail.
- Acceptance criteria:
- Generated maps contain small islands/archipelagos.
- Coastline complexity is adjustable by parameters.

7. **[P1] Tectonic influence approximation**
- Labels: `mvp`, `type:feature`, `area:generation`, `priority:P1`
- Estimate: `3d`
- Depends on: #5
- Description: MVP-level tectonic proxy that influences elevation/ridges (not full plate simulation).
- Acceptance criteria:
- Turning tectonic proxy on/off changes large-scale mountain placement.
- Parameters are exposed in generation settings.

### M2 Simulation Basics

8. **[P0] Hydrology flow direction and accumulation**
- Labels: `mvp`, `type:feature`, `area:hydrology`, `priority:P0`
- Estimate: `3d`
- Depends on: #5
- Description: Compute downhill flow and accumulation grid.
- Acceptance criteria:
- Every non-basin land cell has valid downstream path.
- Ocean cells do not route inland.

9. **[P0] River tracing (source, tributaries, mouth)**
- Labels: `mvp`, `type:feature`, `area:hydrology`, `priority:P0`
- Estimate: `3d`
- Depends on: #8
- Description: Extract river network from accumulation threshold.
- Acceptance criteria:
- Rivers start on high/accumulated areas and terminate at sea/lake.
- Tributary structure is visible.

10. **[P1] Lake detection and basin fill**
- Labels: `mvp`, `type:feature`, `area:hydrology`, `priority:P1`
- Estimate: `2d`
- Depends on: #8
- Description: Detect endorheic basins and generate lakes.
- Acceptance criteria:
- Closed basins form lakes.
- Lake outflow appears when spill elevation is exceeded.

11. **[P1] Simplified erosion pass (hydraulic/thermal)**
- Labels: `mvp`, `type:feature`, `area:hydrology`, `priority:P1`
- Estimate: `3d`
- Depends on: #8
- Description: Smooth unrealistic terrain and carve river valleys.
- Acceptance criteria:
- Erosion reduces isolated spikes and noise artifacts.
- River corridors become more plausible after pass.

12. **[P1] Climate proxy layers (temperature/moisture)**
- Labels: `mvp`, `type:feature`, `area:climate`, `priority:P1`
- Estimate: `2d`
- Depends on: #5, #8
- Description: Build simplified climate fields from latitude, elevation, and moisture transport proxy.
- Acceptance criteria:
- Temperature and moisture maps generated per world.
- Latitude and altitude significantly affect temperature.

13. **[P0] Biome classifier and palette mapping**
- Labels: `mvp`, `type:feature`, `area:biome`, `priority:P0`
- Estimate: `2d`
- Depends on: #12
- Description: Classify each tile into biome using climate + elevation + water proximity.
- Acceptance criteria:
- Includes ocean, beach, plains, forest, desert, mountains, snow.
- Biome transitions look coherent at continental scale.

### M3 Editor + GUI

14. **[P0] Map canvas with pan/zoom and layer toggles**
- Labels: `mvp`, `type:feature`, `area:gui`, `priority:P0`
- Estimate: `3d`
- Depends on: #4, #13
- Description: Build main workspace with map rendering, navigation, and visibility toggles for layers.
- Acceptance criteria:
- Smooth pan/zoom on large maps.
- User can toggle at least terrain/water/biome overlays.

15. **[P0] Generation settings panel**
- Labels: `mvp`, `type:feature`, `area:gui`, `priority:P0`
- Estimate: `2d`
- Depends on: #3, #14
- Description: GUI controls for seed and core generation parameters.
- Acceptance criteria:
- User can set seed and regenerate.
- Terrain/hydrology/biome key parameters are editable.

16. **[P1] Landmass editing tools (add/remove)**
- Labels: `mvp`, `type:feature`, `area:editor`, `priority:P1`
- Estimate: `2.5d`
- Depends on: #14
- Description: Brush tools to add/remove land and re-run dependent local updates.
- Acceptance criteria:
- Brush add/remove modifies land mask.
- View updates without full app restart.

17. **[P1] River drawing/editing tools**
- Labels: `mvp`, `type:feature`, `area:editor`, `priority:P1`
- Estimate: `2d`
- Depends on: #14, #9
- Description: Draw/erase river segments with topology checks.
- Acceptance criteria:
- User can add and remove river segments.
- Invalid uphill flows are rejected or auto-corrected.

18. **[P1] Biome painting tools**
- Labels: `mvp`, `type:feature`, `area:editor`, `priority:P1`
- Estimate: `2d`
- Depends on: #14, #13
- Description: Manual biome brush override.
- Acceptance criteria:
- User can paint selected biome.
- Overrides are persisted in `.infm`.

19. **[P2] Import/export UI workflow**
- Labels: `mvp`, `type:feature`, `area:gui`, `area:io`, `priority:P2`
- Estimate: `1.5d`
- Depends on: #20, #21
- Description: File dialogs and status/error reporting for load/save/export.
- Acceptance criteria:
- Save/load/export is accessible from GUI.
- Errors are user-visible and non-crashing.

### M4 Formats + Stabilization

20. **[P0] `.infm` format specification**
- Labels: `mvp`, `type:docs`, `area:io`, `priority:P0`
- Estimate: `1d`
- Depends on: #2
- Description: Write schema/versioning doc for native map format.
- Acceptance criteria:
- Format versioning policy defined.
- Required and optional fields documented.

21. **[P0] `.infm` serializer/deserializer**
- Labels: `mvp`, `type:feature`, `area:io`, `priority:P0`
- Estimate: `2d`
- Depends on: #20
- Description: Save/load complete world state including edits.
- Acceptance criteria:
- Round-trip save/load preserves map and settings.
- Unsupported version returns explicit error.

22. **[P0] Raster export to `.jpeg`**
- Labels: `mvp`, `type:feature`, `area:io`, `priority:P0`
- Estimate: `1d`
- Depends on: #14
- Description: Export current composited map view (or full map) to JPEG.
- Acceptance criteria:
- JPEG export works for representative map sizes.
- Output quality/compression parameter available.

23. **[P0] Test suite for determinism, hydrology, biome, IO**
- Labels: `mvp`, `type:test`, `area:infra`, `priority:P0`
- Estimate: `3d`
- Depends on: #3, #9, #13, #21
- Description: Add automated tests for core correctness and regression detection.
- Acceptance criteria:
- Determinism test for fixed seed.
- Hydrology test validates downstream consistency.
- Biome validity test for allowed enum set.
- Save/load round-trip tests pass.

24. **[P0] CI pipeline (build + tests)**
- Labels: `mvp`, `type:feature`, `area:infra`, `priority:P0`
- Estimate: `1d`
- Depends on: #23
- Description: Run build and tests on each push/PR.
- Acceptance criteria:
- CI runs automatically.
- PR shows pass/fail status before merge.

25. **[P1] Performance baseline and profiling pass**
- Labels: `mvp`, `type:tech-debt`, `area:infra`, `priority:P1`
- Estimate: `2d`
- Depends on: #14, #23
- Description: Set baseline metrics and optimize obvious bottlenecks.
- Acceptance criteria:
- Generation time and memory metrics captured.
- At least one documented optimization landed.

26. **[P1] MVP documentation and quickstart**
- Labels: `mvp`, `type:docs`, `area:infra`, `priority:P1`
- Estimate: `1d`
- Depends on: #14, #21, #22
- Description: Update README with build/run steps and MVP workflow.
- Acceptance criteria:
- New contributor can build and generate first map from docs.
- Docs include save/load/export instructions.

## Suggested Sprint Breakdown

- Sprint 1: #1-#4
- Sprint 2: #5-#7, #13
- Sprint 3: #8-#12
- Sprint 4: #14-#16
- Sprint 5: #17-#22
- Sprint 6: #23-#26 (stabilization + release candidate)

## Critical Path

`#1 -> #2 -> #3 -> #4 -> #5 -> #8 -> #9 -> #12 -> #13 -> #14 -> #21 -> #23 -> #24`

## Definition of Done (MVP Release)

- All `P0` issues completed.
- CI green on default branch.
- User can generate seeded world, edit land/rivers/biomes, save/load `.infm`, and export `.jpeg`.
- Basic docs published for setup and usage.
