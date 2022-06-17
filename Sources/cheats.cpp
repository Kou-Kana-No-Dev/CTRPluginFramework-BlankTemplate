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
    }
    if(Controller::IsKeysDown(B)) {
      IsK += "B  ";
    }
    if(Controller::IsKeysDown(X)) {
      IsK += "X  ";
    }
    if(Controller::IsKeysDown(Y)) {
      IsK += "Y  ";
    }
    if(Controller::IsKeysDown(R)) {
      IsK += "R  ";
    }
    if(Controller::IsKeysDown(L)) {
      IsK += "L  ";
    }
    if(Controller::IsKeysDown(ZR)) {
      IsK += "ZR  ";
    }
    if(Controller::IsKeysDown(ZL)) {
      IsK += "ZL  ";
    }
    if(Controller::IsKeysDown(Start)) {
      IsK += "Start  ";
    }
    if(Controller::IsKeysDown(Select)) {
      IsK += "Select  ";
    }
    KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
  }
  void KeyStrokesPad(MenuEntry* entry) {
    const Screen &Pad = OSD::GetTopScreen();
    const Screen &Pat = OSD::GetTopScreen();
    u32 KSTX = 355;
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






