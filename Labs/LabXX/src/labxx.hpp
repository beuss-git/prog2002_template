#pragma once
#include <graphics_framework.hpp>


class LabXX final : public GraphicsFramework {
public:
	LabXX(int argc, char* argv[])
		: GraphicsFramework(argc, argv) {}

	bool setup() override;

	bool run() override;

	bool cleanup() override;
};