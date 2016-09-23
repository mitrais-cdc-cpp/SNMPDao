cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao_Test VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

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
	../inc/MsSQLFactory.hpp

	../src/DataAccess.cpp
	../src/MySQLFactory.cpp
			
	 *.h
	 *.cpp)

	
###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(SNMPDao_Test ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)
target_compile_definitions(SNMPDao_Test PRIVATE LIBODB_MYSQL_INCLUDE_SHORT=1)

# just for example add some compiler flags
#target_compile_options(SNMPDao_Test PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET SNMPDao_Test PROPERTY CXX_STANDARD 11)
set_property(TARGET SNMPDao_Test PROPERTY CXX_STANDARD_REQUIRED ON)

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



#MYSQL

set(MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib)  
set(MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/include)  
find_library(  
	MYSQL_LIBRARIES  
	NAMES mysqlclient
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/mysql-connector/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH)

#target_link_libraries(${COMPILATION_OUTPUT_FILE_NAME} ${ODB_LIBRARIES} ${MYSQL_LIBRARIES})
#target_include_directories(${COMPILATION_OUTPUT_FILE_NAME} PRIVATE ${ODB_INCLUDE_DIRS} ${ODB_COMPILE_OUTPUT_DIR} ${MYSQL_INCLUDE_DIRS})
#target_compile_definitions(${COMPILATION_OUTPUT_FILE_NAME} PRIVATE DATABASE_MYSQL)



include_directories(${SNMP_DAO_INCLUDE_DIRS}
					${SNMP_DAO_INCLUDE_DIRS}/Entity
					${ODB_INCLUDE_DIRS}
					${ODB_MYSQL_INCLUDE_DIRS}
					${MYSQL_INCLUDE_DIRS})
					
link_directories(${SNMP_DAO_LIBRARY_DIRS}
				 ${CPPUNIT_LIBRARY}
				 ${ODB_LIBRARY_DIRS}
				 ${ODB_MYSQL_LIBRARY_DIRS})
				 
target_link_libraries(SNMPDao_Test
					  ${SNMP_DAO_LIBRARIES}
					  ${ODB_LIBRARIES}
					  ${ODB_MYSQL_LIBRARIES}
					  ${MYSQL_LIBRARIES}
					  ${CPPUNIT_LIBRARY}
					  ${CMAKE_DL_LIBS})
					  