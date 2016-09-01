cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

# Include odb cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS boost mysql)
include(${ODB_USE_FILE})

###############################################################################
## file globbing ##############################################################
###############################################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/Entity)
set(SNMPDao_SOURCES
	src/MySQLFactory.cpp)

set(SNMPDao_HEADERS
	inc/DBFactory.hpp
	inc/MySQLFactory.hpp)

set(SNMPDao_ODB_SOURCES
	inc/odb_gen/ItemizedObject_odb.cpp
	inc/odb_gen/MonitorHistory_odb.cpp
	inc/odb_gen/NetworkElement_odb.cpp
	inc/odb_gen/ObjectSnmp_odb.cpp
	inc/odb_gen/SnmpObjectType_odb.cpp
	inc/odb_gen/SnmpObjectValue_odb.cpp
	)
set(SNMPDao_ODB_HEADERS
	inc/Entity/ItemizedObject.hpp
	inc/Entity/MonitorHistory.hpp
	inc/Entity/NetworkElement.hpp
	inc/Entity/ObjectSnmp.hpp
	inc/Entity/SnmpObjectType.hpp
	inc/Entity/SnmpObjectValue.hpp)


# Compile the entity to ODB generated file
odb_compile(SNMPDao_SOURCES FILES ${SNMPDao_ODB_HEADERS} DB mysql PROFILE boost GENERATE_QUERY GENERATE_SESSION)


###############################################################################
## target definitions #########################################################
###############################################################################

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# BOOST
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.61 EXACT COMPONENTS system date_time  REQUIRED)
message(STATUS "Boost Version: ${Boost_VERSION_STRING}")

#Generate the shared library from the sources
add_library(SNMPDao SHARED
	${SNMPDao_SOURCES}
	${SNMPDao_ODB_SOURCES})

target_link_libraries(SNMPDao
	${Boost_LIBRARIES}
	${ODB_LIBRARIES})

message("check include dirs:  ${ODB_INCLUDE_DIRS}")
target_include_directories(SNMPDao
	PRIVATE
		${Boost_INCLUDE_DIRS}
		${ODB_INCLUDE_DIRS}
		${ODB_COMPILE_OUTPUT_DIR})
target_compile_definitions(SNMPDao
	PRIVATE
		DATABASE_MYSQL)

add_definitions("-Wdeprecated-declarations") 

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
set(INSTALLATION_DIR "SNMPDao/lib")
set(HEADER_DIR "SNMPDao/inc")
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env/" CACHE PATH "default install path" FORCE )
endif()

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