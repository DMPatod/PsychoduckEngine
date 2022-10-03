#pragma once

#include "Base.h"

int main(int argc, char** argv);

namespace PsyduckEngine {
	class Application {
	public:
		Application() {};
		virtual ~Application() {};
		
	private:
		void Run() {
			while (m_Running) {}
		}

		friend int ::main(int argc, char** argv);

		bool m_Running = true;
	};

	Application* CreateApplication();
}