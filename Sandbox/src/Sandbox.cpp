#include <Eagle.h>

class Sandbox : public Eagle::Application
{
public:
    Sandbox() : Application() {}
    
    virtual ~Sandbox() {}

    void onUpdate() override
    {
        DEBUG_LOG("We are in the Application");
    }

};

Eagle::Application* Eagle::CreateApp()
{
    return new Sandbox();
}