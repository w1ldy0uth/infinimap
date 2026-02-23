#include "world_state.h"

#include <limits>

namespace infinimap::core::world {

namespace {
size_t expectedSize(const WorldMetadata& metadata) {
    return static_cast<size_t>(metadata.worldWidth) * static_cast<size_t>(metadata.worldHeight);
}
}  // namespace

WorldState WorldState::createEmpty(const WorldMetadata& metadata, const GenerationSettings& settings) {
    WorldState state;
    state.metadata = metadata;
    state.settings = settings;

    const size_t count = expectedSize(metadata);
    state.layers.height.assign(count, 0.0f);
    state.layers.water.assign(count, WaterType::None);
    state.layers.flowAccumulation.assign(count, 0.0f);
    state.layers.temperature.assign(count, 0.0f);
    state.layers.moisture.assign(count, 0.0f);
    state.layers.biome.assign(count, BiomeType::Unknown);
    state.layers.editMask.assign(count, 0);

    return state;
}

size_t WorldState::cellCount() const {
    return expectedSize(metadata);
}

size_t WorldState::index(uint32_t x, uint32_t y) const {
    return static_cast<size_t>(y) * metadata.worldWidth + x;
}

bool WorldState::inBounds(uint32_t x, uint32_t y) const {
    return x < metadata.worldWidth && y < metadata.worldHeight;
}

bool WorldState::isValid(std::string* error) const {
    if (metadata.worldWidth == 0 || metadata.worldHeight == 0) {
        if (error) *error = "World dimensions must be greater than zero.";
        return false;
    }

    const uint64_t width = metadata.worldWidth;
    const uint64_t height = metadata.worldHeight;
    if (width > std::numeric_limits<uint64_t>::max() / height) {
        if (error) *error = "World dimensions overflow cell count.";
        return false;
    }

    const size_t expected = cellCount();
    const bool valid =
        layers.height.size() == expected &&
        layers.water.size() == expected &&
        layers.flowAccumulation.size() == expected &&
        layers.temperature.size() == expected &&
        layers.moisture.size() == expected &&
        layers.biome.size() == expected &&
        layers.editMask.size() == expected;

    if (!valid && error) {
        *error = "One or more world layers have invalid size.";
    }
    return valid;
}

}  // namespace infinimap::core::world
