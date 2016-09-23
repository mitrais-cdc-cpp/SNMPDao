cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# receive argument which the default one is mysql.
# the supported database: mysql, mssql
# usage: cmake -Ddatabase=[database] ..
set(database "mysql" CACHE STRING "mysql")
option (database "database" ON)


# terminate the process if the supplied database technology is not supported.
if(NOT (database STREQUAL "mysql" OR database STREQUAL "mssql"))
	message ("Unsupported database " ${database} ". Process is aborted.")
	message ("The supported ones are: mysql, mssql.")
	return()
endif()

set(COMPILATION_OUTPUT_FILE_NAME "SNMPDaoTest-${database}")
project(${COMPILATION_OUTPUT_FILE_NAME} VERSION 0.2 LANGUAGES CXX)
set(_ECLIPSE_VERSION "4.5")


###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
 *.h
 *.cpp)

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(${COMPILATION_OUTPUT_FILE_NAME} ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET ${COMPILATION_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${COMPILATION_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

#set warning level
set_property(TARGET ${COMPILATION_OUTPUT_FILE_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS "-Wno-deprecated")

###############################################################################
## dependencies ###############################################################
###############################################################################

# SNMPDao        
set(SNMP_DAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../build)  
set(SNMP_DAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../inc)  
find_library(  
	SNMP_DAO_LIBRARIES  
	NAMES SNMPDao-mysql 
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../build  
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)  

# ODB
set(ODB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb/lib)  
set(ODB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb/include)  
find_library(  
	ODB_LIBRARIES  
	NAMES odb libodb
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/odb/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)

# ODB_MYSQL
set(ODB_MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mysql/lib)  
set(ODB_MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mysql/include)  
find_library(  
	ODB_MYSQL_LIBRARIES  
	NAMES odb-mysql libodb-mysql
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mysql/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)


#MYSQL_CONNECTOR
set(MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib)  
set(MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/include)  
find_library(  
	MYSQL_LIBRARIES  
	NAMES mysqlclient_r
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH
)
	
# CPPUNIT
set(CPP_UNIT_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/cppunit/lib)  
set(CPP_UNIT_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/cppunit/include)  
find_library(  
	CPP_UNIT_LIBRARIES  
	NAMES cppunit cppunit_dll cppunitd cppunitd_dll
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/cppunit/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)



target_include_directories(${COMPILATION_OUTPUT_FILE_NAME} PRIVATE
					${SNMP_DAO_INCLUDE_DIRS}
					${SNMP_DAO_INCLUDE_DIRS}/Entity
					${ODB_INCLUDE_DIRS}
					${ODB_MYSQL_INCLUDE_DIRS}
					${CPP_UNIT_INCLUDE_DIRS}
					${MYSQL_INCLUDE_DIRS})
					
link_directories(${SNMP_DAO_LIBRARY_DIRS}
				 ${CPP_UNIT_LIBRARY_DIRS}
				 ${ODB_LIBRARY_DIRS}
				 ${ODB_MYSQL_LIBRARY_DIRS}
				 ${MYSQL_LIBRARY_DIRS})
				 
target_link_libraries(${COMPILATION_OUTPUT_FILE_NAME}
					  ${SNMP_DAO_LIBRARIES}
					  ${ODB_LIBRARIES}
					  ${ODB_MYSQL_LIBRARIES}
					  ${CPP_UNIT_LIBRARIES}
					  ${MYSQL_LIBRARIES}
					  ${CMAKE_DL_LIBS})
					  
target_compile_definitions(${COMPILATION_OUTPUT_FILE_NAME} PRIVATE DATABASE_MYSQL)