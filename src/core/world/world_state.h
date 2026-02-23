#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace infinimap::core::world {

enum class WaterType : uint8_t {
    None = 0,
    Ocean = 1,
    Lake = 2,
    River = 3
};

enum class BiomeType : uint16_t {
    Unknown = 0,
    Ocean = 1,
    Beach = 2,
    Plains = 3,
    Forest = 4,
    Desert = 5,
    Mountains = 6,
    Snow = 7
};

struct WorldMetadata {
    uint64_t seed = 0;
    std::string name;
    uint32_t worldWidth = 0;
    uint32_t worldHeight = 0;
    uint32_t formatVersion = 1;
};

struct TerrainSettings {
    uint32_t octaves = 6;
    float persistence = 0.5f;
    float lacunarity = 2.0f;
    float landRatio = 0.35f;
};

struct HydrologySettings {
    float riverThreshold = 0.02f;
    uint32_t erosionIterations = 50;
};

struct ClimateSettings {
    float latitudeWeight = 1.0f;
    float elevationWeight = 0.8f;
    float moistureWeight = 1.0f;
};

struct GenerationSettings {
    TerrainSettings terrain;
    HydrologySettings hydrology;
    ClimateSettings climate;
};

struct WorldLayers {
    std::vector<float> height;
    std::vector<WaterType> water;
    std::vector<float> flowAccumulation;
    std::vector<float> temperature;
    std::vector<float> moisture;
    std::vector<BiomeType> biome;
    std::vector<uint8_t> editMask;
};

class WorldState {
public:
    WorldMetadata metadata;
    GenerationSettings settings;
    WorldLayers layers;

    static WorldState createEmpty(const WorldMetadata& metadata, const GenerationSettings& settings = {});

    [[nodiscard]] size_t cellCount() const;
    [[nodiscard]] size_t index(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool inBounds(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool isValid(std::string* error = nullptr) const;
};

}  // namespace infinimap::core::world
