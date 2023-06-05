cmake_minimum_required(VERSION 3.20.0)
project(Sidemafy)

include_directories( include )

add_executable(Sidemafy 
               include/Music.h 
               include/Node.h 
               include/LinkedList.h 
               include/Playlist.h
               include/PlaylistsManager.h
               include/SongsManager.h
               include/Menus.h
               include/Sidemafy.h
               main.cpp )