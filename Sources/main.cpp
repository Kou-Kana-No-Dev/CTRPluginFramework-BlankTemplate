#include <3ds.h>
#include "csvc.h"
#include <CTRPluginFramework.hpp>

#include <vector>

namespace CTRPluginFramework
{
    // This patch the NFC disabling the touchscreen when scanning an amiibo, which prevents ctrpf to be used
    static void    ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const std::vector<u32> pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalSize = 0;
        s64     startAddress = 0;
        u32 *   found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalSize)))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalSize);
exit:
        svcCloseHandle(processHandle);
    }

    // This function is called before main and before the game starts
    // Useful to do code edits safely
    void    PatchProcess(FwkSettings &settings)
    {
        ToggleTouchscreenForceOn();
    }

    // This function is called when the process exits
    // Useful to save settings, undo patchs or clean up things
    void    OnProcessExit(void)
    {
        ToggleTouchscreenForceOn();
    }

    void    InitMenu(PluginMenu &menu)
    {
menu->Append(new MenuEntry("カヴィリーマイクロ", CavilyMicro, "様々な機能を全てひとつにまとめました"));
MenuFolder *Cavily = new MenuFolder("カヴィリー");
{
	*Cavily += new MenuEntry("FOV強化(修正版)", FOVEnhancementModifiedVersion, "");
	*Cavily += new MenuEntry("エフェクト軽減", EffectReduction, "オフライン時発生するラグを軽減しメモリーアウトを防ぎます");
	*Cavily += new MenuEntry("UIスピードアップ", UISpeedUp, "");
	*Cavily += new MenuEntry("RP変更(-9999)", RPChange9999, "");
	*Cavily += new MenuEntry("RP(ランダム)", RPRandom, "");
	*Cavily += new MenuEntry("Amiiboスキン解放", AmiiboSkinRelease, "Amiiboスキンを購入可能にします、購入してからオンにすると購入前に戻ります");
	MenuFolder *OldVersionUnstable = new MenuFolder("古いバージョン(不安定)");
	{
		MenuFolder *KavilyClient = new MenuFolder("Kavily Client");
		{
			MenuFolder *Camera = new MenuFolder("Camera");
			{
				*Camera += new MenuEntry("Zoom", Zoom, "");
				*Camera += new MenuEntry("FOV Booster", FOVBooster, "");
				*Camera += new MenuEntry("FOV Boostest", FOVBoostest, "");
				
			}
			*KavilyClient += Camera;
			MenuFolder *EffectAndNamePlate = new MenuFolder("effect and name plate");
			{
				*EffectAndNamePlate += new MenuEntry("Name plate Viewer", NamePlateViewer, "");
				*EffectAndNamePlate += new MenuEntry("Name plate Viewer MINI", NamePlateViewerMINI, "");
				*EffectAndNamePlate += new MenuEntry("spak mini", SpakMini, "");
				*EffectAndNamePlate += new MenuEntry("spak", Spak, "");
				*EffectAndNamePlate += new MenuEntry("effect Removing", EffectRemoving, "");
				*EffectAndNamePlate += new MenuEntry("effect smaller", EffectSmaller, "");
				
			}
			*KavilyClient += EffectAndNamePlate;
			MenuFolder *Point = new MenuFolder("Point");
			{
				MenuFolder *RND = new MenuFolder("RND");
				{
					*RND += new MenuEntry("Point Editor(9639)", PointEditor9639, "");
					*RND += new MenuEntry("Point Editor(6873)", PointEditor6873, "");
					*RND += new MenuEntry("Point Editor(4892)", PointEditor4892, "");
					*RND += new MenuEntry("Point Editor(2342)", PointEditor2342, "");
					*RND += new MenuEntry("Point Editor(7202)", PointEditor7202, "");
					*RND += new MenuEntry("Point Editor(129)", PointEditor129, "");
					*RND += new MenuEntry("Point Editor(8635)", PointEditor8635, "");
					*RND += new MenuEntry("Point Editor(3739)", PointEditor3739, "");
					*RND += new MenuEntry("Point Editor(1530)", PointEditor1530, "");
					*RND += new MenuEntry("Point Editor(5566)", PointEditor5566, "");
					
				}
				*Point += RND;
				*Point += new MenuEntry("Point Editor(Randomizer)", PointEditorRandomizer, "");
				*Point += new MenuEntry("Point Editor(9999)", PointEditor9999, "");
				*Point += new MenuEntry("Point Editor(1)", PointEditor1, "");
				*Point += new MenuEntry("Point Editor(-9999)", PointEditor9999, "");
				*Point += new MenuEntry("Point Editor(-1)", PointEditor1, "");
				
			}
			*KavilyClient += Point;
			MenuFolder *SoundAndBGM = new MenuFolder("Sound And BGM");
			{
				*SoundAndBGM += new MenuEntry("Sound Speed Normal", SoundSpeedNormal, "");
				*SoundAndBGM += new MenuEntry("Sound Speed", SoundSpeed, "");
				*SoundAndBGM += new MenuEntry("BGM Ster En", BGMSterEn, "");
				*SoundAndBGM += new MenuEntry("BGM Ster Mini", BGMSterMini, "");
				*SoundAndBGM += new MenuEntry("BGM Ster", BGMSter, "");
				
			}
			*KavilyClient += SoundAndBGM;
			MenuFolder *UIAndStringsSize = new MenuFolder("UI and Strings size");
			{
				*UIAndStringsSize += new MenuEntry("Skip UI animation", SkipUIAnimation, "");
				*UIAndStringsSize += new MenuEntry("UI size", UISize, "");
				*UIAndStringsSize += new MenuEntry("UI size Mini", UISizeMini, "");
				*UIAndStringsSize += new MenuEntry("Strings", Strings, "");
				
			}
			*KavilyClient += UIAndStringsSize;
			MenuFolder *Other = new MenuFolder("Other");
			{
				*Other += new MenuEntry("Kirby Size", KirbySize, "");
				*Other += new MenuEntry("Kirby Size Fix", KirbySizeFix, "");
				
			}
			*KavilyClient += Other;
			MenuFolder *UnlockerHack = new MenuFolder("Unlocker Hack");
			{
				*UnlockerHack += new MenuEntry("Safe amiibo skin", SafeAmiiboSkin, "");
				*UnlockerHack += new MenuEntry("Amiibo Skin Hax(Danger)", AmiiboSkinHaxDanger, "");
				*UnlockerHack += new MenuEntry("Cosmetics Hack(Danger)", CosmeticsHackDanger, "");
				
			}
			*KavilyClient += UnlockerHack;
			
		}
		*OldVersionUnstable += KavilyClient;
		MenuFolder *DevFovarite = new MenuFolder("Dev Fovarite");
		{
			*DevFovarite += new MenuEntry("Sound Speed", SoundSpeed, "");
			*DevFovarite += new MenuEntry("Point Editor(Randomizer)", PointEditorRandomizer, "");
			*DevFovarite += new MenuEntry("effect smaller", EffectSmaller, "");
			*DevFovarite += new MenuEntry("BGM Ster Mini", BGMSterMini, "");
			*DevFovarite += new MenuEntry("Name plate Viewer MINI", NamePlateViewerMINI, "");
			*DevFovarite += new MenuEntry("Skip UI animation", SkipUIAnimation, "");
			*DevFovarite += new MenuEntry("FOV Boostest (Fixed)", FOVBoostestFixed, "");
			*DevFovarite += new MenuEntry("Strings Hide", StringsHide, "");
			*DevFovarite += new MenuEntry("s2", S2, "");
			*DevFovarite += new MenuEntry("Point Editor(-9999)", PointEditor9999, "");
			*DevFovarite += new MenuEntry("[++Dev Think", PlusplusDevThinkItUselessplusplus, "");
			*DevFovarite += new MenuEntry(" It useless++]", FOVBoostest, "");
			*DevFovarite += new MenuEntry("FOV Boostest", SoundSpeed, "");
			*DevFovarite += new MenuEntry("Sound Speed", UISize, "");
			*DevFovarite += new MenuEntry("UI size", UISize2, "");
			*DevFovarite += new MenuEntry("UI size2", UISizeMicro, "");
			*DevFovarite += new MenuEntry("UI size micro", NameChangeKavilyUser, "");
			*DevFovarite += new MenuEntry("name change (Kavily user)", NameChangeKavilyClientUser, "");
			*DevFovarite += new MenuEntry("name change (Kavily Client user)", SpakMini, "");
			*DevFovarite += new MenuEntry("spak mini", EffectMoreMini, "");
			*DevFovarite += new MenuEntry("effect more mini", SoundBalans, "");
			*DevFovarite += new MenuEntry("sound Balans", , "");
			
		}
		*OldVersionUnstable += DevFovarite;
		
	}
	*Cavily += OldVersionUnstable;
	
}
menu->Append(Cavily);

}
* += ;

    }

    int     main(void)
    {
        PluginMenu *menu = new PluginMenu("Kavily", 6, 6, 6,
                                            "Kavily Client v0.1");

       MessageBox("こちらはVIP版です。")

        // Synnchronize the menu with frame event
        menu->SynchronizeWithFrame(true);
        menu->ShowWelcomeMessage(false);
       OSD::Notify(Color::Cyan << "Thank you for Using Kavily Client");

        // Init our menu entries & folders
        InitMenu(*menu);

        // Launch menu and mainloop
        menu->Run();

        delete menu;

        // Exit plugin
        return (0);
    }
}
