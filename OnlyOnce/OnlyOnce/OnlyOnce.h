#pragma once

#include <functional>
#include <atomic>
#include <mutex>

class OnlyOnce
{
private:
	std::atomic_int done;
	std::mutex m;
	[[deprecated]] int ccc{};

public:
	OnlyOnce();
	~OnlyOnce();

public:
	void Do(std::function<void()> f);

	[[deprecated("deprecated")]]
	void DoFunc(std::function<void()> f);
};

