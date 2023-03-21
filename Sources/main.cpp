#include "CTRPluginFramework.hpp"
#include "cheats.hpp"
#include "csvc.h"

namespace CTRPluginFramework
{
	static MenuEntry *AddArg(void *arg, MenuEntry *entry)
	{
		if (entry != nullptr)
			entry->SetArg(arg);
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey& hotkey)
	{
		if (entry != nullptr)
		{
			entry->Hotkeys += hotkey;
			entry->SetArg(new std::string(entry->Name()));
			entry->Name() += " " + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
				{
					std::string *name = reinterpret_cast<std::string*>(entry->GetArg());

					entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
				});
		}
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey>& hotkeys)
	{
		if (entry != nullptr)
		{
			for (const Hotkey& hotkey : hotkeys)
				entry->Hotkeys += hotkey;
		}
		return (entry);
	}

	static MenuEntry *EnabledEntry(MenuEntry *entry)
	{
		if (entry != nullptr) entry->Enable();
		return (entry);
	}

	PluginMenu *menu;

	void InitMenu()
	{
		MenuFolder *folderA = new MenuFolder("");
		*menu += new MenuEntry("start_bruet",nullptr,start_bruet,"");
		*menu += new MenuEntry("mode_selt",nullptr,mode_selt,"");
		*menu += new MenuEntry("setup_bruet",nullptr,setup_bruet,"");
		*menu += new MenuEntry("editor",editor1,"");
		*menu += new MenuEntry("setup_bruet_custom",nullptr,setup_bruet_custom,"");
	}

		int main(void)
	{
		menu = new PluginMenu("Hello", 0, 0, 0, "hi");
		menu->SynchronizeWithFrame(true);
		InitMenu();
		menu->Run();
		delete menu;
		return 0;
	}

}
