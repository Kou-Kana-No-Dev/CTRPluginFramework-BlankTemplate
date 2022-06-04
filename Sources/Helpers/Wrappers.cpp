#include "Helpers/Wrappers.hpp"

namespace CTRPluginFramework {

bool GetInput(std::string& input, const std::string& msg) {
  Keyboard keyboard(msg);

  if (msg.empty()) keyboard.DisplayTopScreen = false;

  if (keyboard.Open(input, input) != -1) return (true);

  return (false);
}

}  // namespace CTRPluginFramework
