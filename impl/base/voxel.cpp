#include <foxl/data.hpp>

namespace foxl {

Voxel::Voxel() {
	this->data = 0;
}

bool Voxel::is_filled() const {
	return (this->data & (1u << 31u)) != 0;
}

uint32_t Voxel::prop_idx() const {
	return this->data & (0x007fffffu);
}

void Voxel::is_filled(bool f) {
	this->data = f ? (this->data | (1u << 31u)) : (this->data & ~(1u << 31u));
}

void Voxel::prop_idx(uint32_t m) {
	this->data &= ~0x007fffffu;
	this->data |= m & 0x007fffffu;
}
}
