#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
void ludora(MenuEntry *entry) {
  std::string ludoralog = "Start ludora\n";
  std::string ludorax;
if (!GetInput(  std::string ludorax += "",   std::string ludoralog  += "" )) { 
return;
 }
ludoralog += ( "\n" + ludorax);
}
}
