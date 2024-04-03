#pragma once
#include "../../include/includes.h"
#include "../../include/Globals.h"

class Menu;
class Weapon;
class Player;
class Account;
class ESP;
class DEBUG;
class Movement;
class Misc;
class HookManager;

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
	ESP* g_esp;
	Account* g_account;
	Misc* g_misc;
	Movement* g_movement;
	DEBUG* g_debug;
	HookManager* m_hookManager;
};