#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
//太刀連射
void TachiFiring(MenuEntry *entry)
{
	if(Controller::IsKeyDown(A))
	{
		Process::Write32(0x0819428C , 0x00000000);
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x000029B8 , 0x3FFFE3CE);
		Process::Write32(offset + 0x00001FE4 , 0x00270004);
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += -52;
		Process::WriteFloat(offset + 0x0000044 , dataf);
		Process::Write32(offset + 0x000002F8 , 0x42950000);
	}
}
//設定バグらせる
void SetBug(MenuEntry *entry)
{
	Process::Write16(0x0831B1F2 , 0xFFFF);
	Process::Write32(0x0831B1F4 , 0xFFFFFFFF);
	Process::Write32(0x0831B1F8 , 0xFFFFFFFF);
	Process::Write32(0x0831B1FC , 0xFFFFFFFF);
	Process::Write32(0x0831B200 , 0xFFFFFFFF);
	Process::Write32(0x0831B204 , 0xFFFFFFFF);
	Process::Write32(0x0831B208 , 0xFFFFFFFF);
}
//プレイヤーのフリーズを治す
void CurePlayerFreeze(MenuEntry *entry)
{
	if(Controller::IsKeysDown(R + L))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001FE4 , 0x005A0001);
	}
}
//Xコマンド
void XCommand(MenuEntry *entry)
{
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206E6566)
	{
		offset2 = 0x083AE780;
		offset = 0x083B3648;
		for(u8 i = 0; i < 0x0000001E; i++)
		{
		Process::Read8(offset2 + i, data8);
		Process::Write8(offset + i, data8);
		}
	}
	offset = 0;
	offset2 = 0;
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206E6566)
	{
		Process::Write32(0x083AE77C , 0x656E6F44);
		Process::Write8(0x083AE780 , 0x00);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D746F)
	{
		offset2 = 0x083AE780;
		offset = 0x08338AFE;
		for(u8 i = 0; i < 0x0000001E; i++)
		{
		Process::Read8(offset2 + i, data8);
		Process::Write8(offset + i, data8);
		}
	}
	offset = 0;
	offset2 = 0;
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D746F)
	{
		Process::Write32(0x083AE77C , 0x656E6F44);
		Process::Write8(0x083AE780 , 0x00);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x316D6163)
	{
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x316D7973)
	{
		Process::Write32(0x083AE77C , 0x09090909);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x6B686C70)
	{
		Process::Write32(0x083AE77C , 0x79616C50);
		Process::Write32(0x083AE780 , 0x3A2F7265);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x79616C50)
	{
		if(Process::Read32(0x083AE780 , cmp32) && cmp32 == 0x3A2F7265)
		{
			if(Process::Read32(0x083AE784 , cmp32) && cmp32 == 0x00000031)
			{
				Process::Write32(0x083AE77C , 0x656E6F44);
				Process::Write32(0x083AE780 , 0x00000000);
				Process::Write32(0x0831B1C8 , 0x00000000);
			}
			if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x79616C50)
			{
				if(Process::Read32(0x083AE780 , cmp32) && cmp32 == 0x3A2F7265)
				{
					if(Process::Read32(0x083AE784 , cmp32) && cmp32 == 0x00000032)
					{
						Process::Write32(0x083AE77C , 0x656E6F44);
						Process::Write32(0x083AE780 , 0x00000000);
						Process::Write32(0x0831B1C8 , 0x00000001);
					}
					if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x79616C50)
					{
						if(Process::Read32(0x083AE780 , cmp32) && cmp32 == 0x3A2F7265)
						{
							if(Process::Read32(0x083AE784 , cmp32) && cmp32 == 0x00000033)
							{
								Process::Write32(0x083AE77C , 0x656E6F44);
								Process::Write32(0x083AE780 , 0x00000000);
								Process::Write32(0x0831B1C8 , 0x00000002);
							}
							if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x79616C50)
							{
								if(Process::Read32(0x083AE780 , cmp32) && cmp32 == 0x3A2F7265)
								{
									if(Process::Read32(0x083AE784 , cmp32) && cmp32 == 0x00000034)
									{
										Process::Write32(0x083AE77C , 0x656E6F44);
										Process::Write32(0x083AE780 , 0x00000000);
										Process::Write32(0x0831B1C8 , 0x00000003);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x646D6358)
	{
		Process::Write32(0x083AE77C , 0x2F9EBCEF);
		Process::Write8(0x083AE780 , 0x5F);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D616E)
	{
		offset2 = 0x083AE780;
		offset = 0x0831B72A;
		for(u8 i = 0; i < 0x0000001E; i++)
		{
		Process::Read8(offset2 + i, data8);
		Process::Write8(offset + i, data8);
		}
	}
	offset = 0;
	offset2 = 0;
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D616E)
	{
		Process::Write32(0x083AE77C , 0x656E6F44);
		Process::Write8(0x083AE780 , 0x00);
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
	{
		data32 = 0x00000000;
	}
	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
	{
		if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2030)
		{
			data32 += 0x00000000;
		}
		if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
		{
			if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2031)
			{
				data32 += 0x00001000;
			}
			if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
			{
				if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2032)
				{
					data32 += 0x00002000;
				}
				if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
				{
					if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2033)
					{
						data32 += 0x00003000;
					}
					if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
					{
						if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2034)
						{
							data32 += 0x00004000;
						}
						if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
						{
							if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2035)
							{
								data32 += 0x00005000;
							}
							if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
							{
								if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2036)
								{
									data32 += 0x00006000;
								}
								if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
								{
									if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2037)
									{
										data32 += 0x00007000;
									}
									if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
									{
										if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2038)
										{
											data32 += 0x00008000;
										}
										if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
										{
											if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2039)
											{
												data32 += 0x00009000;
											}
											if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
											{
												if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2041)
												{
													data32 += 0x0000A000;
												}
												if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
												{
													if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2042)
													{
														data32 += 0x0000B000;
													}
													if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
													{
														if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2043)
														{
															data32 += 0x0000C000;
														}
														if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
														{
															if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2044)
															{
																data32 += 0x0000D000;
															}
															if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
															{
																if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2045)
																{
																	data32 += 0x0000E000;
																}
																if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																{
																	if(Process::Read16(0x083AE780 , cmp16) && (cmp16 & 0xFFFF) == 0x2046)
																	{
																		data32 += 0x0000F000;
																	}
																	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																	{
																		if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2030)
																		{
																			data32 += 0x00000000;
																		}
																		if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																		{
																			if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2031)
																			{
																				data32 += 0x00000100;
																			}
																			if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																			{
																				if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2032)
																				{
																					data32 += 0x00000200;
																				}
																				if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																				{
																					if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2033)
																					{
																						data32 += 0x00000300;
																					}
																					if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																					{
																						if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2034)
																						{
																							data32 += 0x00000400;
																						}
																						if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																						{
																							if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2035)
																							{
																								data32 += 0x00000500;
																							}
																							if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																							{
																								if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2036)
																								{
																									data32 += 0x00000600;
																								}
																								if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																								{
																									if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2037)
																									{
																										data32 += 0x00000700;
																									}
																									if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																									{
																										if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2038)
																										{
																											data32 += 0x00000800;
																										}
																										if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																										{
																											if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2039)
																											{
																												data32 += 0x00000900;
																											}
																											if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																											{
																												if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2041)
																												{
																													data32 += 0x00000A00;
																												}
																												if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																												{
																													if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2042)
																													{
																														data32 += 0x00000B00;
																													}
																													if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																													{
																														if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2043)
																														{
																															data32 += 0x00000C00;
																														}
																														if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																														{
																															if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2044)
																															{
																																data32 += 0x00000D00;
																															}
																															if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																															{
																																if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2045)
																																{
																																	data32 += 0x00000E00;
																																}
																																if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																{
																																	if(Process::Read16(0x083AE782 , cmp16) && (cmp16 & 0xFFFF) == 0x2046)
																																	{
																																		data32 += 0x00000F00;
																																	}
																																	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																	{
																																		if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2030)
																																		{
																																			data32 += 0x00000000;
																																		}
																																		if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																		{
																																			if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2031)
																																			{
																																				data32 += 0x00000010;
																																			}
																																			if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																			{
																																				if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2032)
																																				{
																																					data32 += 0x00000020;
																																				}
																																				if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																				{
																																					if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2033)
																																					{
																																						data32 += 0x00000030;
																																					}
																																					if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																					{
																																						if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2034)
																																						{
																																							data32 += 0x00000040;
																																						}
																																						if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																						{
																																							if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2035)
																																							{
																																								data32 += 0x00000050;
																																							}
																																							if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																							{
																																								if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2036)
																																								{
																																									data32 += 0x00000060;
																																								}
																																								if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																								{
																																									if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2037)
																																									{
																																										data32 += 0x00000070;
																																									}
																																									if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																									{
																																										if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2038)
																																										{
																																											data32 += 0x00000080;
																																										}
																																										if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																										{
																																											if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2039)
																																											{
																																												data32 += 0x00000090;
																																											}
																																											if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																											{
																																												if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2041)
																																												{
																																													data32 += 0x000000A0;
																																												}
																																												if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																												{
																																													if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2041)
																																													{
																																														data32 += 0x000000A0;
																																													}
																																													if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																													{
																																														if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2042)
																																														{
																																															data32 += 0x000000B0;
																																														}
																																														if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																														{
																																															if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2043)
																																															{
																																																data32 += 0x000000C0;
																																															}
																																															if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																															{
																																																if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2044)
																																																{
																																																	data32 += 0x000000D0;
																																																}
																																																if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																{
																																																	if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2045)
																																																	{
																																																		data32 += 0x000000E0;
																																																	}
																																																	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																	{
																																																		if(Process::Read16(0x083AE784 , cmp16) && (cmp16 & 0xFFFF) == 0x2046)
																																																		{
																																																			data32 += 0x000000F0;
																																																		}
																																																		if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																		{
																																																			if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2030)
																																																			{
																																																				data32 += 0x00000000;
																																																			}
																																																			if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																			{
																																																				if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2031)
																																																				{
																																																					data32 += 0x00000001;
																																																				}
																																																				if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																				{
																																																					if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2032)
																																																					{
																																																						data32 += 0x00000002;
																																																					}
																																																					if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																					{
																																																						if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2033)
																																																						{
																																																							data32 += 0x00000003;
																																																						}
																																																						if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																						{
																																																							if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2034)
																																																							{
																																																								data32 += 0x00000004;
																																																							}
																																																							if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																							{
																																																								if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2035)
																																																								{
																																																									data32 += 0x00000005;
																																																								}
																																																								if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																								{
																																																									if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2036)
																																																									{
																																																										data32 += 0x00000006;
																																																									}
																																																									if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																									{
																																																										if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2037)
																																																										{
																																																											data32 += 0x00000007;
																																																										}
																																																										if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																										{
																																																											if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2038)
																																																											{
																																																												data32 += 0x00000008;
																																																											}
																																																											if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																											{
																																																												if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2039)
																																																												{
																																																													data32 += 0x00000009;
																																																												}
																																																												if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																												{
																																																													if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2041)
																																																													{
																																																														data32 += 0x0000000A;
																																																													}
																																																													if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																													{
																																																														if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2042)
																																																														{
																																																															data32 += 0x0000000B;
																																																														}
																																																														if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																														{
																																																															if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2043)
																																																															{
																																																																data32 += 0x0000000C;
																																																															}
																																																															if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																															{
																																																																if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2044)
																																																																{
																																																																	data32 += 0x0000000D;
																																																																}
																																																																if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																																{
																																																																	if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2045)
																																																																	{
																																																																		data32 += 0x0000000E;
																																																																	}
																																																																	if(Process::Read32(0x083AE77C , cmp32) && cmp32 == 0x206D7469)
																																																																	{
																																																																		if(Process::Read16(0x083AE786 , cmp16) && (cmp16 & 0xFFFF) == 0x2046)
																																																																		{
																																																																			data32 += 0x0000000F;
																																																																		}
																																																																		if(Controller::IsKeysDown(DPadRight + Y))
																																																																		{
																																																																			Process::Write16(offset + 0x08372392, data16);
																																																																			offset += 0x2;
																																																																			offset = 0x00000000;
																																																																			data32 = 0x00000000;
																																																																			Process::Write8(offset + 0x08372394 , 0x63);
																																																																			Process::Write32(offset + 0x083AE77C , 0x656E6F44);
																																																																			Process::Write32(offset + 0x083AE780 , 0x00000000);
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
//ハンターとにゃんたーを切り替え
void SwitchBetweenHunterAndNyanta(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeyDown(DPadUp))
	{
		Process::Write8(offset + 0x003237A8 , 0x01);
	}
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Write8(offset + 0x003237A8 , 0x00);
	}
}
//チャット乗っ取り
void ChatHijacking(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeysDown(DPadUp + ZR))
	{
		Process::Write32(offset + 0x0031B1C8 , 0x00000000);
	}
	if(Controller::IsKeysDown(DPadRight + ZR))
	{
		Process::Write32(offset + 0x0031B1C8 , 0x00000001);
	}
	if(Controller::IsKeysDown(DPadDown + ZR))
	{
		Process::Write32(offset + 0x0031B1C8 , 0x00000002);
	}
	if(Controller::IsKeysDown(DPadLeft + ZR))
	{
		Process::Write32(offset + 0x0031B1C8 , 0x00000003);
	}
}

//スピードハックオフ
void SpeedHackOff(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000BE0 , 0x3F800000);
	Process::Write32(offset + 0x00000BDC , 0x3F800000);
	Process::Write32(offset + 0x00000BD8 , 0x3F800000);
}
//スピードハックテスト
void SpeedHackTest(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001040 , 0x41000000);
	}
	offset = 0;
	data32 = 0;
	Process::Write32(0x0000C560 , 0x41000000);
}
//スピードハック
void SpeedHack(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001040 , 0x41000000);
	}
	offset = 0;
	data32 = 0;
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x0000C560 , 0x41000000);
	}
}
//スピードハック2
void SpeedHack2(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00001040 , 0x40450000);
	Process::Write32(offset + 0x0000C560 , 0x40450000);
}
//スローハック
void SlowHack(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001040 , 0x3F000000);
	}
	offset = 0;
	data32 = 0;
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x0000C560 , 0x3F000000);
	}
}
//スローハック2
void SlowHack2(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001040 , 0x3F400000);
	}
	offset = 0;
	data32 = 0;
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x0000C560 , 0x3F400000);
	}
}

