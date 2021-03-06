#include "port_filesystem.h"
#include <string>
/*
#ifndef DIR
#define DIR __dirstream_t *
#endif
*/

#ifdef __linux__
	#include <limits.h>
	#include <libgen.h>
	#include <iostream>
	#include <unistd.h>
	#include <stdarg.h>
	#include <sys/stat.h>
    #include <filesystem>
    #include <cstdio>

	#define MAX_PATH PATH_MAX
	#define _chdir chdir

	extern "C" {
    	#include "findfirst.h"
	}

	std::string getExePath() {
		std::string strpathx;
		char result[ PATH_MAX ];
		ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
		if (count != -1) {
			strpathx = dirname(result);
		}
		return strpathx;
	}
#endif 

std::filesystem::path gamepath("");
char biggraphicspath[512] = "biggraphics/";
char gamepathout[512];
char fixsound[512] = "fix-sound\\";
char fixsoundout[512];


#ifdef _MSC_VER
std::string utf8_encode(const std::wstring &wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}
#endif

char oldpathx[512];
bool firstrun = true;

std::filesystem::path pathfix(const std::filesystem::path& path)
{
	// prefix paths that are releative to the gamedir so that they are absolute paths
#ifdef __linux__
	if (std::filesystem::exists(path))
		return path;
	else
		return gamepath / path;
#else
	if (firstrun)
	{
		#ifdef _MSC_VER
		LPWSTR buffer = new WCHAR[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		std::string locstr = utf8_encode(buffer);
		std::string::size_type pos = std::string(locstr).find_last_of("\\/");
		std::string strpathx = std::string(locstr).substr(0, pos)/*+"\\system.exe"*/;
		#else
		char* buffer = new char[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		std::string strpathx = std::string(buffer).substr(0, pos)/*+"\\system.exe"*/;
		#endif
		char* pathx = (char*)strpathx.c_str();
		delete[] buffer;
		strcpy(oldpathx, pathx);
		firstrun = false;
	}

	sprintf(fixsoundout, "%s\\%s", oldpathx, fixsound);
	sprintf(gamepathout, "%s\\%s", oldpathx, gamepath);
	

	if ((path[0] == 'c') || (path[0] == 'C'))
	{
		long len = strlen(path);
		char* fixstring = (char*)gamepathout;//(char*)"c:/prenos/Magic2/mc2-orig-copy";
		long fixlen = strlen(fixstring);
		for (int i = len;i > 1;i--)
			path2[i + fixlen - 2] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
	}
	else
	{
		long len = strlen(path);
		char* fixstring = (char*)gamepathout;//(char*)"c:/prenos/Magic2/mc2-orig-copy/";
		long fixlen = strlen(fixstring);
		for (int i = len;i > -1;i--)
			path2[i + fixlen+1] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
		path2[fixlen] = '\\';
	}
#endif
}

std::string get_exe_path() {
	#ifdef _MSC_VER
	LPWSTR buffer = new WCHAR[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string locstr = utf8_encode(buffer);
	std::string::size_type pos = std::string(locstr).find_last_of("\\/");
	std::string strpathx = std::string(locstr).substr(0, pos)/*+"\\system.exe"*/;
	sprintf(retpath, "%s", (char*)strpathx.c_str());
	delete[] buffer;
	return retpath.c_str();
	#else
	return getExePath();
	#endif
};


void pathfix2(char* path, char* path2)
{
	#ifdef _MSC_VER
	LPWSTR buffer = new WCHAR[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string locstr = utf8_encode(buffer);
	std::string::size_type pos = std::string(locstr).find_last_of("\\/");
	std::string strpathx = std::string(locstr).substr(0, pos)/*+"\\system.exe"*/;
	#else
	std::string strpathx = getExePath();
	#endif
	char* pathx = (char*)strpathx.c_str();
	sprintf(fixsoundout,"%s%s%s", pathx, std::filesystem::path::preferred_separator, fixsound);
	sprintf(gamepathout, "%s%s%s", pathx, std::filesystem::path::preferred_separator, gamepath);

	#ifdef _MSC_VER
	if ((path[0] == 'c') || (path[0] == 'C'))
	{
		long len = strlen(path);
		char* fixstring = (char*)gamepath;//(char*)"c:/prenos/Magic2/mc2-orig-copy";
		long fixlen = strlen(fixstring);
		for (int i = len;i > 1;i--)
			path2[i + fixlen - 2] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
	}
	else
	{
		long len = strlen(path);
		char* fixstring = (char*)fixsoundout;//(char*)"c:/prenos/Magic2/mc2-orig-copy/NETHERW/sound/";
		//char* fixstring = (char*)"c:/prenos/Magic2/mc2-orig-copy/NETHERW/sound/";
		long fixlen = strlen(fixstring);
		for (int i = len;i > -1;i--)
			path2[i + fixlen] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
	}
	delete[] buffer;
	#endif
}

void unpathfix(char* path, char* path2)
{
	/*if ((path[0] == 'c') || (path[0] == 'C'))
	{
		long len = strlen(path);
		char* fixstring = (char*)"c:/prenos/Magic2/mc2-orig-copy";
		long fixlen = strlen(fixstring);
		for (int i = len;i > 1;i--)
			path2[i + fixlen - 2] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
	}
	else
	{
		long len = strlen(path);
		char* fixstring = (char*)"c:/prenos/Magic2/mc2-orig-copy/";
		long fixlen = strlen(fixstring);
		for (int i = len;i > -1;i--)
			path2[i + fixlen] = path[i];
		for (int i = 0;i < fixlen;i++)
			path2[i] = fixstring[i];
	}*/
	strcpy(path2, "c:/");//fix this
}

long my_findfirst(char* path, _finddata_t* c_file){
	#ifdef DEBUG_START
		debug_printf("my_findfirst:%s\n", path);
	#endif //DEBUG_START
	std::filesystem::path abs_path = pathfix(path);//only for DOSBOX version
	#ifdef DEBUG_START
		debug_printf("my_findfirst:fixed:%s\n", path);
	#endif //DEBUG_START
	long result= _findfirst(abs_path.c_str(), c_file);
	#ifdef DEBUG_START
			debug_printf("my_findfirst:end:%d\n", result);
	#endif //DEBUG_START
	return result;
}

long my_findnext(long hFile, _finddata_t* c_file){
	long result = _findnext(hFile, c_file);
	#ifdef DEBUG_START
		debug_printf("my_findnext:end:%d\n", result);
	#endif //DEBUG_START
	return result;
}

void my_findclose(long hFile){
	_findclose(hFile);
};

bool fix_file_exists(const char* filename) {
	/*if (FILE * file = fopen(filename, "r")) {
		fclose(file);
		return true;
	}
	return false;*/
	char path2[512] = "\0";
	pathfix2((char*)filename, path2);//only for DOSBOX version
	FILE* file;
	if ((file = fopen(path2, "r")) != NULL) {
		fclose(file);
#ifdef DEBUG_START
		debug_printf("ffile_exists:true-%s\n%s\n", filename, path2);
#endif //DEBUG_START
		return true;
	}
#ifdef DEBUG_START
	debug_printf("ffile_exists:false-%s\n%s\n", filename, path2);
#endif //DEBUG_START
	return false;
}

bool file_exists(const char * filename) {
	/*if (FILE * file = fopen(filename, "r")) {
		fclose(file);
		return true;
	}
	return false;*/
	FILE* file;
	if ((file = fopen(filename, "r")) != NULL) {
		fclose(file);
		#ifdef DEBUG_START
				debug_printf("file_exists:true-%s\n", filename);
		#endif //DEBUG_START
		return true;
	}
	#ifdef DEBUG_START
		debug_printf("file_exists:false-%s\n", filename);
	#endif //DEBUG_START
	return false;
}

FILE* mycreate(const char* path, Bit32u flags) {
	FILE *fp;
	std::filesystem::path abs_path = pathfix(path);//only for DOSBOX version
	fp = fopen(abs_path.c_str(), "wb+");
	#ifdef DEBUG_START
		debug_printf("mycreate:%p\n",fp);
	#endif //DEBUG_START
	return fp;
};

FILE* debug_output;

bool debug_first = true;
const char* debug_filename = "debug.txt";

void debug_printf(const char* format, ...) {
	char prbuffer[1024];
	va_list arg;
	int done;
	va_start(arg, format);
	done = vsprintf(prbuffer, format, arg);
	va_end(arg);

	if (debug_first)
	{
		debug_output = fopen(debug_filename, "wt");
		debug_first = false;
	}
	else
		debug_output = fopen(debug_filename, "at");
	fprintf(debug_output, prbuffer);
	fclose(debug_output);
	#ifdef DEBUG_PRINT_DEBUG_TO_SCREEN
		printf(prbuffer);
	#endif
}

Bit32s /*__cdecl*/ mymkdir(char* path) {
	#ifdef DEBUG_FILEOPS
		debug_printf("mymkdir:path: %s\n", path);
	#endif //DEBUG_FILEOPS
	std::filesystem::path abs_path = pathfix(path);

	#ifdef DEBUG_FILEOPS
		debug_printf("mymkdir:path2: %s\n", abs_path);
	#endif //DEBUG_FILEOPS

#ifdef WIN32
	const WCHAR *pwcsName;
	// required size
	int nChars = MultiByteToWideChar(CP_ACP, 0, path2, -1, NULL, 0);
	// allocate it
	pwcsName = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, path2, -1, (LPWSTR)pwcsName, nChars);
	// use it....
#ifdef DEBUG_FILEOPS
	debug_printf("mymkdir:path3: %s\n", pwcsName);
#endif //DEBUG_FILEOPS
#endif




	int result;
#if defined (WIN32)						/* MS Visual C++ */
	result = _wmkdir(pwcsName);
	delete[] pwcsName;
#else
	result = mkdir(abs_path.c_str(), 0700);
#endif

#ifdef DEBUG_FILEOPS
	debug_printf("mymkdir:end: %d\n", result);
#endif //DEBUG_FILEOPS
	return result;
};

FILE* myopen(const char* path, int pmode, Bit32u flags) {
	std::string type;
	#ifdef __linux__
	type = "r";
	#else
	type = "rb+";
	#endif
	FILE *fp;
	std::filesystem::path abs_path = pathfix(path);//only for DOSBOX version

	bool exists = std::filesystem::exists(abs_path);
	const char* tmppath = abs_path.c_str();
	fp=std::fopen(tmppath, type.c_str());

	return fp;
};
int myclose(FILE* descriptor) {
	return fclose(descriptor);
};
Bit32s mylseek(FILE* filedesc, x_DWORD position, char type) {
	return fseek(filedesc, position, type);
};

Bit32s myfseek(FILE* filedesc, x_DWORD position, char type) {
	return fseek(filedesc, position, type);
};

long myftell(FILE* decriptor) {
	return ftell(decriptor);
};



int x_chdir(const char* path) {
	std::filesystem::path abs_path = pathfix(path);
	int result = _chdir(abs_path.c_str());
	return result;
};// weak

char* x_getcwd(x_DWORD a, x_DWORD b) {
	char cwd[512] = "\0";	
	if (getcwd(cwd, 512) == NULL)
		perror("getcwd() error");
	char* path2 = (char*)malloc(512);
	unpathfix(cwd, path2);	
	return path2;
};

FILE* myopent(char* path, char* type) {
	FILE *fp;
	char path2[512] = "\0";
	pathfix2(path, path2);//only for DOSBOX version
	//if(file_exists(path2))

	fp=fopen(path2, type);
	#ifdef DEBUG_FILEOPS
		debug_printf("myopent:end: %p\n", fp);
	#endif //DEBUG_FILEOPS
	return fp;
};

dirsstruct getListDir(char* dirname)
{
	struct dirent *de;  // Pointer for directory entry 
	dirsstruct directories;
	directories.number = 0;
	// opendir() returns a pointer of DIR type.  
	DIR *dr = opendir(dirname);
	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		printf("Could not open current directory1 %s\n", dirname);
		return directories;
	}
	// Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
	// for readdir() 
	while ((de = readdir(dr)) != NULL)
	{
		if(de->d_name[0]!='.')
			sprintf(directories.dir[directories.number++],"%s", de->d_name);
		//printf("%s\n", de->d_name);		
	}
	closedir(dr);
	return directories;
}

void FixDir(char* outdirname, char* indirname) {
	sprintf(outdirname, "%s/%s", get_exe_path().c_str(), indirname);
};
/*

dirsstruct getListDirFix(char* indirname)
{
	struct dirent *de;  // Pointer for directory entry 
	dirsstruct directories;
	directories.number = 0;
	// opendir() returns a pointer of DIR type.  
	char path2[512] = "\0";
	sprintf(path2,"%s/%s", get_exe_path().c_str(),indirname);

	DIR *dr = opendir(path2);
	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		printf("Could not open current directory2 %s\n", path2);
		return directories;
	}
	// Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
	// for readdir() 
	while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] != '.')
			sprintf(directories.dir[directories.number++], "%s", de->d_name);
		//printf("%s\n", de->d_name);		
	}
	closedir(dr);
	return directories;
}
*/

int dos_getdrive(int* a) {
#ifdef WIN32
	*a = _getdrive();
#else
	*a = 0;
	std::cerr << "STUB: dos_getdrive on Linux" << std::endl;
#endif
	return *a;
}

void AdvReadfile(const char* path, Bit8u* buffer) {
	char path2[512];
	sprintf(path2, "%s/%s", get_exe_path().c_str(), path);
	/*
	FILE* file0;
	fopen_s(&file0, path2, (char*)"wb");
	char x = 1;
	fwrite(&x, 1, 1, file0);
	myclose(file0);
	*/
	FILE* file;
	//fopen_s(&file, (char*)"c:\\prenos\\remc2\\biggraphics\\out_rlt-n-out.data", (char*)"rb");
	file=fopen(path2, (char*)"rb");
	fseek(file, 0L, SEEK_END);
	long szdata = ftell(file);
	fseek(file, 0L, SEEK_SET);
	fread(buffer, szdata, 1, file);
	myclose(file);
};

bool ExistGraphicsfile(const char* path) {
	char path2[512];
	sprintf(path2, "%s/%s%s", get_exe_path().c_str(), biggraphicspath, path);

	FILE* file;

	if ((file = fopen(path2, "r")) != NULL) {
		fclose(file);
#ifdef DEBUG_START
		debug_printf("ffile_exists:true-%s\n", path2);
#endif //DEBUG_START
		return true;
	}
#ifdef DEBUG_START
	debug_printf("ffile_exists:false-%s\n", path2);
#endif //DEBUG_START
	return false;
}

void ReadGraphicsfile(const char* path, Bit8u* buffer, long size) {
	char path2[512];
	sprintf(path2, "%s/%s%s", get_exe_path().c_str(), biggraphicspath, path);

	/*FILE* file0;
	fopen_s(&file0, path2, (char*)"wb");
	char x = 1;
	fwrite(&x, 1, 1, file0);
	myclose(file0);*/

	FILE* file;
	//fopen_s(&file, (char*)"c:\\prenos\\remc2\\biggraphics\\out_rlt-n-out.data", (char*)"rb");
	file = fopen(path2, (char*)"rb");
	if (size == -1)
	{
		fseek(file, 0L, SEEK_END);
		size = ftell(file);
		fseek(file, 0L, SEEK_SET);
	}
	fread(buffer, size, 1, file);
	myclose(file);
};
