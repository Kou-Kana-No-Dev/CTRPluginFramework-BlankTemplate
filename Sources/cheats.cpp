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
  u16 hateabl;
  u16 rnd;
  u32 rndst;
  while (ludorax != "lend") {
    if (!GetInput(ludorax, ludoralog + "\n>>")) {
      return;
    }
    ludoralog += ("\n" + ludorax);
    if (ludorax == "atk") {
      ludoralog += ("\nATK >> please enter()");
      if (!GetInput(hateatk, ludoralog + "\n>>")) {
      }
      Process::Write16(0x008F1C0C , hateatk);
      Process::Write16(0x0831B450 , hateatk);
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
    if (ludorax == "atk 2rnd") {
      ludoralog += ("\nATK :" + rnd);
      Process::Write16(0x008F1C0C , rnd);
      Process::Write16(0x0831B450 , rnd);
     }
    }
    if (ludorax == "rnd") {
      rnd = u16(rand)
      ludoralog += ("\n" + rnd);
    }
    if (ludorax == "dfc 2rnd") {
      
      ludoralog += ("\nDFC :" + rnd);
      Process::Write16(0x0831B45E , rnd);
    }
    if (ludorax == "abl 2rnd") {
      
      ludoralog += ("\nABL :" + rnd);
      Process::Write16(0x0831B45A , rnd);
  }
  if (ludorax == "abl") {
      ludoralog += ("\nABL >> please enter");
      if (!GetInput(hateabl, ludoralog + "\n>>")) {
      }
      Process::Write16(0x0831B45A , hateabl);
    }
    if (ludorax == "hr 2rnd") {
      ludoralog += ("\nHR :" + rnd);
      Process::Write16(0x0831B76A , rnd);
     }
}
}  // namespace CTRPluginFramework
