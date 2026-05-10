#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

/************************************************************
/* practice
* 
* Program: showenv
* Purpose: Search and display environment variables provided via command-line arguments.
*
* Requirements:
*   - Accept multiple environment variable names as arguments.
*   - Compare arguments with the keys in the 'env' array (part before '=').
*   - Maintain data integrity (do not modify env strings).
*   - Return 0 on success (all found), -1 on failure (if any variable is missing).
*
* Execution:
* cd C:\Users\jisun\cpac\OOP345\Lecture\showenv\x64\Debug
* .\showenv.exe APPDATA LOCALAPPDATA
*************************************************************/

int main(int argc, char* argv[], char* env[]) {
	//for (int i = 0; env[i]; i++) {
	//	cout << env[i] << endl;
	//}

	auto start = chrono::high_resolution_clock::now();

	//File Name Validation
	size_t fnStartIndex = -1;
	for (size_t i = 0; argv[0][i] != '\0'; i++) {
		if (argv[0][i] == '/' || argv[0][i] == '\\') fnStartIndex = i;
	}
	const char* targetFileName = "showenv";
	bool fnMatched = true;
	int i = 0;
	while (targetFileName[i] != '\0') {
		if (argv[0][fnStartIndex + 1 + i] != targetFileName[0 + i]) {
			fnMatched = false;
			break;
		}
		i++;
	}
	if (fnMatched == false) {
		cout << "Error: Invalid File Name" << endl;
		return -1;
	}

	if (argc < 2) {
		cout << "Error: Environment Variable Name Needed" << endl;
		return -1;
	}
	for (int a = 1; a < argc; a++) {
		const char* argName = argv[a];
		bool found = false;
		for (size_t i = 0; env[i]; i++) {
			char tmpEnvName[256]{};
			size_t j = 0;
			while (env[i][j] != '\0' && env[i][j] != '=' && j < 255) {
				tmpEnvName[j] = env[i][j];
				j++;
			}
			tmpEnvName[j] = '\0';

			if (strcmp(argName, tmpEnvName) == 0) {
				found = true;
				cout << argName << " => " << &env[i][j + 1] << endl;
				break;
			}
		}
		if (!found) {
			cout << "Error: " << argName << " not found" << endl;
			return -1;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution Time: " << duration.count() << " ms" << endl;
	return 0;
}



/************************************************************
* Reflection
*
* Algorithm: Multi-Argument Linear Search
*
* Time Complexity: O(A * N * M)
*   - A: Number of command-line arguments (argc - 1)
*   - N: Total number of environment variables in env[]
*   - M: Average length of each environment string (for extraction and comparison)
*   - For each argument, the program scans the entire env list until found.
*
* Space Complexity: O(M)
*   - Uses a constant 256-byte stack-allocated buffer (tmpEnvName) for key extraction.
*   - No dynamic memory allocation used (O(1) additional space excluding buffer).
*
* Note: Execution time measured in microseconds for higher precision.
*************************************************************/