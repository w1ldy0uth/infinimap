# World Data Model

## Design principles

1. Single authoritative `WorldState`.
2. Layer-oriented storage for predictable transforms.
3. Serializable and versioned fields for `.infm`.

## Core entities

## `WorldMetadata`

- `seed: uint64`
- `name: string`
- `world_width: uint32`
- `world_height: uint32`
- `created_at: timestamp`
- `format_version: uint32`

## `GenerationSettings`

- Terrain settings (noise type, octaves, persistence, lacunarity, land ratio).
- Hydrology settings (flow thresholds, erosion iterations).
- Climate settings (temperature/moisture coefficients).
- Biome settings (classification thresholds/palette id).

## `WorldLayers`

- `height: float32[]` (normalized elevation)
- `water_mask: uint8[]` (ocean/lake/river occupancy)
- `flow_dir: int8[]` (optional direction code)
- `flow_accum: float32[]` (optional accumulation)
- `temperature: float32[]`
- `moisture: float32[]`
- `biome: uint16[]`
- `edit_mask: uint8[]` (manual overrides)

## `WorldState`

- `metadata: WorldMetadata`
- `settings: GenerationSettings`
- `layers: WorldLayers`
- `history: EditOp[]` (optional undo/redo stream)

## Invariants

1. All layer arrays match `world_width * world_height`.
2. Elevation and climate layers stay normalized to documented ranges.
3. River cells must have valid downstream path unless terminal at lake/ocean.
4. Manual edits must be explicitly marked for regeneration policy.

## Coordinate conventions

1. Grid origin is top-left: `(0, 0)`.
2. `x` increases left-to-right, `y` increases top-to-bottom.
3. Linear index is row-major: `index = y * world_width + x`.
4. Valid coordinate range is:
   - `0 <= x < world_width`
   - `0 <= y < world_height`

## Serialization notes

1. `.infm` should include format version and optional migration metadata.
2. Unknown future fields should be ignored safely when possible.
3. Backward compatibility requires migration handlers between minor versions.
