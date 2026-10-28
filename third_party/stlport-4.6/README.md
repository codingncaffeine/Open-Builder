# STLport 4.6

The headers of STLport 4.6 (`stlport/`), unmodified, from the STLport-4.6.tar.gz release; `license.html` is its
licence. The original program was built against STLport 4.6 with the 2003 compiler, so decompiled code that uses
the standard library compiles against these headers to produce the same code.

One change, marked in the file: `stlport/stl/_new.h` declares `__stl_new` and `__stl_delete` out of line when
`_STLP_OUT_OF_LINE_STL_NEW` is defined, as the original program's build of STLport had them.
