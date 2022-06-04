#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  std::string ludoralog = "Start ludora";
  std::string ludorax;
  u16 hatehr;
  u16 hateatk;
  u16 hatedfc;
  while (ludorax != "lend") {
    if (!GetInput(ludorax, ludoralog + "\n>>")) {
      return;
    }
    ludoralog += ("\n" + ludorax);
    if (ludorax == "atk") {
      ludoralog += ("\nATK >> please enter");
      if (!GetInput(hatehr, ludoralog + "\n>>")) {
      return;
      }
      	Process::Write16(0x0831B450 , hateatk);
        Process::Write16(0x008F1C0C , hateatk);
    }
        if (ludorax == "hr") {
          ludoralog += ("\nHR >> please enter");
          if (!GetInput(hatehr, ludoralog + "\n>>")) {
          }
        Process::Write16(0x0831B76A , hatehr);
    }
    if (ludorax == "dfc") {
      ludoralog += ("\nDFC >> please enter");
      if (!GetInput(hatedfc, ludoralog + "\n>>")) {
      }
      Process::Write16(0x0831B45E , hatedfc);
    }
  }
}
}  // namespace CTRPluginFramework
