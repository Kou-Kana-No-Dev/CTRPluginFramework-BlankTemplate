#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  const Screen &top_screen = OSD::GetTopScreen();
  const Screen &top_screen2 = OSD::GetTopScreen();
  std::string logo = "Black Out";
  std::string logo2;
  u32 x = 1;
  u32 y = 1;
  u32 x2 = 1;
  u32 y2 = 21;
  int slct;
  int opned;
  int oneunce;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  if (oneunce == 0) {
  logo2 = "ver 0.1";
  top_screen.Draw(logo, x, y, foreground, background);
  top_screen2.Draw(logo2, x2, y2, foreground, background);
  oneunce = 1;
  }else{
  	if((Controller::IsKeysPressed(L)) && (opned = 0)) {
  	  slct = 0;
      logo2 = "World";
      top_screen2.Draw(logo2, x2, y2, foreground, background);
      opned =1;
  	}else{
  	  logo2 = "ver 0.1";
  	  top_screen2.Draw(logo2, x2, y2, foreground, background);
  	  opned = 0;
  	}
  	if(Controller::IsKeysPressed(Right)) {
  	  slct++;
  	  if(slct ==-1) {
  	    slct = 4;
  	  }
  	  if(slct == 4) {
  	    slct =0;
  	  }
  	  if(slct == 0){
  	    logo2="World";
  	  }
  	  if(slct == 1){
  	    logo2="Combat";
  	  }
  	  if(slct == 2){
  	    logo2="Player";
  	  }
  	  if(slct == 3){
  	    logo2="Movement";
  	  }
  	}
  	if(Controller::IsKeysPressed(Left)) {
  	  slct += -1;
  	  if(slct ==-1) {
  	    slct = 4;
  	  }
  	  if(slct == 4) {
  	    slct =0;
  	  }
  	  if(slct == 0){
  	    logo2="World";
  	  }
  	  if(slct == 1){
  	    logo2="Combat";
  	  }
  	  if(slct == 2){
  	    logo2="Player";
  	  }
  	  if(slct == 3){
  	    logo2="Movement";
  	  }
  	}
  }
}
}  // namespace CTRPluginFramework