//HR 721
void HR721(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x02D1);
}
//HR 810
void HR810(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x032A);
}
//HR 8585
void HR8585(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x2189);
}
//HR 4545
void HR4545(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x11C1);
}
//HR 1919
void HR1919(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x077F);
}
//HR 999
void HR999(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x03E7);
}
//HR 4
void HR4(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x0004);
}
//HR 65535
void HR65535(MenuEntry *entry)
{
	offset = 0x0831B76A;
	Process::Write16(offset + 0x00000000 , 0xFFFF);
}
//HR 1
void HR1(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x0001);
}
//HR 0
void HR0(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x0031B76A , 0x0000);
}

//ボスHP1(オフライン専用)
void BossHP1OfflineOnly(MenuEntry *entry)
{
	Process::Read32(0x08195384 , data32);
	offset = data32;
	Process::Write32(offset + 0x00001318 , 0x00000000);
	offset = 0;
	data32 = 0;
	Process::Read32(0x08195398 , data32);
	offset = data32;
	Process::Write32(offset + 0x00001318 , 0x00000000);
	offset = 0;
	data32 = 0;
	Process::Read32(0x08195380 , data32);
	offset = data32;
	Process::Write32(offset + 0x00001318 , 0x00000000);
	Process::Write32(offset + 0x0000D5C8 , 0x00000000);
	Process::Write32(offset + 0x0000C648 , 0x00000000);
}
//クエスト貼ってなくても行ける(オフ)
void YouCanGoWithoutPostingTheQuestOff(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeysDown(A + B))
	{
		Process::Write32(offset + 0x003665CC , 0x00000000);
	}
}
//クエスト貼ってなくても行ける
void YouCanGoWithoutPostingTheQuest(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeysDown(A + B))
	{
		Process::Write32(offset + 0x003665CC , 0x00000100);
	}
}
//クエスト連続リクエスト
void QuestContinuousRequest(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Read32(offset + 0x03665D0 , data32);
	data32 += 0x00000001;
	Process::Write32(offset + 0x03665D0 , data32);
	if(Process::Read32(offset + 0x003665D0 , cmp32) && cmp32 == 0x00010000)
	{
		Process::Write32(offset + 0x003665D0 , 0x00002775);
	}
}
//クエストリタイア
void QuestRetirement(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x00363ED4 , 0x00000000);
}
//ヘルジェイル
void HellJail(MenuEntry *entry)
{
	offset = 0x08363F00;
	if(Controller::IsKeysDown(DPadRight + L))
	{
		Process::Write32(offset + 0x00000000 , 0x00000004);
	}
}
//タイマー0
void Timer0(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x00363ED4 , 0x00000000);
}
//タイマー増える
void TimerIncreases(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Read32(offset + 0x0363ED4 , data32);
	data32 += 0x00000500;
	Process::Write32(offset + 0x0363ED4 , data32);
}
//タイマーコントローラー(早い)
void TimerControllerFast(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Read32(offset + 0x0363ED4 , data32);
		data32 += 0xFFFFBFFF;
		Process::Write32(offset + 0x0363ED4 , data32);
	}
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Read32(offset + 0x0363ED4 , data32);
		data32 += 0x00005000;
		Process::Write32(offset + 0x0363ED4 , data32);
	}
}
//タイマーコントローラー(普通)
void TimerControllerNormal(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Read32(offset + 0x0363ED4 , data32);
		data32 += 0xFFFFFF10;
		Process::Write32(offset + 0x0363ED4 , data32);
	}
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Read32(offset + 0x0363ED4 , data32);
		data32 += 0x000000F0;
		Process::Write32(offset + 0x0363ED4 , data32);
	}
}
//タイマーすぐ減る
void TimerWillDecreaseSoon(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Read32(offset + 0x0363ED4 , data32);
	data32 += 0xFFFFFBFF;
	Process::Write32(offset + 0x0363ED4 , data32);
}

