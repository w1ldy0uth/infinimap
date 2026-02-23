# Generation Pipeline

## MVP pipeline stages

1. `Seed initialization`
- Build deterministic random streams from seed and settings.

2. `Base terrain synthesis`
- Generate base elevation with noise/fBm and continent/ocean shaping.

3. `Relief refinement`
- Apply elevation redistribution and mountain/coastline refinement.

4. `Hydrology pass`
- Compute flow direction and accumulation.
- Extract river network and lakes.

5. `Erosion pass`
- Run simplified hydraulic/thermal erosion for terrain plausibility.

6. `Climate proxy pass`
- Derive temperature and moisture layers from latitude/elevation/water influence.

7. `Biome classification`
- Assign biome per tile from climate + elevation + water proximity.

8. `Post-process and validation`
- Enforce invariants and prepare render/export-ready layers.

## Rebuild modes

1. `Full rebuild`
- Recompute all stages from seed/settings.

2. `Partial rebuild`
- Recompute only dependent stages after local edits.
- Example: landmass edit invalidates hydrology, climate proxy, and biome maps.

## Determinism rules

1. Each stage must consume deterministic RNG streams.
2. Parallel execution must be deterministic (stable chunk ordering or reduced nondeterminism).
3. Floating-point sensitive paths should define precision and ordering expectations.

## Validation checklist per generation run

1. No NaN/Inf in numeric layers.
2. Flow graph has no invalid cycles on downhill terrain.
3. Biome values belong to supported enum set.
4. Layer dimensions and metadata are consistent.
