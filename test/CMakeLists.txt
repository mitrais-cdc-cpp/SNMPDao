cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPDao_Test VERSION 0.1 LANGUAGES CXX)

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
add_executable(SNMPDao_Test ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SNMPDao_Test PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET SNMPDao_Test PROPERTY CXX_STANDARD 11)
set_property(TARGET SNMPDao_Test PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# SNMPDao        
set(SNMP_DAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../build)  
set(SNMP_DAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../inc)  
find_library(  
	SNMP_DAO_LIBRARIES  
	NAMES SNMPDao  
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

# ODB_BOOST
set(ODB_BOOST_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-boost/lib)  
set(ODB_BOOST_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-boost/include)  
find_library(  
	ODB_BOOST_LIBRARIES  
	NAMES odb-boost libodb-boost
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/odb-boost/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)

# BOOST
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.61 EXACT COMPONENTS date_time  REQUIRED)
message(STATUS "Boost Version: ${Boost_VERSION_STRING}")

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


include_directories(${SNMP_DAO_INCLUDE_DIRS}
					${SNMP_DAO_INCLUDE_DIRS}/Entity
					${ODB_INCLUDE_DIRS}
					${ODB_MYSQL_INCLUDE_DIRS}
					${ODB_BOOST_INCLUDE_DIRS})
link_directories(${SNMP_DAO_LIBRARY_DIRS}
				 ${CPPUNIT_LIBRARY}
				 ${ODB_LIBRARY_DIRS}
				 ${ODB_MYSQL_LIBRARY_DIRS}
				 ${ODB_BOOST_LIBRARY_DIRS})
target_link_libraries(SNMPDao_Test
					  ${SNMP_DAO_LIBRARIES}
					  ${ODB_LIBRARIES}
					  ${ODB_MYSQL_LIBRARIES}
					  ${ODB_BOOST_LIBRARIES}
					  ${CPPUNIT_LIBRARY}
					  ${CMAKE_DL_LIBS})
					  