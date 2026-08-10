# squish-gen - libsquish lookup-table generator tool

This is a `build2` package for the `squish-gen` tool from
[`libsquish`](https://github.com/oblivioncth/libsquish). It regenerates the
single-colour lookup tables that libsquish bakes into its
`singlecolourlookup.inl` source file. This is an internal maintainer tool:
the generated tables are already checked into `libsquish`, so ordinary
consumers of `libsquish` never need to build or run this package.


## Usage

To start using `squish-gen` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * squish-gen ^1.15.104
```

Then import the executable in your `buildfile`:

```
import squish_gen = squish-gen%exe{squish-gen}
```


## Importable targets

This package provides the following importable targets:

```
exe{squish-gen}
```

Takes no arguments; prints the four regenerated lookup tables as C++
source to stdout.


## Configuration variables

This package has no configuration variables.
