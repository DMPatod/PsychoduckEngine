#include <PsyduckEngine.h>

class Application : public PsyduckEngine::Application {
public: 
	Application() {}
	~Application() {}
};

PsyduckEngine::Application* PsyduckEngine::CreateApplication() {
	return new Application();
}