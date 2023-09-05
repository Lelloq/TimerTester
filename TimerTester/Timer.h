#pragma once
#include <chrono>
#include <iostream>

class Timer
{
private:
	using Clock = std::chrono::steady_clock;
	using Millisecond = std::chrono::duration<double, std::milli>;

	inline static std::chrono::time_point<Clock> _begin{ Clock::now() };

	static void reset()
	{
		_begin = Clock::now();
	}

	static double elapsed()
	{
		return std::chrono::duration_cast<Millisecond>(Clock::now() - _begin).count();
	}
public:
	template<typename F,typename... Ts>
	static double measure(F (functor)(Ts...), Ts&&... args)
	{
		reset();
		functor(std::forward<Ts>(args)...);
		return elapsed();
	}
};
