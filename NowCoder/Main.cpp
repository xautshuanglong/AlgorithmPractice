#include <csignal>
#include <iomanip>

#include "NC0000_Test_I.h"
#include "NC0000_Test_II.h"
#include "NC0000_Test_III.h"
#include "NC0000_InputAndOutput.h"
#include "NC0078_ReverseList.h"
#include "NC0093_LRU.h"
#include "NC0121_Permutation.h"
#include "NC0140_MySort.h"

BOOL gEventLoopFlag = TRUE;
HANDLE ghStdin = INVALID_HANDLE_VALUE;
DWORD gdwStdinModeOld = 0;

void AddConsoleHandler();
void RemoveConsoleHandler();
void InitSignalHandler();
void UninitSignalHandler();
void ConsoleSimpleLoop();
void ConsoleInputEventLoop();

void KeyEventHandler(KEY_EVENT_RECORD keyEventRecord);
void MouseEventHandler(MOUSE_EVENT_RECORD mouseEventRecord);
void ResizeEventHandler(WINDOW_BUFFER_SIZE_RECORD resizeEventRecord);
void FocusEventHandler(FOCUS_EVENT_RECORD focusEventRecord);
void MenuEventHandler(MENU_EVENT_RECORD menuEventRecord);

BOOL WINAPI ConsoleHandlerRoutine(DWORD dwCtrlType);
void WINAPI SignalHandler(int sigCode);

int main(int argc, char** argv)
{
    // 控制台事件捕获测试
    //AddConsoleHandler();
    // 中断信号捕获测试
    //InitSignalHandler();

    //NC0000_Test_I instance;
    //NC0000_Test_II instance;
    NC0000_Test_III instance;
    //NC0000_InputAndOutput  instance;
    //NC0078_ReverseList     instance;
    //NC0093_LRU             instance;
    //NC0140_MySort          instance;
    //NC0121_Permutation     instance;

    INowCoderEntry *pNowCoderEntry = &instance;
    int exitCode = pNowCoderEntry->MainEntry(argc, argv);

    // 控制台输入事件测试
    //ConsoleInputEventLoop();
    // 控制台简单循环
    //ConsoleSimpleLoop();

    //UninitSignalHandler();
    //RemoveConsoleHandler();

    std::cout << std::endl << "_________________ Will exit main function _________________" << std::endl;
    return exitCode;
}

void AddConsoleHandler()
{
    BOOL res = SetConsoleCtrlHandler(ConsoleHandlerRoutine, TRUE);
    if (!res)
    {
        std::cout << "SetConsoleCtrlHandler Add failed! Main.cpp" << std::endl;
    }
}

void RemoveConsoleHandler()
{
    BOOL res = SetConsoleCtrlHandler(ConsoleHandlerRoutine, FALSE);
    if (!res)
    {
        std::cout << "SetConsoleCtrlHandler Delete failed! Main.cpp" << std::endl;
    }
}

void InitSignalHandler()
{
    _crt_signal_t pRetValue = signal(SIGINT, SignalHandler);
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGILL, SignalHandler);
    }
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGFPE, SignalHandler);
    }
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGSEGV, SignalHandler);
    }
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGTERM, SignalHandler);
    }
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGBREAK, SignalHandler);
    }
    if (pRetValue != SIG_ERR)
    {
        pRetValue = signal(SIGABRT, SignalHandler);
    }
    if (pRetValue == SIG_ERR)
    {
        std::cout << "Set Signal Handler failed! ErrorCode:" << errno << " Main.cpp" << std::endl;
    }
}

void UninitSignalHandler()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGILL, SIG_DFL);
    signal(SIGFPE, SIG_DFL);
    signal(SIGSEGV, SIG_DFL);
    signal(SIGTERM, SIG_DFL);
    signal(SIGBREAK, SIG_DFL);
    signal(SIGABRT, SIG_DFL);
}

void ConsoleSimpleLoop()
{
    while (gEventLoopFlag)
    {
        Sleep(200);
    }
    std::cout << "Press any key to exit simple loop!" << std::endl;
    int inValue = getchar();
}

