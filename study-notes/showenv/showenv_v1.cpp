#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

/************************************************************
* Practice
*
* Program: showenv
* Purpose: Search and display a specific environment variable value.
*
* Requirements:
*   - Accept an environment variable name as a command-line argument.
*   - Validate that the executable name is 'showenv'.
*   - Compare the argument with environment variable keys (before '=').
*   - Return 0 on success, -1 on failure with an error message.
*
* Execution:
*   cd C:\Users\jisun\cpac\OOP345\Lecture\showenv\x64\Debug
*   .\showenv.exe APPDATA
*************************************************************/

int main(int argc, char* argv[], char* env[]) {
	for (int i = 0; env[i]; i++) {
		cout << env[i] << endl;
	}

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

//File Matching Validation
	if (argc < 2) {
		cout << "Error: Environment Variable Name Needed" << endl;
		return -1;
	}

	const char* argName = argv[1];
	bool found = false;
	for (size_t i = 0; env[i]; i++) {
		char tmpEnvName[256]{};
		size_t j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=' && j<255) {
			tmpEnvName[j] = env[i][j];
			j++;
		}
		tmpEnvName[j] = '\0';
		if (strcmp(argName, tmpEnvName) == 0) {
			found = true;
			cout << argName << ": " << &env[i][j + 1] << endl;
			break;
		}
	}
	if (!found) {
		cout << "Error: " << argName << " not found" << endl;
		return -1;
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution Time: " << duration.count() << " ms" << endl;
	return 0;
}



/************************************************************
* Reflection
*
* Algorithm: Linear Search
*
* Time Complexity: O(N * M)
*   - N: Number of environment variables.
*   - M: Average length of the environment strings.
*   - The program performs a linear scan through the env[] array,
*     parsing each string to extract the key for comparison.
*
* Space Complexity: O(1)
*   - Uses a fixed-size 256-byte buffer (tmpEnvName) on the stack.
*   - Space consumption does not scale with input size.
*
* Note: The execution time is measured in microseconds for precision,
*       though the output string labels it as 'ms'.
*************************************************************/