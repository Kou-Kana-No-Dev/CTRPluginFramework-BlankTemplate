#include "cheats.hpp"

namespace CTRPluginFramework
{
u32 offset=0;
u32 svar=0;
u32 rvar=0;
u32 startadd=0;
u32 endadd=0;
u32 b_addresses[]={};
u32 scanningvar = 0;
int selectingvar=0;
int sizebaddr = 0;
u32 getvar32(std::string str) {
  u32 getvaritem;
  Keyboard key(str);
  key.IsHexadecimal(true);
  if (key.Open(getvaritem) != -1) {
    return getvaritem;
  }
  return getvaritem;
}
u16 getvar16(std::string str) {
  u16 getvaritem;
  Keyboard key(str);
  key.IsHexadecimal(true);
  if (key.Open(getvaritem) != -1) {
    return getvaritem;
  }
  return getvaritem;
}
u8 getvar8(std::string str) {
  u8 getvaritem;
  Keyboard key(str);
  key.IsHexadecimal(true);
  if (key.Open(getvaritem) != -1) {
    return getvaritem;
  }
  return getvaritem;
}
void searcher() {
  u32 21m0 =0;
  int scanning = 0;
  scanningvar = startadd;
  while(!(scanningvar => endadd)){
  Process::Read32(scanningvar,21m0);
  if(21m0 == svar){
    b_addresses[scanning] = 21m0;
    scanning++;
  }
  scanningvar += 0x4;
  }
  int sizebaddr = sizeof b_addresses / sizeof b_addresses[0];
}
void setupvar(MenuEntry *entry)
{
  svar = getvar32("32bit various,search");
  rvar = getvar32("32bit various,replace");
  startadd = getvar32("start address");
  endadd = getvar32("end address");
  b_addresses[]={};
  selectingvar = 0;
  searcher();
}
void startbrute(MenuEntry *entry)
{
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(R)){
    selectingvar++;
    if(selectingvar == sizebaddr+1){
      selectingvar =0;
    }
    Process::Write32(b_addresses[selectingvar],rvar);
    OSD::Notify("Selecting Addr" + std::to_string(b_addresses[selectingvar]));
    if(selectingvar != sizebaddr){
    OSD::Notify("Next Addr" + std::to_string(b_addresses[selectingvar+1]));
    }
    if(selectingvar != 0){
    OSD::Notify("Back Addr" + std::to_string(b_addresses[selectingvar-1]));
    }
  }
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(L)){
    selectingvar += -1;
    if(selectingvar == sizebaddr+1){
      selectingvar =0;
    }
    if(0 > selectingvar){
      selectingvar = sizebaddr;
    }
    Process::Write32(b_addresses[selectingvar],rvar);
    OSD::Notify("Selecting Addr" + std::to_string(b_addresses[selectingvar]));
    if(selectingvar != sizebaddr){
    OSD::Notify("Next Addr" + std::to_string(b_addresses[selectingvar+1]));
    }
    if(selectingvar != 0){
    OSD::Notify("Back Addr" + std::to_string(b_addresses[selectingvar-1]));
    }
}
}
}