//スキルスロット埋める
void FillSkillSlots(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Write16(offset + 0x0031B50C , 0x0001);
	}
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Write16(offset + 0x0031B510 , 0x0001);
	}
	if(Controller::IsKeyDown(DPadUp))
	{
		Process::Write16(offset + 0x0031B50E , 0x0001);
	}
}
//透明
void Transparent(MenuEntry *entry)
{
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00000068 , 0x3F800000);
		Process::Write32(offset + 0x00000064 , 0x3F800000);
		Process::Write32(offset + 0x00000060 , 0x3F800000);
		if(Controller::IsKeyDown(DPadRight))
		{
			Process::Read32(offset + 0x08195350 , data32);
			offset = data32;
			Process::Write32(offset + 0x00000068 , 0x3F800000);
			Process::Write32(offset + 0x00000064 , 0x00000000);
			Process::Write32(offset + 0x00000060 , 0x00000000);
		}
	}
}
//攻撃力1
void AttackPower1(MenuEntry *entry)
{
	Process::Write16(0x0831B450 , 0x0000);
}
//防御力1
void Defense1(MenuEntry *entry)
{
	Process::Write32(0x0831B45C , 0x00000000);
}
//防御力最高
void HighestDefense(MenuEntry *entry)
{
	Process::Write32(0x0831B45C , 0x79999999);
}
//攻撃力999
void AttackPower999(MenuEntry *entry)
{
	Process::Write16(0x0831B450 , 0x03E7);
}
//ボウガン連射
void CrossbowFiring(MenuEntry *entry)
{
	if(Controller::IsKeyDown(A))
	{
		Process::Write32(0x00000000 , 0x00000000);
		Process::Write16(0x0819428C , 0x0000);
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x0000024C , 0x00050501);
		Process::Write8(offset + 0x000025AA , 0x01);
	}
}
//スタミナ置き換え回復
void StaminaSuperFastRecovery(MenuEntry *entry)
{
Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000F5E , 0x00000096);
}
//HP置き換え回復
void HPSuperFastRecovery(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000F52 , 0x00000096)
}

