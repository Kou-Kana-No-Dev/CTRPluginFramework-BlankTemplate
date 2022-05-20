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
		menu += new MenuEntry("設定バグらせる", SetBug, "");
		menu += new MenuEntry("プレイヤーのフリーズを治す", CurePlayerFreeze, "R+Lで実行");
		menu += new MenuEntry("Xコマンド", XCommand, "コマンドツール                       使えるコマンド                                                        nam:名前変更                    例:nam あ                    itm:アイテムをポーチの1番上に出現                     例:itm 0 0 0 A ←最後に空白この状態でY+→                     plhk:チャット乗っ取り                   例:plhkと入力し1度決定してからPlayer/:1");
MenuFolder *Player = new MenuFolder("プレイヤー");
{
	*Player += new MenuEntry("ハンターとにゃんたーを切り替え", SwitchBetweenHunterAndNyanta, "ハンター:→、にゃんたー:↑");
	*Player += new MenuEntry("チャット乗っ取り", ChatHijacking, "XCMD以外にここからでもできます矢印キー");
	
}
menu += Player;
MenuFolder *WhatToBring = new MenuFolder("持ち物");
{
	*WhatToBring += new MenuEntry("龍歴院ポイント無限", RyujiinPointInfinite, "");
	*WhatToBring += new MenuEntry("お金無限", MoneyInfinity, "");
	*WhatToBring += new MenuEntry("ポーチを空にする", EmptyPouch, "");
	*WhatToBring += new MenuEntry("バグアイテムセット", BugItemSet, "");
	*WhatToBring += new MenuEntry("ポーチのアイテム無限", InfiniteItemsOnThePouch, "");
	*WhatToBring += new MenuEntry("開発者お気に入りアイテムセット", DeveloperFavoriteItemSet, "");
	*WhatToBring += new MenuEntry("マップいつでも表示", MapAlwaysDisplayed, "");
	*WhatToBring += new MenuEntry("ピン開発者お気に入りセット", PinDeveloperFavoriteSet, "");
	
}
menu += WhatToBring;
MenuFolder *Mobile = new MenuFolder("移動系");
{
	MenuFolder *CrazyMove = new MenuFolder("クレイジームーブ");
	{
		*CrazyMove += new MenuEntry("クレイジーウォーク(ボタン割り当てなし)", CrazyWalkNoButtonAssignment, "");
		*CrazyMove += new MenuEntry("クレイジージャンプ", CrazyJump, "Bを押している間発動");
		*CrazyMove += new MenuEntry("クレイジーウォーク(ボタンあり)", CrazyWalkWithButton, "R+Y");
		
	}
	*Mobile += CrazyMove;
	*Mobile += new MenuEntry("バルスライド(バルファルク)", BalslideBalfalk, "ダッシュ中、スライドと速度上昇");
	*Mobile += new MenuEntry("バルフライ(バルファルク:テスト段階)", BalflyBalfalkTestStage, "左右十字キーで方向転換上下十字キーで高度変更Lでとぶ(低速)");
	*Mobile += new MenuEntry("バルフライ v2(バルファルク)", BalflyV2Balfalk, "R+X:空中で停止A+R:高度上昇R+L:高度低下R+Y:バルスライドR+左右十字キー:向き変更R+B:バックバルスライド");
	*Mobile += new MenuEntry("自動走行", AutomaticDriving, "走りながらR:走行キープ左右十字キー:向き変更L:停止");
	*Mobile += new MenuEntry("ベースキャンプテレポート", BaseCampTeleport, "実行されない場合、1度しゃがむ");
	*Mobile += new MenuEntry("ジャンプ", Jump, "Lで実行");
	*Mobile += new MenuEntry("ムーンジャンプ", MoonJump, "Lで実行");
	*Mobile += new MenuEntry("NPCの会話中カメラズームされない", CameraDoesNotZoomDuringNPCConversation, "ほぼ使い物にならなくて草");
	*Mobile += new MenuEntry("座標移動(遅め)", CoordinateMovementSlow, "R+スライドパッド");
	*Mobile += new MenuEntry("座標移動(早め)", CoordinateMovementEarly, "R+スライドパッド");
	*Mobile += new MenuEntry("スピードハックv2", SpeedHackV2, "");
	*Mobile += new MenuEntry("スピードハックV2(遅め)", SpeedHackV2Slow, "");
	*Mobile += new MenuEntry("スピードハックオフ", SpeedHackOff, "");
	MenuFolder *SpeedHackUnstableVersion = new MenuFolder("スピードハック(不安定版)");
	{
		*SpeedHackUnstableVersion += new MenuEntry("スピードハックテスト", SpeedHackTest, "");
		*SpeedHackUnstableVersion += new MenuEntry("スピードハック", SpeedHack, "");
		*SpeedHackUnstableVersion += new MenuEntry("スピードハック2", SpeedHack2, "");
		*SpeedHackUnstableVersion += new MenuEntry("スローハック", SlowHack, "");
		*SpeedHackUnstableVersion += new MenuEntry("スローハック2", SlowHack2, "");
		
	}
	*Mobile += SpeedHackUnstableVersion;
	
}
menu += Mobile;
MenuFolder *HR = new MenuFolder("HR");
{
	*HR += new MenuEntry("HR 721", HR721, "");
	*HR += new MenuEntry("HR 810", HR810, "");
	*HR += new MenuEntry("HR 8585", HR8585, "");
	*HR += new MenuEntry("HR 4545", HR4545, "");
	*HR += new MenuEntry("HR 1919", HR1919, "");
	*HR += new MenuEntry("HR 999", HR999, "");
	*HR += new MenuEntry("HR 4", HR4, "");
	*HR += new MenuEntry("HR 65535", HR65535, "");
	*HR += new MenuEntry("HR 1", HR1, "");
	*HR += new MenuEntry("HR 0", HR0, "");
	
}
menu += HR;
MenuFolder *Quest = new MenuFolder("クエスト");
{
	*Quest += new MenuEntry("ボスHP1(オフライン専用)", BossHP1OfflineOnly, "");
	*Quest += new MenuEntry("クエスト貼ってなくても行ける(オフ)", YouCanGoWithoutPostingTheQuestOff, "");
	*Quest += new MenuEntry("クエスト貼ってなくても行ける", YouCanGoWithoutPostingTheQuest, "");
	*Quest += new MenuEntry("クエスト連続リクエスト", QuestContinuousRequest, "");
	*Quest += new MenuEntry("クエストリタイア", QuestRetirement, "");
	*Quest += new MenuEntry("ヘルジェイル", HellJail, "クエストから帰って来れなくなる");
	*Quest += new MenuEntry("タイマー0", Timer0, "");
	*Quest += new MenuEntry("タイマー増える", TimerIncreases, "");
	*Quest += new MenuEntry("タイマーコントローラー(早い)", TimerControllerFast, "");
	*Quest += new MenuEntry("タイマーコントローラー(普通)", TimerControllerNormal, "");
	*Quest += new MenuEntry("タイマーすぐ減る", TimerWillDecreaseSoon, "");
	
}
menu += Quest;
MenuFolder *Status = new MenuFolder("ステータス");
{
	*Status += new MenuEntry("スキルスロット埋める", FillSkillSlots, "→:1番上のスキル↑:真ん中のスキル←:1番下のスキル");
	*Status += new MenuEntry("透明", Transparent, "");
	*Status += new MenuEntry("攻撃力1", AttackPower1, "");
	*Status += new MenuEntry("防御力1", Defense1, "");
	*Status += new MenuEntry("防御力最高", HighestDefense, "");
	*Status += new MenuEntry("攻撃力999", AttackPower999, "");
	*Status += new MenuEntry("ボウガン連射", CrossbowFiring, "Aボタンで実行");
	*Status += new MenuEntry("スタミナ置き換え回復", StaminaSuperFastRecovery, "");
	*Status += new MenuEntry("HP置き換え回復", HPSuperFastRecovery, "");
	*Status += new MenuEntry("太刀連射", TachiFiring, "Aで実行");
	*Status += new MenuEntry("切れ味MAX", SharpnessMAX, "R+L");
	*Status += new MenuEntry("乗りゲージ常にMAX", RidingGaugeAlwaysMAX, "");
	*Status += new MenuEntry("HP0", HP0, "");
	
}
menu += Status;
MenuFolder *Camera = new MenuFolder("カメラ");
{
	*Camera += new MenuEntry("カメラ視野強化", CameraFieldOfViewEnhancement, "");
	*Camera += new MenuEntry("カメラ視野微強化", CameraFieldOfViewSlightlyEnhanced, "");
	*Camera += new MenuEntry("カメラハック1", CameraHack1, "R+L");
	*Camera += new MenuEntry("カメラハック", CameraHack, "");
	*Camera += new MenuEntry("エブリシングビュアー", EverythingViewer, "");
	*Camera += new MenuEntry("スーパーアイ", SuperEye, "");
	*Camera += new MenuEntry("FPS視点(V3)", FPSViewpointV3, "");
	*Camera += new MenuEntry("FPS視点(V2)", FPSViewpointV2, "");
	*Camera += new MenuEntry("FPS視点(V1)", FPSViewpointV1, "");
	
}
menu += Camera;


			
    }

    int     main(void)
    {
        PluginMenu* menu = new PluginMenu("Gen3z", 6,6,6,About);

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
