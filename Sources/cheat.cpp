#include "cheats.hpp"
u32 offset = 0;
u32 data32 = 0;
u8 data8 = 0;
u16 data16 = 0;
u32 patch_address = 0;
u16 cmp16 = 0;
u32 cmp32 = 0;

namespace CTRPluginFramework
{

//カヴィリーマイクロ
void km (MenuEntry *entry)
{
	offset = 0x30000000;
	data32 = Utils::Random(0x0000000 , 0x0000270F);
	Process::Write32(offset + 0x0063C5C0, data32);
	offset += 0x4;
	offset = 0;
	data32 = 0;
	Process::Write32(0x001D9954 , 0x3F600000);
	Process::Write32(0x001D93F8 , 0x3F600000);
	Process::Write32(0x001D92F0 , 0x3F600000);
	Process::Write32(0x00215500 , 0x40C00000);
	offset = 0x31000000;
	if(Process::Read32(offset + 0x006E8CAC , cmp32) && cmp32 == 0x00000080)
	{
		Process::Read32(offset + 0x06E8954 , data32);
		data32 += 0x00506980;
		Process::Write32(offset + 0x06E8954 , data32);
	}
	if(Process::Read32(offset + 0x006E8CAC , cmp32) && cmp32 == 0x00000008)
	{
		Process::Read32(offset + 0x06E8974 , data32);
		data32 += 0x00506980;
		Process::Write32(offset + 0x06E8974 , data32);
	}
}

void fov (MenuEntry *entry)
{
	offset = 0x31000000;
	if(Process::Read32(offset + 0x006E8CAC , cmp32) && cmp32 == 0x00000080)
	{
		Process::Read32(offset + 0x06E8954 , data32);
		data32 += 0x00506980;
		Process::Write32(offset + 0x06E8954 , data32);
	}
	if(Process::Read32(offset + 0x006E8CAC , cmp32) && cmp32 == 0x00000008)
	{
		Process::Read32(offset + 0x06E8974 , data32);
		data32 += 0x00506980;
		Process::Write32(offset + 0x06E8974 , data32);
	}
}
//エフェクト軽減
void eff(MenuEntry *entry)
{
	Process::Write32(0x001D9954 , 0x3F600000);
	Process::Write32(0x001D93F8 , 0x3F600000);
	Process::Write32(0x001D92F0 , 0x3F600000);
}
//UIスピードアップ
void uspeed(MenuEntry *entry)
{
	Process::Write32(0x00215500 , 0x40C00000);
}
//RP変更(-9999)
void rpff(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0xFFFFD8F1);
}
//RP(ランダム)
void rprnd(MenuEntry *entry)
{
	offset = 0x30000000;
	data32 = Utils::Random(0x0000000 , 0x0000270F);
	Process::Write32(offset + 0x0063C5C0, data32);
	offset += 0x4;
}
//Amiiboスキン解放
void amib(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C92C , 0x02020203);
	Process::Write32(offset + 0x0063C93C , 0x02020203);
	Process::Write32(offset + 0x0063C94C , 0x02020203);
	Process::Write32(offset + 0x0063C85C , 0x02020203);
	Process::Write32(offset + 0x0063C86C , 0x02020203);
}

}