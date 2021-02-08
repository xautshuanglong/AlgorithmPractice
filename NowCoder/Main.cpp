#include <csignal>

#include "NC0078_ReverseList.h"
#include "NC0093_LRU.h"
#include "NC0121_Permutation.h"
#include "NC0140_MySort.h"

void AddConsoleHandler();
void RemoveConsoleHandler();
void InitSignalHandler();

BOOL WINAPI ConsoleHandlerRoutine(DWORD dwCtrlType);
void WINAPI SignalHandler(int sigCode);

int main(int argc, char** argv)
{
    // 控制台事件捕获测试
    AddConsoleHandler();
    // 中断信号捕获测试
    //InitSignalHandler();

    //NC0078_ReverseList     instance;
    //NC0093_LRU             instance;
    //NC0140_MySort          instance;
    NC0121_Permutation     instance;

    INowCoderEntry *pNowCoderEntry = &instance;
    int exitCode = pNowCoderEntry->MainEntry(argc, argv);

    getchar();
    getchar();

    RemoveConsoleHandler();

    std::cout << "Will exit main function ..." << std::endl;
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
        std::cout << "Console handler captured: Control + C" << std::endl;
        retValue = TRUE;
        break;
    case CTRL_BREAK_EVENT:
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
