#pragma once

#include "Base.h"

#include "Window.h"

namespace PsychoduckEngine {
	class PsychoduckEngine_API Application {
	public:
		Application();
		virtual ~Application() {};

		void Run();
	private:
		Scope<Window> m_Window;

		bool m_Running = true;
	};

	Application* CreateApplication();
}