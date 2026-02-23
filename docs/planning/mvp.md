# InfiniMap MVP

## Product statement

Desktop application for creating detailed multi-layer 2D maps of fictional worlds.

## MVP goals

1. Generate deterministic 2D world maps from a seed.
2. Produce believable macro geography (continents, ocean, elevations, coastlines).
3. Provide basic hydrology and biome placement logic.
4. Provide minimum viable editing tools in GUI (landmass, rivers, biomes).
5. Support project persistence in native `.infm` and export to `.jpeg`.

## In-scope MVP features

### 1) 2D map generation

- World map generation using randomized/procedural algorithms.
- Realistic generation of continents and world ocean (noise + SDF + fBm as baseline approach).
- Tectonic influence approximation (MVP-level proxy, not full plate simulation).
- Realistic erosion and hydrology baseline:
  - Rivers flow downhill with source, mouth, tributaries, and optional delta logic.
  - Lakes generated from basin and biome/relief constraints.
- Climate influence on biome placement (simplified climate model).
- Realistic elevation distribution.
- Realistic coastlines with islands/archipelagos/fjord-like complexity.

### 2) Map editing tools

- Basic add/remove landmass tools.
- River drawing/editing tools.
- Biome painting tools.

### 3) GUI

- Main map workspace (canvas with navigation).
- UI for map generation parameters.
- UI for drawing tools.
- UI for import/export actions.

### 4) Formats

- Native map format `.infm`.
- Load map from `.infm`.
- Export map to raster `.jpeg`.

## Change control for MVP

Any new feature is included in MVP only if:

1. It directly supports one of the in-scope MVP sections above.
2. It does not introduce dependencies on deferred systems.
3. It can be delivered without moving MVP release criteria.

Otherwise, it goes to post-MVP backlog.
