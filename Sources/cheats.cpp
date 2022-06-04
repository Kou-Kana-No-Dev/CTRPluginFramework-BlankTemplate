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
  while (ludorax != "lend") {
    if (!GetInput(ludorax, ludoralog + "\n>>")) {
      return;
    }
    ludoralog += ("\n" + ludorax);
    if (ludorax == "sudo") {
      ludoralog += ("\nsudo Success");
    }
        if (ludorax == "hr") {
          ludoralog += ("\nHR >> please enter");
          if (!GetInput(hatehr, ludoralog + "\n>>")) {
          Process::Write16(offset + 0x831B76A , hatehr);
          }
    }
  }
}
}  // namespace CTRPluginFramework
