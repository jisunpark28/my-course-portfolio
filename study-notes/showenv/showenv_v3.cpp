#include <iostream>
#include <cstring>
#include <chrono>
#include <unordered_map>
using namespace std;

/************************************************************
* Practice 
*
* Program: showenv (Hash Map Version)
* Purpose: Search and display environment variables using an optimized Hash Table.
*
* Requirements:
*   - Accept environment variable name(s) as command-line arguments.
*   - Validate that the executable name is 'showenv'.
*   - Map all 'env' strings into a Hash Map for O(1) average lookup.
*   - Return 0 on success, -1 on failure (invalid filename or missing arguments).
*
* Execution:
*   cd C:\Users\jisun\cpac\OOP345\Lecture\showenv\x64\Debug
*   .\showenv.exe APPDATA LOCALAPPDATA
*************************************************************/

int main(int argc, char* argv[], char* env[]) {
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
	unordered_map<string, string> dict;
	for (int i = 0; env[i]; i++) {
		string envKeyValue = env[i];

		auto pos = envKeyValue.find("=");
		auto key = envKeyValue.substr(0, pos);
		auto value = envKeyValue.substr(pos + 1, envKeyValue.length() - pos - 1);

		dict[key] = value;
	}

	for (int i = 1; i < argc; i++) {
		auto key = argv[i];
		cout << key << " => " << dict[key] << endl;
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution Time: " << duration.count() << " ms" << endl;
	return 0;
}



/************************************************************
* Reflection
*
* Algorithm: Hash Map Lookup (std::unordered_map)
*
* Time Complexity: O(N*M + A*M)
*   - Pre-processing (Map construction): O(N * M)
*     (N: Total number of environment variables, M: Average length of strings)
*   - Lookup: O(A * M) on average
*     (A: Number of Arguments, M: String hashing/comparison time)
*   - Difference from Linear Search: Instead of O(A*N*M), we trade initial
*     processing time (N) for significantly faster repeated lookups (A).
*
* Space Complexity: O(N * M)
*   - Unlike the Linear Search's O(1) additional space, the Hash Map approach
*     requires storing all environment variables in memory (heap-allocated).
*
* Note: Execution time measured in microseconds.
*************************************************************/