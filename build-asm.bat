@echo off

.\customasm.exe -f binary -o XRCS.bin -s XRCS.sym.txt XRCS.def.asm xrcs-lib/kernel.asm
.\customasm.exe -f annotated -o XRCS.txt XRCS.def.asm xrcs-lib/kernel.asm
.\customasm.exe -f hexdump -o XRCS.dump.txt XRCS.def.asm xrcs-lib/kernel.asm