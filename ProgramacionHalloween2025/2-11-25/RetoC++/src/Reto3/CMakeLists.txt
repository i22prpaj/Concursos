# Crear librería para Reto3
add_library(Reto3 Reto3.cpp Reto3.hpp)

# Hacer públicos los headers
target_include_directories(Reto3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
