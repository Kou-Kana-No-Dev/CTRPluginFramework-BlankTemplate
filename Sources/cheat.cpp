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
void CavilyMicro(MenuEntry *entry)
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
//FOV強化(修正版)
void FOVEnhancementModifiedVersion(MenuEntry *entry)
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
void EffectReduction(MenuEntry *entry)
{
	Process::Write32(0x001D9954 , 0x3F600000);
	Process::Write32(0x001D93F8 , 0x3F600000);
	Process::Write32(0x001D92F0 , 0x3F600000);
}
//UIスピードアップ
void UISpeedUp(MenuEntry *entry)
{
	Process::Write32(0x00215500 , 0x40C00000);
}
//RP変更(-9999)
void RPChange9999(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0xFFFFD8F1);
}
//RP(ランダム)
void RPRandom(MenuEntry *entry)
{
	offset = 0x30000000;
	data32 = Utils::Random(0x0000000 , 0x0000270F);
	Process::Write32(offset + 0x0063C5C0, data32);
	offset += 0x4;
}
//Amiiboスキン解放
void AmiiboSkinRelease(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C92C , 0x02020203);
	Process::Write32(offset + 0x0063C93C , 0x02020203);
	Process::Write32(offset + 0x0063C94C , 0x02020203);
	Process::Write32(offset + 0x0063C85C , 0x02020203);
	Process::Write32(offset + 0x0063C86C , 0x02020203);
}

//Zoom
void Zoom(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00244D04 , 0x3F880000);
}
//FOV Booster
void FOVBooster(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00244D04 , 0x3F4CCCCC);
}
//FOV Boostest
void FOVBoostest(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00244D04 , 0x3F1CCCCC);
}

//Name plate Viewer
void NamePlateViewer(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002451B0 , 0x3E900000);
}
//Name plate Viewer MINI
void NamePlateViewerMINI(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002451B0 , 0x3F100000);
}
//spak mini
void SpakMini(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x0040A384 , 0x3FC00000);
}
//spak
void Spak(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x0040A384 , 0x40000000);
}
//effect Removing
void EffectRemoving(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00403324 , 0x00000000);
	Process::Write32(offset + 0x001D9954 , 0x00000000);
	Process::Write32(offset + 0x001D93F8 , 0x00000000);
	Process::Write32(offset + 0x001D92F0 , 0x00000000);
}
//effect smaller
void EffectSmaller(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x001D9954 , 0x3F600000);
	Process::Write32(offset + 0x001D93F8 , 0x3F600000);
	Process::Write32(offset + 0x001D92F0 , 0x3F600000);
}

//Point Editor(9639)
void PointEditor9639(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x000025A7);
}
//Point Editor(6873)
void PointEditor6873(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00001AD9);
}
//Point Editor(4892)
void PointEditor4892(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x0000131C);
}
//Point Editor(2342)
void PointEditor2342(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00000926);
}
//Point Editor(7202)
void PointEditor7202(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00001C22);
}
//Point Editor(129)
void PointEditor129(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00000081);
}
//Point Editor(8635)
void PointEditor8635(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x000021BB);
}
//Point Editor(3739)
void PointEditor3739(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00000E9B);
}
//Point Editor(1530)
void PointEditor1530(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x000005FA);
}
//Point Editor(5566)
void PointEditor5566(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x000015BE);
}
//Point Editor(Randomizer)
void PointEditorRandomizer(MenuEntry *entry)
{
	offset = 0x30000000;
	data32 = Utils::Random(0x0000000 , 0x0000270F);
	Process::Write32(offset + 0x0063C5C0, data32);
	offset += 0x4;
}
//Point Editor(9999)
void PointEditor9999(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x0000270F);
}
//Point Editor(1)
void PointEditor1(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0x00000001);
}
//Point Editor(-9999)
void PointEditor9999(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0xFFFFD81F);
}
//Point Editor(-1)
void PointEditor1(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0xFFFFFFFF);
}

//Sound Speed Normal
void SoundSpeedNormal(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002D3CEC , 0x3F800000);
}
//Sound Speed
void SoundSpeed(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002D3CEC , 0x40000000);
}
//BGM Ster En
void BGMSterEn(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00213E20 , 0x40400000);
}
//BGM Ster Mini
void BGMSterMini(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00213E20 , 0x3FC00000);
}
//BGM Ster
void BGMSter(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00213E20 , 0x3F800000);
}

//Skip UI animation
void SkipUIAnimation(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00215500 , 0x40C00000);
}
//UI size
void UISize(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002457EC , 0x3F800000);
}
//UI size Mini
void UISizeMini(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002457EC , 0x3F6CCCCC);
}
//Strings
void Strings(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00231BD4 , 0x40400000);
}

