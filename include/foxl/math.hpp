#pragma once

#include <glm/glm.hpp>

namespace foxl {
namespace math {

/**
 * @brief Calculates \f$y\f$, where \f$y = 2^{n}\f$ and \f$y >= x\f$
 * @param x The value to calculate y based on.
 * @returns \f$2^{\lceil \log_2(x) \rceil}\f$
 */
constexpr uint32_t next_power_of_2(uint32_t x);

constexpr glm::uvec3 round_up_to_cube_pow2(glm::uvec3 v);
}
}
