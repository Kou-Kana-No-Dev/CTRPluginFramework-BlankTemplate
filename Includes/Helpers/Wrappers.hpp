#ifndef WRAPPERS_HPP
#define WRAPPERS_HPP

#include "CTRPluginFramework.hpp"

namespace CTRPluginFramework {
using StringVector = std::vector<std::string>;

template <class T>
bool GetInput(T& input, const std::string& msg = "", bool use_hex = false) {
  Keyboard keyboard(msg);

  if (msg.empty()) keyboard.DisplayTopScreen = false;
  keyboard.IsHexadecimal(use_hex);

  if (keyboard.Open(input, input) != -1) return (true);

  return false;
}

bool GetInput(std::string& input, const std::string& msg = "");

template <class T>
bool GetInput(T& input, const StringVector& choices,
              const std::string& msg = "") {
  Keyboard keyboard(msg);

  if (msg.empty()) keyboard.DisplayTopScreen = false;

  keyboard.Populate(const_cast<StringVector&>(choices));

  int selected = keyboard.Open();

  if (selected != -1) {
    input = selected;
    return true;
  }
  return false;
}
}  // namespace CTRPluginFramework

#endif
