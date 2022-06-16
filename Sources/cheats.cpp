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
    Color foreground = Color::Orange;
    Color background = Color::Black;
    if(Controller::IsKeysDown(A)) {
      IsK += "A_";
    }
    if(Controller::IsKeysDown(B)) {
      IsK += "B_";
    }
    if(Controller::IsKeysDown(X)) {
      IsK += "X_";
    }
    if(Controller::IsKeysDown(Y)) {
      IsK += "Y_";
    }
    if(Controller::IsKeysDown(R)) {
      IsK += "R_";
    }
    if(Controller::IsKeysDown(L)) {
      IsK += "L_";
    }
    if(Controller::IsKeysDown(ZR)) {
      IsK += "ZR_";
    }
    if(Controller::IsKeysDown(ZL)) {
      IsK += "ZL_";
    }
    if(Controller::IsKeysDown(Start)) {
      IsK += "Start_";
    }
    if(Controller::IsKeysDown(Select)) {
      IsK += "Select_";
    }
    KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
  }
}






