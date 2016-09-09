cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao VERSION 0.2 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

# Include odb cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

#TODO: set ODB path
find_package(ODB REQUIRED COMPONENTS mysql)
include(${ODB_USE_FILE})

###############################################################################
## file globbing ##############################################################
###############################################################################

#tell odb where to find included from generated headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/Entity)

set(SNMPDao_SOURCES
	src/DataAccess.cpp
	src/MySQLFactory.cpp)

set(SNMPDao_ODB_SOURCES
	inc/odb_gen/ItemizedObject_odb.cpp
	inc/odb_gen/MonitorHistory_odb.cpp
	inc/odb_gen/NetworkElement_odb.cpp
	inc/odb_gen/SnmpObject_odb.cpp
	inc/odb_gen/SnmpObjectType_odb.cpp
	inc/odb_gen/SnmpObjectValue_odb.cpp)
	
set(SNMPDao_ODB_HEADERS
	inc/Entity/ItemizedObject.hpp
	inc/Entity/MonitorHistory.hpp
	inc/Entity/NetworkElement.hpp
	inc/Entity/SnmpObject.hpp
	inc/Entity/SnmpObjectType.hpp
	inc/Entity/SnmpObjectValue.hpp)


# Compile the entity to ODB generated file
odb_compile(SNMPDao_SOURCES FILES ${SNMPDao_ODB_HEADERS} DB mysql STANDARD c++11 GENERATE_QUERY GENERATE_SESSION)


###############################################################################
## target definitions #########################################################
###############################################################################

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

add_library(SNMPDao SHARED ${SNMPDao_SOURCES} ${SNMPDao_ODB_SOURCES})
target_compile_definitions(SNMPDao PRIVATE LIBODB_MYSQL_INCLUDE_SHORT=1)


###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET SNMPDao PROPERTY CXX_STANDARD 11)
set_property(TARGET SNMPDao PROPERTY CXX_STANDARD_REQUIRED ON)

#set warning level
set_property(TARGET SNMPDao APPEND_STRING PROPERTY COMPILE_FLAGS "-Wno-deprecated")


###############################################################################
## generate documentation #####################################################
###############################################################################

find_package(Doxygen)
add_custom_target (doc ALL
	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doxy/*.doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxy)

###############################################################################
## dependencies ###############################################################
###############################################################################

#MYSQL
set(MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib)  
set(MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/include)  
find_library(  
	MYSQL_LIBRARIES  
	NAMES mysqlclient
	PATHS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH)

target_link_libraries(SNMPDao ${ODB_LIBRARIES} ${MYSQL_LIBRARIES})
target_include_directories(SNMPDao PRIVATE ${ODB_INCLUDE_DIRS} ${ODB_COMPILE_OUTPUT_DIR} ${MYSQL_INCLUDE_DIRS})
target_compile_definitions(SNMPDao PRIVATE DATABASE_MYSQL)


###############################################################################
## installation ###############################################################
###############################################################################

set(INSTALLATION_DIR "SNMPDao/lib")
set(HEADER_DIR "SNMPDao/inc")

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env/" CACHE PATH "default install path" FORCE )
endif()

# Set header location that will be copied
file(GLOB HEADERS inc/*)

# Install .so file
INSTALL( FILES "${CMAKE_CURRENT_BINARY_DIR}/libSNMPDao.so"
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

###############################################################################
## clean ######################################################################
###############################################################################

if(UNIX)
    add_custom_target (distclean @echo cleaning generated cmake-files)
    add_custom_command(
        COMMENT "cmake generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        COMMAND rm ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt
        TARGET  distclean)

    add_custom_target (projclean @echo cleaning generated project-files)
    add_custom_command(
        COMMENT "project generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".csettings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".settings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".project" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".cproject" | xargs rm -rf
        TARGET  projclean)

    add_custom_target (clean-all @echo cleaning generated project- and cmake-files)
    add_custom_command(
        COMMENT "cmake & project generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "build" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".csettings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".settings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".project" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".cproject" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        COMMAND rm ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt
        TARGET  clean-all)
endif(UNIX)
