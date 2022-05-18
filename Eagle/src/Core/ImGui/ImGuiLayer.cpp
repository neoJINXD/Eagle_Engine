#include "pch.h"
#include "ImGuiLayer.h"

#include "Platform/ImGui/imgui_impl_opengl3.h"
#include "Platform/ImGui/imgui_impl_glfw.h"
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "Core/Application.h"
#include "Platform/OpenGL/OpenGLWindow.h"

Eagle::ImGuiLayer::ImGuiLayer() : Layer("ImGui Layer") {}

Eagle::ImGuiLayer::~ImGuiLayer()
{
   onDetach();
}

void Eagle::ImGuiLayer::onAttach()
{
   IMGUI_CHECKVERSION();
   ImGui::CreateContext();
   ImGuiIO& io = ImGui::GetIO();

   io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
   io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

   ImGui::StyleColorsDark();

   ImGuiStyle& style = ImGui::GetStyle();
   if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
   {
      style.WindowRounding = 0.0f;
      style.Colors[ImGuiCol_WindowBg].w = 1.0f;
   }

   Window* win = &Application::getInstance()->getWindow(); // TODO store reference
   ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)win->getWindow(), true);
   ImGui_ImplOpenGL3_Init("#version 430");
}

void Eagle::ImGuiLayer::onDetach()
{
   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();
}

void Eagle::ImGuiLayer::onUpdate() {}

void Eagle::ImGuiLayer::onEvent(Event& e) {}

void Eagle::ImGuiLayer::onImGUIUpdate()
{
   static bool showDemo = true;
   ImGui::ShowDemoWindow(&showDemo);
}

void Eagle::ImGuiLayer::ImGuiInitFrame()
{
   ImGui_ImplOpenGL3_NewFrame();
   ImGui_ImplGlfw_NewFrame();
   ImGui::NewFrame();
}

void Eagle::ImGuiLayer::ImGuiRenderFrame()
{
   ImGuiIO& io = ImGui::GetIO();
   Application* app = Application::getInstance();
   io.DisplaySize = ImVec2(app->getWindow().getWidth(), app->getWindow().getHeight());

   ImGui::Render();
   ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

   if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
   {
      GLFWwindow* backup_current_context = glfwGetCurrentContext();
      ImGui::UpdatePlatformWindows();
      ImGui::RenderPlatformWindowsDefault();
      glfwMakeContextCurrent(backup_current_context);
   }
}