//Kirby Size
void KirbySize(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002779C4 , 0x3F4CCCCC);
}
//Kirby Size Fix
void KirbySizeFix(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002779C4 , 0x3F800000);
}

//Safe amiibo skin
void SafeAmiiboSkin(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C92C , 0x02020203);
	Process::Write32(offset + 0x0063C93C , 0x02020203);
	Process::Write32(offset + 0x0063C94C , 0x02020203);
	Process::Write32(offset + 0x0063C85C , 0x02020203);
	Process::Write32(offset + 0x0063C86C , 0x02020203);
}
//Amiibo Skin Hax(Danger)
void AmiiboSkinHaxDanger(MenuEntry *entry)
{
	offset = 0x30000000;
	for(u32 i = 0; i < 0x0000003F; i++)
	{
		Process::Write32(offset + 0x4*i + 0x0063C858 , 0x05050505);
		
	}
}
//Cosmetics Hack(Danger)
void CosmeticsHackDanger(MenuEntry *entry)
{
	offset = 0x30000000;
	for(u32 i = 0; i < 0x00001000; i++)
	{
		Process::Write16(offset + 0x2*i + 0x0063C618 , 0x0505);
		
	}
}

//Sound Speed
void SoundSpeed(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002D3CEC , 0x40000000);
}
//Point Editor(Randomizer)
void PointEditorRandomizer(MenuEntry *entry)
{
	offset = 0x30000000;
	data32 = Utils::Random(0x0000000 , 0x0000270F);
	Process::Write32(offset + 0x0063C5C0, data32);
	offset += 0x4;
}
//effect smaller
void EffectSmaller(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x001D9954 , 0x3F600000);
	Process::Write32(offset + 0x001D93F8 , 0x3F600000);
	Process::Write32(offset + 0x001D92F0 , 0x3F600000);
}
//BGM Ster Mini
void BGMSterMini(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00213E20 , 0x3FC00000);
}
//Name plate Viewer MINI
void NamePlateViewerMINI(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002451B0 , 0x3F100000);
}
//Skip UI animation
void SkipUIAnimation(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00215500 , 0x40C00000);
}
//FOV Boostest (Fixed)
void FOVBoostestFixed(MenuEntry *entry)
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
//Strings Hide
void StringsHide(MenuEntry *entry)
{
	Process::Write32(0x00231BD4 , 0x42C00000);
}
//s2
void S2(MenuEntry *entry)
{
	Process::Write32(0x00416FE0 , 0x3F4CCCCC);
	Process::Write32(0x0042500C , 0x3F4CCCCC);
}
//Point Editor(-9999)
void PointEditor9999(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C5C0 , 0xFFFFD8F1);
}
//FOV Boostest
void FOVBoostest(MenuEntry *entry)
{
	offset = 0x31000000;
	Process::Write32(offset + 0x006E8954 , 0xC2C00000);
}
//Sound Speed
void SoundSpeed(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002D3CEC , 0x00000000);
}
//UI size
void UISize(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002457EC , 0x3F800000);
}
//UI size2
void UISize2(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x00413B74 , 0x40A00000);
}
//UI size micro
void UISizeMicro(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x002457EC , 0x3F700000);
}
//name change (Kavily user)
void NameChangeKavilyUser(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C468 , 0x0061004B);
	Process::Write32(offset + 0x0063C46C , 0x00690076);
	Process::Write32(offset + 0x0063C470 , 0x0079006C);
	Process::Write32(offset + 0x0063C474 , 0x00750020);
	Process::Write32(offset + 0x0063C478 , 0x00650073);
	Process::Write16(offset + 0x0063C47C , 0x0072);
}
//name change (Kavily Client user)
void NameChangeKavilyClientUser(MenuEntry *entry)
{
	offset = 0x30000000;
	Process::Write32(offset + 0x0063C468 , 0x0061004B);
	Process::Write32(offset + 0x0063C46C , 0x00690076);
	Process::Write32(offset + 0x0063C470 , 0x0079006C);
	Process::Write32(offset + 0x0063C474 , 0x00430020);
	Process::Write32(offset + 0x0063C478 , 0x0069006C);
	Process::Write32(offset + 0x0063C47C , 0x006E0065);
	Process::Write32(offset + 0x0063C480 , 0x00200074);
	Process::Write32(offset + 0x0063C484 , 0x00730075);
	Process::Write32(offset + 0x0063C488 , 0x00720065);
}
//spak mini
void SpakMini(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x0040A384 , 0x3FC00000);
}
//effect more mini
void EffectMoreMini(MenuEntry *entry)
{
	Process::Write32(0x00403324 , 0x3F600000);
}
//sound Balans
void SoundBalans(MenuEntry *entry)
{
	offset = 0x00000000;
	Process::Write32(offset + 0x0041C1A0 , 0x3F800000);
	Process::Write32(offset + 0x00423774 , 0x3F800000);
}

}
