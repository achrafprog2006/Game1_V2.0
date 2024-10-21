#include"Panel.h"
Panel::Panel(GLFWwindow*window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    initData();
}
 void Panel::render() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Edit ");
    
    data["less"] = ImGui::Button("less") ? 1 : 0;
    data["always"] = ImGui::Button("always") ? 1 : 0;
    data["never"] = ImGui::Button("never") ? 1 : 0;
    data["equal"] = ImGui::Button("equal") ? 1 : 0;
    data["greater"] = ImGui::Button("greater") ? 1 : 0;
    data["not equal"] = ImGui::Button("not equal") ? 1 : 0;
    data["up"] = ImGui::Button("update") ? 1 : 0;

    ImGui::InputFloat("B", &data["C"], 0.0001, 0.5f, "%.00001f");
    ImGui::InputFloat("C", &data["B"], 0.0001, 0.5f, "%.00001f");

    ImGui::SliderFloat("a", &data["a"], 0.0f, 2);
    ImGui::SliderFloat("b", &data["b"], 0.0f, 1);
    ImGui::SliderFloat("c", &data["c"], 0.0f, 1);
    ImGui::SliderFloat("fov", &data["fov"], 0.0f, 360.0f);
    ImGui::SliderFloat("near", &data["near"], 0.01f, 0.1f);
    ImGui::SliderFloat("far", &data["far"], 0.0f, 100);
    ImGui::SliderFloat("height", &data["height"], 0.0f, 2000.0f);
    ImGui::SliderFloat("width", &data["width"], 0.0f, 2000.0f);
    ImGui::SliderFloat("n", &data["n"], 0.0f, 3.0f);
    ImGui::SliderFloat("select", &data["select"], 0.0f, 2);
    data["select"] = (data["select"] < 1) ? 0 : 1;
    ImGui::End();
    ImGui::Render();
}
 void Panel::destroy() {
     ImGui_ImplOpenGL3_Shutdown();
     ImGui_ImplGlfw_Shutdown();
     ImGui::DestroyContext();
 }
 void Panel::update() {
     ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
 }
 void Panel::initData() {
     data["far"] = 5.0f;
     data["near"] = .01f;
     data["a"] = 0;
     data["fov"] = 45.0f;
     data["ya"] = .2f;
     data["n"] = 1.0f;
     data["xd"] = 1;
     data["yd"] = 1;
     data["zd"] = 1;
 }
