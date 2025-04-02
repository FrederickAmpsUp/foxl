#include <foxl/data.hpp>
#include <foxl/util.hpp>
#include <stdexcept>
#include <fmt/core.h>

namespace foxl {

DenseVoxelGrid::DenseVoxelGrid(const glm::uvec3& dims) {
	size_t size = dims.x*dims.y*dims.z;
	this->data = std::make_unique<Voxel[]>(size);
	this->dims = dims;

	for (size_t i = 0; i < size; ++i) {
		this->data[i] = Voxel { 0 };
	}
}

const Voxel& DenseVoxelGrid::get(const glm::uvec3& pos) const {
	return (*this)[pos];
}

void DenseVoxelGrid::set(const Voxel& voxel, const glm::uvec3& pos) {
	(*this)[pos] = voxel;
}

Voxel& DenseVoxelGrid::operator[](const glm::uvec3& pos) {
	unsigned int idx = this->index(pos);

	return this->data[idx];
}

const Voxel& DenseVoxelGrid::operator[](const glm::uvec3& pos) const {
	return (*this)[pos];
}

unsigned int DenseVoxelGrid::index(const glm::uvec3& pos) const {

	// We only do bounds checking in debug mode
#ifndef NDEBUG
	if (pos.x > this->dims.x || pos.y > this->dims.y || pos.x > this->dims.z)
		throw std::out_of_range(fmt::format("Attempted to access voxel at {}, out of bounds for size {}!", pos, this->dims));
#endif

	return pos.x + pos.y * this->dims.x + pos.x * this->dims.x*this->dims.y;
}
}
