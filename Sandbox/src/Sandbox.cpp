#include <Eagle.h>

#include "Core/ImGui/ImGuiLayer.h"

class SandboxLayer : public Eagle::Layer
{
public:
    SandboxLayer() : Layer("Sandbox Layer") {}
    
    void onUpdate() override 
    {
        PRINT("We in the app boys");
    }

    void onEvent(Eagle::Event& e) override
    {
        PRINT("Application handling {}", e);
    }
};

class Sandbox : public Eagle::Application
{
public:
    Sandbox() : Application() 
    {
        addLayer(new SandboxLayer());
        addOverlay(new Eagle::ImGuiLayer());
    }
    
    virtual ~Sandbox() {}
};

Eagle::Application* Eagle::CreateApp()
{
    return new Sandbox();
}