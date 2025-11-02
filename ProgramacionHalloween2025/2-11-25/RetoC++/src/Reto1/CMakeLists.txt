# Crear librería para Reto1
add_library(Reto1 Reto1.cpp Reto1.hpp)

# Hacer públicos los headers
target_include_directories(Reto1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
