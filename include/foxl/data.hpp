#pragma once

#include <cstdint>
#include <memory>
#include <glm/glm.hpp>

namespace foxl {

/**
* A single voxel's data. In Voxelforge, this simply stores a single 32-bit int, an index into a material/property array.
*/
struct Voxel {
	uint32_t matid;
};

/**
* A base class for all voxel storage constructs.
*/
class VoxelStorage {
public:
	/**
	* Get a constref to a specific voxel.
	*/
	virtual const Voxel& get(const glm::uvec3& pos) const = 0;

	/**
	* Copies the voxel into the storage.
	*/
	virtual void set(const Voxel& voxel, const glm::uvec3& pos) = 0;

	virtual Voxel& operator[](const glm::uvec3& pos) = 0;
	virtual const Voxel& operator[](const glm::uvec3& pos) const = 0;

	virtual ~VoxelStorage() = 0;
};

/**
* The simplest form of voxel data storage, just a 3d array of voxels.
*/
class DenseVoxelGrid : public VoxelStorage {
public:
	/**
	* Creates an empty voxel grid (initialized to matid 0) with the specified dimensions.
	*/
	DenseVoxelGrid(const glm::uvec3& dims);

	virtual const Voxel& get(const glm::uvec3& pos) const override;

	virtual void set(const Voxel& voxel, const glm::uvec3& pos) override;

	virtual Voxel& operator[](const glm::uvec3& pos) override;
	virtual const Voxel& operator[](const glm::uvec3& pos) const override;

	~DenseVoxelGrid();
private:
	std::unique_ptr<Voxel[]> data;
	glm::uvec3 dims;

	unsigned int index(const glm::uvec3& pos) const;
};
}
