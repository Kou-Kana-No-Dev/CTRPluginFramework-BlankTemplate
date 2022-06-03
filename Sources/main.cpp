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

const std::string Hunateiastus = "" << Color::Red << "";
const std::string mving = "" << Color::Blue << "";
const std::string dpa = "" << Color::DeepSkyBlue << "";
const std::string ski = "" << Color::SkyBlue << "";


		menu += new MenuEntry(Shyyy + "設定バグらせる", SetBug, "");
		menu += new MenuEntry(Shyyy + "プレイヤーのフリーズを治す" + Shyyy, CurePlayerFreeze, "R+Lで実行");
		menu += new MenuEntry(Shyyy + "Xコマンド" + Shyyy, XCommand, "コマンドツール\n使えるコマンド\nnam:名前変更:例:nam あ\nitm:アイテムをポーチの1番上に出現:\n例:itm 0 0 0 A ←最後に空白この状態でY+→\nplhk:チャット乗っ取り:\n例:plhkと入力し1度決定してからPlayer/:と表示されるので1や2と付け足し\nプレイヤーを選択して再度決定");
MenuFolder *Player = new MenuFolder(mving + "プレイヤー");
{
	*Player += new MenuEntry(Shyyy + "ハンターとにゃんたーを切り替え", SwitchBetweenHunterAndNyanta, "ハンター:→、にゃんたー:↑");
	*Player += new MenuEntry(Shyyy + "チャット乗っ取り", ChatHijacking, "XCMD以外にここからでもできます矢印キー");
	*Player += new MenuEntry(Shyyy + "メッセージ連投", MessageContinuousThrow, "Aで実行");
	*Player += new MenuEntry(Shyyy + "チャットでプレイヤーの名前が虹色になる", ThePlayersNameTurnsRainbowInChat, "");
	
}
menu += Player;
MenuFolder *WhatToBring = new MenuFolder(mving + "持ち物");
{
	*WhatToBring += new MenuEntry(Shyyy + "龍歴院ポイント無限", RyujiinPointInfinite, "");
	*WhatToBring += new MenuEntry(Shyyy + "お金無限", MoneyInfinity, "");
	*WhatToBring += new MenuEntry(Shyyy + "ポーチを空にする", EmptyPouch, "");
	*WhatToBring += new MenuEntry(Shyyy + "バグアイテムセット", BugItemSet, "");
	*WhatToBring += new MenuEntry(Shyyy + "ポーチのアイテム無限", InfiniteItemsOnThePouch, "");
	*WhatToBring += new MenuEntry(Shyyy + "開発者お気に入りアイテムセット", DeveloperFavoriteItemSet, "");
	*WhatToBring += new MenuEntry(Shyyy + "マップいつでも表示", MapAlwaysDisplayed, "");
	*WhatToBring += new MenuEntry(Shyyy + "ピン開発者お気に入りセット", PinDeveloperFavoriteSet, "");
	
}
menu += WhatToBring;
MenuFolder *Mobile = new MenuFolder(mving + "移動系");
{
	MenuFolder *CrazyMove = new MenuFolder(mving + "クレイジームーブ");
	{
		*CrazyMove += new MenuEntry(Shyyy + "クレイジーウォーク(ボタン割り当てなし)", CrazyWalkNoButtonAssignment, "");
		*CrazyMove += new MenuEntry(Shyyy + "クレイジージャンプ", CrazyJump, "Bを押している間発動");
		*CrazyMove += new MenuEntry(Shyyy + "クレイジーウォーク(ボタンあり)", CrazyWalkWithButton, "R+Y");
		
	}
	*Mobile += CrazyMove;
	*Mobile += new MenuEntry(Shyyy +  "バルスライド(バルファルク)", BalslideBalfalk, "ダッシュ中、スライドと速度上昇");
	*Mobile += new MenuEntry(Shyyy +  "バルフライ(バルファルク:テスト段階)", BalflyBalfalkTestStage, "左右十字キーで方向転換\n上下十字キーで高度変更\nLでとぶ(低速)");
	*Mobile += new MenuEntry(Shyyy +  "バルフライ v2(バルファルク)", BalflyV2Balfalk, "R+X:空中で停止\nA+R:高度上昇\nR+L:高度低下\nR+Y:バルスライド\nR+左右十字キー:向き変更\nR+B:バックバルスライド");
	*Mobile += new MenuEntry(Shyyy +  "自動走行", AutomaticDriving, "走りながらR:走行キープ\n左右十字キー:向き変更\nL:停止");
	*Mobile += new MenuEntry(Shyyy +  "ベースキャンプテレポート", BaseCampTeleport, "実行されない場合、1度しゃがむ");
	*Mobile += new MenuEntry(Shyyy + "ジャンプ", Jump, "Lで実行");
	*Mobile += new MenuEntry(Shyyy +  "ムーンジャンプ", MoonJump, "Lで実行");
	*Mobile += new MenuEntry(Shyyy +  "座標移動(遅め)", CoordinateMovementSlow, "R+スライドパッド");
	*Mobile += new MenuEntry(Shyyy +  "座標移動(早め)", CoordinateMovementEarly, "R+スライドパッド");
	*Mobile += new MenuEntry(Shyyy +  "スピードハックV2", SpeedHackV2, "");
	*Mobile += new MenuEntry(Shyyy +  "スピードハックV2(遅め)", SpeedHackV2Slow, "");
	*Mobile += new MenuEntry(Shyyy +  "スピードハックオフ", SpeedHackOff, "");
	*Mobile += new MenuEntry(Shyyy + "ハイパーダッシュ", HyperDash, "Rでダッシュ中、移動速度アップ\nバルスライドとの違いは、滑らず、\n純粋なスピードハックのような動きをすること");
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
MenuFolder *HR = new MenuFolder(mving + "HR");
{
	*HR += new MenuEntry(Shyyy + "HR 721", HR721, "");
	*HR += new MenuEntry(Shyyy + "HR 810", HR810, "");
	*HR += new MenuEntry(Shyyy + "HR 8585", HR8585, "");
	*HR += new MenuEntry(Shyyy + "HR 4545", HR4545, "");
	*HR += new MenuEntry(Shyyy + "HR 1919", HR1919, "");
	*HR += new MenuEntry(Shyyy + "HR 999", HR999, "");
	*HR += new MenuEntry(Shyyy + "HR 4", HR4, "");
	*HR += new MenuEntry(Shyyy + "HR 65535", HR65535, "");
	*HR += new MenuEntry(Shyyy + "HR 1", HR1, "");
	*HR += new MenuEntry(Shyyy + "HR 0", HR0, "");
	
}
menu += HR;
MenuFolder *Quest = new MenuFolder(mving + "クエスト");
{
	*Quest += new MenuEntry(Shyyy + "モンスターHP減らない", MonsterHPDoesNotDecrease, "");
	*Quest += new MenuEntry(Shyyy + "ボスHP1(オフライン専用)", BossHP1OfflineOnly, "");
	*Quest += new MenuEntry(Shyyy + "クエ受注してなくても行ける(強制的)", YouCanGoWithoutPostingTheQuest, "");
	*Quest += new MenuEntry(Shyyy + "クエ受注してなくても行けるオフ",YouCanGoWithoutPostingTheQuestOff, "");
	*Quest += new MenuEntry(Shyyy + "全員クエストリタイア", QuestRetirement, "");
	*Quest += new MenuEntry(Shyyy + "ヘルジェイル", HellJail, "L+→\nクエストから帰って来れなくなる");
	*Quest += new MenuEntry(Shyyy + "タイマー0", Timer0, "");
	*Quest += new MenuEntry(Shyyy + "タイマー増える", TimerIncreases, "");
	*Quest += new MenuEntry(Shyyy + "タイマーコントローラー(早い)", TimerControllerFast, "");
	*Quest += new MenuEntry(Shyyy + "タイマーコントローラー(普通)", TimerControllerNormal, "");
	*Quest += new MenuEntry(Shyyy + "タイマーすぐ減る", TimerWillDecreaseSoon, "");
	
}
menu += Quest;
MenuFolder *Status = new MenuFolder(mving + "ステータス");
{
   MenuFolder *zksi = new MenuFolder(mving + "属性変更");
    {
        *zksi += new MenuEntry(Shyyy + "火属性", FireAttribute, "");
        *zksi += new MenuEntry(Shyyy + "水属性", WaterAttribute, "");
        *zksi += new MenuEntry(Shyyy + "雷属性", LightningAttribute, "");
        *zksi += new MenuEntry(Shyyy + "龍属性", DragonAttribute, "");
        *zksi += new MenuEntry(Shyyy + "氷属性", IceAttribute, "");
        *zksi += new MenuEntry(Shyyy + "毒属性", PoisonAttribute, "");
        *zksi += new MenuEntry(Shyyy + "麻痺属性", ParalysisAttribute, "");
        *zksi += new MenuEntry(Shyyy + "睡眠属性", SleepAttribute, "");
        *zksi += new MenuEntry(Shyyy + "爆破属性", BombingAttribute, "");
        *zksi += new MenuEntry(Shyyy + "バグ属性", BugAttribute, "");
        *zksi += new MenuEntry(Shyyy + "バグ属性2", BugAttribute2, "");
        *zksi += new MenuEntry(Shyyy + "全属性", AllAttributes, "");
}
    *Status += zksi;
    *Status += new MenuEntry(Shyyy + "ファストイート", FastEat, "肉、笛、調合薬などを速く使用できます");
	*Status += new MenuEntry(Shyyy + "スキルスロット埋める", FillSkillSlots, "→:1番上のスキル↑:真ん中のスキル←:1番下のスキル");
	*Status += new MenuEntry(Shyyy + "透明", Transparent, "テスト段階、使用不可");
	*Status += new MenuEntry(Shyyy + "攻撃力1", AttackPower1, "");
	*Status += new MenuEntry(Shyyy + "防御力1", Defense1, "");
	*Status += new MenuEntry(Shyyy + "防御力最高", HighestDefense, "");
	*Status += new MenuEntry(Shyyy + "攻撃力最高", AttackPower999, "");
	*Status += new MenuEntry(Shyyy + "属性最高", TheStrongestAttributeValue, "");
	*Status += new MenuEntry(Shyyy + "ボウガン連射", CrossbowFiring, "Aボタンで実行");
	*Status += new MenuEntry(Shyyy + "スタミナ置き換え回復", StaminaSuperFastRecovery, "");
	*Status += new MenuEntry(Shyyy + "HP置き換え回復", HPSuperFastRecovery, "");
	*Status += new MenuEntry(Shyyy + "太刀連射 Ver2", TachiFireVer2, "Aで連射/A+Rでローリング");
	*Status += new MenuEntry(Shyyy + "太刀連射", TachiFiring, "Aで実行");
	*Status += new MenuEntry(Shyyy + "切れ味MAX", SharpnessMAX, "R+L");
	*Status += new MenuEntry(Shyyy + "乗りゲージ常にMAX", RidingGaugeAlwaysMAX, "");
	*Status += new MenuEntry(Shyyy + "HP0", HP0, "");

	*Status +=new MenuEntry(Shyyy +"エリアル用壁抜け", WallThroughForErial, "");
	*Status +=new MenuEntry(Shyyy +"壁抜け", WallThrough, "");
}
menu += Status;
MenuFolder *Camera = new MenuFolder(mving + "カメラ");
{
	*Camera += new MenuEntry(Shyyy + "ズーム", Zoom, "Rで実行");
	*Camera += new MenuEntry(Shyyy + "カメラ視野強化", CameraFieldOfViewEnhancement, "");
	*Camera += new MenuEntry(Shyyy + "カメラ視野微強化", CameraFieldOfViewSlightlyEnhanced, "");
	*Camera += new MenuEntry(Shyyy + "カメラハック1", CameraHack1, "R+L");
	*Camera += new MenuEntry(Shyyy + "カメラハック", CameraHack, "");
	*Camera += new MenuEntry(Shyyy + "エブリシングビュアー", EverythingViewer, "");
	*Camera += new MenuEntry(Shyyy + "スーパーアイ", SuperEye, "");
	*Camera += new MenuEntry(Shyyy + "FPS視点(V3)", FPSViewpointV3, "");
	*Camera += new MenuEntry(Shyyy + "FPS視点(V2)", FPSViewpointV2, "");
	*Camera += new MenuEntry(Shyyy + "FPS視点(V1)", FPSViewpointV1, "");
    *Camera += new MenuEntry(Shyyy + "NPCの会話中カメラズームされない", CameraDoesNotZoomDuringNPCConversation, "ほぼ使い物にならなくて草");
}
menu += Camera;
MenuFolder *Danger = new MenuFolder(Hunateiastus + "危険なコード");
{
         *Danger += new MenuEntry(Hunateiastus + "ゲームをクラッシュさせる", CrashTheGame, "");
}
menu += Danger;
MenuFolder *VIPMode = new MenuFolder( dpa + "VIPモード");
{
	MenuFolder *CrashDisabledCode = new MenuFolder( dpa + "クラッシュ無効化したコード");
	{
		MenuFolder *SpeedHacksInstabilityImprovedVersion = new MenuFolder( dpa + "スピードハックス(不安定改良版)");
		{
			*SpeedHacksInstabilityImprovedVersion += new MenuEntry(ski + "スピードハック x2", SpeedHackX2, "Rで速度変更");
			*SpeedHacksInstabilityImprovedVersion += new MenuEntry(ski + "スピードハック", SpeedHacksss, "Rで速度変更");
			*SpeedHacksInstabilityImprovedVersion += new MenuEntry(ski + "スローハック", SlowHacksss, "Rで速度変更");
			*SpeedHacksInstabilityImprovedVersion += new MenuEntry(ski + "スローハック x2", SlowHackX2, "Rで速度変更");
			
		}
		*CrashDisabledCode += SpeedHacksInstabilityImprovedVersion;
		*CrashDisabledCode += new MenuEntry(ski + "ボマー V2", BomberVv2, "AとRで実行\n使用のための条件を克服");
		*CrashDisabledCode += new MenuEntry(ski + "太刀連射 V2", TachiFireV2, "");
		*CrashDisabledCode += new MenuEntry(ski + "ビーホップ", BeeHoop, "L+左右矢印でオンオフ\nスライドパッドで移動");
		*CrashDisabledCode += new MenuEntry(ski + "ボマー", Bommeru, "使用する際にタル爆弾を置く必要がある\nA+R");
		*CrashDisabledCode += new MenuEntry(ski + "支給品ボックスアイテム盗む", StealingSuppliesBoxIteems, "支給品ボックスを開いてL+A\nポーチの中身が消えるので注意");
		*CrashDisabledCode += new MenuEntry(ski + "支給品ボックスを高速で取れる", Sussybaka, "支給品ボックスのアイテム移動モーションの制限解除");
		
	}
	*VIPMode += CrashDisabledCode;
	*VIPMode += new MenuEntry(ski + "支給品ボックスアイテム盗む", StealingSuppliesBoxItems, "支給品ボックスを開いてL+A\nポーチの中身が消えるので注意");
	*VIPMode += new MenuEntry(ski + "空中でのプレイヤーのフリーズを対策", CountermeasuresAgainstPlayerFreezesInTheAir, "");
	*VIPMode += new MenuEntry(ski + "基本的な攻撃で吹き飛ばない", DoesntBlowOffWithABasicAttack, "");
	*VIPMode += new MenuEntry(ski + "ネオンオーラ(バージョン2)", NeonAuraVersion2, "→で実行");
	*VIPMode += new MenuEntry(ski + "ネオンオーラ", NeonAura, "→で実行");
	*VIPMode += new MenuEntry(ski + "ビーホップ", BeeHop, "L+左右矢印でオンオフ\nスライドパッドで移動");
	*VIPMode += new MenuEntry(ski + "プレイヤームーブ式座標移動", PlayerMoveTypeCoordinateMovement, "スライドパッドで移動");
	*VIPMode += new MenuEntry(ski + "ボマー V2", BomberV2, "AとRで実行\n使用のための条件を克服");
	*VIPMode += new MenuEntry(ski + "ボマー", Bommer, "使用する際にタル爆弾を置く必要がある\nA+R");
}
menu += VIPMode;

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
