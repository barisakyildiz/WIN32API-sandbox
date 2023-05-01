#include <windows.h>
#include <stdio.h>

STARTUPINFO si = { 0 };
PROCESS_INFORMATION pi = { 0 };

int main(){


    if(!CreateProcessW(

        L"C:\\Windows\\System32\\notepad.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        BELOW_NORMAL_PRIORITY_CLASS,
        NULL,
        NULL,
        &si,
        &pi


    )){
        printf("(-) failed to create process, %ld", GetLastError());
        return EXIT_FAILURE;
    }

    printf("(+) process started! pid: %ld\n", pi.dwProcessId);
    printf("\tPID: %ld --> Handle:0x%x\n", pi.dwProcessId, &pi.hProcess);
    printf("\tTID: %ld --> Handle:0x%x\n", pi.dwThreadId, &pi.hThread);

    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("(+) Exited Successfully PID: %ld", pi.dwProcessId);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return EXIT_SUCCESS;
}