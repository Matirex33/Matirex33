#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "funciones.h"

using namespace std;

int main() {
    if (!glfwInit()) return 1;

    // Configuración para Mac
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Tres en Raya - ImGui", NULL, NULL);
    if (!window) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    // VARIABLES DEL JUEGO
    char tablero[3][3] = {{'V','V','V'},{'V','V','V'},{'V','V','V'}};
    int jugador1[3] = {0,0,0}, jugador2[3] = {0,0,0};
    int turnos1 = 0, turnos2 = 0;
    bool turnoJ1 = true, ganado = false;
    string estado = "Turno: Jugador 1 (X)";

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Tablero de Juego");
        ImGui::Text("%s", estado.c_str());
        ImGui::Spacing();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                string etiqueta = string(1, tablero[i][j]) + "##" + to_string(i) + to_string(j);

                if (ImGui::Button(etiqueta.c_str(), ImVec2(80, 80))) {
                    if (tablero[i][j] == 'V' && !ganado) {
                        int pos = (i + 1) * 10 + (j + 1);
                        if (turnoJ1) {
                            tablero[i][j] = 'X';
                            jugador1[turnos1 % 3] = pos;
                            turnos1++;
                            if (comprobar(jugador1, 3)) { estado = "¡GANA JUGADOR 1!"; ganado = true; }
                            else { turnoJ1 = false; estado = "Turno: Jugador 2 (O)"; }
                        } else {
                            tablero[i][j] = 'O';
                            jugador2[turnos2 % 3] = pos;
                            turnos2++;
                            if (comprobar(jugador2, 3)) { estado = "¡GANA JUGADOR 2!"; ganado = true; }
                            else { turnoJ1 = true; estado = "Turno: Jugador 1 (X)"; }
                        }
                    }
                }
                if (j < 2) ImGui::SameLine();
            }
        }

        if (ImGui::Button("Reiniciar")) {
            reiniciar(tablero, 3);
            for(int i=0; i<3; i++) { jugador1[i]=0; jugador2[i]=0; }
            turnos1 = turnos2 = 0;
            ganado = false; turnoJ1 = true;
            estado = "Turno: Jugador 1 (X)";
        }
        ImGui::End();

        // RENDER
        ImGui::Render();
        int dw, dh;
        glfwGetFramebufferSize(window, &dw, &dh);
        glViewport(0, 0, dw, dh);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}