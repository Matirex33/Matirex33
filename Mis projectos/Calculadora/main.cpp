#include <iostream>
#include "funciones.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
#include "cmath"
using namespace std;

int main() {
    if (!glfwInit()) return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Calculadora", nullptr, nullptr);
    if (!window) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Habilita V-Sync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");
    string resultado="";
    string num;
    int rest=0;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("a");
        char calculadora[100][100]={{'<','A','%','/'},{'7','8','9','x'},{'4','5','6','-'},{'1','2','3','+'},{'^','0',',','='}};


        ImGui::BeginChild("CuadroResultado", ImVec2(0, 60), true);
        ImGui::Text("%s", resultado.c_str());
        ImGui::EndChild();

        for (int i=0;i<5;i++) {
            for (int j=0;j<4;j++) {
                ImGui::PushID(i * 10 + j);
                string etiqueta = string(1, calculadora[i][j]) + "##" + to_string(i) + to_string(j);
                if (ImGui::Button(etiqueta.c_str(), ImVec2(30, 30))) {
                    switch (calculadora[i][j]) {
                        case '<':
                            rest=stoi(num);
                            rest=rest/10;
                            resultado=to_string(rest);
                            break;
                        case 'A':
                            resultado=' ';
                            break;
                        case '%':
                            rest=stoi(num);
                            resultado+='%';
                            rest=rest/100;
                            break;
                        case '/':
                            resultado+='/';
                            break;
                        case '7':
                            resultado+='7';
                            num+='7';
                            break;
                        case '8':
                            resultado+='8';
                            num+='8';
                            break;
                        case '9':
                            resultado+='9';
                            num+='9';
                            break;
                        case 'x':
                            resultado+='x';
                            break;
                        case '4':
                            resultado+='4';
                            num+='4';
                            break;
                        case '5':
                            resultado+='5';
                            num+='5';
                            break;
                        case '6':
                            resultado+='6';
                            num+='6';
                            break;
                        case '-':
                            resultado+='-';
                            break;
                        case '1':
                            resultado+='1';
                            num+='1';
                            break;
                        case '2':
                            resultado+='2';
                            num+='2';
                            break;
                        case '3':
                            resultado+='3';
                            num+='3';
                            break;
                        case '+':
                            resultado+='+';
                            break;
                        case '^':
                            resultado+='^';
                            break;
                        case '0':
                            resultado+='0';
                            break;
                        case ',':
                            resultado+=',';
                            break;
                        case '=':
                            resultado=to_string(rest);
                            break;
                    }
                }
                if (j < 3) ImGui::SameLine();
                ImGui::PopID();
            }
        }
        ImGui::End();
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Fondo gris oscuro
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
}