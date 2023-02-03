#include "cheats.hpp"
u32 offset=0;
u32 PlayerP=0;//
u32 MonsterP=0;//
u32 MonsterP2=0;//
u32 ItemP=0;//
int fakreg = 0;
int fakreg2 = 0;
const Screen &Dispe = OSD::GetTopScreen();
bool pointer_finder_is_enable = false;
namespace CTRPluginFramework
{
  
/**/u32 pmm32(bool Write_or_Read,u32 mem,u32 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write32(mem,mem_manage);
    return 0;
  }else{
    Process::Read32(mem,mem_manage);
    return mem_manage;
  }
}
u16 pmm16(bool Write_or_Read,u32 mem,u16 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write16(mem,mem_manage);
    return 0;
  }else{
    Process::Read16(mem,mem_manage);
    return mem_manage;
  }
}
u8 pmm8(bool Write_or_Read,u32 mem,u8 mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::Write8(mem,mem_manage);
    return 0;
  }else{
    Process::Read8(mem,mem_manage);
    return mem_manage;
  }
}
float pmmfl(bool Write_or_Read,u32 mem,float mem_manage = 0){
  if(Write_or_Read){/*true=write*/
    Process::WriteFloat(mem,mem_manage);
    return 0;
  }else{
    Process::ReadFloat(mem,mem_manage);
    return mem_manage;
  }
}
void osd_mana(int osdtype,const std::string mes, const Color fg = Color::White, const Color p = Color::Black, u32 pox=-1, u32 poy=-1){
  switch(osdtype){
    case 1:
    Dispe::Notify(mes, fg, p);
    break;
    case 2:
    if(pox!=-1 && poy!=-1){
      Dispe::DrawSysfont(mes,pox,poy,fg,p);
      
    }
    break;
    case 3:
    if(pox!=-1 && poy!=-1){
      Dispe::Draw(mes,pox,poy,fg,p);
      
    }
    break;
    default:
    break;
  }
  
}
void n1(MenuEntry *entry)//Core
{
PlayerP = pmm32(false,0x8195350);
MonsterP = pmm32(false,0x8195380);
MonsterP2 = pmm32(false,0x8195384);
ItemP = pmm32(false,0x8195380);
}
void n2(MenuEntry *entry)//
{
  if(fakreg == 0 && MonsterP != 0){
    osd_mana(1,"Monster1 Calculation start");
    fakreg = pmm16(false,MonsterP + 0x1318);
  }
  if(fakreg2 == 0 && MonsterP2 != 0){
    osd_mana(1,"Monster2 Calculation start");
    fakreg2= pmm16(false,MonsterP2+ 0x1318);
  }else{
    if(fakreg != 0 && fakreg != pmm16(false,MonsterP + 0x1318)){
      osd_mana(1,std::to_string(fakreg - pmm16(false,MonsterP + 0x1318)));
      fakreg = pmm16(false,MonsterP + 0x1318);
    }
    if(fakreg2 != 0 && fakreg2 != pmm16(false,MonsterP2 + 0x1318)){
      osd_mana(1,std::to_string(fakreg2 - pmm16(false,MonsterP2 + 0x1318)));
      fakreg2 = pmm16(false,MonsterP2 + 0x1318);
    }
  }
}


//独自関数
//ProcessMemoryManager Better

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
