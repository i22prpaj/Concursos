# Crear el ejecutable principal
add_executable(RetoC++ RetoC++.cpp)

# Configurar la salida del ejecutable en la carpeta que queremos
set_target_properties(RetoC++ PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    #RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Enlazar con todas las librerías de los retos
target_link_libraries(RetoC++ 
    Reto1
    Reto2
    Reto3
    Reto4
)

# Incluir directorios de headers
target_include_directories(RetoC++ 
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src/Reto1
    ${CMAKE_SOURCE_DIR}/src/Reto2
    ${CMAKE_SOURCE_DIR}/src/Reto3
    ${CMAKE_SOURCE_DIR}/src/Reto4
)
