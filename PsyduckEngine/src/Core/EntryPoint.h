#pragma once

#include "Log.h"

extern PsyduckEngine::Application* PsyduckEngine::CreateApplication();

int main(int argc, char** argv) {
	PsyduckEngine::Log::Init();

	CONSOLE_CORE_TRACE("Psyduck Engine Initialize!");

	auto app = PsyduckEngine::CreateApplication();
	app->Run();
	delete app;
}