#include "cheats.hpp"

namespace CTRPluginFramework
{
u32 offset=0;
u32 svar=0;
u32 rvar=0;
u32 startadd=0;
u32 endadd=0;
File file;
u32 scanningvar = 0;
int selectingvar=0;
int sizebaddr = 0;
int scanning = 0;
int scancalc =0;
u32 readedaddr = 0;
u32 readedaddr2 = 0;
u32 readedaddr3 = 0;
u32 maaa =0;
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
  
}
void setupvar(MenuEntry *entry)
{
  svar = getvar32("32bit various,search");
  rvar = getvar32("32bit various,replace");
  startadd = getvar32("start address");
  endadd = getvar32("end address");
  scancalc = ((startadd-endadd)/4)+1;
  getvar32(std::to_string(scancalc));
  File file;
  maaa =0;
  scanning = 0;
  scanningvar = startadd;
  for(int i = 0,i!=scancalc,i++;){
  Process::Read32(scanningvar,maaa);
  if(maaa == svar){
    u32 data = maaa;
    File::Open(file,"file.bin");
    file.Seek(4);
    file.Write((void*)&maaa, sizeof(u32));
    file.Flush();
  }
  file.Close();
  scanningvar += 0x4;
  }
}
void startbrute(MenuEntry *entry)
{
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(R)){
    selectingvar++;
File::Open(file,"file.bin");
    selectingvar += -1;
    file.Seek(selectingvar*4);
    
    file.Read((void*)&readedaddr, sizeof(u32));
    if(file.Tell()!=file.GetSize()){
    file.Seek(4);
    file.Read((void*)&readedaddr2, sizeof(u32));
    }
    if(file.Tell()!=0){
    file.Seek(-8);
    file.Read((void*)&readedaddr3, sizeof(u32));
    }
    file.Close();
    
    Process::Write32(readedaddr,rvar);
    OSD::Notify("Selecting Addr" + std::to_string(readedaddr));
    if(file.Tell()!=file.GetSize()){
    OSD::Notify("Next Addr" + std::to_string(readedaddr2));
    }
    if(file.Tell()!=0){
    OSD::Notify("Back Addr" + std::to_string(readedaddr3));
    }
  }
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(L)){
    File::Open(file,"file.bin");
    selectingvar += -1;
    file.Seek(selectingvar*4);
    
    file.Read((void*)&readedaddr, sizeof(u32));
    if(file.Tell()!=file.GetSize){
    file.Seek(4);
    file.Read((void*)&readedaddr2, sizeof(u32));
    }
    if(file.Tell()!=0){
    file.Seek(-8);
    file.Read((void*)&readedaddr3, sizeof(u32));
    }
    file.Close();
    
    Process::Write32(readedaddr,rvar);
    OSD::Notify("Selecting Addr" + std::to_string(readedaddr));
    if(file.Tell()!=file.GetSize){
    OSD::Notify("Next Addr" + std::to_string(readedaddr2));
    }
    if(file.Tell()!=0){
    OSD::Notify("Back Addr" + std::to_string(readedaddr3));
    }
}
}
}
