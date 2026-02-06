#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "funciones.h"

using namespace std;

int main() {
    // 1. Inicialización de GLFW
    if (!glfwInit()) return 1;

    // Configuración para macOS (Core Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Tres en Raya - ImGui", NULL, NULL);
    if (!window) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Habilita V-Sync

    // 2. Inicializar Contextos de ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    // --- VARIABLES DEL JUEGO (Persistentes) ---
    char tablero[3][3] = {{'V','V','V'},{'V','V','V'},{'V','V','V'}};
    int jugador1[3] = {0, 0, 0};
    int jugador2[3] = {0, 0, 0};
    int turnos1 = 0, turnos2 = 0;
    bool turnoJ1 = true, ganado = false;
    string estado = "Turno: Jugador 1 (X)";

    // 4. Bucle principal
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Iniciar el frame de ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // --- INTERFAZ DEL JUEGO ---
        ImGui::Begin("Tablero de Juego");
        ImGui::Text("%s", estado.c_str());
        ImGui::Spacing();

        // Dibujamos el tablero 3x3
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Creamos un ID único para cada botón basado en su posición
                string etiqueta = string(1, tablero[i][j]) + "##" + to_string(i) + to_string(j);

                if (ImGui::Button(etiqueta.c_str(), ImVec2(80, 80))) {
                    // Solo permitimos jugar si la casilla está vacía ('V') y nadie ha ganado
                    if (tablero[i][j] == 'V' && !ganado) {
                        int pos = (i + 1) * 10 + (j + 1); // Conversión a tu formato de lógica

                        if (turnoJ1) {
                            jugador1[turnos1 % 3] = pos; // Guarda la ficha (reemplaza la 1ª si hay > 3)
                            turnos1++;

                            // REFRESCO DEL TABLERO: Limpiar y redibujar posiciones actuales
                            reiniciar(tablero, 3);
                            posiciones1(tablero, jugador1, 3);
                            posiciones2(tablero, jugador2, 3);

                            if (comprobar(jugador1, 3)) {
                                estado = "¡GANA JUGADOR 1!";
                                ganado = true;
                            } else {
                                turnoJ1 = false;
                                estado = "Turno: Jugador 2 (O)";
                            }
                        } else {
                            jugador2[turnos2 % 3] = pos;
                            turnos2++;

                            // REFRESCO DEL TABLERO: Limpiar y redibujar posiciones actuales
                            reiniciar(tablero, 3);
                            posiciones1(tablero, jugador1, 3);
                            posiciones2(tablero, jugador2, 3);

                            if (comprobar(jugador2, 3)) {
                                estado = "¡GANA JUGADOR 2!";
                                ganado = true;
                            } else {
                                turnoJ1 = true;
                                estado = "Turno: Jugador 1 (X)";
                            }
                        }
                    }
                }
                if (j < 2) ImGui::SameLine(); // Pone los botones en la misma fila
            }
        }

        ImGui::Spacing();
        if (ImGui::Button("Reiniciar Partida", ImVec2(256, 30))) {
            reiniciar(tablero, 3);
            for(int k=0; k<3; k++) { jugador1[k]=0; jugador2[k]=0; }
            turnos1 = turnos2 = 0;
            ganado = false;
            turnoJ1 = true;
            estado = "Turno: Jugador 1 (X)";
        }

        ImGui::End();

        // RENDERIZADO
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Fondo gris oscuro
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // 5. Limpieza final
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}