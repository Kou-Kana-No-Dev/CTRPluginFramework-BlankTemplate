#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
void E_field(MenuEntry* entry){
  u32 B_fieldP
  u8 B_field
  Process::Read32(0x8195384 , B_fieldP)
  Offset = B_fieldP
  Process::Read8(Offset + 0x00000CF4 , B_field)
  const Screen &top_screen = OSD::GetTopScreen();
  std::string str = ("Boss living : " + B_field);
  u32 x = 10;
  u32 y = 0;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(str, x, y, foreground, background);
}
}