void ConsoleInputEventLoop()
{
    BOOL resultFlag = 0;
    ghStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (ghStdin == INVALID_HANDLE_VALUE)
    {
        std::cout << "GetStdHandle failed! ConsoleInputEventLoop Main.cpp" << std::endl;
        return;
    }
    resultFlag = GetConsoleMode(ghStdin, &gdwStdinModeOld);
    if (!resultFlag)
    {
        std::cout << "GetConsoleMode failed! ConsoleInputEventLoop Main.cpp" << std::endl;
        return;
    }

    DWORD dwConsoleMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_EXTENDED_FLAGS; // 使用 ENABLE_EXTENDED_FLAGS 或者手动改变控制台窗口属性，取消快速编辑选项。
    resultFlag = SetConsoleMode(ghStdin, dwConsoleMode);
    if (!resultFlag)
    {
        std::cout << "SetConsoleMode failed! ConsoleInputEventLoop Main.cpp" << std::endl;
        return;
    }

    int counter = 0;
    DWORD numOfEventRead = 0;
    INPUT_RECORD inputBuffer[128];
    while (gEventLoopFlag)
    {
        resultFlag = ReadConsoleInput(ghStdin, inputBuffer, 128, &numOfEventRead); // PeekConsoleInput 读取事件不移除，造成死循环。
        if (!resultFlag)
        {
            std::cout << "ReadConsoleInput failed! ConsoleInputEventLoop Main.cpp" << std::endl;
            return;
        }
        for (DWORD i = 0; i < numOfEventRead; ++i)
        {
            WORD eventType = inputBuffer[i].EventType;
            switch (eventType)
            {
            case KEY_EVENT:
                KeyEventHandler(inputBuffer[i].Event.KeyEvent);
                break;
            case MOUSE_EVENT:
                MouseEventHandler(inputBuffer[i].Event.MouseEvent);
                break;
            case WINDOW_BUFFER_SIZE_EVENT:
                ResizeEventHandler(inputBuffer[i].Event.WindowBufferSizeEvent);
                break;
            case FOCUS_EVENT:
                FocusEventHandler(inputBuffer[i].Event.FocusEvent);
                break;
            case MENU_EVENT:
                MenuEventHandler(inputBuffer[i].Event.MenuEvent);
                break;
            default:
                std::cout << "Unknown input event! ConsoleInputEventLoop Main.cpp" << std::endl;
                break;
            }
        }
    }
    SetConsoleMode(ghStdin, gdwStdinModeOld);
    CloseHandle(ghStdin);
    ghStdin = INVALID_HANDLE_VALUE;
}

void KeyEventHandler(KEY_EVENT_RECORD keyEventRecord)
{
    //
    // ControlKeyState flags
    //

    // #define RIGHT_ALT_PRESSED     0x0001 // the right alt key is pressed.
    // #define LEFT_ALT_PRESSED      0x0002 // the left alt key is pressed.
    // #define RIGHT_CTRL_PRESSED    0x0004 // the right ctrl key is pressed.
    // #define LEFT_CTRL_PRESSED     0x0008 // the left ctrl key is pressed.
    // #define SHIFT_PRESSED         0x0010 // the shift key is pressed.
    // #define NUMLOCK_ON            0x0020 // the numlock light is on.
    // #define SCROLLLOCK_ON         0x0040 // the scrolllock light is on.
    // #define CAPSLOCK_ON           0x0080 // the capslock light is on.
    // #define ENHANCED_KEY          0x0100 // the key is enhanced.
    // #define NLS_DBCSCHAR          0x00010000 // DBCS for JPN: SBCS/DBCS mode.
    // #define NLS_ALPHANUMERIC      0x00000000 // DBCS for JPN: Alphanumeric mode.
    // #define NLS_KATAKANA          0x00020000 // DBCS for JPN: Katakana mode.
    // #define NLS_HIRAGANA          0x00040000 // DBCS for JPN: Hiragana mode.
    // #define NLS_ROMAN             0x00400000 // DBCS for JPN: Roman/Noroman mode.
    // #define NLS_IME_CONVERSION    0x00800000 // DBCS for JPN: IME conversion.
    // #define ALTNUMPAD_BIT         0x04000000 // AltNumpad OEM char (copied from ntuser\inc\kbd.h) ;internal_NT
    // #define NLS_IME_DISABLE       0x20000000 // DBCS for JPN: IME enable/disable.

    std::cout << "Inside function KeyEventHandler: "
        << keyEventRecord.wVirtualKeyCode
        << " (" << keyEventRecord.uChar.AsciiChar << ") "
        << " ["
        << (keyEventRecord.dwControlKeyState & RIGHT_ALT_PRESSED ? " RIGHT_ALT_PRESSED" : "")
        << (keyEventRecord.dwControlKeyState & LEFT_ALT_PRESSED ? " LEFT_ALT_PRESSED" : "")
        << (keyEventRecord.dwControlKeyState & RIGHT_CTRL_PRESSED ? " RIGHT_CTRL_PRESSED" : "")
        << (keyEventRecord.dwControlKeyState & LEFT_CTRL_PRESSED ? " LEFT_CTRL_PRESSED" : "")
        << (keyEventRecord.dwControlKeyState & SHIFT_PRESSED ? " SHIFT_PRESSED" : "")
        << (keyEventRecord.dwControlKeyState & NUMLOCK_ON ? " NUMLOCK_ON" : "")
        << (keyEventRecord.dwControlKeyState & SCROLLLOCK_ON ? " SCROLLLOCK_ON" : "")
        << (keyEventRecord.dwControlKeyState & CAPSLOCK_ON ? " CAPSLOCK_ON" : "")
        << (keyEventRecord.dwControlKeyState & ENHANCED_KEY ? " ENHANCED_KEY" : "")
        << (keyEventRecord.dwControlKeyState & NLS_DBCSCHAR ? " NLS_DBCSCHAR" : "")
        << (keyEventRecord.dwControlKeyState & NLS_ALPHANUMERIC ? " NLS_ALPHANUMERIC" : "")
        << (keyEventRecord.dwControlKeyState & NLS_KATAKANA ? " NLS_KATAKANA" : "")
        << (keyEventRecord.dwControlKeyState & NLS_HIRAGANA ? " NLS_HIRAGANA" : "")
        << (keyEventRecord.dwControlKeyState & NLS_ROMAN ? " NLS_ROMAN" : "")
        << (keyEventRecord.dwControlKeyState & NLS_IME_CONVERSION ? " NLS_IME_CONVERSION" : "")
        << (keyEventRecord.dwControlKeyState & ALTNUMPAD_BIT ? " ALTNUMPAD_BIT" : "")
        << (keyEventRecord.dwControlKeyState & NLS_IME_DISABLE ? " NLS_IME_DISABLE" : "")
        << " ] "
        << (keyEventRecord.bKeyDown ? "pressed" : "released")
        << std::endl;

    //if (keyEventRecord.wVirtualKeyCode == 'H' && !keyEventRecord.bKeyDown)
    //{
    //    DWORD consoleMode = 0;
    //    GetConsoleMode(ghStdin, &consoleMode);
    //    if (consoleMode & ENABLE_MOUSE_INPUT)
    //    {
    //        std::cout << "--> ENABLE_MOUSE_INPUT" << std::endl;
    //    }
    //    else
    //    {
    //        std::cout << "--> DISABLE_MOUSE_INPUT" << std::endl;
    //    }
    //}
}

