#include <iostream>
#include <string>
#include <locale>

using namespace std;

long int ISeconds;
int inputSeconds();
string convertSecondsToMinute(int seconds);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите секунды\n";
    inputSeconds();
}

int inputSeconds()
{
    cin >> ISeconds;
    int resultMinute = stoi(convertSecondsToMinute(ISeconds));
    if(resultMinute != 0 && ISeconds != 0)
        cout << "Минут: " << resultMinute << " Секунд: " << ISeconds;
    else if(ISeconds == 0 && resultMinute != 0)
        cout << " Минут: " << resultMinute;
    else
        cout << " Секунд: " << ISeconds;
    return 0;
}

string convertSecondsToMinute(int seconds)
{
    int Minutes = 0;
    if (seconds >= 60)
    {
        while (seconds >= 60)
        {
            seconds -= 60;
            if (!(seconds < 0))
                Minutes += 1;
            else if (seconds == 0)
                Minutes += 1;
        }
        if (seconds != 60)
            ISeconds = abs(seconds);
    }
    return to_string(Minutes);
}