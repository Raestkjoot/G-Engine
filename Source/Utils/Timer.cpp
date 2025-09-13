#include "Timer.h"

using Clock = std::chrono::steady_clock;

Timer::Timer() {
	_lastTick = Clock::now();
}

float Timer::Tick() {
	std::chrono::time_point<Clock> now = Clock::now();
	std::chrono::duration<float> delta = now - _lastTick; // time in seconds
	_lastTick = now;
	return delta.count();
}