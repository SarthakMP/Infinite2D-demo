#pragma once
#include"Headers/Behaviour.h"
#include <array>

class TreeGen : public Behaviour_Adapter
{
public:
	std::array<std::array<std::array<int, 6>, 6>, 2 > TreePreset;


	void InitializePresets();
	
	TreeGen();
};
