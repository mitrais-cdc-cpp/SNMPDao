cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
 	src/*.cpp)
 
message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

include_directories(inc)  

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_library(SNMPDao SHARED ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SNMPDao PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET SNMPDao PROPERTY CXX_STANDARD 11)
set_property(TARGET SNMPDao PROPERTY CXX_STANDARD_REQUIRED ON)


###############################################################################
## generate documentation #####################################################
###############################################################################

find_package(Doxygen)
add_custom_target (doc ALL
	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doxy/*.doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxy
)

###############################################################################
## dependencies ###############################################################
###############################################################################

# THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


include_directories()
link_directories()
target_link_libraries(SNMPDao Threads::Threads)

####################
##  Installation  ##
####################

# Set installation destination folder for .so and .h files.
# Change the destination folder
###############################
set(INSTALLATION_DIR "/home/developer/git/Nemsta/env/SNMPDao/lib")
set(HEADER_DIR "/home/developer/git/Nemsta/env/SNMPDao/inc")

# Set header location that will be copied
file(GLOB HEADERS inc/*)

# Install .so file
#install(TARGETS MongoDao DESTINATION ${INSTALLATION_DIR}
#	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

INSTALL( FILES "${CMAKE_CURRENT_SOURCE_DIR}/build/libSNMPDao.so"
	DESTINATION ${INSTALLATION_DIR}
	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

# Install .h files
foreach(ITEM ${HEADERS})
   IF( IS_DIRECTORY "${ITEM}" )
      LIST( APPEND DIRS_TO_DEPLOY "${ITEM}" )
   ELSE()
      LIST( APPEND FILES_TO_DEPLOY "${ITEM}" )
   ENDIF()
endforeach()

INSTALL( FILES ${FILES_TO_DEPLOY} DESTINATION ${HEADER_DIR} 
	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

INSTALL( DIRECTORY ${DIRS_TO_DEPLOY} DESTINATION ${HEADER_DIR} )