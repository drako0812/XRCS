#include "xrcsterm.hpp"

namespace XRCS::term {

    ftxui::Color ConvertColor(TermAttr attr) {
        ftxui::Color::Palette16 col;
        TermAttr                c = (TermAttr)(attr & 0x0F);
        switch (c) {
        case TermAttr::Black: col = ftxui::Color::Palette16::Black; break;
        case TermAttr::Red: col = ftxui::Color::Palette16::Red; break;
        case TermAttr::Yellow: col = ftxui::Color::Palette16::Yellow; break;
        case TermAttr::Green: col = ftxui::Color::Palette16::Green; break;
        case TermAttr::Cyan: col = ftxui::Color::Palette16::Cyan; break;
        case TermAttr::Blue: col = ftxui::Color::Palette16::Blue; break;
        case TermAttr::Magenta: col = ftxui::Color::Palette16::Magenta; break;
        case TermAttr::White: col = ftxui::Color::Palette16::GrayLight; break;
        case TermAttr::Gray: col = ftxui::Color::Palette16::GrayDark; break;
        case TermAttr::LRed: col = ftxui::Color::Palette16::RedLight; break;
        case TermAttr::LYellow: col = ftxui::Color::Palette16::YellowLight; break;
        case TermAttr::LGreen: col = ftxui::Color::Palette16::GreenLight; break;
        case TermAttr::LCyan: col = ftxui::Color::Palette16::CyanLight; break;
        case TermAttr::LBlue: col = ftxui::Color::Palette16::BlueLight; break;
        case TermAttr::LMagenta: col = ftxui::Color::Palette16::MagentaLight; break;
        case TermAttr::LWhite: col = ftxui::Color::Palette16::White; break;
        }

        return ftxui::Color(col);
    }

    void Term::Tick() {
        bool update_cursor = false;
        if (Data->CursorX != CursorX) {
            CursorX       = Data->CursorX;
            update_cursor = true;
        }
        if (Data->CursorY != CursorY) {
            CursorY       = Data->CursorY;
            update_cursor = true;
        }
        if (Data->CursorOn && !CursorOn) {
            CursorOn      = true;
            update_cursor = true;
        } else if (!Data->CursorOn && CursorOn) {
            CursorOn = false;
            Screen->SetCursor({.x = -1, .y = -1}); // TODO: Maybe this hides it?
        }
        if (update_cursor) {
            Screen->SetCursor({.x = CursorX, .y = CursorY});
            update_cursor = false;
        }

        Ticks++;
        if (Ticks >= TermTicksPerFrame) {
            Ticks = 0;
            Render();
        }
    }

    void Term::Render() {
        static std::string pix_s = " ";

        for (int y = 0; y < TerminalHeight; y++) {
            for (int x = 0; x < TerminalWidth; x++) {
                auto tch          = Data->Buffer[x + (y * TerminalWidth)];
                auto [fg, bg, ch] = tch;
                pix_s[0]          = ch;
                ftxui::Pixel pix;
                pix.character        = pix_s;
                pix.foreground_color = ConvertColor(fg);
                pix.background_color = ConvertColor(bg);
                Screen->PixelAt(x, y) = pix;
            }
        }

        Screen->Print();
    }

    Term Initialize(TermData * data) {
        Term term;

        term.Data = data;
        term.CursorOn = true;
        term.CursorX = 0;
        term.CursorY = 0;
        term.Ticks = 0;
        term.Screen.reset(new ftxui::Screen(ftxui::Dimension::Fixed(80).dimx, ftxui::Dimension::Fixed(25).dimy));
        term.Screen->SetCursor({.x = 0, .y = 0});
        term.Render();

        return term;
    }

} // namespace XRCS::term
