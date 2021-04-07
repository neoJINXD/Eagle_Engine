#include "Sandbox.h"
#include <Eagle.h>

int main()
{
    Eagle::main_func();

    DEBUG_LOG("From the {}", "Sandbox");
    PRINT("Now using print {}:{}", 5,7);

    return 0;

    //Sandbox* app = new Sandbox();
    //app->run();
    //delete app;
}