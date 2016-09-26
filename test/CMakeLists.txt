cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# receive argument which the default one is mysql.
# the supported database: mysql, mssql
# usage: cmake -Ddatabase=[database] ..
SET(database "mysql" CACHE STRING "mysql")
option (database "database" ON)


# terminate the process if the supplied database technology is not supported.
if(NOT (database STREQUAL "mysql" OR database STREQUAL "mssql"))
	message ("Unsupported database " ${database} ". Process is aborted.")
	message ("The supported ones are: mysql, mssql.")
	return()
endif()

set (TESTSUITE_EXECUTABLE_FILE_NAME "TestSuite_SNMPDao-${database}")

project(${TESTSUITE_EXECUTABLE_FILE_NAME} VERSION 0.2 LANGUAGES CXX)
set(_ECLIPSE_VERSION "4.5")


###############################################################################
## file globbing ##############################################################
###############################################################################

if(database STREQUAL "mysql")
	file(GLOB SOURCES
		../inc/odb_gen/ItemizedObject_odb.cpp
		../inc/odb_gen/MonitorHistory_odb.cpp
		../inc/odb_gen/NetworkElement_odb.cpp
		../inc/odb_gen/SnmpObject_odb.cpp
		../inc/odb_gen/SnmpObjectType_odb.cpp
		../inc/odb_gen/SnmpObjectValue_odb.cpp
	
		../inc/Entity/ItemizedObject.hpp
		../inc/Entity/MonitorHistory.hpp
		../inc/Entity/NetworkElement.hpp
		../inc/Entity/SnmpObject.hpp
		../inc/Entity/SnmpObjectType.hpp
		../inc/Entity/SnmpObjectValue.hpp
	
		../inc/DataAccess.hpp
		../inc/DBFactory.hpp
		../inc/MySQLFactory.hpp
	
		../src/DataAccess.cpp
		../src/MySQLFactory.cpp
				
		TestMySQLFactory.hpp
		TestMySQLFactory.cpp
		main.cpp)
				
elseif(database STREQUAL "mssql")
	
	file(GLOB SOURCES
		../inc/odb_gen/ItemizedObject_odb.cpp
		../inc/odb_gen/MonitorHistory_odb.cpp
		../inc/odb_gen/NetworkElement_odb.cpp
		../inc/odb_gen/SnmpObject_odb.cpp
		../inc/odb_gen/SnmpObjectType_odb.cpp
		../inc/odb_gen/SnmpObjectValue_odb.cpp
	
		../inc/Entity/ItemizedObject.hpp
		../inc/Entity/MonitorHistory.hpp
		../inc/Entity/NetworkElement.hpp
		../inc/Entity/SnmpObject.hpp
		../inc/Entity/SnmpObjectType.hpp
		../inc/Entity/SnmpObjectValue.hpp
	
		../inc/DataAccess.hpp
		../inc/DBFactory.hpp
		../inc/MicrosoftSQLFactory.hpp
	
		../src/DataAccess.cpp
		../src/MicrosoftSQLFactory.cpp
				
		 TestMicrosoftSQLFactory.hpp
		 TestMicrosoftSQLFactory.cpp
		 main.cpp)
endif()




	
###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(${TESTSUITE_EXECUTABLE_FILE_NAME} ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)
target_compile_definitions(${TESTSUITE_EXECUTABLE_FILE_NAME} PRIVATE LIBODB_MYSQL_INCLUDE_SHORT=1)

# just for example add some compiler flags
#target_compile_options(${TESTSUITE_EXECUTABLE_FILE_NAME} PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET ${TESTSUITE_EXECUTABLE_FILE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${TESTSUITE_EXECUTABLE_FILE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

