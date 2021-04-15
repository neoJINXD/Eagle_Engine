#include "pch.h"
#include "ImGuiLayer.h"

#include <imgui.h>
#include "Platform/ImGui/imgui_impl_opengl3.h"
#include "Platform/ImGui/imgui_impl_glfw.h"
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "Core/Application.h"
#include "Platform/OpenGL/OpenGLWindow.h"


Eagle::ImGuiLayer::ImGuiLayer() : Layer("ImGui Layer")
{
}

Eagle::ImGuiLayer::~ImGuiLayer()
{
    onDetach();
}

void Eagle::ImGuiLayer::onAttach()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui::StyleColorsDark();

    Window* win = &Application::getInstance()->getWindow(); // TODO store reference
    ImGui_ImplGlfw_InitForOpenGL(((OpenGLWindow*)win)->getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void Eagle::ImGuiLayer::onDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Eagle::ImGuiLayer::onUpdate()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static bool showDemo = true;
    ImGui::ShowDemoWindow(&showDemo);

    
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Checkbox("Demo Window", &showDemo);      // Edit bools storing our window open/close state
    ImGui::Checkbox("Another Window", &showDemo);

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
    

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwPollEvents();
    Window* win = &Application::getInstance()->getWindow(); // TODO store reference
    glfwSwapBuffers(((OpenGLWindow*)win)->getWindow());
}

void Eagle::ImGuiLayer::onEvent(Event& e)
{
}