//切れ味MAX
void SharpnessMAX(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		if(Controller::IsKeysDown(R + L))
		{
			Process::Write16(offset + 0x00002214 , 0xFFFF);
		}
	}
}
//乗りゲージ常にMAX
void RidingGaugeAlwaysMAX(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		if(Controller::IsKeyDown(A))
		{
			Process::Read32(offset + 0x0002C1A , data32);
			data32 += 0x00000010;
			Process::Write32(offset + 0x0002C1A , data32);
		}
	}
}
//HP0
void HP0(MenuEntry *entry)
{
	if(Process::Read32(0x08195350 , cmp32) && cmp32 != 0x00000000)
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Read32(offset + 0x0000F52 , data32);
		data32 += 0xFFFFFFFF;
		Process::Write32(offset + 0x0000F52 , data32);
	}
}

//カメラ視野強化
void CameraFieldOfViewEnhancement(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x001944C4 , 0x3F58B3D5);
	Process::Write32(offset + 0x001944B0 , 0x3F000580);
}
//カメラ視野微強化
void CameraFieldOfViewSlightlyEnhanced(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x001944C4 , 0x3F98B3D5);
	Process::Write32(offset + 0x001944B0 , 0x3F400580);
}
//カメラハック1
void CameraHack1(MenuEntry *entry)
{
	offset = 0x08000000;
	if(Controller::IsKeysDown(R + L))
	{
		Process::Write32(offset + 0x00194484 , 0x3F758F72);
		Process::Write32(offset + 0x00194488 , 0xBE90B8E0);
	}
}
//カメラハック
void CameraHack(MenuEntry *entry)
{
	Process::Write32(0x081944A4 , 0x414FA06C);
	Process::Write32(0x081944A8 , 0xC51884BD);
}
//エブリシングビュアー
void EverythingViewer(MenuEntry *entry)
{
	offset = 0x08000000;
	//floatmode:on
	Process::ReadFloat(offset + 0x01944A4 , dataf);
	dataf += -512;
	Process::WriteFloat(offset + 0x01944A4 , dataf);
	Process::ReadFloat(offset + 0x01944A8 , dataf);
	dataf += -2128;
	Process::WriteFloat(offset + 0x01944A8 , dataf);
}
//スーパーアイ
void SuperEye(MenuEntry *entry)
{
	offset = 0x08000000;
	//floatmode:on
	Process::ReadFloat(offset + 0x01944A4 , dataf);
	dataf += -128;
	Process::WriteFloat(offset + 0x01944A4 , dataf);
	Process::ReadFloat(offset + 0x01944A8 , dataf);
	dataf += -532;
	Process::WriteFloat(offset + 0x01944A8 , dataf);
}
//FPS視点(V3)
void FPSViewpointV3(MenuEntry *entry)
{
	offset = 0x08000000;
	//floatmode:on
	Process::ReadFloat(offset + 0x01944A4 , dataf);
	dataf += -8;
	Process::WriteFloat(offset + 0x01944A4 , dataf);
	Process::ReadFloat(offset + 0x01944A8 , dataf);
	dataf += 532;
	Process::WriteFloat(offset + 0x01944A8 , dataf);
	offset = 0x08000000;
	Process::Write32(offset + 0x001944C4 , 0x3FF8B3D5);
	Process::Write32(offset + 0x001944B0 , 0x3F900580);
}
//FPS視点(V2)
void FPSViewpointV2(MenuEntry *entry)
{
	offset = 0x08000000;
	//floatmode:on
	Process::ReadFloat(offset + 0x01944A4 , dataf);
	dataf += 8;
	Process::WriteFloat(offset + 0x01944A4 , dataf);
	Process::ReadFloat(offset + 0x01944A8 , dataf);
	dataf += 512;
	Process::WriteFloat(offset + 0x01944A8 , dataf);
	Process::Write32(offset + 0x001944C4 , 0x3F78B3D5);
	Process::Write32(offset + 0x001944B0 , 0x3F200580);
	offset = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Process::Read32(offset + 0x00001040 , cmp32) && cmp32 == 0x3F800000)
	{
		offset = 0x08000000;
		//floatmode:on
		Process::ReadFloat(offset + 0x01944A8 , dataf);
		dataf += 13;
		Process::WriteFloat(offset + 0x01944A8 , dataf);
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Process::Read32(offset + 0x00001040 , cmp32) && cmp32 == 0x3FA00000)
	{
		offset = 0x08000000;
		//floatmode:on
		Process::ReadFloat(offset + 0x01944A8 , dataf);
		dataf += 128;
		Process::WriteFloat(offset + 0x01944A8 , dataf);
		Process::Write32(offset + 0x001944C4 , 0x3F58B3D5);
		Process::Write32(offset + 0x001944B0 , 0x3F000580);
	}
}
//FPS視点(V1)
void FPSViewpointV1(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x0000000F , 0x00000000);
	Process::Read32(offset + 0x00000044, data32);
	Process::Write32(offset + 0x081944A4, data32);
	offset += 0x4;
	offset = 0;
	data32 = 0;
	offset = 0x08000000;
	Process::Write32(offset + 0x001944C4 , 0x3F98B3D5);
	Process::Write32(offset + 0x001944B0 , 0x3F400580);
	//floatmode:on
	Process::ReadFloat(offset + 0x01944A4 , dataf);
	dataf += 13;
	Process::WriteFloat(offset + 0x01944A4 , dataf);
	Process::ReadFloat(offset + 0x01944A8 , dataf);
	dataf += 510;
	Process::WriteFloat(offset + 0x01944A8 , dataf);
}
//龍歴院ポイント無限
void RyujiinPointInfinite(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x003B3820 , 0x3B9AC9FF);
}
//お金無限
void MoneyInfinity(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x003B3818 , 0x3B9AC9FF);
}
//ポーチを空にする
void EmptyPouch(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x00372390 , 0x00000000);
	Process::Write32(offset + 0x00372394 , 0x00000000);
	Process::Write32(offset + 0x00372398 , 0x00000000);
	Process::Write32(offset + 0x0037239C , 0x00000000);
	Process::Write32(offset + 0x003723A0 , 0x00000000);
	Process::Write32(offset + 0x003723A4 , 0x00000000);
	Process::Write32(offset + 0x003723A8 , 0x00000000);
	Process::Write32(offset + 0x003723AC , 0x00000000);
	Process::Write32(offset + 0x003723D8 , 0x00000000);
	Process::Write32(offset + 0x003723DC , 0x00000000);
	Process::Write32(offset + 0x003723B0 , 0x00000000);
	Process::Write32(offset + 0x003723B4 , 0x00000000);
	Process::Write32(offset + 0x003723B8 , 0x00000000);
	Process::Write32(offset + 0x003723BC , 0x00000000);
	Process::Write32(offset + 0x003723C0 , 0x00000000);
	Process::Write32(offset + 0x003723C4 , 0x00000000);
	Process::Write32(offset + 0x003723C8 , 0x00000000);
	Process::Write32(offset + 0x003723CC , 0x00000000);
	Process::Write32(offset + 0x003723D0 , 0x00000000);
	Process::Write32(offset + 0x003723D4 , 0x00000000);
	Process::Write32(offset + 0x003723D8 , 0x00000000);
	Process::Write32(offset + 0x003723DC , 0x00000000);
	Process::Write32(offset + 0x003723E0 , 0x00000000);
	Process::Write32(offset + 0x003723E4 , 0x00000000);
	Process::Write32(offset + 0x003723E8 , 0x00000000);
	Process::Write32(offset + 0x003723EC , 0x00000000);
	Process::Write16(offset + 0x003723F0 , 0x0000);
}
//バグアイテムセット
void BugItemSet(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x00372390 , 0x005C0001);
	Process::Write32(offset + 0x00372394 , 0x07890001);
	Process::Write32(offset + 0x00372398 , 0x078A0001);
	Process::Write32(offset + 0x0037239C , 0x078B0001);
	Process::Write32(offset + 0x003723A0 , 0x078C0001);
	Process::Write32(offset + 0x003723A4 , 0x078D0001);
	Process::Write32(offset + 0x003723A8 , 0x078E0001);
	Process::Write32(offset + 0x003723AC , 0x078F0001);
	Process::Write32(offset + 0x003723D8 , 0x07900001);
	Process::Write32(offset + 0x003723DC , 0x07910001);
	Process::Write32(offset + 0x003723B0 , 0x07920001);
	Process::Write32(offset + 0x003723B4 , 0x07930001);
	Process::Write32(offset + 0x003723B8 , 0x07940001);
	Process::Write32(offset + 0x003723BC , 0x07950001);
	Process::Write32(offset + 0x003723C0 , 0x07960001);
	Process::Write32(offset + 0x003723C4 , 0x07970001);
	Process::Write32(offset + 0x003723C8 , 0x07980001);
	Process::Write32(offset + 0x003723CC , 0x07990001);
	Process::Write32(offset + 0x003723D0 , 0x079A0001);
	Process::Write32(offset + 0x003723D4 , 0x079B0001);
	Process::Write32(offset + 0x003723D8 , 0x079C0001);
	Process::Write32(offset + 0x003723DC , 0x07880001);
	Process::Write32(offset + 0x003723E0 , 0x00CC0001);
	Process::Write32(offset + 0x003723E4 , 0x00CD0001);
}
//ポーチのアイテム無限
void InfiniteItemsOnThePouch(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x00372390 , 0x0063);
	Process::Write16(offset + 0x00372394 , 0x0063);
	Process::Write16(offset + 0x00372398 , 0x0063);
	Process::Write16(offset + 0x0037239C , 0x0063);
	Process::Write16(offset + 0x003723A0 , 0x0063);
	Process::Write16(offset + 0x003723A4 , 0x0063);
	Process::Write16(offset + 0x003723A8 , 0x0063);
	Process::Write16(offset + 0x003723AC , 0x0063);
	Process::Write16(offset + 0x003723D8 , 0x0063);
	Process::Write16(offset + 0x003723DC , 0x0063);
	Process::Write16(offset + 0x003723B0 , 0x0063);
	Process::Write16(offset + 0x003723B4 , 0x0063);
	Process::Write16(offset + 0x003723B8 , 0x0063);
	Process::Write16(offset + 0x003723BC , 0x0063);
	Process::Write16(offset + 0x003723C0 , 0x0063);
	Process::Write16(offset + 0x003723C4 , 0x0063);
	Process::Write16(offset + 0x003723C8 , 0x0063);
	Process::Write16(offset + 0x003723CC , 0x0063);
	Process::Write16(offset + 0x003723D0 , 0x0063);
	Process::Write16(offset + 0x003723D4 , 0x0063);
	Process::Write16(offset + 0x003723D8 , 0x0063);
	Process::Write16(offset + 0x003723DC , 0x0063);
	Process::Write16(offset + 0x003723E0 , 0x0063);
	Process::Write16(offset + 0x003723E4 , 0x0063);
	Process::Write16(offset + 0x003723E8 , 0x0063);
	Process::Write16(offset + 0x003723EC , 0x0063);
	Process::Write16(offset + 0x003723F0 , 0x0063);
}
//開発者お気に入りアイテムセット
void DeveloperFavoriteItemSet(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x00372390 , 0x00010001);
	Process::Write32(offset + 0x00372394 , 0x00020001);
	Process::Write32(offset + 0x00372398 , 0x00030001);
	Process::Write32(offset + 0x0037239C , 0x00040001);
	Process::Write32(offset + 0x003723A0 , 0x00050001);
	Process::Write32(offset + 0x003723A4 , 0x01200001);
	Process::Write32(offset + 0x003723A8 , 0x00480063);
	Process::Write32(offset + 0x003723AC , 0x00FC000A);
	Process::Write32(offset + 0x003723D8 , 0x00050001);
	Process::Write32(offset + 0x003723DC , 0x00060001);
	Process::Write32(offset + 0x003723B0 , 0x00310001);
	Process::Write32(offset + 0x003723B4 , 0x0037000A);
	Process::Write32(offset + 0x003723B8 , 0x001A000A);
	Process::Write32(offset + 0x003723BC , 0x0017000A);
	Process::Write32(offset + 0x003723C0 , 0x0018000A);
	Process::Write32(offset + 0x003723C4 , 0x003A000A);
	Process::Write32(offset + 0x003723C8 , 0x003D0005);
	Process::Write32(offset + 0x003723CC , 0x00420005);
	Process::Write32(offset + 0x003723D0 , 0x00590063);
	Process::Write32(offset + 0x003723D4 , 0x00520002);
	Process::Write32(offset + 0x003723D8 , 0x00530001);
	Process::Write32(offset + 0x003723DC , 0x00100001);
	Process::Write32(offset + 0x003723E0 , 0x00FD000A);
	Process::Write32(offset + 0x003723E4 , 0x00FE000A);
	Process::Write32(offset + 0x003723E8 , 0x00FF000A);
	Process::Write32(offset + 0x003723EC , 0x001D000A);
	Process::Write16(offset + 0x003723F0 , 0x0002);
}
//マップいつでも表示
void MapAlwaysDisplayed(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write16(offset + 0x00372436 , 0x0444);
	Process::Write16(offset + 0x00372438 , 0x0001);
}
//ピン開発者お気に入りセット
void PinDeveloperFavoriteSet(MenuEntry *entry)
{
	offset = 0x08000000;
	Process::Write32(offset + 0x003723F0 , 0x006C0063);
	Process::Write32(offset + 0x003723F4 , 0x006F0063);
	Process::Write32(offset + 0x003723F8 , 0x00690063);
	Process::Write32(offset + 0x003723FC , 0x00D50063);
	Process::Write32(offset + 0x00372400 , 0x067F0063);
	Process::Write32(offset + 0x00372404 , 0x00D80063);
	Process::Write32(offset + 0x00372408 , 0x007A0063);
	Process::Write32(offset + 0x0037240C , 0x00760063);
	Process::Write16(offset + 0x00372410 , 0x0063);
}

