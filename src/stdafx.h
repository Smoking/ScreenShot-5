// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�:
#include <windows.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <atlbase.h>
#include <atlstr.h>
#include <shlobj.h>
#include "Log.h"
#include <atlimage.h>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include <ShellAPI.h>
#include <list>
#include <vector>
#include <string>

#include "DuiLib/TOM2.h"
#include "DuiLib/UIlib.h"
#include "UILib/stUILib.h"
#include "UIlib/ServyouUILib.h"
#include "Public.h"
using namespace Gdiplus;

#pragma comment(lib,"shell32.lib" )
#pragma comment(lib,"GdiPlus.lib" )
#pragma comment(lib,"Base.lib")
#pragma comment(lib,"Duilib.lib")
#pragma comment(lib,"ServYou_UILib.lib ")
#pragma comment(lib,"uilib.lib")