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
  std::string logo2 = "Die";
  u32 x = 1;
  u32 y = 1;
  u32 x2 = 1;
  u32 y2 = 21;
  int whilend = 0;
  int Changed
  int slct = 0;
  int indian;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(logo, x, y, foreground, background);
  while (whilend == 0) {
    if(Controller::IsKeysPressed(L)) {
      if (indian==0) {
        indian = 1;
        Changed=1;
      }else{
        indian=0;
        Changed=1;
      }
    }
    if(Controller::IsKeysPressed(R)) {
      whilend = 1;
      Changed=1;
    }
    if(Controller::IsKeysPressed(Right)) {
      slct
      Changed=1;
    }
    if(Controller::IsKeysPressed(Left)) {
      slct += -1;
      Changed=1;
    }
  if(Changed==1) {
    Chanhed=0;
    top_screen2.Draw(logo2, x, y, foreground, background);
  }
  }
 }
}  // namespace CTRPluginFramework