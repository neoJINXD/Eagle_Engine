#include <Eagle.h>

class SandboxLayer : public Eagle::Layer
{
public:
    SandboxLayer() : Layer("Sandbox Layer") {}
    
    void OnUpdate() override 
    {
    }

    void OnEvent(Eagle::Event& e) override
    {
        PRINT("Application handling {}", e);
    }
};

class Sandbox : public Eagle::Application
{
public:
    Sandbox() : Application() 
    {
        AddLayer(new SandboxLayer());
    }
};

auto Eagle::CreateApp() -> Eagle::Application*
{
    return new Sandbox();
}
