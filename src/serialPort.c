#include "serialPort.h"

HANDLE Open_SerialPort(const char *port_name)
{
    HANDLE hComm = CreateFile(port_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
    if (hComm == INVALID_HANDLE_VALUE)
    {
        printf("Error opening serial port\n");
    }
    return hComm;
}

BOOL Get_SerialPort_Params(HANDLE hComm, DCB *psDcbSerialParams)
{

    if (!GetCommState(hComm, psDcbSerialParams))
    {
        printf("Error getting port state\n");
        return -1;
    }

    return 0;
}

BOOL Set_SerialPort_Params(HANDLE hComm, DCB *psDcbSerialParams)
{

    if (!SetCommState(hComm, psDcbSerialParams))
    {
        printf("Error setting port state\n");
        return -1;
    }
    return 0;
}

BOOL readFromPort(HANDLE hComm, char *buffer, DWORD bufferSize, DWORD *bytesRead)
{
    if (!ReadFile(hComm, buffer, bufferSize, bytesRead, NULL))
    {
        printf("Error reading from port\n");
        return FALSE;
    }
    return TRUE;
}

BOOL writeToPort(HANDLE hComm, const char *data, DWORD dataSize, DWORD *bytesWritten)
{
    if (!WriteFile(hComm, data, dataSize, bytesWritten, NULL))
    {
        printf("Error writing to port\n");
        return FALSE;
    }
    return TRUE;
}
