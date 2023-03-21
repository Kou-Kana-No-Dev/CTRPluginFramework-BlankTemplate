#include "cheats.hpp"
#include "CTRPluginFramework.hpp"
#include <string>
#include <cstdio>
u32 address1=0;
u32 address2=0;
u32 bruetvar=0;
u32 var2edit=0;
u16 bruetvar_16=0;
u16 var2edit_16=0;
u8 bruetvar_8=0;
u8 var2edit_8=0;
int mode=0;
u32 memories[] = {};
u32 progress=0;
int hits = 0;
u16 memories_16[] = {};
u8 memories_8[] = {};
int sel_mem = 0;

u32 vari0 = 0;
u32 vari1 = 0;
u32 vari2 = 0;
u32 vari3 = 0;

u16 SV_16b = 0;
u16 V2V_16b = 0;
u8 SV_8b = 0;
u8 V2V_8b = 0;
namespace CTRPluginFramework
{
  //プロセス管理の関数(コード短縮)
/**/u32 pmm32(bool Write_or_Read,u32 mem,u32 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write32(mem,mem_manage);
    return 0;
  }else{
    Process::Read32(mem,mem_manage);
    return mem_manage;
  }
}
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
//プロセス管理の関数(コード短縮)
u16 pmm16(bool Write_or_Read,u32 mem,u16 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write16(mem,mem_manage);
    return 0;
  }else{
    Process::Read16(mem,mem_manage);
    return mem_manage;
  }
}
//プロセス管理の関数(コード短縮)
u8 pmm8(bool Write_or_Read,u32 mem,u8 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write8(mem,mem_manage);
    return 0;
  }else{
    Process::Read8(mem,mem_manage);
    return mem_manage;
  }
}
//プロセス管理の関数(コード短縮)
float pmmfl(bool Write_or_Read,u32 mem,float mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::WriteFloat(mem,mem_manage);
    return 0;
  }else{
    Process::ReadFloat(mem,mem_manage);
    return mem_manage;
  }
}
//OSD.h関連の命令をショートカットするための関数
void osd_mana(int osdtype,const std::string mes, const Color fg = Color::White, const Color p = Color::Black, u32 pox=-1, u32 poy=-1){
  const Screen& osdmn = OSD::GetTopScreen();
  
  switch(osdtype){
    case 1:
    OSD::Notify(mes, fg, p);
    break;
    case 2:
    if(pox!=-1 && poy!=-1){
      osdmn.DrawSysfont(mes,pox,poy,fg);
    }
    break;
    case 3:
    if(pox!=-1 && poy!=-1){
      osdmn.Draw(mes,pox,poy,fg,p);
      
    }
    break;
    default:
    break;
  }
  
}




void start_bruet(MenuEntry *entry)//Pointer Refresher
{
  if(!(address1-1 > address2)){
    hits=0;
    progress = address1;
    while(progress!=address2){
    switch(mode){
      case 1://32bit Var
      
      if(pmm32(false,progress)==bruetvar){
        memories[hits] = progress;
        hits++;
      }
      progress+=0x4;
      break;
      case 2:
      if(pmm16(false,progress)==bruetvar_16){
        memories_16[hits] = progress;
        hits++;
      }
      progress+=0x2;
      
      
      break;
      case 3:
      if(pmm8(false,progress)==bruetvar_8){
        memories_8[hits] = progress;
        hits++;
      }
      progress+=0x1;
      
      
      break;
    default:
    break;
    }
    }
  }
}



void editor1(MenuEntry *entry)
{
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(R)){
    switch(mode){
      case 1://32bit Var
      if(sel_mem < hits && sel_mem < 0){
      pmm32(true,memories[sel_mem],var2edit);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m32 edited " + std::to_string(memories[sel_mem]));
    OSD::Notify("m32 next " + std::to_string(memories[sel_mem+1]));
    OSD::Notify("m32 backs " + std::to_string(memories[sel_mem-1]));
      sel_mem++;
      
      break;
      case 2:
      if(sel_mem < hits && sel_mem < 0){
      pmm16(true,memories_16[sel_mem],var2edit_16);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m16 edited " + std::to_string(memories_16[sel_mem]));
    OSD::Notify("m16 next " + std::to_string(memories_16[sel_mem+1]));
    OSD::Notify("m16 backs " + std::to_string(memories_16[sel_mem-1]));
      sel_mem++;
      break;
      case 3:
      if(sel_mem < hits && sel_mem < 0){
      pmm8(true,memories_8[sel_mem],var2edit_8);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m8 edited " + std::to_string(memories_8[sel_mem]));
    OSD::Notify("m8 next " + std::to_string(memories_8[sel_mem+1]));
    OSD::Notify("m8 backs " + std::to_string(memories_8[sel_mem-1]));
      sel_mem++;
      
      break;
    default:
    break;
    }
    
  }
  if(Controller::IsKeysDown(X) && Controller::IsKeysPressed(L)){
    switch(mode){
      case 1://32bit Var
      if(sel_mem < hits && sel_mem < 0){
      pmm32(true,memories[sel_mem],var2edit);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m32 edited " + std::to_string(memories[sel_mem]));
    OSD::Notify("m32 next " + std::to_string(memories[sel_mem+1]));
    OSD::Notify("m32 backs " + std::to_string(memories[sel_mem-1]));
      sel_mem+=-1;
      break;
      case 2:
      if(sel_mem < hits && sel_mem < 0){
      pmm16(true,memories_16[sel_mem],var2edit_16);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m16 edited " + std::to_string(memories_16[sel_mem]));
    OSD::Notify("m16 next " + std::to_string(memories_16[sel_mem+1]));
    OSD::Notify("m16 backs " + std::to_string(memories_16[sel_mem-1]));
      sel_mem+=-1;
      break;
      case 3:
      if(sel_mem < hits && sel_mem < 0){
      pmm8(true,memories_8[sel_mem],var2edit_8);
      }else{
        sel_mem = 0;
      }
      OSD::Notify("m8 edited " + std::to_string(memories_8[sel_mem]));
    OSD::Notify("m8 next " + std::to_string(memories_8[sel_mem+1]));
    OSD::Notify("m8 backs " + std::to_string(memories_8[sel_mem-1]));
      sel_mem+=-1;
      
      break;
    default:
    break;
    }
  }
  
}
void setup_bruet(MenuEntry *entry)
{
  address1 = getvar32("start_bruet");
  bruetvar = getvar32("Search");
  address2 = getvar32("end");
  var2edit = getvar32("edit");
  
  
}
void setup_bruet_custom(MenuEntry *entry)
{
  bruetvar_16 = getvar16("bruetvar_16");
  var2edit_16 = getvar16("var2edit_16");
  bruetvar_8 = getvar8("bruetvar_8");
  var2edit_8 = getvar8("var2edit_8");
}

}
/*メモｍ
Color(u8 red, u8 green, u8 blue, u8 alpha = 255);

Notify画面右下に表示
引数
Notify(const std::string &str, const Color &foreground = Color::White, const Color &background = Color::Black);
戻りint

OSDマネージャー - 
1 - Notify
2 - Sysfont
3 - Draw
*/
