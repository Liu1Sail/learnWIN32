//
// Created by 23118 on 2023/9/7.
//

#ifndef LEARNWIN32_WINPROC_H
#define LEARNWIN32_WINPROC_H
#include <windows.h>
#include <windowsx.h>
#include <string>
/**
 *
 * @param hWnd 窗口
 * @param uMsg 消息编号
 * @param wParam 取决于消息的类型,伴随新消息传入
 * @param lparam  取决于消息类型,伴随消息传入
 * @return
 */
LRESULT CALLBACK WinProc(HWND hWnd,UINT uMsg ,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CLOSE:
            if(MessageBox(hWnd,TEXT("关闭窗口"),TEXT("是否关闭窗口"),MB_YESNO)==IDYES)
            {
                DestroyWindow(hWnd);//会发送WM_DESTROY消息
            }
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_KEYDOWN:
            if(wParam == 'A')
            {
                SetWindowText(hWnd,TEXT("A Down"));
            }
            return 0;
        case WM_KEYUP:
            if(wParam=='A')
            {
                SetWindowText(hWnd,TEXT("A up"));
            }
            return 0;
        case WM_LBUTTONDOWN:
        {
            int x , y;
            x = GET_X_LPARAM(lParam);
            y = GET_Y_LPARAM(lParam);
            SetWindowText(hWnd,(std::to_wstring(x)+L','+std::to_wstring(y)).c_str());
            return 0;
        }
        default:
            return DefWindowProc(hWnd,uMsg,wParam,lParam);
    }
}
#endif //LEARNWIN32_WINPROC_H
