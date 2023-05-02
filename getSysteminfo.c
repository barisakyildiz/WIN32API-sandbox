#include <windows.h>
#include <stdio.h>



int main(){

    ULONGLONG a;
    BOOL b;
    b = GetPhysicallyInstalledSystemMemory(&a);
    printf("Installed RAM is: %lu Kilobytes", a);

    return 0;
}