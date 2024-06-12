#include <windows.h>
#include <stdio.h>

/// @brief Open the serial port
/// @param port_name Should be the "COM3", "COM4", "COM5"...
/// @return the HANDLE of COM
HANDLE Open_SerialPort(const char *port_name);

/// @brief Get the opened serial port params
/// @param hComm The handle of opened serial port
/// @param psDcbSerialParams The serial params structure
/// @return 0 - success , -1 - fail
BOOL Get_SerialPort_Params(HANDLE hComm, DCB *psDcbSerialParams);

/// @brief Set the opened serial port params
/// @param hComm The handle of opened serial port
/// @param psDcbSerialParams The serial params structure
/// @return 0 - success , -1 - fail
BOOL Set_SerialPort_Params(HANDLE hComm, DCB *psDcbSerialParams);

BOOL readFromPort(HANDLE hComm, char *buffer, DWORD bufferSize, DWORD *bytesRead);

BOOL writeToPort(HANDLE hComm, const char *data, DWORD dataSize, DWORD *bytesWritten);
