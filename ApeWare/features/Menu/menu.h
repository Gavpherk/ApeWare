#pragma once
#include "../../include/includes.h"

class Menu;
class Weapon;
class Player;

class Menu : public FeatureBase
{
public:

	void OnInit() override;
	void OnLoop() override;
	void OnUnInit() override;
	void OnRender() override;
	bool showmenu = false;
	bool debugtypeinfos = false;
	bool debugmethods = false;

	Menu* g_menu;
	Weapon* g_weapon;
	Player* g_player;


	bool g_InstantReload = false;
};