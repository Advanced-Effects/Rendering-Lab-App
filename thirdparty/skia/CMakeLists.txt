#
# Friction - https://friction.graphics
#
# Copyright (c) Ole-André Rodlie and contributors
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.12)

message("")
message("-- Hello Skia!")

include(ExternalProject)
include(ProcessorCount)

ProcessorCount(N)


option(USE_SKIA_SYSTEM_LIBS "Use skia (third-party) system libraries on Linux" ON)
option(LINUX_DEPLOY "Linux Deploy" OFF)
option(MAC_DEPLOY "Mac Deploy" OFF)
option(SYNC_SKIA_DEPS "Sync third-party depends" ON)

if(UNIX AND NOT APPLE)
    option(USE_EGL "Use EGL" ON)
endif()

set(SKIA_SRC "${CMAKE_CURRENT_SOURCE_DIR}/skia")
set(SKIA_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/skia")
message("-- SKIA_SRC: ${SKIA_SRC}")
message("-- SKIA_BUILD_DIR: ${SKIA_BUILD_DIR}")


message("-- Setting up variables to pass to ExternalProject_Add")
include(SetupSkiaVariables)
message("   source code directory: ${SKIA_SRC}")
message("   build directory: ${SKIA_BUILD_DIR}")
message("   update command: ${SKIA_UPDATE_CMD}")
message("   build command: ${SKIA_BUILD_CMD}")
message(" skia argumentss: ${SKIA_ARGS}")


message("-- Building skia as ExternalProject Engine")
ExternalProject_Add(
    Engine
    SOURCE_DIR ${SKIA_SRC}
    BINARY_DIR ${SKIA_BUILD_DIR}
    DOWNLOAD_COMMAND :
    UPDATE_COMMAND ${SKIA_UPDATE_CMD}
    PATCH_COMMAND :
    CONFIGURE_COMMAND ${GN_PATH} gen --root=${SKIA_SRC} ${SKIA_BUILD_DIR} "--args=${SKIA_ARGS}" ${SKIA_ARGS_EXTRA}
    BUILD_COMMAND ${SKIA_BUILD_CMD}
    INSTALL_COMMAND :
    USES_TERMINAL_UPDATE true
    USES_TERMINAL_CONFIGURE true
    USES_TERMINAL_BUILD true
)


if(UNIX AND NOT APPLE)
    #include(CopySkiaLibraryToInstallDir)
endif()


if(WIN32)
    add_custom_command(TARGET Engine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SKIA_BUILD_DIR}/skia.dll.lib ${SKIA_BUILD_DIR}/skia.lib)
endif()

