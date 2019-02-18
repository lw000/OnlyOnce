#pragma once

#include <functional>
#include <atomic>
#include <mutex>

class OnlyOnce
{
private:
	std::atomic_int done;
	std::mutex m;

public:
	OnlyOnce();
	~OnlyOnce();

public:
	void Do(std::function<void()> f);
};

