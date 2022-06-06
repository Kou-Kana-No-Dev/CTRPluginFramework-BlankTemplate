#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework {
void ludora(MenuEntry* entry) {
 const std::string ldcl = "" << Color::Red << ""; //色
 const std::string ldcl2 = "" << Color::Orange << ""; //色2
  std::string ludoralog = "Start ludora"; //ログの役割
  std::string ludorax; //何を書き込んだのか確認、
  u16 hatehr; //HRを書き換える時に使用
  u16 hateatk; //攻撃力を書き換える時に使用
  u16 hatedfc; //防御力を書き換える時に使用
  u16 hateabl; //属性値を書き換える時に使用
  u16 rnd; //ランダム変数をintからこっちに移動する
  int rndst; //ランダム変数を作成
  while (ludorax != "Fend") {
    if (!GetInput(ludorax, ludoralog + "\n>>")) {
      return;
    }
    ludoralog += ("\n" + ludorax);
    if (ludorax == "atk") {
      ludoralog += ("\nATK >> please enter()");
      if (!GetInput(hateatk, ludoralog + "\n>>")) {
      }
      Process::Write16(0x008F1C0C , hateatk);
      Process::Write16(0x0831B450 , hateatk);
    }
    if (ludorax == "hr") {
      ludoralog += ("\nHR >> please enter");
      if (!GetInput(hatehr, ludoralog + "\n>>")) {
      }
      Process::Write16(0x0831B76A , hatehr);
    }
    if (ludorax == "dfc") {
      ludoralog += ("\nDFC >> please enter");
      if (!GetInput(hatedfc, ludoralog + "\n>>")) {
      }
      Process::Write16(0x0831B45E , hatedfc);
    }
    if (ludorax == "abl") {
      ludoralog += ("\nABL >> please enter");
      if (!GetInput(hateabl, ludoralog + "\n>>")) {
      }
      Process::Write16(0x0831B45A , hateabl);
    }
    if (ludorax == "rnd") {
      rndst = int(rand);
      while (rndst > 32766) {
        rndst = (rndst - 32766);
      }
      rnd = rndst;
      ludoralog += ("\nrnd Success");
      ludorax = ("");
    }
    if (ludorax == "atkn2rnd") {
      ludoralog += ("\nATK :" + rnd);
      Process::Write16(0x008F1C0C , rnd);
      Process::Write16(0x0831B450 , rnd);
      ludorax = ("");
     }
    if (ludorax == "dfcn2rnd") {
      ludoralog += ("\nDFC :" + rnd);
      Process::Write16(0x0831B45E , rnd);
      ludorax = ("");
    }
    if (ludorax == "abln2rnd") {
      ludoralog += ("\nABL :" + rnd);
      Process::Write16(0x0831B45A , rnd);
      ludorax = ("");
  }
    if (ludorax == "hrn2rnd") {
      ludoralog += ("\nHR :" + rnd);
      Process::Write16(0x0831B76A , rnd);
      ludorax = ("");
     }
}
}
}  // namespace CTRPluginFramework
