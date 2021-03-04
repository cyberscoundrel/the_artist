# Spackster's build system
A non-intrusive build system utilizing cmake to build projects by source with an emphasis that libraries are also linked by source. Only con is the that the CMakeLists.txt it depends on is located in this folder and will have to be updated from the parent project's. Please keep that in mind.
## Requirements
This build system depends on bash. It was created and tested in Windows Subsystem for Linux. Requires:
 - bash
 - cmake
 - a compiler of some sort supported by cmake

## Tasks
 - `setup` for first time setup, downloads and configures libraries. installs them in the 'libs' folder.
 - `build` builds the cmake file according to the CMakeLists.txt in this folder. Run `setup` before running this command.
 - `run` runs the application if it has been built by the `built` command.
 - `clean` quickly deletes specific folders according to arguements. c = cmake, s = sandbox, l = libs, each arguement is seperated by spaces.

To build the parent project, just run the above commands in order from top to bottom. 
