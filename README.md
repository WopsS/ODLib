# ODLib

[![Build Status](https://travis-ci.org/WopsS/ODLib.svg?branch=master)](https://travis-ci.org/WopsS/ODLib)
[![Build status](https://ci.appveyor.com/api/projects/status/vb8v76uqojfp60oy?svg=true)](https://ci.appveyor.com/project/WopsS/odlib)

An open-source library that contains useful classes for C++ projects.

## Build instructions

### Requirements

* **[PREMAKE 5](https://github.com/premake/premake-core/releases)**.

### Windows

1. Download and install **[Visual Studio 2017 Community Edition](https://www.visualstudio.com/)** or a higher version.
2. Clone this repository.
3. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into **Premake** directory.
11. Go to the **Premake** directory and run **GenerateVisualStudioProject.bat**.
12. Open the solution (**ODLib.sln**) located in **Premake/Project** directory.
13. Build the project.

### Linux

1. Download and install a **C++ compiler**.
2. Clone this repository.
3. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into **Premake** directory.
4. Go to the **Premake** directory and run **GenerateGNUMakeProject.sh**.
5. Build the project by running the `make` command into **Premake/Project** directory.