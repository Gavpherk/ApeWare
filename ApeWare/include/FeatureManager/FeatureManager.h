#pragma once
class FeatureManager
{
public:
	std::vector<std::pair<const char*, FeatureBase*>> features;

	FeatureBase* FindFeature(const char* identifier);
	void AddFeature(const char* identifier, FeatureBase* feature);

	void LoopFeature(const char* identifier);
	void LoopAll();

	void RenderFeature(const char* identifier);
	void RenderAll();

	void RemoveFeature(const char* identifier);
	void RemoveAll();
};