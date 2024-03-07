#pragma once
class FeatureBase
{
public:
	virtual void OnInit();
	virtual void OnLoop();
	virtual void OnUnInit();
	virtual void OnRender();
	size_t index;
	bool bToggle;
};