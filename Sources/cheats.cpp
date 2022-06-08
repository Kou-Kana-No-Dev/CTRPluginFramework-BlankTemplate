#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
  if (antiLoop == 0) {
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
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  top_screen.Draw(logo, x, y, foreground, background);
  int antiLoop = 1;
  }
  if(Controller::IsKeysPressed(L)) {
    opned++;
    if (opned ==2) {
     opned =0; 
    }
  }
  if(opned==1) {
  	slct = 0;
    logo2 = "World";
    top_screen2.Draw(logo2, x2, y2, foreground, background);
  }
  if(opned == 0);
  
  }
  if((Controller::IsKeysPressed(Right)) && (opned == 1)) {
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
  	  top_screen2.Draw(logo2, x2, y2, foreground, background);
  	}
  if((Controller::IsKeysPressed(Left)) && (opned == 1)) {
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
  	  top_screen2.Draw(logo2, x2, y2, foreground, background);
  	}
}
}  // namespace CTRPluginFramework