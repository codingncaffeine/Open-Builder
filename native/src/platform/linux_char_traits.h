// linux_char_traits.h - (Open City Builder's Linux build) std::char_traits for 16-bit code units. The macOS libc++ the
// original port was built against still had the generic char_traits template; the libc++ on Linux (19+) defines it only
// for the character types, so std::basic_string<std::uint16_t> (the game's UTF-16 strings) needs this. Force-included.
#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cwchar>
#include <ios>
#include <string>

template <>
struct std::char_traits<unsigned short> {
    using char_type = unsigned short;
    using int_type = unsigned int;
    using off_type = std::streamoff;
    using pos_type = std::streampos;
    using state_type = std::mbstate_t;

    static constexpr void assign(char_type& r, const char_type& a) noexcept { r = a; }
    static constexpr bool eq(char_type a, char_type b) noexcept { return a == b; }
    static constexpr bool lt(char_type a, char_type b) noexcept { return a < b; }
    static constexpr int compare(const char_type* a, const char_type* b, std::size_t n) {
        for (; n; --n, ++a, ++b) {
            if (*a < *b) return -1;
            if (*b < *a) return 1;
        }
        return 0;
    }
    static constexpr std::size_t length(const char_type* s) {
        std::size_t n = 0;
        while (s[n]) ++n;
        return n;
    }
    static constexpr const char_type* find(const char_type* s, std::size_t n, const char_type& a) {
        for (; n; --n, ++s)
            if (*s == a) return s;
        return nullptr;
    }
    static char_type* move(char_type* d, const char_type* s, std::size_t n) {
        return n ? static_cast<char_type*>(std::memmove(d, s, n * sizeof(char_type))) : d;
    }
    static char_type* copy(char_type* d, const char_type* s, std::size_t n) {
        return n ? static_cast<char_type*>(std::memcpy(d, s, n * sizeof(char_type))) : d;
    }
    static char_type* assign(char_type* d, std::size_t n, char_type a) {
        for (std::size_t i = 0; i < n; ++i) d[i] = a;
        return d;
    }
    static constexpr int_type not_eof(int_type c) noexcept { return eq_int_type(c, eof()) ? 0 : c; }
    static constexpr char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }
    static constexpr int_type to_int_type(char_type c) noexcept { return c; }
    static constexpr bool eq_int_type(int_type a, int_type b) noexcept { return a == b; }
    static constexpr int_type eof() noexcept { return static_cast<int_type>(0xFFFFFFFFu); }
};
