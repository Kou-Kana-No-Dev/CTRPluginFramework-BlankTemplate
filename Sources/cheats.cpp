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
  u32 y2 = 175;
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
void Readanim(MenuEntry* entry) {
  u8 HP;
  u8 Sutam;
  u16 sharp;
  u8 field;
  const Screen &HPi = OSD::GetTopScreen();
  const Screen &Sutami = OSD::GetTopScreen();
  const Screen &sharpi = OSD::GetTopScreen();
  const Screen &fieldi = OSD::GetTopScreen();
  u32 x4= 10;
  u32 y4 = 120;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  Process::Read32(0x08195350 , offset);
  Process::Read8(offset + 0x0F52 , HP);
  Process::Read8(offset + 0x0F5E , Sutam);
  Process::Read16(offset + 0x2214 , sharp);
  Process::Read8(offset + 0x0CF4 , field);
  HPi.Draw("HP : " + Utils::Format("%d" , HP), x4, y4, foreground, background);
  Sutami.Draw("Moving : " + Utils::Format("%d" , Sutam), x4, y4+10, foreground, background);
  sharpi.Draw("Sharpness : " + Utils::Format("%d" , sharp), x4, y4+20, foreground, background);
  fieldi.Draw("Field : " + Utils::Format("%d" , field), x4, y4+30, foreground, background);
}
void Readanim2(MenuEntry* entry) {
  const Screen &HRi = OSD::GetTopScreen();
  const Screen &atki = OSD::GetTopScreen();
  const Screen &dfci = OSD::GetTopScreen();
  const Screen &abli = OSD::GetTopScreen();
  const Screen &monyi = OSD::GetTopScreen();
  const Screen &pointi = OSD::GetTopScreen();
  u32 x5 = 10;
  u32 y5 = 50;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  u16 atk;
  u16 dfc;
  u16 abl;
  u16 HR;
  u32 Money;
  u32 point;
  Process::Read16(0x831B450 , atk);
  Process::Read16(0x831B45E , dfc);
  Process::Read16(0x831B45A , abl);
  Process::Read16(0x831B76A , HR);
  Process::Read32(0x83B3818 , Money);
  Process::Read32(0x83B3820 , point);
  dfc += 1;
  atki.Draw("attacks : " + Utils::Format("%d" , atk), x5, y5, foreground, background);
  dfci.Draw("Defenses : " + Utils::Format("%d" , dfc), x5, y5+10, foreground, background);
  abli.Draw("attributes : " + Utils::Format("%d" , abl), x5, y5+20, foreground, background);
  HRi.Draw("HR : " + Utils::Format("%d" , HR), x5, y5+30, foreground, background);
  monyi.Draw("Money : " + Utils::Format("%d" , Money), x5, y5+40, foreground, background);
  pointi.Draw("RRI Point : " + Utils::Format("%d" , point), x5, y5+50, foreground, background);
}
}

