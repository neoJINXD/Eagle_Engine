
//#include <t1.h>
//#include <main.h>

#include "Sandbox.h"


int main()
{
    //return Eagle::main_func();

    Sandbox* app = new Sandbox();
    app->run();
    delete app;

    return 0;
}