//クレイジーウォーク(ボタン割り当てなし)
void CrazyWalkNoButtonAssignment(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Read32(offset + 0x0000C9C , data32);
	data32 += 0x00003000;
	Process::Write32(offset + 0x0000C9C , data32);
	Process::Read32(offset + 0x0001020 , data32);
	data32 += 0x00003000;
	Process::Write32(offset + 0x0001020 , data32);
}
//クレイジージャンプ
void CrazyJump(MenuEntry *entry)
{
	if(Process::Read32(0x00101248 , cmp32) && cmp32 < 0x00000049)
	{
		Process::Read32(0x0101248 , data32);
		data32 += 0x00000001;
		Process::Write32(0x0101248 , data32);
	}
	data32 = 0;
	if(Controller::IsKeyDown(B))
	{
		if(Process::Read32(0x00101248 , cmp32) && cmp32 == 0x00000050)
		{
			Process::Read32(0x0000C9C , data32);
			data32 += 0x00003000;
			Process::Write32(0x0000C9C , data32);
			Process::Read32(0x0001020 , data32);
			data32 += 0x00003000;
			Process::Write32(0x0001020 , data32);
		}
	}
}
//クレイジーウォーク(ボタンあり)
void CrazyWalkWithButton(MenuEntry *entry)
{
	if(Controller::IsKeysDown(R + Y))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Read32(offset + 0x0000C9C , data32);
		data32 += 0x00003000;
		Process::Write32(offset + 0x0000C9C , data32);
		Process::Read32(offset + 0x0001020 , data32);
		data32 += 0x00003000;
		Process::Write32(offset + 0x0001020 , data32);
	}
}
//バルスライド(バルファルク)
void BalslideBalfalk(MenuEntry *entry)
{
	if(Controller::IsKeyDown(R))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x000002F8 , 0xC0000000);
	}
}
//バルフライ(バルファルク:テスト段階)
void BalflyBalfalkTestStage(MenuEntry *entry)
{
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Read32(offset + 0x0001020 , data32);
		data32 += 0x00000500;
		Process::Write32(offset + 0x0001020 , data32);
		Process::Read32(offset + 0x0000C9C , data32);
		data32 += 0x00000500;
		Process::Write32(offset + 0x0000C9C , data32);
	}
	offset = 0;
	data32 = 0;
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Read32(offset + 0x0001020 , data32);
		data32 += 0xFFFFFAFF;
		Process::Write32(offset + 0x0001020 , data32);
		Process::Read32(offset + 0x0000C9C , data32);
		data32 += 0xFFFFFAFF;
		Process::Write32(offset + 0x0000C9C , data32);
	}
	offset = 0;
	data32 = 0;
	Process::Read32(0x00101248, data32);
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000044, data32);
	offset += 0x4;
	offset = 0;
	data32 = 0;
	if(Controller::IsKeyDown(DPadUp))
	{
		//floatmode:on
		Process::ReadFloat(0x0101248 , dataf);
		dataf += 52;
		Process::WriteFloat(0x0101248 , dataf);
	}
	dataf = 0;
	if(Controller::IsKeyDown(DPadDown))
	{
		//floatmode:on
		Process::ReadFloat(0x0101248 , dataf);
		dataf += -52;
		Process::WriteFloat(0x0101248 , dataf);
	}
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeyDown(L))
	{
		Process::Read32(offset + 0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001FE0 , 0x0040BD04);
		Process::Write32(offset + 0x00001FE4 , 0x00050010);
	}
}
//バルフライ v2(バルファルク)
void BalflyV2Balfalk(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + X))
	{
		Process::Write32(offset + 0x00001FE4 , 0x005A0001);
	}
	if(Controller::IsKeysDown(A + R))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += 208;
		Process::WriteFloat(offset + 0x0000044 , dataf);
		
	}
	if(Controller::IsKeysDown(R + L))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += -208;
		Process::WriteFloat(offset + 0x0000044 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	if(Controller::IsKeysDown(R + Y))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x000002F8 , 0xC406A3E9);
	}
	if(Controller::IsKeysDown(DPadLeft + R))
	{
		Process::Read32(offset + 0x0000C9C , data32);
		data32 += 0x00000500;
		Process::Write32(offset + 0x0000C9C , data32);
		Process::Read32(offset + 0x0001020 , data32);
		data32 += 0x00000500;
		Process::Write32(offset + 0x0001020 , data32);
	}
	if(Controller::IsKeysDown(DPadRight + R))
	{
		Process::Read32(offset + 0x0000C9C , data32);
		data32 += 0xFFFFFAFF;
		Process::Write32(offset + 0x0000C9C , data32);
		Process::Read32(offset + 0x0001020 , data32);
		data32 += 0xFFFFFAFF;
		Process::Write32(offset + 0x0001020 , data32);
	}
	offset = 0;
	data32 = 0;
	if(Controller::IsKeysDown(B + R))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x000002F8 , 0x4406A3E9);
	}
}
//自動走行
void AutomaticDriving(MenuEntry *entry)
{
	if(Controller::IsKeyDown(L))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001FE4 , 0x00000000);
	}
	offset = 0;
	data32 = 0;
	if(Controller::IsKeyDown(R))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		Process::Write32(offset + 0x00001FE4 , 0x00030002);
	}
	offset = 0;
	data32 = 0;
	if(Controller::IsKeyDown(DPadLeft))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		if(Process::Read32(offset + 0x00001FE4 , cmp32) && cmp32 == 0x00030002)
		{
			Process::Read32(offset + 0x0000C9C , data32);
			data32 += 0x00000500;
			Process::Write32(offset + 0x0000C9C , data32);
			Process::Read32(offset + 0x0001020 , data32);
			data32 += 0x00000500;
			Process::Write32(offset + 0x0001020 , data32);
		}
	}
	offset = 0;
	data32 = 0;
	if(Controller::IsKeyDown(DPadRight))
	{
		Process::Read32(0x08195350 , data32);
		offset = data32;
		if(Process::Read32(offset + 0x00001FE4 , cmp32) && cmp32 == 0x00030002)
		{
			Process::Read32(offset + 0x0000C9C , data32);
			data32 += 0xFFFFFAFF;
			Process::Write32(offset + 0x0000C9C , data32);
			Process::Read32(offset + 0x0001020 , data32);
			data32 += 0xFFFFFAFF;
			Process::Write32(offset + 0x0001020 , data32);
		}
	}
}
//ベースキャンプテレポート
void BaseCampTeleport(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00001FE4 , 0x00110001);
}
//ジャンプ
void Jump(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeyDown(L))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += 52;
		Process::WriteFloat(offset + 0x0000044 , dataf);
	}
	if(Controller::IsKeyDown(DPadDown))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += -52;
		Process::WriteFloat(offset + 0x0000044 , dataf);
	}
}
//ムーンジャンプ
void MoonJump(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeyDown(L))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += 128;
		Process::WriteFloat(offset + 0x0000044 , dataf);
	}
	if(Controller::IsKeyDown(DPadDown))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000044 , dataf);
		dataf += -128;
		Process::WriteFloat(offset + 0x0000044 , dataf);
	}
}
//NPCの会話中カメラズームされない
void CameraDoesNotZoomDuringNPCConversation(MenuEntry *entry)
{
	Process::Read32(0x081943DC , data32);
	offset = data32;
	Process::Write32(offset + 0x000005BC , 0x00000000);
}
//座標移動(遅め)
void CoordinateMovementSlow(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadDown))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000048 , dataf);
		dataf += 32;
		Process::WriteFloat(offset + 0x0000048 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadUp))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000048 , dataf);
		dataf += -32;
		Process::WriteFloat(offset + 0x0000048 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadRight))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000040 , dataf);
		dataf += 32;
		Process::WriteFloat(offset + 0x0000040 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadLeft))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000040 , dataf);
		dataf += -32;
		Process::WriteFloat(offset + 0x0000040 , dataf);
	}
}
//座標移動(早め)
void CoordinateMovementEarly(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadDown))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000048 , dataf);
		dataf += 128;
		Process::WriteFloat(offset + 0x0000048 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadUp))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000048 , dataf);
		dataf += -128;
		Process::WriteFloat(offset + 0x0000048 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadRight))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000040 , dataf);
		dataf += 128;
		Process::WriteFloat(offset + 0x0000040 , dataf);
		
	}
	offset = 0;
	data32 = 0;
	dataf = 0;
	Process::Read32(0x08195350 , data32);
	offset = data32;
	if(Controller::IsKeysDown(R + CPadLeft))
	{
		//floatmode:on
		Process::ReadFloat(offset + 0x0000040 , dataf);
		dataf += -128;
		Process::WriteFloat(offset + 0x0000040 , dataf);
	}
}
//スピードハックv2
void SpeedHackV2(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000BE0 , 0x41000000);
	Process::Write32(offset + 0x00000BDC , 0x41000000);
	Process::Write32(offset + 0x00000BD8 , 0x41000000);
}
//スピードハックV2(遅め)
void SpeedHackV2Slow(MenuEntry *entry)
{
	Process::Read32(0x08195350 , data32);
	offset = data32;
	Process::Write32(offset + 0x00000BE0 , 0x40000000);
	Process::Write32(offset + 0x00000BDC , 0x40000000);
	Process::Write32(offset + 0x00000BD8 , 0x40000000);
}

}
