#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  std::string str = "K Plugin";
  u32 x = 0;
  u32 y = 0;
  Color foreground = Color::White;
  Color background = Color::Black;
  OSD::Draw(str, x, y, foreground, background);
}

}
}  // namespace CTRPluginFramework
