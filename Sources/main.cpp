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
       menu->Append(new MenuEntry("最初にこちらをお読みください", PleaseReadThisFirst, "Kavily Client VIP v0.1 カヴィリークライアントこちらはVIP版となります。CTRPFやActionReplayの扱いに慣れている方におすすめ致します慣れていない方は無印版をご利用くださいなおVIP版は限定公開ですので2次配布はおやめください"));
menu->Append(new MenuEntry("カヴィリーミニ", CavilyMini, "超安定していて、作者も最近このコードひとつでオン潜ってます！"));
MenuFolder *AuthorsFavoriteCode = new MenuFolder("作者が愛用しているコード");
{
	*AuthorsFavoriteCode += new MenuEntry("ランクポイント変更(8635)", RankPointChange8635, "");
	*AuthorsFavoriteCode += new MenuEntry("エフェクト軽減", EffectReduction, "");
	*AuthorsFavoriteCode += new MenuEntry("BGMの速度をあげる", IncreaseTheSpeedOfBGM, "");
	*AuthorsFavoriteCode += new MenuEntry("BGMを再生しない", DoNotPlayBGM, "");
	*AuthorsFavoriteCode += new MenuEntry("ネームプレートを自分に近づける", MakeTheNameplateCloserToYou, "");
	*AuthorsFavoriteCode += new MenuEntry("効果音の速度をあげる", IncreaseTheSpeedOfSoundEffects, "");
	*AuthorsFavoriteCode += new MenuEntry("効果音を消す(UIのみ)", TurnOffSoundEffectsUIOnly, "");
	*AuthorsFavoriteCode += new MenuEntry("UIのアニメーション速度をあげる(6倍)", IncreaseUIAnimationSpeed6x, "");
	*AuthorsFavoriteCode += new MenuEntry("カメラの視野:最大", CameraFieldOfViewMaximum, "");
	*AuthorsFavoriteCode += new MenuEntry("文字をほぼ非表示", AlmostHideCharacters, "");
	*AuthorsFavoriteCode += new MenuEntry("UIサイズを 0.9375倍に", UISizeIncreasedBy09375Times, "");
	*AuthorsFavoriteCode += new MenuEntry("UIサイズを戻す", ReturnUISize, "");
	
}
menu->Append(AuthorsFavoriteCode);
MenuFolder *MoldyClient = new MenuFolder("カビリークライアント");
{
	MenuFolder *Camera = new MenuFolder("カメラ");
	{
		*Camera += new MenuEntry("ズーム", Zoom, "");
		*Camera += new MenuEntry("カメラの視野:大", CameraFieldOfViewLarge, "");
		*Camera += new MenuEntry("カメラの視野:最大", CameraFieldOfViewMaximum, "");
		
	}
	*MoldyClient += Camera;
	MenuFolder *EffectsAndNameplates = new MenuFolder("エフェクトとネームプレート");
	{
		*EffectsAndNameplates += new MenuEntry("ネームプレートの場所を変える", ChangeTheLocationOfTheNameplate, "");
		*EffectsAndNameplates += new MenuEntry("エフェクト削除", DeleteEffect, "");
		*EffectsAndNameplates += new MenuEntry("エフェクト減少", EffectReduction, "");
		
	}
	*MoldyClient += EffectsAndNameplates;
	MenuFolder *RankPoint = new MenuFolder("ランクポイント");
	{
		MenuFolder *Random = new MenuFolder("ランダム");
		{
			*Random += new MenuEntry("(9639)", N9639, "");
			*Random += new MenuEntry("(6873)", N6873, "");
			*Random += new MenuEntry("(4892)", N4892, "");
			*Random += new MenuEntry("(2342)", N2342, "");
			*Random += new MenuEntry("(7202)", N7202, "");
			*Random += new MenuEntry("(129)", N129, "");
			*Random += new MenuEntry("(8635)", N8635, "");
			*Random += new MenuEntry("(3739)", N3739, "");
			*Random += new MenuEntry("(1530)", N1530, "");
			*Random += new MenuEntry("(5566)", N5566, "");
			
		}
		*RankPoint += Random;
		*RankPoint += new MenuEntry("(9999)", N9999, "");
		*RankPoint += new MenuEntry("(1)", N1, "");
		*RankPoint += new MenuEntry("(-1)", 1, "");
		
	}
	*MoldyClient += RankPoint;
	MenuFolder *Sound = new MenuFolder("サウンド");
	{
		*Sound += new MenuEntry("効果音の速度を通常にする", SetTheSpeedOfSoundEffectsToNormal, "");
		*Sound += new MenuEntry("サウンドの速度2倍", DoubleTheSpeedOfSound, "");
		*Sound += new MenuEntry("BGM速度最大", MaximumBGMSpeed, "");
		*Sound += new MenuEntry("BGM速度アップ", BGMSpeedUp, "");
		*Sound += new MenuEntry("BGM速度通常", BGMSpeedNormal, "");
		
	}
	*MoldyClient += Sound;
	MenuFolder *UIAndCharacters = new MenuFolder("UIと文字");
	{
		*UIAndCharacters += new MenuEntry("UIのアニメーション速度を6倍", UIAnimationSpeed6Times, "");
		*UIAndCharacters += new MenuEntry("UIのサイズを通常にする", MakeUISizeNormal, "");
		*UIAndCharacters += new MenuEntry("UIのサイズをx0.9250倍", UISizeX09250Times, "");
		*UIAndCharacters += new MenuEntry("文字", Letter, "");
		
	}
	*MoldyClient += UIAndCharacters;
	MenuFolder *Other = new MenuFolder("そのほか");
	{
		*Other += new MenuEntry("カービィのサイズを小さく", KirbySizeSmaller, "");
		*Other += new MenuEntry("カービィのサイズを治す", CureKirbysSize, "");
		
	}
	*MoldyClient += Other;
	MenuFolder *UnlockerSlightCheat = new MenuFolder("アンロッカー(微チート)");
	{
		*UnlockerSlightCheat += new MenuEntry("全てのコレクションをアンロック", UnlockAllCollections, "");
		
	}
	*MoldyClient += UnlockerSlightCheat;
	
}
menu->Append(new MenuEntry("最初にこちらをお読みください", PleaseReadThisFirst, "Kavily Client VIP v0.1 カヴィリークライアントこちらはVIP版となります。CTRPFやActionReplayの扱いに慣れている方におすすめ致します慣れていない方は無印版をご利用くださいなおVIP版は限定公開ですので2次配布はおやめください"));
menu->Append(new MenuEntry("カヴィリーミニ", CavilyMini, "超安定していて、作者も最近このコードひとつでオン潜ってます！"));
MenuFolder *AuthorsFavoriteCode = new MenuFolder("作者が愛用しているコード");
{
	*AuthorsFavoriteCode += new MenuEntry("ランクポイント変更(8635)", RankPointChange8635, "");
	*AuthorsFavoriteCode += new MenuEntry("エフェクト軽減", EffectReduction, "");
	*AuthorsFavoriteCode += new MenuEntry("BGMの速度をあげる", IncreaseTheSpeedOfBGM, "");
	*AuthorsFavoriteCode += new MenuEntry("BGMを再生しない", DoNotPlayBGM, "");
	*AuthorsFavoriteCode += new MenuEntry("ネームプレートを自分に近づける", MakeTheNameplateCloserToYou, "");
	*AuthorsFavoriteCode += new MenuEntry("効果音の速度をあげる", IncreaseTheSpeedOfSoundEffects, "");
	*AuthorsFavoriteCode += new MenuEntry("効果音を消す(UIのみ)", TurnOffSoundEffectsUIOnly, "");
	*AuthorsFavoriteCode += new MenuEntry("UIのアニメーション速度をあげる(6倍)", IncreaseUIAnimationSpeed6x, "");
	*AuthorsFavoriteCode += new MenuEntry("カメラの視野:最大", CameraFieldOfViewMaximum, "");
	*AuthorsFavoriteCode += new MenuEntry("文字をほぼ非表示", AlmostHideCharacters, "");
	*AuthorsFavoriteCode += new MenuEntry("UIサイズを 0.9375倍に", UISizeIncreasedBy09375Times, "");
	*AuthorsFavoriteCode += new MenuEntry("UIサイズを戻す", ReturnUISize, "");
	
}
menu->Append(AuthorsFavoriteCode);
MenuFolder *MoldyClient = new MenuFolder("カビリークライアント");
{
	MenuFolder *Camera = new MenuFolder("カメラ");
	{
		*Camera += new MenuEntry("ズーム", Zoom, "");
		*Camera += new MenuEntry("カメラの視野:大", CameraFieldOfViewLarge, "");
		*Camera += new MenuEntry("カメラの視野:最大", CameraFieldOfViewMaximum, "");
		
	}
	*MoldyClient += Camera;
	MenuFolder *EffectsAndNameplates = new MenuFolder("エフェクトとネームプレート");
	{
		*EffectsAndNameplates += new MenuEntry("ネームプレートの場所を変える", ChangeTheLocationOfTheNameplate, "");
		*EffectsAndNameplates += new MenuEntry("エフェクト削除", DeleteEffect, "");
		*EffectsAndNameplates += new MenuEntry("エフェクト減少", EffectReduction, "");
		
	}
	*MoldyClient += EffectsAndNameplates;
	MenuFolder *RankPoint = new MenuFolder("ランクポイント");
	{
		MenuFolder *Random = new MenuFolder("ランダム");
		{
			*Random += new MenuEntry("(9639)", N9639, "");
			*Random += new MenuEntry("(6873)", N6873, "");
			*Random += new MenuEntry("(4892)", N4892, "");
			*Random += new MenuEntry("(2342)", N2342, "");
			*Random += new MenuEntry("(7202)", N7202, "");
			*Random += new MenuEntry("(129)", N129, "");
			*Random += new MenuEntry("(8635)", N8635, "");
			*Random += new MenuEntry("(3739)", N3739, "");
			*Random += new MenuEntry("(1530)", N1530, "");
			*Random += new MenuEntry("(5566)", N5566, "");
			
		}
		*RankPoint += Random;
		*RankPoint += new MenuEntry("(9999)", N9999, "");
		*RankPoint += new MenuEntry("(1)", N1, "");
		*RankPoint += new MenuEntry("(-1)", 1, "");
		
	}
	*MoldyClient += RankPoint;
	MenuFolder *Sound = new MenuFolder("サウンド");
	{
		*Sound += new MenuEntry("効果音の速度を通常にする", SetTheSpeedOfSoundEffectsToNormal, "");
		*Sound += new MenuEntry("サウンドの速度2倍", DoubleTheSpeedOfSound, "");
		*Sound += new MenuEntry("BGM速度最大", MaximumBGMSpeed, "");
		*Sound += new MenuEntry("BGM速度アップ", BGMSpeedUp, "");
		*Sound += new MenuEntry("BGM速度通常", BGMSpeedNormal, "");
		
	}
	*MoldyClient += Sound;
	MenuFolder *UIAndCharacters = new MenuFolder("UIと文字");
	{
		*UIAndCharacters += new MenuEntry("UIのアニメーション速度を6倍", UIAnimationSpeed6Times, "");
		*UIAndCharacters += new MenuEntry("UIのサイズを通常にする", MakeUISizeNormal, "");
		*UIAndCharacters += new MenuEntry("UIのサイズをx0.9250倍", UISizeX09250Times, "");
		*UIAndCharacters += new MenuEntry("文字", Letter, "");
		
	}
	*MoldyClient += UIAndCharacters;
	MenuFolder *Other = new MenuFolder("そのほか");
	{
		*Other += new MenuEntry("カービィのサイズを小さく", KirbySizeSmaller, "");
		*Other += new MenuEntry("カービィのサイズを治す", CureKirbysSize, "");
		
	}
	*MoldyClient += Other;
	MenuFolder *UnlockerSlightCheat = new MenuFolder("アンロッカー(微チート)");
	{
		*UnlockerSlightCheat += new MenuEntry("全てのコレクションをアンロック", UnlockAllCollections, "");
		
	}
	*MoldyClient += UnlockerSlightCheat;
	
}

menu->Append(MoldyClient);

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
