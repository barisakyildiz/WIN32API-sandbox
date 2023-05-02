#include <windows.h>
#include <stdio.h>

void systemMemory(){
    ULONGLONG totalMemory;
    BOOL tr_or_fls;
    tr_or_fls = GetPhysicallyInstalledSystemMemory(&totalMemory);
    printf("Installed RAM is: %lu Kilobytes", totalMemory);
}

/*
void firmwareTables(){
    DWORD firmware_table_signature = 'ACPI';
    VOID* firmware_table_buffer;
    DWORD buffer_size = 1024000000;
    UINT returnValue;

    returnValue = EnumSystemFirmwareTables(firmware_table_signature, firmware_table_buffer, buffer_size);
    printf("\n%lu\n\n", returnValue);
    printf("\n%lu\n\n", firmware_table_buffer);

}

void getComputerName(){
    COMPUTER_NAME_FORMAT name_type = ComputerNameNetBIOS;
    LPWSTR lp_buffer;
    LPDWORD n_size;
    BOOL retValue;

    retValue = GetComputerNameExW(name_type, lp_buffer, n_size);
    printf("\n\n%s\n\n", *lp_buffer);
}
*/ //Gonna fix these

int main(){

    getComputerName();

    return 0;
}