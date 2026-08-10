#pragma once

/* Upstream's own build (CMake's GenerateExportHeader) generates this file
 * at configure time; it is not checked into the git repository. This
 * build2 package supplies it directly instead.
 *
 * Symbol visibility for the DLL case is handled by build2's own
 * auto-symexport mechanism (a generated module-definition file listing
 * every exported symbol, see src/buildfile), not by per-declaration
 * dllexport/dllimport annotations, so no platform branching is needed here.
 */

#define SQUISH_EXPORT
#define SQUISH_NO_EXPORT
