#pragma once
#include "../../include/includes.h"

class Weapon : public FeatureBase
{
public:

	void OnInit() override;
	void OnLoop() override;
	void OnUnInit() override;
	void OnRender() override;
};