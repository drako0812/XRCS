#pragma once

#include <iostream>
#include <string>

namespace XRCS {

    // class AssertionException {
    //   protected:
    //     std::string message;

    //   public:
    //     inline AssertionException(const std::string & message = "AssertionException") : message{message} {}
    //     inline const char * Message() const { return message.c_str(); }
    // };

#ifndef ASSERTION_OPT_LEVEL
#    define ASSERTION_OPT_LEVEL 0
#else
#    if !((ASSERTION_OPT_LEVEL == 0) || (ASSERTION_OPT_LEVEL == 1) || (ASSERTION_OPT_LEVEL == 2))
#        error "ASSERTION_OPT_LEVEL must be 0, 1, or 2"
#    endif
#endif

#if ASSERTION_OPT_LEVEL == 0
    inline void Assert(bool condition, const std::string & message) {
        if (!condition) {
            std::cerr << "Assertion Failed: " << message << std::endl;
            std::exit(1);
        }
    }
#elif ASSERTION_OPT_LEVEL == 1
    inline void Assert(bool condition, const std::string & message) {}
#else
#    define Assert(condition, message)
#endif

    template<class Function> class Defer {
      private:
        Function function;

      public:
        explicit inline Defer(Function && function) : function{function} {}
        inline Defer(Defer && other) : function{other.function} {}
        Defer(const Defer & other) = delete;
        inline ~Defer() { function(); }
    };

#define CAT(a, b)       CAT2(a, b)
#define CAT2(a, b)      a##b
#define DEFER(function) auto CAT(defer_, __COUNTER__) = Defer(function)

} // namespace XRCS
