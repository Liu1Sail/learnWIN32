/**
 * 创建win32窗口程序<a href="https://learn.microsoft.com/zh-cn/windows/win32/learnwin32/creating-a-window#window-classes">相关微软文档</a>
 */

/**
 * @类型<a href="https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/ns-winuser-wndclassa">WNDCLASS</a>每个窗口都必须与一个窗口类相关联，即使程序曾经只创建该类的一个实例。 窗口类不是 C++ 意义上的类。 相反，它是操作系统内部使用的数据结构。 窗口类在运行时向系统注册。
 */

 /**
 * @参数 hInstance 当前模块实例句柄
 * @参数 szCmdLine 字符串的形式包含命令行参数。
 * @参数 nCmdShow 是一个标志，指示主应用程序窗口是最小化、最大化还是正常显示.
 * */
#include <windows.h>

 int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE, PSTR szCmdLine , int nCmdShow)
{
    const TCHAR szWndClassName[] = TEXT("Window Class Name");/*每个WNDCLASS都需要一个唯一标识的名字,该名称只需在当前进程中是唯一的。*/

    WNDCLASS wndClass = {};//必须初始化,wndclass除了一下成员都可以初始化为0
    wndClass.hInstance = hInstance; //搬运一下当前模块实例
    wndClass.lpfnWndProc = DefWindowProc;//设置窗口消息处理函数
    wndClass.lpszClassName = szWndClassName;//设置wndclass名称

    if(!RegisterClass(&wndClass))
        return 1;

    auto hWnd = CreateWindowEx(0,szWndClassName,TEXT("window name"),WS_OVERLAPPEDWINDOW,0,0,800,600,NULL,NULL,hInstance,0);
    MSG msg;

    ShowWindow(hWnd,nCmdShow);
    while(GetMessage(&msg,0,0,0)>0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}