#pragma once

/*
	@brief A showcase of the library: eight lit, colored cubes tumbling in a 2x4 grid, with a
	text overlay and free camera movement.

	This lives with the examples rather than inside the library because it loads runtime assets
	(a font, the window icon, the logo texture) from the resources folder. The library itself
	has no runtime file dependencies -- its shaders are compiled into the binary.
 */
namespace demo
{
	/*
		@brief Runs the demo. Initializes the library if it isn't already initialized, and
		terminates it again on exit if it was the one that initialized it.
		@param log_progress Whether to log setup progress to stdout.
	 */
	void run(bool log_progress = true);
}
