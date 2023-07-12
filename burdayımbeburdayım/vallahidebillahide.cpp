#include <Windows.h>
#include <stdio.h>

DWORD PID = NULL;
LPVOID rBuffer = NULL;
HANDLE hProcess = NULL;
HANDLE hThread = NULL;

unsigned char kemalKýlýcdaroglu[] = "\x41\x41\x41\x41\x41\x41\x41\x41\x41";

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("usage: program.exe <PID>");
		return EXIT_FAILURE;
	}

	PID = atoi(argv[1]);
	printf("trying to open a handle to process (%ld)\n", PID);

	//OPENING PROCESS HANDLE
	hProcess = OpenProcess(
		PROCESS_ALL_ACCESS,
		FALSE,
		PID
	);

	if (hProcess == NULL) {
		printf("Couldn't get a handle to the process (%ld)", GetLastError());
		return EXIT_FAILURE;
	}

	printf("got a handle to the process! \n\\---0x%p\n", hProcess);

	//ALLOCATE BYTES TO THE PROCESS MEMORY
	rBuffer = VirtualAllocEx(hProcess, NULL, sizeof(kemalKýlýcdaroglu), (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);

	if (rBuffer == NULL) {
		printf("Virtual memory allocation didn't go the way as expected, exiting...\n");
		return EXIT_FAILURE;
	}
	printf("allocated %zu-bytes with PAGE_EXECUTE_READWRITE permissions\n", sizeof(kemalKýlýcdaroglu));

	return EXIT_SUCCESS;
}