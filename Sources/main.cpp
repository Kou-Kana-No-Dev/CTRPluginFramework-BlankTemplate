#include "3ds.h"
#include "csvc.h"
#include "CTRPluginFramework.hpp"
#include "cheats.hpp"
#include <vector>

namespace CTRPluginFramework
{
	//aboutの部分
	static const std::string About ="Made By Kou Kana                                      Discord:Kou Kana#7262";
	
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
const std::string Shyyy = "" << Color::Cyan << "";
const std::string nimotsu = "" << Color::Green << "";
const std::string Hunateiastus = "" << Color::Red << "";
const std::string mving = "" << Color::Blue << "";
const std::string Inv = "" << Color::Yellow << "";
const std::string HRS = "" << Color::Orange << "";
		menu += new MenuEntry(Shyyy + "設定バグらせる", SetBug, "");
		menu += new MenuEntry(Shyyy + "プレイヤーのフリーズを治す" + Shyyy, CurePlayerFreeze, "R+Lで実行");
		menu += new MenuEntry(Shyyy + "Xコマンド" + Shyyy, XCommand, "コマンドツール                       使えるコマンド                                                        nam:名前変更                    例:nam あ                    itm:アイテムをポーチの1番上に出現                     例:itm 0 0 0 A ←最後に空白この状態でY+→                     plhk:チャット乗っ取り                   例:plhkと入力し1度決定してからPlayer/:1");
MenuFolder *Player = new MenuFolder( Hunateiastus + "プレイヤー");
{
	*Player += new MenuEntry(Hunateiastus + "ハンターとにゃんたーを切り替え", SwitchBetweenHunterAndNyanta, "ハンター:→、にゃんたー:↑");
	*Player += new MenuEntry(Hunateiastus + "チャット乗っ取り", ChatHijacking, "XCMD以外にここからでもできます矢印キー");
	
}
menu += Player;
MenuFolder *WhatToBring = new MenuFolder(Inv + "持ち物");
{
	*WhatToBring += new MenuEntry(Inv + "龍歴院ポイント無限", RyujiinPointInfinite, "");
	*WhatToBring += new MenuEntry(Inv + "お金無限"+ Inv, MoneyInfinity, "");
	*WhatToBring += new MenuEntry(Inv + "ポーチを空にする"+ Inv, EmptyPouch, "");
	*WhatToBring += new MenuEntry(Inv + "バグアイテムセット"+ Inv, BugItemSet, "");
	*WhatToBring += new MenuEntry(Inv + "ポーチのアイテム無限"+ Inv, InfiniteItemsOnThePouch, "");
	*WhatToBring += new MenuEntry(Inv + "開発者お気に入りアイテムセット"+ Inv, DeveloperFavoriteItemSet, "");
	*WhatToBring += new MenuEntry(Inv + "マップいつでも表示"+ Inv, MapAlwaysDisplayed, "");
	*WhatToBring += new MenuEntry(Inv + "ピン開発者お気に入りセット" + Inv, PinDeveloperFavoriteSet, "");
	
}
menu += WhatToBring;
MenuFolder *Mobile = new MenuFolder(mving + "移動系");
{
	MenuFolder *CrazyMove = new MenuFolder(HRS + "クレイジームーブ");
	{
		*CrazyMove += new MenuEntry(HRS + "クレイジーウォーク(ボタン割り当てなし)", CrazyWalkNoButtonAssignment, "");
		*CrazyMove += new MenuEntry(HRS + "クレイジージャンプ", CrazyJump, "Bを押している間発動");
		*CrazyMove += new MenuEntry(HRS + "クレイジーウォーク(ボタンあり)", CrazyWalkWithButton, "R+Y");
		
	}
	*Mobile += CrazyMove;
	*Mobile += new MenuEntry(mving + "バルスライド(バルファルク)", BalslideBalfalk, "ダッシュ中、スライドと速度上昇");
	*Mobile += new MenuEntry(mving + "バルフライ(バルファルク:テスト段階)", BalflyBalfalkTestStage, "左右十字キーで方向転換                                   上下十字キーで高度変更                   Lでとぶ(低速)");
	*Mobile += new MenuEntry(mving + "バルフライ v2(バルファルク)", BalflyV2Balfalk, "R+X:空中で停止                    A+R:高度上昇                                      R+L:高度低下                    R+Y:バルスライド              R+左右十字キー:向き変更                    R+B:バックバルスライド");
	*Mobile += new MenuEntry(mving + "自動走行", AutomaticDriving, "走りながらR:走行キープ                      左右十字キー:向き変更                 L:停止");
	*Mobile += new MenuEntry(mving + "ベースキャンプテレポート", BaseCampTeleport, "実行されない場合、1度しゃがむ");
	*Mobile += new MenuEntry(mving + "ジャンプ", Jump, "Lで実行");
	*Mobile += new MenuEntry(mving + "ムーンジャンプ", MoonJump, "Lで実行");
	*Mobile += new MenuEntry(mving + "座標移動(遅め)", CoordinateMovementSlow, "R+スライドパッド");
	*Mobile += new MenuEntry(mving + "座標移動(早め)", CoordinateMovementEarly, "R+スライドパッド");
	*Mobile += new MenuEntry(mving + "スピードハックV2", SpeedHackV2, "");
	*Mobile += new MenuEntry(mving + "スピードハックV2(遅め)", SpeedHackV2Slow, "");
	*Mobile += new MenuEntry(mving + "スピードハックオフ", SpeedHackOff, "");
	MenuFolder *SpeedHackUnstableVersion = new MenuFolder(Hunateiastus + "スピードハック(不安定版)");
	{
		*SpeedHackUnstableVersion += new MenuEntry(Hunateiastus + "スピードハックテスト", SpeedHackTest, "");
		*SpeedHackUnstableVersion += new MenuEntry(Hunateiastus + "スピードハック", SpeedHack, "");
		*SpeedHackUnstableVersion += new MenuEntry(Hunateiastus + "スピードハック2", SpeedHack2, "");
		*SpeedHackUnstableVersion += new MenuEntry(Hunateiastus + "スローハック", SlowHack, "");
		*SpeedHackUnstableVersion += new MenuEntry(Hunateiastus + "スローハック2", SlowHack2, "");
		
	}
	*Mobile += SpeedHackUnstableVersion;
	
}
menu += Mobile;
MenuFolder *HR = new MenuFolder(HRS + "HR");
{
	*HR += new MenuEntry(HRS + "HR 721", HR721, "");
	*HR += new MenuEntry(HRS + "HR 810", HR810, "");
	*HR += new MenuEntry(HRS + "HR 8585", HR8585, "");
	*HR += new MenuEntry(HRS + "HR 4545", HR4545, "");
	*HR += new MenuEntry(HRS + "HR 1919", HR1919, "");
	*HR += new MenuEntry(HRS + "HR 999", HR999, "");
	*HR += new MenuEntry(HRS + "HR 4", HR4, "");
	*HR += new MenuEntry(HRS + "HR 65535", HR65535, "");
	*HR += new MenuEntry(HRS + "HR 1", HR1, "");
	*HR += new MenuEntry(HRS + "HR 0", HR0, "");
	
}
menu += HR;
MenuFolder *Quest = new MenuFolder(nimotsu + "クエスト");
{
	*Quest += new MenuEntry(nimotsu + "ボスHP1(オフライン専用)", BossHP1OfflineOnly, "");
	*Quest += new MenuEntry(nimotsu + "クエスト貼ってなくても行ける(オフ)", YouCanGoWithoutPostingTheQuestOff, "");
	*Quest += new MenuEntry(nimotsu + "クエスト貼ってなくても行ける", YouCanGoWithoutPostingTheQuest, "");
	*Quest += new MenuEntry(nimotsu + "クエスト連続リクエスト", QuestContinuousRequest, "");
	*Quest += new MenuEntry(nimotsu + "全員クエストリタイア", QuestRetirement, "");
	*Quest += new MenuEntry(nimotsu + "ヘルジェイル", HellJail, "クエストから帰って来れなくなる");
	*Quest += new MenuEntry(nimotsu + "タイマー0", Timer0, "");
	*Quest += new MenuEntry(nimotsu + "タイマー増える", TimerIncreases, "");
	*Quest += new MenuEntry(nimotsu + "タイマーコントローラー(早い)", TimerControllerFast, "");
	*Quest += new MenuEntry(nimotsu + "タイマーコントローラー(普通)", TimerControllerNormal, "");
	*Quest += new MenuEntry(nimotsu + "タイマーすぐ減る", TimerWillDecreaseSoon, "");
	
}
menu += Quest;
MenuFolder *Status = new MenuFolder(Hunateiastus + "ステータス");
{
	*Status += new MenuEntry(Hunateiastus + "スキルスロット埋める", FillSkillSlots, "→:1番上のスキル↑:真ん中のスキル←:1番下のスキル");
	*Status += new MenuEntry(Hunateiastus + "透明", Transparent, "テスト段階、使用不可");
	*Status += new MenuEntry(Hunateiastus + "攻撃力1", AttackPower1, "");
	*Status += new MenuEntry(Hunateiastus + "防御力1", Defense1, "");
	*Status += new MenuEntry(Hunateiastus + "防御力最高", HighestDefense, "");
	*Status += new MenuEntry(Hunateiastus + "攻撃力999", AttackPower999, "");
	*Status += new MenuEntry(Hunateiastus + "ボウガン連射", CrossbowFiring, "Aボタンで実行");
	*Status += new MenuEntry(Hunateiastus + "スタミナ置き換え回復", StaminaSuperFastRecovery, "");
	*Status += new MenuEntry(Hunateiastus + "HP置き換え回復", HPSuperFastRecovery, "");
	*Status += new MenuEntry(Hunateiastus + "太刀連射", TachiFiring, "Aで実行");
	*Status += new MenuEntry(Hunateiastus + "切れ味MAX", SharpnessMAX, "R+L");
	*Status += new MenuEntry(Hunateiastus + "乗りゲージ常にMAX", RidingGaugeAlwaysMAX, "");
	*Status += new MenuEntry(Hunateiastus + "HP0", HP0, "");
	
}
menu += Status;
MenuFolder *Camera = new MenuFolder(nimotsu + "カメラ");
{
	*Camera += new MenuEntry(nimotsu + "カメラ視野強化", CameraFieldOfViewEnhancement, "");
	*Camera += new MenuEntry(nimotsu + "カメラ視野微強化", CameraFieldOfViewSlightlyEnhanced, "");
	*Camera += new MenuEntry(nimotsu + "カメラハック1", CameraHack1, "R+L");
	*Camera += new MenuEntry(nimotsu + "カメラハック", CameraHack, "");
	*Camera += new MenuEntry(nimotsu + "エブリシングビュアー", EverythingViewer, "");
	*Camera += new MenuEntry(nimotsu + "スーパーアイ", SuperEye, "");
	*Camera += new MenuEntry(nimotsu + "FPS視点(V3)", FPSViewpointV3, "");
	*Camera += new MenuEntry(nimotsu + "FPS視点(V2)", FPSViewpointV2, "");
	*Camera += new MenuEntry(nimotsu + "FPS視点(V1)", FPSViewpointV1, "");
    *Camera += new MenuEntry(nimotsu + "NPCの会話中カメラズームされない", CameraDoesNotZoomDuringNPCConversation, "ほぼ使い物にならなくて草");
}
menu += Camera;


			
    }

    int     main(void)
    {
        PluginMenu* menu = new PluginMenu(Color::Cyan << "Gen3z", 6,6,6,About);

        // Synnchronize the menu with frame event
        menu->SynchronizeWithFrame(true);
        menu->ShowWelcomeMessage(false);
		OSD::Notify(Color::Cyan << "Luanch Success");
		
        // Init our menu entries & folders
        InitMenu(*menu);

        // Launch menu and mainloop
        menu->Run();

        delete menu;

        // Exit plugin
		return (0);
    }
}
