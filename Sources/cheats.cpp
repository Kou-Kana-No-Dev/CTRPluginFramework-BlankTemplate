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
  int slct = 0;
  int slct2 = 0;
  int isopned = 0;
  str = "Black OUT";
  u32 x = 1;
  u32 y = 1;
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
    str2 = "";
  }
  if (Controller::IsKeyPressed(L)) {
  if(isopned == 0) {
   isopned =1;
  }
  }
  while (isopned == 1) {
  	if(Controller::IsKeyPressed(DPadDown)) {
  	  slct=slct-1;
  	  if (slct == -1) {
  	    slct=4;
  	    str2 = "movement";
  	  }
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
      }
    	if(Controller::IsKeyPressed(DPadUp)) {
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
      if (Controller::IsKeyPressed(L)) {
        if(isopned == 1) {
      isopned =0;
      
  	}
   
  }
     tp_screen.Draw(str2, x, y+20, foreground, background);
  }
}  // namespace CTRPluginFramework
}
