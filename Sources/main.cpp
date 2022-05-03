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
            new MenuEntry("カヴィリーマイクロ" + kStable, km, "カヴィリーの主な機能を詰め込んだもの");
           MenuFolder* Kavily = new MenuFolder("カヴィリー ver 0.1");
           {
            Kavily += new MenuEntry("FOV強化(安定化済)" + kStable, fov, "視野を広げられます");
            Kavily += new MenuEntry("エフェクト軽減" + kStable, eff, "エフェクトを軽減しオフラインでのラグを軽減することができます");
            Kavily += new MenuEntry("UIスピードアップ" + kStable, uspeed, "UIのスピードをあげて無駄な時間を少しはぶけます");
            Kavily += new MenuEntry("RP(-9999)" + kStable, rpff, "");
            Kavily += new MenuEntry("RP(ランダム)" + kStable, rprnd, "");
            Kavily += new MenuEntry("Amiiboスキン購入フラグ解放" + kStable, amib, "Amiiboスキンを購入可能にします、購入してからオンにすると購入前に戻ります");
            }
    }

    int     main(void)
    {
        PluginMenu *menu = new PluginMenu("Kavily", 6, 6, 6,
                                            "Kavily Client v0.1                              Made By Kou Kana");

       MessageBox("VIP! Luanch Success");

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
