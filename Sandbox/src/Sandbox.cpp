#include <Eagle.h>

class Sandbox : public Eagle::Application
{
public:
    Sandbox() {}
    
    ~Sandbox() {}

    void onUpdate() override
    {
        DEBUG_LOG("We are in the Application");
    }

private:

};

Eagle::Application* Eagle::CreateApp()
{
    return new Sandbox();
}