
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib> 

using namespace std;


			// USE . AS A DELIMITER. LANGUAGE USED: C++

void RunProcess() {
	string input; // define string input
	cout << " Enter Process Name: " << endl;     // print on console
	cin >> input;  // user input 


	HANDLE hProcess = NULL;   // create a handle for your process
	HANDLE hThread = NULL;    // create a thread handler
	STARTUPINFO si;           // start info 
	PROCESS_INFORMATION pi;    // process info, we will get process id from it
	DWORD dwProcessId = 0;
	DWORD dwThreadId = 0;
	ZeroMemory(&si, sizeof(si)); // initialze structures to 0
	ZeroMemory(&pi, sizeof(pi));
	BOOL createprocess = NULL;  // create process variable. boolean type
	string p = "c:\\windows\\" + input + ".exe" ;   // merge user input





	/* createprocess = CreateProcess( L"C:\\Program Files\\Windowslayer.exe",
	NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); */     // THIS IS HARD CODED
	//convert string into Long Pointer to Const. TO CHAR
	std::wstring stemp = std::wstring(p.begin(), p.end());
	LPCWSTR sw = stemp.c_str();
	
	

	// create process function with 10 parameters using user input and then converting it into long pointer
	 createprocess = CreateProcess(sw,
		NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); 
	






	if (createprocess == FALSE) {
		cout << "Create process Failed & Error No - " << GetLastError() << endl;
	}
	else {
		cout << "Create process Success " << endl;
		cout << "Process Id: " << pi.dwProcessId << endl;
		cout << "Thread Id: " << pi.dwThreadId << endl;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);  // terminate process first then the program
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}
	int Add() {
		double result = 0;
		cout << " Enter numbers: " << endl;
		char str[200];
		scanf("%s", str);
		char* token = strtok(str, ".");

		// Keep printing tokens while one of the 
		// delimiters present in str[]. 
		while (token != NULL) {
			result = atof(token)+result;
			token = strtok(NULL, ".");
		}

		return result;
	}


double Mul() {
	double result = 1;
	cout << " Enter numbers: " << endl;
	char str[200];
	scanf("%s", str);
	char* token = strtok(str, ".");

	// Keep printing tokens while one of the 
	// delimiters present in str[]. 
	while (token != NULL) {
		result = atof(token)*result;
		token = strtok(NULL, ".");
	}

	return result;

}
double Sub() {
	double result = 0;
	cout << " Enter numbers: " << endl;
	char str[200];
	scanf("%s", str);
	char* token = strtok(str, ".");
	result = atof(token);
	token = strtok(NULL, ".");
	// Keep printing tokens while one of the 
	// delimiters present in str[]. 
	while (token != NULL) {
		result -= atof(token);
		token = strtok(NULL, ".");
	}

	return result;
}
double Div() {
	double result = 1;
	cout << " Enter numbers: " << endl;
	char str[200];
	scanf("%s", str);
	char* token = strtok(str, ".");
	result = atof(token);
	 token = strtok(NULL, ".");
	// Keep printing tokens while one of the 
	// delimiters present in str[]. 
	while (token != NULL) {
		result /= atof(token);
		token = strtok(NULL, ".");
	}

	return result;


}

void App(string in) {
	if (in == "Add")
	{
		 int x =Add();
		
		 cout << x;
	}
	if (in == "Subtract")
	{
		int x = Sub();
		cout << x;
	}
	if (in == "Multiply")
	{

		int x = Mul();
		cout << x;
	}
	if (in == "Divide")
	{

		double x = Div();
		cout << x;
	}
	if (in == "RunProcess")
	{
		RunProcess();
	}
	if (in == "Help")
	{
		cout << " The Program encorporates a basic Calculator and a Process Creator, Write RunProcess in the console and then enter -->notepad<-- to execute. When entering numbers for Calculator, use . as a delimiter" << endl;

	}
	if (in == "Exit")
	{
		exit(0);
	}
}


































int main()
{

	
	char in[500] = " " ;
	
	while (in != "Exit") {
		cout << "Enter ----> Add/Subtract/Multiply/Divide/RunProcess/Help/Exit" << endl;
		cin >> in;
		App(in);
		cout << "\n";
	}
	exit(0);
}



