#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  u16 english;
  u16 slct = 0;
  Process::Read16(0x350B48 , english);
  Process::Read16(0x350B4A , slct);
  const Screen &top_screen = OSD::GetTopScreen();
  const Screen &top_screen2 = OSD::GetTopScreen();
  std::string logo = "Black Out";
  std::string logo2 = "Die";
  u32 x = 1;
  u32 y = 1;
  u32 x2 = 1;
  u32 y2 = 21;
  int whilend = 0;
  int Changed;
  int indian;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(logo, x, y, foreground, background);
  if(Controller::IsKeysPressed(L)) {
   if (english == 1) {
    Process::Write16(0x350B48 , 0x0000);
   }else{
    Process::Write16(0x350B48 , 0x0001);
   }
  }
  if(Controller::IsKeysPressed(Right)) {
    if (english == 1) {
      Process::Write16(0x350B4A , slct += 1);
      Process::Read16(0x350B4A , slct);
      if(slct!=1) {
        if(slct!=0) {
          if(slct!=2) {
            if(slct!=3) {
              slct = 0;
            }
          }
      }
    }
      }
  }
  if(Controller::IsKeysPressed(Left)) {
    if (english == 1) {
      Process::Write16(0x350B4A , slct += -1);
      Process::Read16(0x350B4A , slct);
      if(slct!=1) {
        if(slct!=0) {
          if(slct!=2) {
            if(slct!=3) {
              slct = 0;
            }
          }
      }
    }
  }
  if(slct == 0) {
    logo2 = "World";
  }
  if(slct == 1) {
    logo2 = "combat";
  }
  if(slct == 2) {
    logo2 = "Player";
  }
  if(slct == 3) {
    logo2 = "Movement";
  }
  
  
  
  if (english == 1) {
    top_screen2.Draw(logo2, x2, y2, foreground, background);
  }
 }
}  // namespace CTRPluginFramework