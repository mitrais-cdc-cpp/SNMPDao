# SNMPDao Project
It's an Data Access Object library to communicate between database and Nemsta application.
The supported databases are mysql and mssql.

### How to compile:
Before you compile the project, the destination directory for installation need to be adjusted to appropriate location, it's located on CmakeList.txt on Installation section.

1. create folder 'build' with $mkdir build in project root
2. switch directory to build with $ cd build

The next step will depend on your preference database tool.

Note: to use mysql database:
3. run cmake with $cmake .. or $cmake -Ddatabase=mysql .. (if you want to install this lib on default location), OR
4. run cmake with $cmake .. -DCMAKE_INSTALL_PREFIX=/path/to/custom/location or $cmake -Ddatabase=mysql .. -DCMAKE_INSTALL_PREFIX=/path/to/custom/location (if you want to install this lib to the custom location)
5. run make install with $make install

Note: to use mssql database:
3. run cmake with $cmake -Ddatabase=mssql .. (if you want to install this lib on default location), OR
4. run cmake with $cmake -Ddatabase=mssql .. -DCMAKE_INSTALL_PREFIX=/path/to/custom/location (if you want to install this lib to the custom location)
5. run make install with $make install

Important: if you specified any unsupported database, the compilation will be terminated.

### How to run the test:
1. from root directory, go to folder "test" then create "build" folder
2. switch directory to build with $ cd build
3. run cmake with $ cmake ..
4. run make with $ make
5. run the test with $ ./SNMPDao_Test



