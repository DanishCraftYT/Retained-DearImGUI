#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "GUI/RetainedGUI.hpp"
#include "GUI/Fonts.hpp"
#include "GUI/GUIElements/CoreGUIElements.hpp"
#include "GUI/GUIWindow.hpp"
#include "GUI/GUIElements/ComboBox/ComboBox.hpp"
#include "GUI/GUIElements/Child/Child.hpp"
#include "GUI/GUIModal.hpp"
#include "GUI/GUIElements/ListBox/ListBox.hpp"
#include "GUI/Toolbar/GUIToolbar.hpp"
#include "GUI/GUI.hpp"
#include "GUI/GUIElements/Table/Table.hpp"
#include "GUI/GUIElements/ProgressBar/SimpleProgressBar.hpp"
#include "GUI/GUIElements/ProgressBar/ProgressBar.hpp"
#include "GUI/GUIElements/ProgressBar/AdvancedProgressBar.hpp"
#include "GUI/GUIElements/Text/BulletText.hpp"
#include "GUI/GUIElements/CollapsingHeader/CollapsingHeader.hpp"
#include "GUI/GUIElements/ColorPicker/ColorPicker.hpp"
#include "GUI/GUIElements/Slider/SliderFloat.hpp"
#include "GUI/GUIElements/Slider/SliderInt.hpp"
#include "GUI/GUIElements/Slider/SliderUInt.hpp"

/* TODO:
* IMPROVEMENTS:
* (GUI WINDOW) implement ability to lock the position and/or size of the GUI Window.
* * make sure to update classes that contain GUI Elements to terminate them when their terminate function is called.
* (INPUT FIELD) add preview text for input fields.
* (SAME LINE) implement ability to adjust x axis offset and spacing.
* (TABLE) implement ability to add lines between each GUI Element to separate them more visually.
* (CALLBACK) do so you can get whatever the callback returns (unless it's void).
* * you might be able to use this: "this->callbackReturnValue = this->callback(*this) || std::monostate();". should set it to "std::monostate" if the callback is void.
* (TEXT) add support for modifying text color.
* (TEXT) add support for differently sized text.
* (TEXT) add support for text filters.
* (TOOLTIP) add support for more GUI Elements (currently supported: Button, Checkbox, Input Field).
* (COLLAPSING HEADER) add a option to do so that when it's reached the end of the Collapsing Header. it displays something to separate elements after it (Empty Text Field?, Separator?).
* (COLOR PICKER) do so you can set the color of the Color Picker when creating it.
* (SLIDER) do so you can set the default value of the Slider.
* (FONTS | CONSIDER) consider making the Fonts class static.
*
* CORE:
* add support for lists (a GUI Element that can only store 1 type of GUI Element).
* add support for multiline input fields.
* add support for images.
* add support for tree nodes.
* add drag and drop functionality.
* add support for links.
*
* LAYOUT:
* add support for empty element (element's which contain a empty text field. should primarily be used for putting a empty space between elements).
* add support for groups.
* add support for tabs.
* add support for Docking (https://github.com/ocornut/imgui/wiki/Docking).
*
* EXTENSIONS:
* add support for drawing simple shapes.
* add support for Multiple-Viewports (https://github.com/ocornut/imgui/wiki/Multi-Viewports).
*/

/* Fonts Note:
* you need to add "io.Fonts->AddFontDefault();" when adding other fonts or else the program will only use the new font.
*/

