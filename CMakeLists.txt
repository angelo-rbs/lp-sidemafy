cmake_minimum_required(VERSION 3.20.0)
project(Sidemafy)
include_directories( include )
set ( CMAKE_CXX_FLAGS "-Wall" )
add_executable( program
                main.cpp
                src/GerenciadorMusica.cpp
                src/GerenciadorPlaylist.cpp
                src/LinkedList.cpp
                src/Menu.cpp
                src/Musica.cpp
                src/Node.cpp
                src/Playlist.cpp )