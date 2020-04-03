#pragma execution_character_set("utf-8")
#include <time.h>
#include <string>
#include <iostream>

int main(int, char **)
{
    using namespace std;

//windows终端需要切换解析字符集为UTF-8，否则是乱码
#if PLATFORM==WINDOWS
    system("chcp 65001");
#endif

#ifdef DEBUG
    //打印调试信息
    cout << "┌──────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│                         DEBUG BUILD INFO                         │" << endl;
    cout << "└──────────────────────────────────────────────────────────────────┘" << endl;
    cout << "Project: " << PROJECT_NAME<< endl; 
    cout << "Build: " << BUILD << endl;
    cout << "Platform: ";

#if  PLATFORM==WINDOWS
    cout << "Windows" << endl;
#elif PLATFORM==LINUX
    cout << "Linux" << endl;
#endif
    cout << "Encoding Test: 你好，世界！" << endl;
#endif
}
