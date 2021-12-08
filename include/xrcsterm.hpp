#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include <ftxui/screen/screen.hpp>

namespace XRCS::term {

    enum TermAttr : std::uint8_t {
        Black   = 0b00000000,
        Red     = 0b00000100,
        Yellow  = 0b00000110,
        Green   = 0b00000010,
        Cyan    = 0b00000011,
        Blue    = 0b00000001,
        Magenta = 0b00000101,
        White   = 0b00000111,

        Bright = 0b00001000,

        Gray     = Black | Bright,
        LRed     = Red | Bright,
        LYellow  = Yellow | Bright,
        LGreen   = Green | Bright,
        LCyan    = Cyan | Bright,
        LBlue    = Blue | Bright,
        LMagenta = Magenta | Bright,
        LWhite   = White | Bright,
    };

    ftxui::Color ConvertColor(TermAttr attr);

    struct TermCh {
        TermAttr     FgAttr : 4;
        TermAttr     BgAttr : 4;
        std::uint8_t Char;
    };

    constexpr int TermChBytes         = sizeof(TermCh);
    constexpr int TerminalWidth       = 80;
    constexpr int TerminalHeight      = 25;
    constexpr int TerminalBufferSize  = TerminalWidth * TerminalHeight;
    constexpr int TerminalBufferBytes = TerminalBufferSize * TermChBytes;

    struct TermData {
        std::uint8_t CursorOn;
        std::uint8_t CursorX;
        std::uint8_t CursorY;
        TermCh       Buffer[TerminalBufferSize];
    };

    constexpr int TermDataBytes          = sizeof(TermData);
    constexpr int TermDataCursorOnOffset = offsetof(TermData, CursorOn);
    constexpr int TermDataCursorXOffset  = offsetof(TermData, CursorX);
    constexpr int TermDataCursorYOffset  = offsetof(TermData, CursorY);
    constexpr int TermDataBufferOffset   = offsetof(TermData, Buffer);

    struct Term {
        TermData * Data;
        bool       CursorOn;
        int        CursorX;
        int        CursorY;
        int        Ticks; // Ticks are going to be clock cycles with an initial estimate of 10 MHz
                          // Which for 15 FPS equates to 666,667 ticks

        std::unique_ptr<ftxui::Screen> Screen;

        void Tick();
        void Render();
    };

    constexpr int TermSize          = sizeof(Term);
    constexpr int TermTicksPerFrame = 666667;

    Term Initialize(TermData * data);

} // namespace XRCS::term
