Run `make` to produce and test the `libmy.so`. To let an (already compiled and statically linked) program use re-defined `malloc` and `new`, set the environment variable `LD_PRELOAD` to the path of `libmy.so`, e.g.
```bash
LD_PRELOAD=/software/zeromalloc/libmy.so Gate Main.mac
```

