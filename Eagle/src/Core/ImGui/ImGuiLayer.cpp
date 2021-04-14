#include "pch.h"
#include "ImGuiLayer.h"

#include <imgui.h>
#include "Platform/ImGui/imgui_impl_opengl3.h"
#include "Platform/ImGui/imgui_impl_glfw.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

    bool showDemo = true;
    ImGui::ShowDemoWindow(&showDemo);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwPollEvents();
    Window* win = &Application::getInstance()->getWindow(); // TODO store reference
    glfwSwapBuffers(((OpenGLWindow*)win)->getWindow());
}

void Eagle::ImGuiLayer::onEvent(Event& e)
{
}
