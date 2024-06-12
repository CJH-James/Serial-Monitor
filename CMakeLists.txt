# Set the minimum required
cmake_minimum_required(VERSION 3.30)

# Set the project name and version
project(SerialMonitor VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Set the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Add the executable
add_executable(SerialMonitor src/ReadSerialPort.c src/serialPort.c)
