cmake_minimum_required(VERSION 4.0)
project(TresEnRaya)

# 1. Configuración del estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Buscar dependencias (GLFW3)
# Asegúrate de tenerlo instalado con: brew install glfw
find_package(glfw3 REQUIRED)

# 3. Definir la ruta de ImGui (asumiendo que está en una carpeta llamada 'imgui')
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

# 4. Lista de archivos fuente de ImGui
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# 5. Configuración del Icono para macOS
# El archivo debe llamarse AppIcon.icns y estar en la raíz del proyecto
set(MACOS_ICON ${CMAKE_CURRENT_SOURCE_DIR}/AppIcon.icns)
set_source_files_properties(${MACOS_ICON} PROPERTIES MACOSX_BUNDLE_LOCATION Resources)

# 6. CREAR EL EJECUTABLE (Target)
# Incluimos tus archivos, los de ImGui y el icono
add_executable(MiProyectoGui
        main.cpp
        funciones.cpp
        ${IMGUI_SOURCES}
        ${MACOS_ICON}
)

# 7. Configurar las propiedades del Bundle de macOS (.app)
set_target_properties(MiProyectoGui PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_ICON_FILE AppIcon.icns
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.matias.tresenraya"
        MACOSX_BUNDLE_BUNDLE_NAME "Tres En Raya"
)

# 8. Directorios de inclusión (Cabeceras)
target_include_directories(MiProyectoGui PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

# 9. Vinculación de librerías y Frameworks de Apple
target_link_libraries(MiProyectoGui PRIVATE
        glfw
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework OpenGL"
)
