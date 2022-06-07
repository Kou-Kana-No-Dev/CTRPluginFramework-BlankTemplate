#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  const Screen &top_screen = OSD::GetTopScreen();
  const Screen &btm_screen = OSD::GetBottomScreen();
  std::string str;
  int slct = 0;
  int slct2 = 0;
  int isopned = 0;
  str = "Black OUT";
  u32 x = 0;
  u32 y = 0;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(str, x, y, foreground, background);
  	if(Controller::IsKeyDown(DPadDown)) {
  	  slct--;
  	}
  	if(Controller::IsKeyDown(DPadUp)) {
  	  slct++;
  	}
}
}  // namespace CTRPluginFramework
