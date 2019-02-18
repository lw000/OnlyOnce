#include "pch.h"
#include "OnlyOnce.h"
#include <iostream>

OnlyOnce::OnlyOnce()
{
	this->done = 0;
}

OnlyOnce::~OnlyOnce()
{
}

void OnlyOnce::Do(std::function<void()> f) {
	if (this->done == 1) {
		return;
	}

	std::lock_guard<std::mutex> l(m);
	if (this->done == 0) {
		this->done.fetch_add(1);
		if (f != nullptr)
		{
			f();
		}
	}
}

void OnlyOnce::DoFunc(std::function<void()> f) {
	this->Do(f);
}
