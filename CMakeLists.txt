cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

# Include odb cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS mysql)
include(${ODB_USE_FILE})

###############################################################################
## file globbing ##############################################################
###############################################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/Entity)
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/inc")
set(SNMPDao_SOURCES
	src/Connector.cpp)

set(SNMPDao_ODB_HEADERS
	inc/Entity/MonitorHistory.hpp
	inc/Entity/NetworkElement.hpp
	inc/Entity/NetworkElemetsToSNMPValues.hpp
	inc/Entity/SNMPValues.hpp)


# Compile the entity to ODB generated file
odb_compile(SNMPDao_SOURCES FILES ${SNMPDao_ODB_HEADERS} DB mysql GENERATE_QUERY GENERATE_SESSION)


###############################################################################
## target definitions #########################################################
###############################################################################

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

#Generate the shared library from the sources
add_library(SNMPDao SHARED
	${SNMPDao_SOURCES}
	${SNMPDao_ODB_HEADERS})

target_link_libraries(SNMPDao
	${ODB_LIBRARIES})

target_include_directories(SNMPDao
	PRIVATE
		${ODB_INCLUDE_DIRS}
		${ODB_COMPILE_OUTPUT_DIR})
target_compile_definitions(SNMPDao
	PRIVATE
		DATABASE_MYSQL)


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