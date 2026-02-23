# InfiniMap post-MVP planning

## Product statement

Desktop application for creating detailed multi-layer 2D maps of fictional worlds.

## Post-MVP goals

1. Generate deterministic 2D world maps from a seed.
2. Produce believable macro geography (continents, ocean, elevations, coastlines).
3. Provide basic hydrology and biome placement logic.
4. Provide minimum viable editing tools in GUI (landmass, rivers, biomes).
5. Support project persistence in native `.infm` and export to `.jpeg`.

## Main goals

### 1) 2D map generation

- Keep all MVP capabilities and deepen simulation fidelity.
- Add lithosphere layer:
  - tectonic plates,
  - volcanic activity,
  - rock and mineral deposition,
  - soil types.
- Add advanced hydrology layer:
  - ocean currents,
  - river watersheds,
  - swamps,
  - glaciers,
  - groundwater.
- Add atmospheric layer:
  - temperature,
  - persistent wind flows,
  - weather map simulation.
- Add biosphere layer:
  - habitat ranges,
  - vegetation distribution,
  - life concentration.
- Add human population generation:
  - cities,
  - rural areas,
  - roads and logistics,
  - geography/climate-aware distribution.
- Add political layer:
  - culture groups,
  - language groups,
  - religion layer,
  - state generation,
  - trade maps.
- Add 2.5D projection mode for terrain relief visualization.

### 2) Spherical 3D maps

- Support 3D spherical maps with simulation and generation parity to 2D.
- Support sphere-shape adjustment.
- Support 2D ↔ 3D map conversion workflows.

### 3) Map editing tools

- Support editing of 3D maps.
- Support editing across all generated layers.
- Add additional brush modes and advanced editing workflows.

### 4) Formats

- Add map generation from source images (`jpg-to-noise`).
- Add vector format support.
- Add `.psd` support.

### 5) Extensibility

- Add plugin system (SDK) for third-party feature extensions.

## Change control for post-MVP

Any new feature is included in post-MVP implementation only if:

1. It directly supports one of the defined post-MVP main goals.
2. Its prerequisites are already delivered, or explicitly planned in the same phase.
3. It has clear acceptance criteria and can be tested automatically or with a repeatable manual protocol.
4. It preserves MVP guarantees:
   - deterministic generation for fixed seed and parameters,
   - backward compatibility for .infm (or documented migration),
   - no regression beyond agreed performance budgets.
5. It delivers clear user value (simulation realism, editing capability, interoperability, or extensibility).
If a proposal fails any criterion, it is moved to a long-term research backlog and excluded from the active post-MVP roadmap.
