// Copyright 2015-2021 Piperift - All rights reserved

#include "Misc/Time.h"

#include "Profiler.h"

#include <thread>


namespace Rift
{
	void FrameTime::Tick()
	{
		previousTime = currentTime;
		currentTime = DateTime::Now();

		// Avoid too big delta times
		realDeltaTime = Math::Min(0.15f, (currentTime - previousTime).GetTotalSeconds());

		// Apply time dilation
		deltaTime = realDeltaTime * timeDilation;
	}

	void FrameTime::PostTick()
	{
		const float secondsPassed      = (DateTime::Now() - currentTime).GetTotalSeconds();
		const float extraTimeForFPSCAP = minFrameTime - secondsPassed;
		if (extraTimeForFPSCAP > 0.0f)
		{
			// Cap FPS with a delay
			ZoneScopedNC("Sleep", 0xD15545);

			Chrono::duration<float, Chrono::seconds::period> sleepPeriod{extraTimeForFPSCAP};
			std::this_thread::sleep_for(sleepPeriod);
		}
	}
}	 // namespace Rift
