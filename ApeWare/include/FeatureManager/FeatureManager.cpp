#include "../../include/includes.h"
#include "FeatureManager.h"

FeatureBase* FeatureManager::FindFeature(const char* identifier)
{
	for (size_t i = 0; i < this->features.size(); i++)
	{
		if (strcmp(this->features[i].first, identifier) == 0)
			return this->features[i].second;
	}
	return nullptr;
}

void FeatureManager::AddFeature(const char* identifier, FeatureBase* feature)
{
	feature->OnInit();
	feature->index = this->features.size();
	this->features.push_back(std::pair<const char*, FeatureBase*>(identifier, feature));
}


void FeatureManager::LoopFeature(const char* identifier)
{
	FeatureBase* feature = this->FindFeature(identifier);
	if (feature)
		feature->OnLoop();
}

void FeatureManager::LoopAll()
{
	for (size_t i = 0; i < this->features.size(); i++)
		if (this->features[i].second->bToggle)
			this->features[i].second->OnLoop();
}

void FeatureManager::RenderFeature(const char* identifier)
{
	FeatureBase* feature = this->FindFeature(identifier);
	if (feature)
		feature->OnRender();
}

void FeatureManager::RenderAll()
{
	for (size_t i = 0; i < this->features.size(); i++)
		if (this->features[i].second->bToggle)
			this->features[i].second->OnRender();
}

void FeatureManager::RemoveFeature(const char* identifier)
{
	FeatureBase* feature = this->FindFeature(identifier);
	if (feature)
		feature->OnUnInit();

	this->features.erase(this->features.begin() + feature->index);
}

void FeatureManager::RemoveAll()
{
	for (size_t i = 0; i < this->features.size(); i++)
		this->features[i].second->OnUnInit();
}