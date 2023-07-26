# reGS
![reGS_WONbg](https://github.com/ScriptedSnark/reGS_WON/assets/51358194/0ab64f4a-50a2-4ccc-a931-5277f2ad7e39)

Reverse-engineered GoldSrc (738 build / WON). **Based on [HL SDK 1.0](https://github.com/a1batross/HLSDK_ancient)**.

## Current projects

All projects oriented on [738 build of Half-Life](https://www.betaarchive.com/wiki/index.php?title=Half-Life/build_738).

Original `version` output (hw):
<pre>
Build 738
Exe: 21:52:31 Nov  1 1998
</pre>

- cl_dll (client.dll) | Status: Finished (seems like it's finished but I think some inconsistencies exist)
- hw (hw.dll) | Status: WIP (doing researches)

## Future projects

- hl | Server
- sw | Software engine
- launcher | Launcher. Contains GUI.

## Building

This project is for Windows 32-bit systems only.

### Visual Studio 2022
1. Install [Visual Studio 2022](https://visualstudio.microsoft.com/en-us/vs/). In the Visual Studio Installer, select Desktop Development for C++.
2. Open Visual Studio.
3. On the starting screen, click "Clone or check out code".
4. Enter `https://github.com/ScriptedSnark/reGS_WON.git` and press the Clone button. Wait for the process to finish.
5. Choose Debug or Release configuration. You can build the workspace using Build→Build All. If you want to build only client or something else, right click on wanted project (for example, `cl_dll`) and select Build.
