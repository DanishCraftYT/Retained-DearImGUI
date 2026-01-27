#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "GUI/GUIElements/CoreGUIElements.hpp"
#include "GUI/GUIWindow.hpp"
#include "GUI/GUIElements/ComboBox/ComboBox.hpp"
#include "GUI/GUIElements/Child/Child.hpp"
#include "GUI/GUIModal.hpp"
#include "GUI/GUIElements/ListBox/ListBox.hpp"
#include "GUI/Toolbar/GUIToolbar.hpp"
#include "GUI/GUI.hpp"

/* TODO:
* (GUI WINDOW) implement ability to lock the position and/or size of the GUI Window.
* (GUIELEMENT.hpp) implement a virtual "terminate()" function that can be overridden by GUI Elements like Child which has vectors inside them.
* * make sure to update classes that contain GUI Elements to terminate them when their terminate function is called.
* (INPUT FIELD) add preview text for input fields.
* (SAME LINE) implement ability to adjust x axis offset and spacing.
* add support for multiline input fields.
* (TEST) GUI.hpp and it's toolbar and disabling it and making it invisible.
* add support for groups.
* add support for sliders.
* add support for color pickers.
* add support for images.
* add support for tree nodes.
* add support for progress bars.
* add support for tooltips.
* add drag and drop functionality.
* add support for tables.
* add support for tabs.

* EXTENSIONS:
* add support for drawing simple shapes.
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

    // GUI Elements //

    Text text("TestText", "TTT");
    Checkbox<void> checkbox("TestCheck", "gfgf", [](Checkbox<void>& checkbox) { std::cout << checkbox.isChecked() << std::endl; });
    Button<void> button("TestBtn", "ButtonText", ImVec2(75, 25));
    ComboBox combobox("NameC", "DD", "ffd");
    combobox.addItem(Selectable<void>("Selectable", "Select", [](Selectable<void>& selectable) { std::cout << selectable.getName(); }));
    combobox.addItem("Selectable 2", "Select");

    InputField<void> inputField("InputFieldTest", "Input Field", [](InputField<void>& inputField) { std::cout << inputField.getInputFieldText() << std::endl; });

    Selectable<void> selectable("SelectableTest", "Selectable", [](Selectable<void>& selected) { std::cout << "selected: " << selected.getName() << std::endl; });
    Selectable<void> selectable2("SelectableTest2", "Selectable 2", [](Selectable<void>& selected) { std::cout << "selected: " << selected.getName() << std::endl; });

    ListBox listbox("ListBoxTest", "ListBox", ImVec2(50, 50));
    listbox.addItem(Selectable<void>("Select", "Select", [](Selectable<void>& selectable) { std::cout << selectable.getName(); }));
    listbox.addItem("Select2", "Select 2");

    Separator separatorNoText("SeparatorNoText");
    Separator separatorWithText("SeparatorWithText", "Separator Text");

    SameLine sameline("SameLineTest");

    // Child Element.

    Child child("f", ImVec2(200, 100), true);
    child.visible = GUIElementVisibility::Disabled;
    child.addGUIElement(std::make_shared<Text>("TextChild", "Child"));
    std::shared_ptr child2 = std::make_shared<Child>("c2", ImVec2(150, 50), true);
    child2->addGUIElement(std::make_shared<Text>("TextChild", "Another Child :)"));
    child.addGUIElement(child2);

    // GUI //

    GUI gui("TestGUI");
    gui.toolbar.visible = GUIElementVisibility::Visible;

    // GUI Window & Toolbars //

    GUIWindow& win = gui.createWindow("WinTest", "test", ImVec2(200, 200), ImVec2(100, 100));
    win.visible = GUIElementVisibility::Visible;
    win.toolbar.visible = GUIElementVisibility::Disabled;
    ToolbarMenu& winToolbar = win.toolbar.addToolbarMenu("WinToolbarMenu1", "Test");
    winToolbar.addGUIElement(std::make_shared<Checkbox<void>>("ToolbarCheckbox", "Toolbar Checkbox"));
    winToolbar.addGUIElement(std::make_shared<Text>("ToolbarText", "Toolbar Text"));

    ToolbarMenu& winToolbar2 = win.toolbar.addToolbarMenu("WinToolbarMenu2", "Toolbar Menu 2");
    winToolbar2.addGUIElement(std::make_shared<Button<void>>("ToolbarButton", "Toolbar Button", ImVec2(100, 50)));
    winToolbar2.addGUIElement(std::make_shared<Text>("ToolbarText2", "Toolbar Text 2"));

    gui.toolbar.addToolbarMenu("ToolbarMenu1", "GUIToolbar!").addGUIElement(std::make_shared<ListBox>("ToolbarListBox", "ListBox in Toolbar", ImVec2(50, 50)));
    gui.toolbar.addToolbarMenu("ToolbarMenu2", "GUIToolbar 2!!").addGUIElement(std::make_shared<ComboBox>("ToolbarComboBox", "ComboBox in Toolbar"));

    // GUI Window 2 //

    GUIWindow& win2 = gui.createWindow("Win2", "Window 2", ImVec2(400, 400), ImVec2(200, 200));

    // GUI Modal //

    GUIModal modal("ModalTest", "Modal Popup");
    modal.addGUIElement(std::make_shared<Button<int>>("CloseModal", "Close", ImVec2(100, 50), [&modal](Button<int>& button) { modal.close(); return 1; }));
    
    Button<int> openModalBtn("OpenModal", "Open Modal Popup", ImVec2(100, 50), [&modal](Button<int>& button) { modal.open(); return 1; });

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
        selectable.render();
        selectable2.render();
        separatorNoText.render();
        inputField.render();
        child.render();
        sameline.render();
        checkbox.render();
        separatorWithText.render();
        button.render();
        openModalBtn.render();
        listbox.render();
        combobox.render();
        ImGui::End();

        gui.renderAllWindows();

        modal.render();

        // ImGui Render.
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // swaps GLFW window buffers and handle poll events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    gui.terminate();
    modal.terminate();

    // ImGui Shutdown.
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // terminates GLFW.
    glfwTerminate();
    return 0;
}
