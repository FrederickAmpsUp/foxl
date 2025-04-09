#include <foxl/math.hpp>

namespace foxl {
namespace math {

constexpr uint32_t next_power_of_2(uint32_t x) {
	if (x == 0) return 1;
	uint32_t power = 1;
	while (power < x) {
		power <<= 1;
	}
	return power;
}
}
}
