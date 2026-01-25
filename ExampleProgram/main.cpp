#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "GUI/GUIElement.hpp"
#include "GUI/GUIElements/Text/Text.hpp"
#include "GUI/GUIElements/Checkbox/Checkbox.hpp"
#include "GUI/GUIElements/Button/Button.hpp"
#include "GUI/GUIWindow.hpp"
#include "GUI/GUIElements/ComboBox/ComboBox.hpp"
#include "GUI/GUIElements/Child/Child.hpp"

/* TODO:
* (TEST) disabled GUI Elements.
* implement callbacks (lambdas or std::function?).
* (TEST) input fields.
* * add preview text for input fields.
* (TEST) list boxes.
* add support for selectables.
* add support for multiline input fields.
* (TEST) modals.
* add support for toolbars.
* add support for separators.
* add support for same lines?
* add support for sliders.
* add support for color pickers.
* add support for images.
* add support for tree nodes.
* add support for progress bars.
* add support for tooltips.
* add drag and drop functionality.
* add support for tables.
* add support for tabs.
*/

int main() {
    // inits GLFW and handles GLFW window hints.
    if (!glfwInit()) {
        return 1;
    }

    // handles GLFW window hints.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "Retained ImGUI Example", NULL, NULL);

    // creates the GLFW window and checks if it was successfully created.
    if (!window) {
        return 1;
    }

    // makes the GLFW window the current context.
    glfwMakeContextCurrent(window);

    // inits GLAD.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return 1;
    }

    glViewport(0, 0, 800, 600);

    // configure global opengl state.
    glEnable(GL_DEPTH_TEST);

    // creates the ImGui context and it's IO.
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // sets the ImGui style to dark.
    ImGui::StyleColorsDark();

    // ImGui GLFW & OpenGL init functions.
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    Text text("TestText", "TTT");
    Checkbox checkbox("TestCheck", "gfgf");
    Button button("TestBtn", "ButtonText", ImVec2(75, 25));
    GUIWindow win("WinTest", "test");
    ComboBox combobox("NameC", "DD", "ffd");
    combobox.addItem("gf");

    Child child("f", ImVec2(200, 100), true);
    child.addGUIElement(std::make_shared<Text>("TextChild", "Child"));
    std::shared_ptr child2 = std::make_shared<Child>("c2", ImVec2(150, 50), true);
    child2->addGUIElement(std::make_shared<Text>("TextChild", "Another Child :)"));
    child.addGUIElement(child2);

    // render loop.
    while(!glfwWindowShouldClose(window))
    {
        // sets the viewport color.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // ImGui NewFrame.
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // imgui window.
        ImGui::Begin("r");
        ImGui::Text("Test");
        text.render();
        child.render();
        checkbox.render();
        button.render();
        ImGui::End();

        combobox.render();

        // ImGui Render.
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // swaps GLFW window buffers and handle poll events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ImGui Shutdown.
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // terminates GLFW.
    glfwTerminate();
    return 0;
}
