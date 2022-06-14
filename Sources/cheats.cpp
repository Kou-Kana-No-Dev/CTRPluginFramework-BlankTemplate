#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
void keykeysokesb(MenuEntry* entry){
  const Screen &top_screen = OSD::GetTopScreen();
  u32 x = 5;
  u32 y = 200;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  std::string keys;
  if(Controller::IsKeysDown(A)) {
    keys += "A  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(B)) {
    keys += "B  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(X)) {
    keys += "X  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(Y)) {
    keys += "Y  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(R)) {
    keys += "R  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(L)) {
    keys += "L  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(ZR)) {
    keys += "ZR  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(ZL)) {
    keys += "ZL  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(Start)) {
    keys += "Start  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
  if(Controller::IsKeysDown(Select)) {
    keys += "Select  ";
    top_screen.Draw(keys, x, y, foreground, background);
  }
}
void keykeysokesp(MenuEntry* entry) {
  const Screen &topkeyp = OSD::GetTopScreen();
  const Screen &topkeyp2 = OSD::GetTopScreen();
  u32 x2 = 350;
  u32 y2 = 5;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  std::string pad;
  std::string pad2;
  pad = "_";
  pad2 = "_ _ _";
  u8 Disdown;
  if(Controller::IsKeysDown(CPadUp)) {
    pad = "X";
    if(Controller::IsKeysDown(CPadRight)) {
      pad2 = "_ _ X"; 
    }else{
    if(Controller::IsKeysDown(CPadLeft)) {
      pad2 = "X _ _";
    }
    }
  }else{
  if(Controller::IsKeysDown(CPadDown)) {
    if(Controller::IsKeysDown(CPadRight)) {
      pad2 = "_ X X"; 
    }else{
    if(Controller::IsKeysDown(CPadLeft)) {
      pad2 = "X X _";
    }else{
    pad2 = "_ X _";
    }
    }
  }else{
    if(Controller::IsKeysDown(CPadLeft)) {
      pad2 = "X _ _";
    }else{
     if(Controller::IsKeysDown(CPadRight)) {
       pad2 = "_ _ X";
     }
    }
    }
  
  }
  topkeyp.Draw(pad, x2+12, y2, foreground, background);
  topkeyp2.Draw(pad2, x2, y2+13, foreground, background);
}
void keykeysokesc(MenuEntry* entry) {
  const Screen &topkeyp = OSD::GetTopScreen();
  const Screen &topkeyp2 = OSD::GetTopScreen();
  u32 x2 = 5;
  u32 y2 = 170;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  std::string pad;
  std::string pad2;
  pad = "_";
  pad2 = "_ _ _";
  u8 Disdown;
  if(Controller::IsKeysDown(DPadUp)) {
    pad = "X";
    if(Controller::IsKeysDown(DPadRight)) {
      pad2 = "_ _ X"; 
    }else{
    if(Controller::IsKeysDown(DPadLeft)) {
      pad2 = "X _ _";
    }
    }
  }else{
  if(Controller::IsKeysDown(DPadDown)) {
    if(Controller::IsKeysDown(DPadRight)) {
      pad2 = "_ X X"; 
    }else{
    if(Controller::IsKeysDown(DPadLeft)) {
      pad2 = "X X _";
    }else{
    pad2 = "_ X _";
    }
    }
  }else{
    if(Controller::IsKeysDown(DPadLeft)) {
      pad2 = "X _ _";
    }else{
     if(Controller::IsKeysDown(DPadRight)) {
       pad2 = "_ _ X";
     }
    }
    }
  
  }
  topkeyp.Draw(pad, x2+12, y2, foreground, background);
  topkeyp2.Draw(pad2, x2, y2+13, foreground, background);
}
}

