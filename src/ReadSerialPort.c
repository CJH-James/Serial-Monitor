#include <stdio.h>
#include <signal.h>

#include "serialPort.h"


volatile sig_atomic_t stop = 0;
// Signal handler for Ctrl + C
void handle_sigint(int sig)
{
    printf("Get Terminate!");
    stop = 1;
}

int main()
{
    HANDLE hComm = NULL;
    DCB dcbSerialParams = {0};
    int ret = 0;

    signal(SIGINT, handle_sigint); // Register signal handler for Ctrl + C

    // Open the com
    hComm = Open_SerialPort("COM3");

    ret = Get_SerialPort_Params(hComm, &dcbSerialParams);
    if (ret)
    {
        printf("Fail to set the serial port\n");
        system("pause");
        return 0;
    }

    // --- Read Serial Port
    DWORD bytesRead;
    char buffer[1000];

    while (!stop)
    {
        if (ReadFile(hComm, buffer, sizeof(buffer), &bytesRead, NULL))
        {
            if (bytesRead > 0)
            {
                buffer[bytesRead] = '\0'; // Null-terminate the string
                // printf("Read %d bytes: %s\n", bytesRead, buffer);
                printf("%s", buffer);
            }
        }
        else
        {
            printf("Error reading from port\n");
            return FALSE;
        }
    }

    CloseHandle(hComm);

    return 0;
}
