# Module Boundaries

## Proposed module map

1. `core/world`
- Owns data structures for map layers and metadata.
- No GUI dependencies.

2. `core/generation`
- Terrain generation, hydrology, climate proxy, biome classification.
- Depends on `core/world`.

3. `core/editing`
- Brush and topology-safe edit operations.
- Depends on `core/world`.

4. `core/render`
- Layer compositing and raster generation.
- Depends on `core/world`.

5. `core/io`
- `.infm` serialization, version migration, and `.jpeg` export.
- Depends on `core/world` and `core/render` for export path.

6. `app/ui`
- Desktop UI composition and interaction.
- Depends on `core/*` modules.

## Dependency rules

1. `app/ui` can depend on all core modules.
2. Core modules must not depend on `app/ui`.
3. `core/world` is leaf dependency and must stay framework-agnostic.
4. Cross-core calls should prefer stable interfaces over shared mutable internals.

## Extension points (post-MVP)

1. `core/simulation/lithosphere`
2. `core/simulation/atmosphere`
3. `core/simulation/biosphere`
4. `core/simulation/society`
5. `plugins/*` (when plugin system is introduced)

## Testing strategy by module

1. `core/generation`: deterministic golden tests.
2. `core/editing`: operation invariants and topology constraints.
3. `core/io`: round-trip compatibility tests.
4. `core/render`: snapshot tests for reference maps.
