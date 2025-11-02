# Crear librería para Reto4
add_library(Reto4 Reto4.cpp Reto4.hpp)

# Hacer públicos los headers
target_include_directories(Reto4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
