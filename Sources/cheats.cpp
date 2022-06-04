#include "cheats.hpp"
#include "Helpers.hpp"

namespace CTRPluginFramework {
void ludora(MenuEntry*) {
  std::string ludoralog = "Start ludora";
  std::string ludorax;
  if (!GetInput(ludorax, ludoralog + "\n>>")) {
    return;
  }
  ludoralog += ("\n" + ludorax);
}
}  // namespace CTRPluginFramework
