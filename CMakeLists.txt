cmake_minimum_required(VERSION 3.7)
project(Force3)

set(CMAKE_CXX_STANDARD 11)

# Réglages pour la compilation de SFML
link_directories(./SFML/lib/)
include_directories(./SFML/include/)

# Ajouter SFML à la compilation
add_subdirectory(./SFML/)

# Mettre en place le répertoire de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp)
add_executable(Force3 ${SOURCE_FILES})

# Link de SFML pour la compilation
target_link_libraries(Force3 sfml-graphics sfml-system sfml-window)

# Copie des librairies dans le résultat de compilation
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/SFML/cmake-build-debug/lib/" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin/")