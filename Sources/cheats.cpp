#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
  void KeyStrokesButtom(MenuEntry* entry) {
    const Screen &KSTSC = OSD::GetTopScreen();
    std::string IsK = "";
    u32 KSTX = 10;
    u32 KSTY = 50;
    Color foreground = Color::White;
    Color background = Color::Black;
    if(Controller::IsKeysDown(A)) {
      IsK += "A  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(B)) {
      IsK += "B  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(X)) {
      IsK += "X  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Y)) {
      IsK += "Y  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(R)) {
      IsK += "R  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(L)) {
      IsK += "L  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(ZR)) {
      IsK += "ZR  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(ZL)) {
      IsK += "ZL  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Start)) {
      IsK += "Start  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Select)) {
      IsK += "Select  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
  }
  void KeyStrokesPad(MenuEntry* entry) {
    if(Controller::IsKeysDown(CPadUp) || Controller::IsKeysDown(CPadDown) || Controller::IsKeysDown(CPadRight) || Controller::IsKeysDown(CPadLeft)) {
    const Screen &Pad = OSD::GetTopScreen();
    const Screen &Pat = OSD::GetTopScreen();
    u32 KSTX = 360;
    u32 KSTY = 5;
    Color foreground = Color::White;
    Color background = Color::Black;
    std::string Pad1 = "_";
    std::string Pad2 = "_ _ _";
    if(Controller::IsKeysDown(CPadUp)) {
      Pad1 = "X";
      if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ _ X";
      }
      if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X _ _";
      }
    }
    if(Controller::IsKeysDown(CPadDown)) {
      if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ X X";
      }else{
      if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X X _";
      }else{
        Pad2 = "_ X _";
      }
      }
    }else{
    if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ _ X";
      }
    if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X _ _";
      }
    }
  Pad.Draw(Pad1, KSTX+12, KSTY, foreground, background);
  Pat.Draw(Pad2, KSTX, KSTY+13, foreground, background);
  }
  }
  void KeyStrokesDPad(MenuEntry* entry) {
    if(Controller::IsKeysDown(DPadUp) || Controller::IsKeysDown(DPadDown) || Controller::IsKeysDown(DPadRight) || Controller::IsKeysDown(DPadLeft)) {
    const Screen &Pad = OSD::GetTopScreen();
    const Screen &Pat = OSD::GetTopScreen();
    u32 KSTX = 5;
    u32 KSTY = 210;
    Color foreground = Color::White;
    Color background = Color::Black;
    std::string Pad1 = "_";
    std::string Pad2 = "_ _ _";
    if(Controller::IsKeysDown(DPadUp)) {
      Pad1 = "X";
      if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ _ X";
      }
      if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X _ _";
      }
    }
    if(Controller::IsKeysDown(DPadDown)) {
      if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ X X";
      }else{
      if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X X _";
      }else{
        Pad2 = "_ X _";
      }
      }
    }else{
    if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ _ X";
      }
    if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X _ _";
      }
    }
  Pad.Draw(Pad1, KSTX+12, KSTY, foreground, background);
  Pat.Draw(Pad2, KSTX, KSTY+13, foreground, background);
  }
  }
}






