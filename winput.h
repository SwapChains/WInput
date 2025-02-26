#pragma once
#include <Windows.h>

enum KeyType
{
	KEY_SCAN,
	KEY_VIRTUAL
};

class WInput
{
	static int AbsW;
	static int AbsH;
    static INPUT mouInput;
    static INPUT kbdInput;

public:

    static inline void SendKeyUp(WORD key, KeyType kt = KEY_VIRTUAL)
	{
        kbdInput.ki.dwFlags = KEYEVENTF_KEYUP | (kt == KEY_SCAN ? KEYEVENTF_SCANCODE : 0);

		if (kt == KEY_SCAN) kbdInput.ki.wScan = key;
		else kbdInput.ki.wVk = key;

		SendInput(1, &kbdInput, sizeof(INPUT));
	}

    static inline void SendKeyDown(WORD key, KeyType kt = KEY_VIRTUAL)
    {
        kbdInput.ki.dwFlags = kt == KEY_SCAN ? KEYEVENTF_SCANCODE : 0;

        if (kt == KEY_SCAN) kbdInput.ki.wScan = key;
        else kbdInput.ki.wVk = key;

        SendInput(1, &kbdInput, sizeof(INPUT));
    }

    static inline void SendClick()
    {
        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendClickAt(POINT pt)
    {
        mouInput.mi.dx = pt.x * AbsW;
        mouInput.mi.dy = pt.y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendClickAt(POINT* pt)
    {
        mouInput.mi.dx = pt->x * AbsW;
        mouInput.mi.dy = pt->y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendRightClick()
    {
        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendRightClickAt(POINT pt)
    {
        mouInput.mi.dx = pt.x * AbsW;
        mouInput.mi.dy = pt.y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendRightClickAt(POINT* pt)
    {
        mouInput.mi.dx = pt->x * AbsW;
        mouInput.mi.dy = pt->y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &mouInput, sizeof(INPUT));

        mouInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendMouseTo(POINT pt)
    {
        mouInput.mi.dx = pt.x * AbsW;
        mouInput.mi.dy = pt.y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void SendMouseTo(POINT* pt)
    {
        mouInput.mi.dx = pt->x * AbsW;
        mouInput.mi.dy = pt->y * AbsH;
        mouInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
        SendInput(1, &mouInput, sizeof(INPUT));
    }

    static inline void LockMouse()
    {
        RECT rect;
        GetCursorPos((POINT*)&rect);
        rect.right = rect.left + 1;
        rect.bottom = rect.top + 1;
        ClipCursor(&rect);
    }

    static inline void UnlockMouse()
    {
        ClipCursor(NULL);
    }
};