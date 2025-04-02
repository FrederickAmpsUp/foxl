#pragma once

#include <fmt/core.h>
#include <glm/glm.hpp>

// glm::uvec3 formatter
template <>
struct fmt::formatter<glm::uvec3> : fmt::formatter<std::string> {
    // Format the glm::uvec3 as a tuple (x, y, z)
    template <typename FormatContext>
    auto format(const glm::uvec3& vec, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("({}, {}, {})", vec.x, vec.y, vec.z), ctx);
    }
};

