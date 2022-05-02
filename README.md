Build a shared object that provides `malloc`, `new` which initialize the memory that they allocate.

**Note**: If you use the original allocators from glibc, setting the environment variable `MALLOC_PERTURB_` to a value 1..255 has a similar effect (and is easier).

**How to build and use**:  
Run `make` to produce and test the `libzeromalloc.so`. To let an (already compiled and statically linked) program use the re-defined `malloc` and `new`, set the environment variable `LD_PRELOAD` to the path of `libzeromalloc.so`, e.g.
```bash
LD_PRELOAD=/software/zeromalloc/libzeromalloc.so Gate Main.mac
```
To make the tests more meaningful, set the constant `zero` to e.g. 1 in `malloc.c` and rebuild. Then the output will be three times 16843009 (=0x01010101).

**Warning**:
Some allocation functions (e.g. `realloc`) are not properly re-defined with this simple wrapper.


