# CMakeLists.txt for NitroHack 4.0.0

cmake_minimum_required (VERSION 2.6)
project (NitroHack)

if (WIN32)
    set(INSTALL_BASE "$ENV{USERPROFILE}")
else ()
    set(INSTALL_BASE "$ENV{HOME}")
endif ()

# default installation paths in $HOME/nitrohack
if (NOT BINDIR)
    set (BINDIR "${INSTALL_BASE}/nitrohack/nitrohack-data"
         CACHE PATH "binary location" )
endif()

if (NOT LIBDIR)
    set (LIBDIR "${INSTALL_BASE}/nitrohack/nitrohack-data"
         CACHE PATH "library location" )
endif()

if (NOT DATADIR)
    set (DATADIR "${INSTALL_BASE}/nitrohack/nitrohack-data"
         CACHE PATH "data location" )
endif()

if (NOT SHELLDIR)
    set (SHELLDIR "${INSTALL_BASE}/nitrohack"
         CACHE PATH "launch script location" )
endif()

set (ALL_STATIC FALSE CACHE BOOL "Fully static build")
if (NOT ALL_STATIC)
    set (LIB_TYPE SHARED)
else ()
    add_definitions(-fPIC -DSTATIC_BUILD)
    set (LIB_TYPE STATIC)
endif ()

# NitroHack server currently uses several Linux-specific apis.
# Generalizing the code to the point where it will work on other systems
# is not impossible, but the work has not been done.
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set (ENABLE_SERVER TRUE CACHE BOOL "Build the NitroHack network server")
else ()
    set (ENABLE_SERVER FALSE)
endif ()



if (CMAKE_COMPILER_IS_GNUCC)
    set (CMAKE_C_FLAGS_DEBUG "-Wall -g3 -Wold-style-definition -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wpointer-arith")
    if (UNIX)
	add_definitions (-fvisibility=hidden)
    endif ()
endif ()

# nitrohack core
add_subdirectory (libnitrohack)

# nitrohack network client
add_subdirectory (libnitrohack_client)

# nitrohack text ui
add_subdirectory (nitrohack)

if (ENABLE_SERVER)
    add_subdirectory (nitrohack_server)
endif ()
