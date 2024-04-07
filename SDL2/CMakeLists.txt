if(MSVC)
    set(SDL2_SHARED_LIB "SDL2.dll")
    set(SDL2_STATIC_LIB "SDL2.lib")
    set(PLAT_DIR "windows-x86-msvc")
elseif(MINGW)
    set(SDL2_SHARED_LIB "SDL2.dll")
    set(SDL2_STATIC_LIB "SDL2.lib")
    set(PLAT_DIR "windows-x86-mingw")
elseif(UNIX)
    set(SDL2_SHARED_LIB "libSDL2.so")
    set(PLAT_DIR "linux-x86-gcc")
endif()

add_library(sim_SDL2 SHARED IMPORTED)

set_target_properties(
    sim_SDL2
    PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/include"
        IMPORTED_IMPLIB "${CMAKE_CURRENT_LIST_DIR}/lib/${PLAT_DIR}/${SDL2_STATIC_LIB}"
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/lib/${PLAT_DIR}/${SDL2_SHARED_LIB}"
        INTERFACE_LINK_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/lib/${PLAT_DIR}"
        INTERFACE_LINK_LIBRARIES "SDL2main"
)
