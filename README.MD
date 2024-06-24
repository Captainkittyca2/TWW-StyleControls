# TWW-Style Controls
A "The Legend of Zelda: Twilight Princess" mod that modifies aspects of Twilight Princess to work more like "The Wind Waker", a GameCube Zelda game.

`Currently supports most GameCube and Wii versions of Twilight Princess`

## Modified/Added features

* Crouching: Hold R button to crouch.
* L-Targeting: Player doesn't aim his shield automatically when L-Targeting, instead have to hold down R button after L-Targeting to aim shield.
* Cucco item: Modfiied normal bombs so that Player takes out Cucco when in mid-air and can glide. When in the ground, player will take out bomb.
* Armors Quick-Toggle returns from [ALBW-Style Meter mod](https://github.com/Captainkittyca2/TP_ALBWStyleMeter)!
* Shield-Crouching: Hold R button while holding an item/sword to shield-crouch.

## Known Major Issues
* If Player takes Cucco out after Link enters screaming state when falling, he can't glide.
* If player voids out while still holding Cucco item, game might crash.
* In some conditions, Link won't be able to press R to interact with things because he will crouch. One possible workaround is L-targeting before interacting with those things (GC issue only)

## Clips
### Crouching
| Twilight Princess                            | The Wind Waker                            |
| ----------------------------------- | ----------------------------------- |
| ![](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/crouchTP.gif) | ![image](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/crouchTWW.gif) |
### L-Targeting
| Twilight Princess                            | The Wind Waker                            |
| ----------------------------------- | ----------------------------------- |
| ![](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/LltargetingTP.gif) | ![image](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/LltargetingTWW.gif) |
### Deku Leaf
| Twilight Princess                            | The Wind Waker                            |
| ----------------------------------- | ----------------------------------- |
| ![](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/glideTP.gif) | ![image](https://github.com/Captainkittyca2/tp/blob/TWW-Style_Controls/GIFs/glideTWW.gif) |
### Armors Quick-toggle (ignore meter)
| Kokiri->Zora                            | Kokiri->Armor                            |
| ----------------------------------- | ----------------------------------- |
| ![](https://github.com/Captainkittyca2/TP_ALBWStyleMeter/blob/main/GIFs/KokiriToZora.gif) | ![](https://github.com/Captainkittyca2/TP_ALBWStyleMeter/blob/main/GIFs/KokiriToArmor.gif) |

## Building
---
**Repository**

*You need to have git installed ([windows](https://git-scm.com/download/win))*

Open a CMD and navigate to where you want your code to be:
```
C:\>mkdir Code
C:\>cd Code
C:\Code>git clone https://github.com/zsrtp/REL.git
Cloning into REL
remote: Enumerating objects: 132, done.
remote: Counting objects: 100% (132/132), done.
remote: Compressing objects: 100% (87/87), done.
remote: Total 132 (delta 56), reused 98 (delta 29), pack-reused 0
Receiving objects: 100% (132/132), 1.24 MiB | 6.45 MiB/s, done.
Resolving deltas: 100% (56/56), done.
```
Download and upate libtp_rel
```
C:\Code\REL> git submodule update --init --remote
```
Done.

**Dependencies**
  * DevkitPPC comes with [devkitPro](//github.com/devkitPro/installer/releases)
  * [Python3](//www.python.org/downloads) (should be added to PATH or you will likely need Makefile adjustments)
  * [pycryptodomex](https://pypi.org/project/pycryptodomex/) (For Wii only, dependency of [`nandpack.py`](https://github.com/kipcode66/wii_tools))
  * Optional: [Visual Studio Code](//code.visualstudio.com) with [GC Settings](//wiki.tprandomizer.com/index.php?title=Dev:Visual_Studio_Code)

**Compiling**

*devkitPro comes with its own MSys2 shell, it is recommended to use it for compilation.

This is an example of how to build for the NTSC-U version of the Game
```shell
$ cd /c/Path/To/REL
$ make us
main.cpp
cxx.cpp
memory.cpp
patch.cpp
rel.cpp
tools.cpp
timer.cpp
stages.cpp
console.cpp
card.cpp
color_utils.cpp
texture_utils.cpp
restfpr_x.s
restgpr_x.s
linking ... REL.us.elf
output ... REL.us.rel
packing ... REL.us.gci
```
The `REL.us.gci` (`REL.wus0.bin` for wii) (other versions are: `jp`, `eu`, `wus0`, `wus2`, `wjp`, and `weu`, as well as two other build target `gcn` and `wii` which build all the version for the specified platform) file is now containing our custom REL. Load it with the REL Loader cheat or a hacked save file that contains the loader, both of which can be found on the wiki [REL Loader](//wiki.tprandomizer.com/index.php?title=REL_Loader) page.

##### Injecting into an existing Wii save

If you wish to inject the mod into an existing Wii save instead of generating an empty save, you can use the `nandpack.py` script to do that. Here is an example:

```shell
$ ./bin/nandpack.py inject -i 3 -g us0 -f "REL Example" REL.wus0.rel data.bin REL.wus0.bin
```

Where:
- `-i 3`: inject the mod into the 3rd slot.
- `-g us0`: specify we're injecting into an NTSCU 1.0 save.
- `-f "REL Example"`: set the name of the slot to `REL Example`
- `REL.wus0.rel`: this is the file containing the mod itself that we want to inject into the save.
- `data.bin`: this is the save file we want to inject the mod into.
- `REL.wus0.bin`: this is the resulting save file with the mod injected into it.

---
This mod is powered by [libtp_rel](//github.com/zsrtp/libtp_rel) and licensed under [GPLv3](/LICENSE) | (C) [AECX](//github.com/AECX), [LunarSoap](//github.com/lunarsoap5), [Zephiles](//github.com/Zephiles), [kipcode66](//github.com/kipcode66)
