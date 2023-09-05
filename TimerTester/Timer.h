#pragma once
#include <chrono>
#include <iostream>

class Timer
{
private:
	using Clock = std::chrono::steady_clock;
	using Millisecond = std::chrono::duration<double, std::milli>;

	std::chrono::time_point<Clock> _begin{ Clock::now() };
public:
	template<typename F,typename... Ts>
	void measure(F (functor)(Ts...), Ts&&... args)
	{
		reset();
		functor(std::forward<Ts>(args)...);
		std::cout << "Time elapsed: " << elapsed() << "\n";
		reset();
	}

	void reset()
	{
		_begin = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Millisecond>(Clock::now() - _begin).count();
	}
};
