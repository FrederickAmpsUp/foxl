#include <gtest/gtest.h>
#include <foxl/data.hpp>
#include <foxl/util.hpp>
#include <random>
#include <iostream>

template<typename S>
void test_voxel_storage() {
	static const glm::uvec3 dims(12, 24, 36);
	static const int iters = 100;

	std::uniform_int_distribution<unsigned int> x_dist(0, dims.x-1);
	std::uniform_int_distribution<unsigned int> y_dist(0, dims.y-1);
	std::uniform_int_distribution<unsigned int> z_dist(0, dims.z-1);

	std::uniform_int_distribution<unsigned int> prop_idx_dist(0, (1 << 23) - 1);

	static const unsigned int seed = 0;

	std::mt19937 gen(seed);

	S s(dims);
	foxl::VoxelStorage &storage = s;

	for (int i = 0; i < iters; ++i) {
		const glm::uvec3 pos(
			x_dist(gen), y_dist(gen), z_dist(gen)
		);

		const unsigned int prop_idx = prop_idx_dist(gen);

		std::cout << fmt::format("Testing voxel {} with prop idx {} (iteration {})...", pos, prop_idx, i);

		storage[pos].is_filled(true);
		storage[pos].prop_idx(prop_idx);

		const foxl::Voxel& voxel = storage.get(pos);
	
		EXPECT_TRUE(voxel.is_filled()) << "voxel.is_filled() reported false!";
		EXPECT_EQ(voxel.prop_idx(), prop_idx) << fmt::format("voxel.prop_idx() reported {}, expected {}!", voxel.prop_idx(), prop_idx);

		std::cout << "Passed!" << std::endl;
	}
}

TEST(FoxlTestSuite, DenseVoxelGrid) {
	test_voxel_storage<foxl::DenseVoxelGrid>();
}
