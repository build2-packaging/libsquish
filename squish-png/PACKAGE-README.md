# squish-png - libsquish PNG round-trip compression tester

This is a `build2` package for the `squish-png` tool from
[`libsquish`](https://github.com/oblivioncth/libsquish). It loads a PNG
image, compresses it with DXT1/DXT3/DXT5, decompresses it back, reports the
RMS error, and optionally writes the round-tripped image back out as PNG.
It exists to exercise `libsquish`'s whole-image compression API against
real images; ordinary consumers of `libsquish` don't need this tool.


## Usage

To start using `squish-png` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * squish-png ^1.15.104
```

Then import the executable in your `buildfile`:

```
import squish_png = squish-png%exe{squish-png}
```


## Importable targets

This package provides the following importable targets:

```
exe{squish-png}
```

`squish-png [-135riw] <source> [<target>]` -- see `squish-png -h` for the
full option list.


## Configuration variables

This package has no configuration variables.