// 无法捕获 MK_XBUTTON1-2 （鼠标前进后退键） Key State Masks for Mouse Messages
void MouseEventHandler(MOUSE_EVENT_RECORD mouseEventRecord)
{
    static DWORD oldButtonState = 0;
    DWORD changedButtonState = 0;

    switch (mouseEventRecord.dwEventFlags)
    {
    case 0: // If this value is zero, it indicates a mouse button being pressed or released.
        changedButtonState = oldButtonState ^ mouseEventRecord.dwButtonState;
        oldButtonState = mouseEventRecord.dwButtonState;
        std::cout << "Inside function MouseEventHandler ("
            << "0x" << std::hex << std::setw(4) << std::setfill('0') << mouseEventRecord.dwButtonState
            << "): [ ";
        if (changedButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            if (mouseEventRecord.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                std::cout << "Press LEFT_1ST";
            }
            else
            {
                std::cout << "Release LEFT_1ST";
            }
        }
        if (changedButtonState & FROM_LEFT_2ND_BUTTON_PRESSED)
        {
            if (mouseEventRecord.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED)
            {
                std::cout << "Press LEFT_2ND";
            }
            else
            {
                std::cout << "Release LEFT_2ND";
            }
        }
        if (changedButtonState & FROM_LEFT_3RD_BUTTON_PRESSED)
        {
            if (mouseEventRecord.dwButtonState & FROM_LEFT_3RD_BUTTON_PRESSED)
            {
                std::cout << "Press LEFT_3RD";
            }
            else
            {
                std::cout << "Release LEFT_3RD";
            }
        }
        if (changedButtonState & FROM_LEFT_4TH_BUTTON_PRESSED)
        {
            if (mouseEventRecord.dwButtonState & FROM_LEFT_4TH_BUTTON_PRESSED)
            {
                std::cout << "Press LEFT_4TH";
            }
            else
            {
                std::cout << "Release LEFT_4TH";
            }
        }
        if (changedButtonState & RIGHTMOST_BUTTON_PRESSED)
        {
            if (mouseEventRecord.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
            {
                std::cout << "Press RIGHT";
            }
            else
            {
                std::cout << "Release RIGHT";
            }
        }
        std::cout << "]";
        std::cout << std::endl;
        std::cout << std::dec;
        break;
    case DOUBLE_CLICK:
        std::cout << "Inside function MouseEventHandler: DOUBLE_CLICK" << std::endl;
        break;
    case MOUSE_HWHEELED:
        std::cout << "Inside function MouseEventHandler: MOUSE_HWHEELED" << std::endl;
        break;
    case MOUSE_MOVED:
        std::cout << "Inside function MouseEventHandler: MOUSE_MOVED ("
            << mouseEventRecord.dwMousePosition.X << ", "
            << mouseEventRecord.dwMousePosition.Y <<")"
            << "\r";
        break;
    case MOUSE_WHEELED:
        std::cout << "Inside function MouseEventHandler: MOUSE_WHEELED" << std::endl;
        break;
    default:
        std::cout << "Inside function MouseEventHandler: UNKNOWN" << std::endl;
        break;
    }
}

void ResizeEventHandler(WINDOW_BUFFER_SIZE_RECORD resizeEventRecord)
{
    std::cout << "Inside function ResizeEventHandler : "
        << resizeEventRecord.dwSize.X << " columns "
        << resizeEventRecord.dwSize.Y << " rows"
        << std::endl;
}

void FocusEventHandler(FOCUS_EVENT_RECORD focusEventRecord)
{
    std::cout << "Inside function FocusEventHandler: " 
        << (focusEventRecord.bSetFocus ? "FOCUS" : "NOFOCUS")
        <<" Main.cpp" << std::endl;
}

void MenuEventHandler(MENU_EVENT_RECORD menuEventRecord)
{
    std::cout << "Inside function MenuEventHandler: "
        << menuEventRecord.dwCommandId
        << " Main.cpp" << std::endl;
}

BOOL WINAPI ConsoleHandlerRoutine(DWORD dwCtrlType)
{
    //
    // Ctrl Event flags
    //

    // #define CTRL_C_EVENT        0
    // #define CTRL_BREAK_EVENT    1
    // #define CTRL_CLOSE_EVENT    2
    // 3 is reserved!
    // 4 is reserved!
    // #define CTRL_LOGOFF_EVENT   5
    // #define CTRL_SHUTDOWN_EVENT 6

    BOOL retValue = FALSE;
    std::cout << "Inside function ConsoleHandlerRoutine Main.cpp" << std::endl;
    switch (dwCtrlType)
    {
    case CTRL_C_EVENT:
        retValue = TRUE;
        gEventLoopFlag = FALSE;
        std::cout << "Console handler captured: Control + C" << std::endl;
        //Beep(5000, 1000);
        break;
    case CTRL_BREAK_EVENT:
        gEventLoopFlag = FALSE;
        std::cout << "Console handler captured: Control + Break" << std::endl;
        retValue = TRUE;
        break;
    case CTRL_CLOSE_EVENT:
        std::cout << "Console handler captured: Control + Close" << std::endl;
        break;
    case CTRL_LOGOFF_EVENT:
        std::cout << "Console handler captured: Control + LogOff" << std::endl;
        break;
    case CTRL_SHUTDOWN_EVENT:
        std::cout << "Console handler captured: Control + Shutdown" << std::endl;
        break;
    default:
        break;
    }

    return retValue;
}

void SignalHandler(int sigCode)
{
    // #define SIGINT          2   // interrupt
    // #define SIGILL          4   // illegal instruction - invalid function image
    // #define SIGFPE          8   // floating point exception
    // #define SIGSEGV         11  // segment violation
    // #define SIGTERM         15  // Software termination signal from kill
    // #define SIGBREAK        21  // Ctrl-Break sequence
    // #define SIGABRT         22  // abnormal termination triggered by abort call
    std::cout << "Inside function SignalHandler Main.cpp" << std::endl;
    switch (sigCode)
    {
    case SIGINT:
        gEventLoopFlag = FALSE;
        std::cout << "Signal handler captured: SIGINT" << std::endl;
        break;
    case SIGILL:
        std::cout << "Signal handler captured: SIGILL" << std::endl;
        break;
    case SIGFPE:
        std::cout << "Signal handler captured: SIGFPE" << std::endl;
        break;
    case SIGSEGV:
        std::cout << "Signal handler captured: SIGSEGV" << std::endl;
        break;
    case SIGTERM:
        std::cout << "Signal handler captured: SIGTERM" << std::endl;
        break;
    case SIGBREAK:
        gEventLoopFlag = FALSE;
        std::cout << "Signal handler captured: SIGBREAK" << std::endl;
        break;
    case SIGABRT:
        std::cout << "Signal handler captured: SIGABRT" << std::endl;
        break;
    default:
        break;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
