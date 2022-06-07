#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  const Screen &top_screen = OSD::GetTopScreen();
  const Screen &tp_screen = OSD::GetTopScreen();
  const Screen &btm_screen = OSD::GetBottomScreen();
  std::string str;
  std::string str2;
  u32 slct = 0;
  u32 slct2 = 0;
  u32 isopned = 0;
  str = "Black OUT";
  u32 x = 1;
  u32 y = 1;
  u32 bt1;
  u32 bt2;
  u32 bt3;
  u32 bt4;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(str, x, y, foreground, background);
  if (slct == 0) {
    str2 = "World";
  }
  if (slct == 1) {
    str2 = "combat";
  }
  if (slct == 2) {
    str2 = "Player";
  }
  if (slct == 3) {
    str2 = "movement";
  }
  if (isopned == 0) {
    str2="";
  }
  tp_screen.Draw(str2, x, y+20, foreground, background);
  if(Controller::IsKeysPressed(L) && bt1==0) {
      isopned = 1;
  }
  while (isopned == 1) {
  	if(Controller::IsKeysPressed(DPadDown) && bt2==0) {
  	  slct=slct-1;
  	  if (slct == 0) {
        str2 = "World";
      }
      if (slct == 1) {
        str2 = "combat";
      }
      if (slct == 2) {
        str2 = "Player";
      }
      if (slct == 3) {
        str2 = "movement";
      }
      if (slct == -1) {
  	    slct=3;
  	    str2 = "movement";
  	  }
      }
    	if(Controller::IsKeysPressed(DPadUp)) {
     	  slct++;
    	  if (slct == 0) {
         str2 = "World";
        }
        if (slct == 1) {
          str2 = "combat";
        }
        if (slct == 2) {
         str2 = "Player";
        }
        if (slct == 3) {
          str2 = "movement";
        }
        if (slct == 4) {
        slct = 0;
        str2 = "World";
        }
    	}
      if (Controller::IsKeysPressed(L)) {
        if(isopned == 1) {
      isopned =0;
        }
  	}
   
  }
     tp_screen.Draw(str2, x, y+20, foreground, background);
}  // namespace CTRPluginFramework
}