#ifndef COMMFUNC_H_
#define COMMFUNC_H_
#include <windows.h>
#include <string>
#include <vector>

//����ϵͳ
#define SYSTEM_UNKNOWN              0        //δ֪�汾
#define SYSTEM_XP                   1        //xpϵͳ
#define SYSTEM_XP_SP3               2        //xpϵͳ
#define SYSTEM_XP_64                3        //xpϵͳ
#define SYSTEM_VISTA_32             4        //vista 32λϵͳ
#define SYSTEM_VISTA_64             5        //vista 64λϵͳ
#define SYSTEM_WIN7_32              6        //win7 32λϵͳ
#define SYSTEM_WIN7_64              7        //win7 64λϵͳ
#define SYSTEM_WIN8_32              8        //win8 32λϵͳ
#define SYSTEM_WIN8_64              9        //win8 64λϵͳ
#define SYSTEM_WIN8_1_32            10       //win8.1 32λϵͳ
#define SYSTEM_WIN8_1_64            11       //win8.1 64λϵͳ
#define SYSTEM_WIN10_32             12       //win10 32λϵͳ
#define SYSTEM_WIN10_64             13       //win10 64λϵͳ

typedef struct tagShortcutCfg
{
	// ���캯��
	tagShortcutCfg()
	{
		nShowCmd = SW_SHOWNORMAL;
		wHotKey = 0;
		nIconIndex = 0;
	}

	// �ṹ��Ա:
	TCHAR  szShortcutName[MAX_PATH]; //
	TCHAR  szLnkDir[MAX_PATH];       //
	TCHAR  szDestFile[MAX_PATH];     //
	TCHAR  szUninstallFile[MAX_PATH];//
	TCHAR  szArguments[MAX_PATH];    //
	TCHAR  szIconFile[MAX_PATH];     //
	TCHAR  szWorkingDir[MAX_PATH];   //
	TCHAR  szDescription[1024];      //
	int   nIconIndex;               //
	int   nShowCmd;                 //
	WORD  wHotKey;                  //
}SHORTCUTCFG, *PSHORTCUTCFG;

//������ݷ�ʽ ��ʼ�˵� ���������� ����ǰ �� CoInitialize(NULL) ���ú� CoUninitialize()
bool CreateShortcut(PSHORTCUTCFG pShortcut, int nCsidl);
//ɾ����ݷ�ʽ ɾ����ʼ�˵��Ϳ��������� ����ǰ �� CoInitialize(NULL) ���ú� CoUninitialize()
BOOL DeleteShortcut(const TCHAR* szShortcutName, int nCsidl);

//�ж��Ƿ���64λϵͳ
bool IsWin64();
//����ϵͳ�汾
BOOL GetSystemVersion(int& nVersion);
BOOL GetSystemStrVersion(std::string& strVersion);
BOOL GetSystemStrVersion(std::wstring& strVersion);

//��ȡ����·��
std::wstring GetExeDir();

// �ַ����ָ�
int StringSplit(std::vector<std::wstring>& dst, const std::wstring& src, const std::wstring& separator);
int StringSplit(std::vector<std::string>& dst, const std::string& src, const std::string& separator);
//�滻�ַ�
void StringReplace(std::wstring& str, const std::wstring& to_replaced, const std::wstring& newchars);
void StringReplace(std::string& str, const std::string& to_replaced, const std::string& newchars);
//�ļ���ȥ���������
std::wstring TrimFileName(const std::wstring& str);
//�ļ���ȥ���������
std::wstring XmlTrim(const std::wstring& str);

std::string ws2s(const std::wstring& ws);
std::wstring s2ws(const std::string& s);

//GB2312��UTF-8��ת��
std::string G2U(const std::string gStr);
//UTF-8��GB2312��ת��
std::string U2G(const std::string utf8Str);

//����ص�����ָ��
typedef void(*pf)(const std::wstring& str);
int CmdOutputByPipe(wchar_t *cmdline, std::wstring &result, int timeout = 3000, pf callback = NULL, bool bRetU2G = false, bool* bExit = NULL);

/*���Ŀ��Ŀ¼�Ѵ��ڣ�����ԴĿ¼��ΪĿ��Ŀ¼����Ŀ¼*/
/*���Ҫʵ����ȫ���ǣ���Ҫ��ɾ��Ŀ��Ŀ¼*/
//����=��CopyTo(_T("E:\\mywww\\server\\mysql\\5.5"), _T("E:\\mywww\\server\\test\\5.5"))
bool CopyTo(const std::wstring &strSrcDir, const std::wstring &strDescDir);
bool CopyFileTo(const std::wstring &strSrcFileName, const std::wstring &strDesFileName, bool bCover = true);

//�ļ���С
LONG64 FileSize(const std::wstring& strFileName);
bool GetFileMd5(__in const std::wstring& strFile, __out std::wstring& strOutMd5);

bool DelRecursionDir(const std::wstring& strDirPath);
bool DelRecursionDir(const std::string& strDirPath);
bool CreateRecursionDir(const std::wstring& strPath);
bool CreateRecursionDir(const std::string& strPath);
bool isDirectory(const std::wstring& strPath);
bool isDirectory(const std::string& strPath);

std::string ByteToFitFloat(LONG64 size);
std::string ByteToFitUnit(LONG64 size);


int RenameEx(const std::wstring& strOldFileName, const std::wstring& strNewFileName);
int RenameEx(const std::string& strOldFileName, const std::string& strNewFileName);
int AccessEx(const std::wstring& strFileName, int mode);
int AccessEx(const std::string& strFileName, int mode);
int RemoveEx(const std::wstring& strFileName);
int RemoveEx(const std::string& strFileName);
int MkdirEx(const std::wstring& strPath);
int MkdirEx(const std::string& strPath);
void FOpenEx(FILE**file, const std::wstring& strFileName, const std::wstring& strMode);
void FOpenEx(FILE**file, const std::string& strFileName, const std::string& strMode);

//���ݽ���������pid
BOOL FindProcessPid(LPCTSTR ProcessName, DWORD& dwPid);

//�ж��Ƿ���tail��β
bool endWith(const std::wstring &str, const std::wstring &tail);
bool endWith(const std::string &str, const std::string &tail);
bool startWith(const std::string &str, const std::string &start);
bool startWith(const std::wstring &str, const std::wstring &start);

void ToLowerCase(std::string& str);
void ToLowerCase(std::wstring& str);
void ToUpperCase(std::string& str);
void ToUpperCase(std::wstring& str);

//��������
bool StartProcess(LPCTSTR pszExeName, LPTSTR pszCmdLine, bool bIsBackground = true);
//��������
bool StartProcessWait(LPCTSTR pszExeName, LPTSTR pszCmdLine, DWORD& dwExitCode, bool bIsBackground = true);

//��ȡ�ļ��б�
//type -1->only file
//0->file and dir
//1->onlydir
std::vector<std::wstring> GetFileList(const std::wstring& path, int type = 0);

//������������
bool PinUnpinTaskbar(const std::wstring& strFilePath, bool pin = true);
#endif/*COMMFUNC_H_*/