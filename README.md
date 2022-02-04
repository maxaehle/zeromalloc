Run `make` to produce and test the `libzeromalloc.so`. To let an (already compiled and statically linked) program use re-defined `malloc` and `new`, set the environment variable `LD_PRELOAD` to the path of `libzeromalloc.so`, e.g.
```bash
LD_PRELOAD=/software/zeromalloc/libzeromalloc.so Gate Main.mac
```

Some allocation functions (e.g. `realloc`) might not be re-defined with this simple wrapper.

To make the tests more meaningful, set the constant `zero` to e.g. 1 in `malloc.c`. Then the output will be three times 16843009 (=0x01010101).

