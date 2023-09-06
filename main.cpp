/**
 * 创建win32窗口程序<a href="https://learn.microsoft.com/zh-cn/windows/win32/learnwin32/creating-a-window#window-classes">相关微软文档</a>
 */

/**
 * @类型 <a href="https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/ns-winuser-wndclassa">WNDCLASS</a>: 每个窗口都必须与一个窗口类相关联，即使程序曾经只创建该类的一个实例。 窗口类不是 C++ 意义上的类。 相反，它是操作系统内部使用的数据结构。 窗口类在运行时向系统注册。
 * \n
 * @类型 HINSTANCE: 实例的句柄 或模块的句柄.当可执行文件加载到内存中时，操作系统使用此值来标识可执行文件或 EXE。 某些 Windows 函数需要实例句柄，例如加载图标或位图。
 * \n
 * @类型 HWND: Windows是对象,它们同时具有代码和数据，但它们不是 C++ 类。 相反，程序通过使用称为 句柄的值来引用窗口。 句柄是不透明的类型。 从本质上讲，它只是操作系统用来标识对象的数字。 你可以将 Windows 想象成有一个大表，其中包含已创建的所有窗口。 它使用此表按句柄查找窗口。
 */

 /**
 * @参数 hInstance 当前模块实例句柄
 * @参数 szCmdLine 字符串的形式包含命令行参数。
 * @参数 nCmdShow 是一个标志，指示主应用程序窗口是最小化、最大化还是正常显示.
 * */

/**
 * @窗口创建步骤 1.   创建并注册窗口类(WNDCLASS)
 * @窗口创建步骤 2.   创建窗口(CreateWindow)
 * @窗口创建步骤 3.   显示窗口(ShowWindow)并写消息处理循环(get -> translate -> dispatch)
 */

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