#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
void keykeysokesb(MenuEntry* entry){
  const Screen &top_screen = OSD::GetTopScreen();
  u32 x = 0;
  u32 y = 0;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  std::string keys
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
}
