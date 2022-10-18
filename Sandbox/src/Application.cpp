#include <PsychoduckEngine.h>

class Application : public PsychoduckEngine::Application {
public: 
	Application() {}
	~Application() {}
};

PsychoduckEngine::Application* PsychoduckEngine::CreateApplication() {
	return new Application();
}