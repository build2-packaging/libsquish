// Public API smoke test for libsquish.
//
// Exercises squish::CompressImage()/DecompressImage() with the exact flag
// combination used by bgfx/libbimg-encode's image_encode.cpp: each of the
// DXT1/DXT3/DXT5/BC4/BC5 formats crossed with each of the three colour
// compressors, round-tripped through decompression.

#include <squish/squish.h>

#undef NDEBUG
#include <cassert>
#include <cstring>
#include <vector>

using namespace squish;

static void
test (int format, int fit)
{
  int flags = format | fit;

  // 4x4 block of pixels: a simple horizontal red-to-blue gradient with
  // varying alpha, distinct enough per-channel to exercise real fitting.
  //
  unsigned char src[4 * 4 * 4];
  for (int i = 0; i != 16; ++i)
  {
    src[i * 4 + 0] = static_cast<unsigned char> (i * 16);       // R
    src[i * 4 + 1] = static_cast<unsigned char> (128);          // G
    src[i * 4 + 2] = static_cast<unsigned char> (255 - i * 16); // B
    src[i * 4 + 3] = static_cast<unsigned char> (i % 2 ? 255 : 0); // A
  }

  int size = GetStorageRequirements (4, 4, flags);
  assert (size > 0);

  std::vector<unsigned char> block (static_cast<std::size_t> (size));
  CompressImage (src, 4, 4, block.data (), flags);

  unsigned char dst[4 * 4 * 4];
  std::memset (dst, 0, sizeof (dst));
  DecompressImage (dst, 4, 4, block.data (), flags);

  // Lossy codec: just confirm decompression produced plausible-looking
  // data (not left zeroed) for the channels the format actually encodes.
  //
  bool any_non_zero = false;
  for (unsigned char b : dst)
  {
    if (b != 0)
    {
      any_non_zero = true;
      break;
    }
  }
  assert (any_non_zero);
}

int
main ()
{
  int formats[] = {kDxt1, kDxt3, kDxt5, kBc4, kBc5};
  int fits[] = {kColourClusterFit, kColourIterativeClusterFit, kColourRangeFit};

  for (int format : formats)
    for (int fit : fits)
      test (format, fit);

  // Also confirm the single-block entry points used internally still work.
  //
  unsigned char rgba[16 * 4];
  std::memset (rgba, 128, sizeof (rgba));
  unsigned char block[16];
  Compress (rgba, block, kDxt5 | kColourClusterFit);
  unsigned char out[16 * 4];
  Decompress (out, block, kDxt5 | kColourClusterFit);
}
