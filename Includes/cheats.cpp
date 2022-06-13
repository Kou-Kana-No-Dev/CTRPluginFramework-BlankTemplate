#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
void E_field(MenuEntry* entry){
  u32 B_fieldP;
  u8 B_fieldN;
  Process::Read32(0x8195384 , B_fieldP);
  offset = B_fieldP;
  Process::Read8(offset + 0x00000CF4 , B_fieldN);
  const Screen &boss1 = OSD::GetTopScreen();
  const Screen &boss2 = OSD::GetTopScreen();
  const Screen &boss3 = OSD::GetTopScreen();
  const Screen &boss4 = OSD::GetTopScreen();
  const Screen &boss5 = OSD::GetTopScreen();
  std::string Blv = B_fieldN;
  std::string str = ("Boss1 : " + Blv);
  
  u32 x = 10;
  u32 y = 0;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  boss1.Draw(str, x, y, foreground, background);
}
}
