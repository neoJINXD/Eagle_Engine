#pragma once

#include <imgui.h>
#include "Core/Layer.h"

namespace Eagle
{

   class EAGLE_API ImGuiLayer : public Layer
   {
    public:
      ImGuiLayer();
      ~ImGuiLayer();

      void onAttach() override;
      void onDetach() override;
      void onUpdate() override;
      void onEvent(Event& e) override;

      virtual void onImGUIUpdate() override;
      void ImGuiInitFrame();
      void ImGuiRenderFrame();

      inline ImGuiContext* getImGuiCtx() { return ImGui::GetCurrentContext(); }

    private:
      float dt = 0;
      // GLFWwindow* win;
   };
}
