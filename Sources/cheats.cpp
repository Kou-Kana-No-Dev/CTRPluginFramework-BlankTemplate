#include "cheats.hpp"
#include "CTRPluginFramework.hpp"
#include <string>
u32 offset=0;
u32 PlayerP=0;//
u32 MonsterP=0;//
u32 MonsterP2=0;//
u32 ItemP=0;//
int fakreg = 0;
int fakreg2 = 0;

bool pointer_finder_is_enable = false;
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




void n1(MenuEntry *entry)//Pointer Refresher
{
PlayerP = pmm32(false,0x8195350);
MonsterP = pmm32(false,0x8195380);
MonsterP2 = pmm32(false,0x8195384);
ItemP = pmm32(false,0x8195380);
}
void n2(MenuEntry *entry)//Function Tester1
{
  if(fakreg == 0){
    fakreg = pmm16(false,MonsterP2 + 0x1318);
  }
  if(fakreg != pmm16(false,MonsterP2 + 0x1318)){
    osd_mana(1,std::to_string(pmm16(false,fakreg - MonsterP2 + 0x1318)));
    fakreg = pmm16(false,MonsterP2 + 0x1318);
  }
  if(fakreg2 == 0){
    fakreg2 = pmm16(false,MonsterP + 0x1318);
    
  }
  if(fakreg2 != pmm16(false,MonsterP + 0x1318)){
    osd_mana(1,std::to_string(pmm16(false,fakreg2 - MonsterP + 0x1318)));
    fakreg2 = pmm16(false,MonsterP + 0x1318);
  }
}

void n3(MenuEntry *entry)//Pointer Refresher
{
PlayerP = pmm32(false,0x8195350);
MonsterP = pmm32(false,0x8195380);
MonsterP2 = pmm32(false,0x8195384);
ItemP = pmm32(false,0x8195380);
if(Controller::IsKeysDown(R)){
OSD::Notify(std::to_string(pmm32(false,0x8195350)));
osd_mana(1,"by osdmana" + std::to_string(pmm32(false,0x8195350)));
OSD::Notify(std::to_string("boss2" + fakreg));
OSD::Notify(std::to_string("boss1" + fakreg2));
}//独自関数
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
