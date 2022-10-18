#pragma once

#include "Log.h"

extern PsychoduckEngine::Application* PsychoduckEngine::CreateApplication();

int main(int argc, char** argv) {
	PsychoduckEngine::Log::Init();

	CONSOLE_CORE_TRACE("Psychoduck Engine Initialize!");

	auto app = PsychoduckEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}