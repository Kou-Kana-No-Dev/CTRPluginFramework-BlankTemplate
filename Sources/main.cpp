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
		menu += new MenuEntry("~#b0c4de~設定バグらせる", SetBug, "");
		menu += new MenuEntry("~#b0c4de~プレイヤーのフリーズを治す", CurePlayerFreeze, "R+Lで実行");
		menu += new MenuEntry("~#b0c4de~Xコマンド", XCommand, "コマンドツール                       使えるコマンド                                                        nam:名前変更                    例:nam あ                    itm:アイテムをポーチの1番上に出現                     例:itm 0 0 0 A ←最後に空白この状態でY+→                     plhk:チャット乗っ取り                   例:plhkと入力し1度決定してからPlayer/:1");
MenuFolder *Player = new MenuFolder("~#ff0000~プレイヤー");
{
	*Player += new MenuEntry("~#ff0000~ハンターとにゃんたーを切り替え", SwitchBetweenHunterAndNyanta, "ハンター:→、にゃんたー:↑");
	*Player += new MenuEntry("~#ff0000~チャット乗っ取り", ChatHijacking, "XCMD以外にここからでもできます矢印キー");
	
}
menu += Player;
MenuFolder *WhatToBring = new MenuFolder("~#ffd700~持ち物");
{
	*WhatToBring += new MenuEntry("~#ffd700~龍歴院ポイント無限", RyujiinPointInfinite, "");
	*WhatToBring += new MenuEntry("~#ffd700~お金無限", MoneyInfinity, "");
	*WhatToBring += new MenuEntry("~#ffd700~ポーチを空にする", EmptyPouch, "");
	*WhatToBring += new MenuEntry("~#ffd700~バグアイテムセット", BugItemSet, "");
	*WhatToBring += new MenuEntry("~#ffd700~ポーチのアイテム無限", InfiniteItemsOnThePouch, "");
	*WhatToBring += new MenuEntry("~#ffd700~開発者お気に入りアイテムセット", DeveloperFavoriteItemSet, "");
	*WhatToBring += new MenuEntry("~#ffd700~マップいつでも表示", MapAlwaysDisplayed, "");
	*WhatToBring += new MenuEntry("~#ffd700~ピン開発者お気に入りセット", PinDeveloperFavoriteSet, "");
	
}
menu += WhatToBring;
MenuFolder *Mobile = new MenuFolder("~#4169e1~移動系");
{
	MenuFolder *CrazyMove = new MenuFolder("クレイジームーブ");
	{
		*CrazyMove += new MenuEntry("クレイジーウォーク(ボタン割り当てなし)", CrazyWalkNoButtonAssignment, "");
		*CrazyMove += new MenuEntry("クレイジージャンプ", CrazyJump, "Bを押している間発動");
		*CrazyMove += new MenuEntry("クレイジーウォーク(ボタンあり)", CrazyWalkWithButton, "R+Y");
		
	}
	*Mobile += CrazyMove;
	*Mobile += new MenuEntry("~#4169e1~バルスライド(バルファルク)", BalslideBalfalk, "ダッシュ中、スライドと速度上昇");
	*Mobile += new MenuEntry("~#4169e1~バルフライ(バルファルク:テスト段階)", BalflyBalfalkTestStage, "左右十字キーで方向転換                                   上下十字キーで高度変更                   Lでとぶ(低速)");
	*Mobile += new MenuEntry("~#4169e1~バルフライ v2(バルファルク)", BalflyV2Balfalk, "R+X:空中で停止                    A+R:高度上昇                                      R+L:高度低下                    R+Y:バルスライド              R+左右十字キー:向き変更                    R+B:バックバルスライド");
	*Mobile += new MenuEntry("~#4169e1~自動走行", AutomaticDriving, "走りながらR:走行キープ                      左右十字キー:向き変更                 L:停止");
	*Mobile += new MenuEntry("~#4169e1~ベースキャンプテレポート", BaseCampTeleport, "実行されない場合、1度しゃがむ");
	*Mobile += new MenuEntry("~#4169e1~ジャンプ", Jump, "Lで実行");
	*Mobile += new MenuEntry("~#4169e1~ムーンジャンプ", MoonJump, "Lで実行");
	*Mobile += new MenuEntry("~#4169e1~座標移動(遅め)", CoordinateMovementSlow, "R+スライドパッド");
	*Mobile += new MenuEntry("~#4169e1~座標移動(早め)", CoordinateMovementEarly, "R+スライドパッド");
	*Mobile += new MenuEntry("~#4169e1~スピードハックv2", SpeedHackV2, "");
	*Mobile += new MenuEntry("~#4169e1~スピードハックV2(遅め)", SpeedHackV2Slow, "");
	*Mobile += new MenuEntry("~#4169e1~スピードハックオフ", SpeedHackOff, "");
	MenuFolder *SpeedHackUnstableVersion = new MenuFolder("~#9932cc~スピードハック(不安定版)");
	{
		*SpeedHackUnstableVersion += new MenuEntry("~#9932cc~スピードハックテスト", SpeedHackTest, "");
		*SpeedHackUnstableVersion += new MenuEntry("~#9932cc~スピードハック", SpeedHack, "");
		*SpeedHackUnstableVersion += new MenuEntry("~#9932cc~スピードハック2", SpeedHack2, "");
		*SpeedHackUnstableVersion += new MenuEntry("~#9932cc~スローハック", SlowHack, "");
		*SpeedHackUnstableVersion += new MenuEntry("~#9932cc~スローハック2", SlowHack2, "");
		
	}
	*Mobile += SpeedHackUnstableVersion;
	
}
menu += Mobile;
MenuFolder *HR = new MenuFolder("~#008080~HR");
{
	*HR += new MenuEntry("~#008080~HR 721", HR721, "");
	*HR += new MenuEntry("~#008080~HR 810", HR810, "");
	*HR += new MenuEntry("~#008080~HR 8585", HR8585, "");
	*HR += new MenuEntry("~#008080~HR 4545", HR4545, "");
	*HR += new MenuEntry("~#008080~HR 1919", HR1919, "");
	*HR += new MenuEntry("~#008080~HR 999", HR999, "");
	*HR += new MenuEntry("~#008080~HR 4", HR4, "");
	*HR += new MenuEntry("~#008080~HR 65535", HR65535, "");
	*HR += new MenuEntry("~#008080~HR 1", HR1, "");
	*HR += new MenuEntry("~#008080~HR 0", HR0, "");
	
}
menu += HR;
MenuFolder *Quest = new MenuFolder("~#ff69b4~クエスト");
{
	*Quest += new MenuEntry("~#ff69b4~ボスHP1(オフライン専用)", BossHP1OfflineOnly, "");
	*Quest += new MenuEntry("~#ff69b4~クエスト貼ってなくても行ける(オフ)", YouCanGoWithoutPostingTheQuestOff, "");
	*Quest += new MenuEntry("~#ff69b4~クエスト貼ってなくても行ける", YouCanGoWithoutPostingTheQuest, "");
	*Quest += new MenuEntry("~#ff69b4~クエスト連続リクエスト", QuestContinuousRequest, "");
	*Quest += new MenuEntry("~#ff69b4~クエストリタイア", QuestRetirement, "");
	*Quest += new MenuEntry("~#ff69b4~ヘルジェイル", HellJail, "クエストから帰って来れなくなる");
	*Quest += new MenuEntry("~#ff69b4~タイマー0", Timer0, "");
	*Quest += new MenuEntry("~#ff69b4~タイマー増える", TimerIncreases, "");
	*Quest += new MenuEntry("~#ff69b4~タイマーコントローラー(早い)", TimerControllerFast, "");
	*Quest += new MenuEntry("~#ff69b4~タイマーコントローラー(普通)", TimerControllerNormal, "");
	*Quest += new MenuEntry("~#ff69b4~タイマーすぐ減る", TimerWillDecreaseSoon, "");
	
}
menu += Quest;
MenuFolder *Status = new MenuFolder("~#dc143c~ステータス");
{
	*Status += new MenuEntry("~#dc143c~スキルスロット埋める", FillSkillSlots, "→:1番上のスキル↑:真ん中のスキル←:1番下のスキル");
	*Status += new MenuEntry("~#dc143c~透明", Transparent, "");
	*Status += new MenuEntry("~#dc143c~攻撃力1", AttackPower1, "");
	*Status += new MenuEntry("~#dc143c~防御力1", Defense1, "");
	*Status += new MenuEntry("~#dc143c~防御力最高", HighestDefense, "");
	*Status += new MenuEntry("~#dc143c~攻撃力999", AttackPower999, "");
	*Status += new MenuEntry("~#dc143c~ボウガン連射", CrossbowFiring, "Aボタンで実行");
	*Status += new MenuEntry("~#dc143c~スタミナ置き換え回復", StaminaSuperFastRecovery, "");
	*Status += new MenuEntry("~#dc143c~HP置き換え回復", HPSuperFastRecovery, "");
	*Status += new MenuEntry("~#dc143c~太刀連射", TachiFiring, "Aで実行");
	*Status += new MenuEntry("~#dc143c~切れ味MAX", SharpnessMAX, "R+L");
	*Status += new MenuEntry("~#dc143c~乗りゲージ常にMAX", RidingGaugeAlwaysMAX, "");
	*Status += new MenuEntry("~#dc143c~HP0", HP0, "");
	
}
menu += Status;
MenuFolder *Camera = new MenuFolder("~#00ff7f~カメラ");
{
	*Camera += new MenuEntry("~#00ff7f~カメラ視野強化", CameraFieldOfViewEnhancement, "");
	*Camera += new MenuEntry("~#00ff7f~カメラ視野微強化", CameraFieldOfViewSlightlyEnhanced, "");
	*Camera += new MenuEntry("~#00ff7f~カメラハック1", CameraHack1, "R+L");
	*Camera += new MenuEntry("~#00ff7f~カメラハック", CameraHack, "");
	*Camera += new MenuEntry("~#00ff7f~エブリシングビュアー", EverythingViewer, "");
	*Camera += new MenuEntry("~#00ff7f~スーパーアイ", SuperEye, "");
	*Camera += new MenuEntry("~#00ff7f~FPS視点(V3)", FPSViewpointV3, "");
	*Camera += new MenuEntry("~#00ff7f~FPS視点(V2)", FPSViewpointV2, "");
	*Camera += new MenuEntry("~#00ff7f~FPS視点(V1)", FPSViewpointV1, "");
    *Camera += new MenuEntry("~#00ff7f~NPCの会話中カメラズームされない", CameraDoesNotZoomDuringNPCConversation, "ほぼ使い物にならなくて草");
}
menu += Camera;


			
    }

    int     main(void)
    {
        PluginMenu* menu = new PluginMenu("~#6495ed~Gen3z", 6,6,6,About);

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
