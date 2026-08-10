# libsquish - DXT/S3TC texture compression C++ library

This is a `build2` package repository for [`libsquish`](https://github.com/oblivioncth/libsquish),
a C++ library providing open source DXT/S3TC compression and decompression
of RGBA textures.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
these packages in your `build2`-based project, then instead see the
accompanying `PACKAGE-README.md` files:

- [`libsquish`](libsquish/PACKAGE-README.md)
- [`squish-gen`](squish-gen/PACKAGE-README.md) (maintainer lookup-table tool)
- [`squish-png`](squish-png/PACKAGE-README.md) (PNG round-trip tester)

The development setup uses the standard `bdep`-based workflow. For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/libsquish.git
cd libsquish

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
