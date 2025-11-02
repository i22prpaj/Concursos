# Crear librería para Reto2
add_library(Reto2 Reto2.cpp Reto2.hpp)

# Hacer públicos los headers
target_include_directories(Reto2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