#set warning level
set_property(TARGET ${COMPILATION_OUTPUT_FILE_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS "-Wno-deprecated")

# in attemp to suppress warning of boost <auto-ptr> within all the following directories
#set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../inc APPEND_STRING PROPERTY COMPILE_FLAGS "-Wno-deprecated")


###############################################################################
## dependencies ###############################################################
###############################################################################

# CPPUNIT
find_library(CPPUNIT_LIBRARY_DEBUG NAMES cppunit cppunit_dll cppunitd cppunitd_dll
            	PATHS  
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES debug )

find_library(CPPUNIT_LIBRARY_RELEASE NAMES cppunit cppunit_dll
            PATHS   ${PATH}/lib
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES release )

if(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)
    set(CPPUNIT_LIBRARY_RELEASE ${CPPUNIT_LIBRARY_DEBUG})
endif(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)

set( CPPUNIT_LIBRARY debug ${CPPUNIT_LIBRARY_DEBUG} optimized ${CPPUNIT_LIBRARY_RELEASE} )


# SNMPDao-database (either mysql or mssql)        
set(SNMP_DAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../build)  
set(SNMP_DAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../inc)  
find_library(  
	SNMP_DAO_LIBRARIES  
	NAMES SNMPDao-${database}
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




if(database STREQUAL "mysql")
	
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
	
	#MYSQL-Connector
	set(MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib)  
	set(MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/include)  
	find_library(  
		MYSQL_LIBRARIES  
		NAMES mysqlclient
		PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib
		PATH_SUFFIXES "lib"  
		NO_DEFAULT_PATH)

	
	include_directories(${SNMP_DAO_INCLUDE_DIRS}
						${SNMP_DAO_INCLUDE_DIRS}/Entity
						${ODB_INCLUDE_DIRS}
						${ODB_MYSQL_INCLUDE_DIRS}
						${MYSQL_INCLUDE_DIRS})
						
	link_directories(${SNMP_DAO_LIBRARY_DIRS}
					 ${CPPUNIT_LIBRARY}
					 ${ODB_LIBRARY_DIRS}
					 ${ODB_MYSQL_LIBRARY_DIRS})
					 
	target_link_libraries(${TESTSUITE_EXECUTABLE_FILE_NAME}
						  ${SNMP_DAO_LIBRARIES}
						  ${ODB_LIBRARIES}
						  ${ODB_MYSQL_LIBRARIES}
						  ${MYSQL_LIBRARIES}
						  ${CPPUNIT_LIBRARY}
						  ${CMAKE_DL_LIBS})
						  				
elseif(database STREQUAL "mssql")
		
	# ODB MSSQL
	set(ODB_MSSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mssql/lib)  
	set(ODB_MSSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mssql/include)  
	find_library(  
		ODB_MSSQL_LIBRARIES  
		NAMES odb-mssql libodb-mssql
		PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-mssql/lib
		PATH_SUFFIXES "lib"  
		NO_DEFAULT_PATH  
	)
	
	#MSSQL connector called unix odbc
	set(UNIX-ODBC_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/unix-odbc/lib)  
	set(UNIX-ODBC_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/unix-odbc/include)  
	find_library(  
		UNIX-ODBC_LIBRARIES  
		NAMES odbc
		PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/unix-odbc/lib
		PATH_SUFFIXES "lib"  
		NO_DEFAULT_PATH)

	
	
	include_directories(${SNMP_DAO_INCLUDE_DIRS}
						${SNMP_DAO_INCLUDE_DIRS}/Entity
						${ODB_INCLUDE_DIRS}
						${ODB_MSSQL_INCLUDE_DIRS}
						${UNIX-ODBC_INCLUDE_DIRS})
						
	link_directories(${SNMP_DAO_LIBRARY_DIRS}
					 ${CPPUNIT_LIBRARY}
					 ${ODB_LIBRARY_DIRS}
					 ${ODB_MSSQL_LIBRARY_DIRS})
					 
	target_link_libraries(${TESTSUITE_EXECUTABLE_FILE_NAME}
						  ${SNMP_DAO_LIBRARIES}
						  ${ODB_LIBRARIES}
						  ${ODB_MSSQL_LIBRARIES}
						  ${UNIX-ODBC_LIBRARIES}
						  ${CPPUNIT_LIBRARY}
						  ${CMAKE_DL_LIBS})
						  		
endif()
					  