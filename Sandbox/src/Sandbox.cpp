#include <Eagle.h>


class SandboxLayer : public Eagle::Layer
{
public:
    SandboxLayer() : Layer("Sandbox Layer") {}
    
    void onUpdate() override 
    {
        //PRINT("We in the app boys");
    }

    void onEvent(Eagle::Event& e) override
    {
        PRINT("Application handling {}", e);
    }

    void onImGUIUpdate() override
    {
        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        
        ImGui::End();
    }
private:
    int counter = 0;
    float f = 0.0f;
    bool showDemo = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

class Sandbox : public Eagle::Application
{
public:
    Sandbox() : Application() 
    {
        addLayer(new SandboxLayer());
        ImGui::SetCurrentContext(ImgGuiCtx);
    }
    
    virtual ~Sandbox() {}
};

Eagle::Application* Eagle::CreateApp()
{
    return new Sandbox();
}