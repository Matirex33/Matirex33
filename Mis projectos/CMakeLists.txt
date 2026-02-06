cmake_minimum_required(VERSION 4.0)
project(MiProyectoGui)

set(CMAKE_CXX_STANDARD 17)

# Buscar GLFW (instalado vía Homebrew)
find_package(glfw3 REQUIRED)

# Agregar los archivos de ImGui al ejecutable
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(MiProyectoGui main.cpp funciones.cpp funciones.h ${IMGUI_SOURCES})

# Incluir las rutas de ImGui y GLFW
target_include_directories(MiProyectoGui PRIVATE ${IMGUI_DIR} ${IMGUI_DIR}/backends)

# LINKER: Aquí es donde macOS necesita sus Frameworks
target_link_libraries(MiProyectoGui PRIVATE
        glfw
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework OpenGL"
)
