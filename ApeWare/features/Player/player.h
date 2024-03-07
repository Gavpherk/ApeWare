#pragma once
#include "../../include/includes.h"

class Player : public FeatureBase
{
public:

	void UnlockAll(bool toggle);

	void OnInit() override;
	void OnLoop() override;
	void OnUnInit() override;
	void OnRender() override;
};