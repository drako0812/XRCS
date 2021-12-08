#! /bin/bash

# # Preprocess source files
#cpp -E -H -Wall -traditional-cpp -undef -CC -P -nostdinc -isystem ./xrcs-lib -o XRCS.pp.asm xrcs-lib/kernel.asm

# # Further process because of needing newlines in macro exspansions
#sed -i -e 's/__NEWLINE__/\n/g' XRCS.pp.asm

# Assemble preprocessed sources
./customasm.exe -f binary -o XRCS.bin -s XRCS.sym.txt ./xrcs-lib/kernel.asm
./customasm.exe -f annotated -o XRCS.txt ./xrcs-lib/kernel.asm
./customasm.exe -f hexdump -o XRCS.dump.txt ./xrcs-lib/kernel.asm