cmake_minimum_required(VERSION 3.22.1)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/historico.cpp
                src/usuario.cpp 
                src/node.cpp
                src/arvore.cpp
                src/main.cpp
                )
