#include "../pepch.h"

#include "Application.h"

#include <SDL_opengl.h>

namespace PsyduckEngine {
	Application::Application() {
		m_Window = Scope<Window>(Window::Create());
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}