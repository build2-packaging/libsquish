# libsquish - DXT/S3TC texture compression C++ library

This is a `build2` package for the [`libsquish`](https://github.com/oblivioncth/libsquish)
C++ library. It provides open source DXT/S3TC compression and decompression
of RGBA textures, commonly used with OpenGL and DirectX.


## Usage

To start using `libsquish` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libsquish ^1.15.104
```

Then import the library in your `buildfile`:

```
import libs = libsquish%lib{squish}
```

Include the public header as:

```
#include <squish/squish.h>
```


## Importable targets

This package provides the following importable targets:

```
lib{squish}
```

The DXT1/DXT3/DXT5/BC4/BC5 compressor/decompressor library (static and
shared variants), in the `squish` namespace.


## Configuration variables

This package has no configuration variables. SIMD acceleration
(`SQUISH_USE_SSE`/`SQUISH_USE_ALTIVEC` in upstream's own build) is enabled
automatically whenever the compiler already targets SSE2 or Altivec, for
example on x86-64 by default, or when the consumer's own
`-march=`/`-msse2`/`-maltivec` compile options are already active.
libsquish never adds its own instruction-set compile flags, so it cannot
widen a consumer's binary beyond what they already targeted. Upstream's
`SQUISH_USE_OPENMP` option is not enabled by this package.
