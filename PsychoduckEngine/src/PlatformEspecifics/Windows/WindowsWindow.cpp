#include "../../pepch.h"
#include "WindowsWindow.h"

namespace PsychoduckEngine {
	static bool s_SDLInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CONSOLE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_SDLInitialized) {
			int success = SDL_Init(SDL_INIT_VIDEO);
			CORE_ASSERT(success, "Could not initialize SDL2!");
			s_SDLInitialized = true;
		}
		m_Window = SDL_CreateWindow(m_Data.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Data.Width, m_Data.Height, SDL_WINDOW_OPENGL);

		SDL_GLContext context = SDL_GL_CreateContext(m_Window);
		CORE_ASSERT(context, "Failed to create a SDL_GLContext!");

		SetVSync(true);
	}

	void WindowsWindow::Shutdown() {
		while (SDL_PollEvent(&m_Event)) {}
		SDL_DestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		SDL_PollEvent(&m_Event);
		SDL_GL_SwapWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			SDL_GL_SetSwapInterval(1);
		}
		else {
			SDL_GL_SetSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool  WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}
}