int main(int argc, char *argv[]) {
    std::filesystem::path exePath;
    if (argc == 0) {
        std::cout << "no path to executable found" << std::endl;
        return 0;
    }
    else if (argc == 1) {
        exePath = std::filesystem::path(argv[0]);
    }

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

    // Retained GUI //

    RetainedGUI retainedGUI(window, 460);

    // Fonts //

    Fonts fonts;
    fonts.addFont("Roboto", exePath.parent_path().parent_path() / "fonts\\Roboto\\Roboto-Regular.ttf", 20);

    // GUI Elements //

    Text text("TestText", "TTT");
    Checkbox<void> checkbox("TestCheck", "gfgf", [](Checkbox<void>& checkbox) { std::cout << checkbox.isChecked() << std::endl; }, "Tooltip Text");
    Button<void> button("TestBtn", "ButtonText", ImVec2(75, 25), __null, "Tooltip Text Button");
    ComboBox combobox("NameC", "DD", "ffd");
    combobox.addItem(Selectable<void>("Selectable", "Select", [](Selectable<void>& selectable) { std::cout << selectable.getName(); }));
    combobox.addItem("Selectable 2", "Select");

    InputField<void> inputField("InputFieldTest", "Input Field", [](InputField<void>& inputField) { std::cout << inputField.getInputFieldText() << std::endl; }, "Tooltip Text IF");

    Selectable<void> selectable("SelectableTest", "Selectable", [](Selectable<void>& selected) { std::cout << "selected: " << selected.getName() << std::endl; });
    Selectable<void> selectable2("SelectableTest2", "Selectable 2", [](Selectable<void>& selected) { std::cout << "selected: " << selected.getName() << std::endl; });

    ListBox listbox("ListBoxTest", "ListBox", ImVec2(50, 50));
    listbox.addItem(Selectable<void>("Select", "Select", [](Selectable<void>& selectable) { std::cout << selectable.getName(); }));
    listbox.addItem("Select2", "Select 2");

    Separator separatorNoText("SeparatorNoText");
    Separator separatorWithText("SeparatorWithText", "Separator Text");

    SameLine sameline("SameLineTest");

    Table table("TableTest", 2);
    table.addGUIElement(std::make_shared<Text>("TableText", "Table Text"));
    table.addGUIElement(std::make_shared<Checkbox<void>>("TableCheckbox", "Table Checkbox"));
    table.addGUIElement(std::make_shared<Button<void>>("TableButton", "Table Button", ImVec2(100, 25)));
    table.addGUIElement(std::make_shared<Text>("TableText2", "Table Text 2"));
    table.addGUIElement(std::make_shared<Text>("TableText3", "Table Text 3"));

    BulletText bulletText("BulletText", "Bullet Text");

    CollapsingHeader collapHeader("CollapHeader");
    collapHeader.addGUIElement(std::make_shared<Text>("CollapText", "Inside Header"));
    collapHeader.addGUIElement(std::make_shared<ComboBox>("CollapCombo", "Combo Header", "Combo"));

    ColorPicker<void> colorPicker("ColorPickerTest", "Color Picker Test", ColorFormat::RGB, ColorAlpha::ALPHA, [](ColorPicker<void>& colorPicker) { std::cout << colorPicker.getColor().x << std::endl << colorPicker.getColor().y << std::endl << colorPicker.getColor().z << std::endl << colorPicker.getColor().w << std::endl; });

    SliderFloat<void> sliderF("FloatSliderTest", "Float Slider", 1, 0.0f, 1.0f);
    SliderInt<int> sliderI("IntSliderTest", "Int Slider", 6, 0, 100, [](SliderBase<int, int>& slider) { std::cout << slider.getCurrentValues().at(0) << std::endl; return 1; });
    SliderUInt<void> sliderUI("UISliderTest", "Unsigned Int Slider", 20, 0, 100, [](SliderBase<unsigned int, void>& slider) { for (size_t i = 0; i < slider.getCurrentValues().size(); i++) { std::cout << slider.getCurrentValues().at(i) << std::endl; } });
    SliderBase<unsigned int, void> sliderB("BaseSliderTest", "Base Slider", 10, 0, 12, ImGuiDataType_::ImGuiDataType_U32);

    Text fontText("FontText", "Font Text");

    // Progress Bars.

    SimpleProgressBar simpleProgressBar("SimpleProgressBarTest", 0.0f, 1.0f, 0.01f, ProgressDirection::FORWARD, ImVec2(50, 20));
    Button<void> checkProgressButton("CheckButton", "Check Progress", ImVec2(150, 30), [&simpleProgressBar](Button<void>& button) { std::cout << simpleProgressBar.getProgress() << std::endl; });
    SameLine sameLineButtons("SameLineButtons");
    Button<void> finishedButton("FinishedButton", "Has Progress Finished", ImVec2(150, 30), [&simpleProgressBar](Button<void>& button) { std::cout << simpleProgressBar.hasFinished() << std::endl; });

    float advancedProgress = 0.0f;
    AdvancedProgressBar advancedProgressBar("AdvancedPB", advancedProgress, ImVec2(100, 20));

    ProgressBar progressBar("ProgressBar", 0.0f, 1.0f, 0.1f, ProgressDirection::FORWARD, ImVec2(100, 30));
    Button<void> updateProgressBar("UpdateProgressBar", "Update Progress Bar", ImVec2(150, 30), [&progressBar](Button<void>& button) { progressBar.update(); });

    // Tooltips.

    button.tooltip.visible = GUIElementVisibility::Visible;
    checkbox.tooltip.visible = GUIElementVisibility::Visible;
    inputField.tooltip.visible = GUIElementVisibility::Visible;

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

    gui.createWindow("Win2", "Window 2", ImVec2(400, 400), ImVec2(200, 200));

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
        retainedGUI.ImGUINewFrame();

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

        ImGui::Begin("f");
        fonts.setFont("Roboto");
        fontText.render();
        simpleProgressBar.render();
        checkProgressButton.render();
        sameLineButtons.render();
        finishedButton.render();
        bulletText.render();
        collapHeader.render();

        advancedProgressBar.render();
        if (advancedProgress < 1.0f) {
            advancedProgress += 0.1f * ImGui::GetIO().DeltaTime;
        }

        progressBar.render();
        updateProgressBar.render();

        colorPicker.render();
        sliderF.render();
        sliderI.render();
        sliderUI.render();
        sliderB.render();
        Fonts::popFont();
        ImGui::End();

        ImGui::Begin("W");
        table.render();
        ImGui::End();

        gui.renderAllWindows();

        modal.render();

        // ImGui Render.
        retainedGUI.ImGUIRender();

        // swaps GLFW window buffers and handle poll events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    gui.terminate();
    modal.terminate();

    // ImGui Shutdown.
    retainedGUI.ImGUITerminate();

    // terminates GLFW.
    glfwTerminate();
    return 0;
}
