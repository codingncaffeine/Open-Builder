# STLport 4.6

The headers of STLport 4.6 (`stlport/`) from the STLport-4.6.tar.gz release; `license.html` is its licence. The
original program was built with the 2003 compiler against an STLport that is 4.6 in nearly everything, so decompiled
code that uses the standard library compiles against these headers to produce the same code.

Four changes, each marked in its file and each off unless its macro is defined:

- `stlport/stl/_new.h` declares `__stl_new` and `__stl_delete` out of line when `_STLP_OUT_OF_LINE_STL_NEW` is
  defined, as the original program's build of STLport had them.
- `stlport/stl/_vector.h` takes `resize`'s value by reference when `_STLP_RESIZE_BY_REFERENCE` is defined. The
  original's STLport predates the 4.6 release (October 2003) here: its `vector::resize` passes the value by address,
  as 4.5.3 did, where 4.6 passes it by value.
- `stlport/stl/_tree.h`: the tree iterator's `++` and `--` walk the tree themselves when `_STLP_TREE_ITERATOR_WALKS`
  is defined. The original kept them out of line (one copy each, shared by every tree), where 4.6's inline operators
  call static helpers.
- `stlport/stl/_tree.c`: `insert_unique` passes `__x` to `_M_insert` on its "insert at the start" path when
  `_STLP_INSERT_UNIQUE_BY_X` is defined, as 4.5.3 does; 4.6 passes `__y`.
