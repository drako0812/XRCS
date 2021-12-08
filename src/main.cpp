#include <array>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#include "instruction-table.hpp"
#include "memory.hpp"
#include "xrcsterm.hpp"

int main() {
    using namespace XRCS;

    std::cout << "CWD: " << std::filesystem::current_path() << std::endl;
    auto mem = std::make_unique<mem::XRCSMemory>();
    mem->LoadAt(0, 0x80000, "XRCS.bin");
    std::cin.get();

    term::TermData tdata;
    tdata.CursorOn   = true;
    tdata.CursorX    = 0;
    tdata.CursorY    = 0;
    auto term        = term::Initialize(&tdata);
    tdata.Buffer[0]  = {.FgAttr = term::LRed, .BgAttr = term::Black, .Char = 'H'};
    tdata.Buffer[1]  = {.FgAttr = term::LYellow, .BgAttr = term::Black, .Char = 'e'};
    tdata.Buffer[2]  = {.FgAttr = term::LGreen, .BgAttr = term::Black, .Char = 'l'};
    tdata.Buffer[3]  = {.FgAttr = term::LCyan, .BgAttr = term::Black, .Char = 'l'};
    tdata.Buffer[4]  = {.FgAttr = term::LBlue, .BgAttr = term::Black, .Char = 'o'};
    tdata.Buffer[5]  = {.FgAttr = term::LMagenta, .BgAttr = term::Black, .Char = ','};
    tdata.Buffer[6]  = {.FgAttr = term::LWhite, .BgAttr = term::Black, .Char = ' '};
    tdata.Buffer[7]  = {.FgAttr = term::LRed, .BgAttr = term::Black, .Char = 'W'};
    tdata.Buffer[8]  = {.FgAttr = term::LYellow, .BgAttr = term::Black, .Char = 'o'};
    tdata.Buffer[9]  = {.FgAttr = term::LGreen, .BgAttr = term::Black, .Char = 'r'};
    tdata.Buffer[10] = {.FgAttr = term::LCyan, .BgAttr = term::Black, .Char = 'l'};
    tdata.Buffer[11] = {.FgAttr = term::LBlue, .BgAttr = term::Black, .Char = 'd'};
    tdata.Buffer[12] = {.FgAttr = term::LMagenta, .BgAttr = term::Black, .Char = '!'};
    term.Render();
    term.Render();
    term.Render();
    term.Render();

    std::cin.get();

    return EXIT_SUCCESS;
}
