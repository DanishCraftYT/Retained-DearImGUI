#include "RetainedGUI.hpp"

RetainedGUI::RetainedGUI(GLFWwindow* window, int OpenGLVersion) {
    // creates the ImGui context and it's IO.
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();  // loads embedded font.

    // sets the ImGui style to dark.
    ImGui::StyleColorsDark();

    // ImGui GLFW & OpenGL init functions.
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(std::format("#version {}", OpenGLVersion).c_str());
}

void RetainedGUI::ImGUINewFrame() {
    // ImGui NewFrame.
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void RetainedGUI::ImGUIRender() {
    // ImGui Render.
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void RetainedGUI::ImGUITerminate() {
    // ImGui Shutdown.
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
