#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  const Screen &top_screen = OSD::GetTopScreen();
  const Screen &top_screen2 = OSD::GetTopScreen();
  std::string logo = "Black Out";
  std::string logo2 = "ver 0.1";
  u32 x = 1;
  u32 y = 1;
  u32 x2 = 1;
  u32 y2 = 21;
  int pushed;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(logo, x, y, foreground, background);
  top_screen2.Draw(logo2, x2, y2, foreground, background);
  int asd;
  while (asd == 0) { // Main Loop
  	if(Controller::IsKeysPressed(DPadUp)) {
        logo2 = "1";
      top_screen2.Draw(logo2, x2, y2, foreground, background);
    }
  }
}
}  // namespace CTRPluginFramework