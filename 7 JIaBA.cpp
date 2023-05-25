#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale.h>


using namespace std;

int main()
{
    HANDLE hEvent;
    setlocale(0, "Ru");
    hEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"MyEvent1");
    if (hEvent == 0) {
        cout << "Ошибка открытия объект\"Событие \",\ созданного в другом приложении";
        _getch();
        return 0;
    }
    cout << "Для запуска потоков в другом приложении \
 нажмите любую клавиши" << endl;
    _getch();
    SetEvent(hEvent);
    cout << "Для завершения потоков в другом приложении \
нажмите любую клавишу" << endl;
    _getch();
    ResetEvent(hEvent);
    cout << "Для выхода из приложения нажмите любую \
клавишу" << endl;
    _getch();
    return 0;
}