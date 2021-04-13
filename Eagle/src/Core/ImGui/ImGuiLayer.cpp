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
 //   IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO();

	//ImGui::StyleColorsDark();

 //   auto app = Application::getInstance();
 //   
 //   //GLFWwindow* window = app->getWindow().getWindow();
 //   ImGui_ImplGlfw_InitForOpenGL(window, true); // TODO get reference to GFLWwindow*
 //   ImGui_ImplOpenGL3_Init("#version 410");
}

void Eagle::ImGuiLayer::onDetach()
{
    //ImGui_ImplOpenGL3_Shutdown();
    //ImGui_ImplGlfw_Shutdown();
    //ImGui::DestroyContext();
}

void Eagle::ImGuiLayer::onUpdate()
{
    //ImGui_ImplOpenGL3_NewFrame();
    //ImGui_ImplGlfw_NewFrame();
    //ImGui::NewFrame();

    //bool showDemo = true;
    //ImGui::ShowDemoWindow(&showDemo);

    //ImGui::Render();
    //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Eagle::ImGuiLayer::onEvent(Event& e)
{
}
