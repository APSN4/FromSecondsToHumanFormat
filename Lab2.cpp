#include <iostream>
#include <string>
#include <locale>

using namespace std;

long int ISeconds;
int resultMinute;
int resultHours;
int resultdays;

int inputSeconds();
string convertSecondsToMinute(int seconds);
string convertMinutesToHours(int minutes);
string convertHoursToDays(int hours);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите секунды\n";
    inputSeconds();
}

int inputSeconds()
{
    cin >> ISeconds;
    resultMinute = stoi(convertSecondsToMinute(ISeconds));
    if (resultMinute >= 60)
        resultHours = stoi(convertMinutesToHours(resultMinute));
    if (resultHours >= 24)
        resultdays = stoi(convertHoursToDays(resultHours));

    cout << resultdays << " " << resultHours << " " << resultMinute << " " << ISeconds << endl;
    /*
    if (resultMinute < 60) {
        if (resultMinute != 0 && ISeconds != 0)
            cout << "Минут: " << resultMinute << " Секунд: " << ISeconds;
        else if (ISeconds == 0 && resultMinute != 0)
            cout << " Минут: " << resultMinute;
        else
            cout << " Секунд: " << ISeconds;
    }
    */
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
                Minutes++;
            else if (seconds == 0)
                Minutes++;
        }
        if (seconds != 60)
            ISeconds = abs(seconds);
    }
    return to_string(Minutes);
}

string convertMinutesToHours(int minutes) {
    int Hours = 0;
    if (minutes >= 60) {
        while (minutes >= 60)
        {
            minutes -= 60;
            if (!(minutes < 0))
                Hours++;
            else if (minutes == 0)
                Hours++;
        }
        if (minutes != 60)
            resultMinute = abs(minutes);
    }
    return to_string(Hours);
}

string convertHoursToDays(int hours) {
    int days = 0;
    if (hours >= 24) {
        while (hours >= 24)
        {
            hours -= 24;
            if (!(hours < 0))
                days++;
            else if (hours == 0)
                days++;

        }
        if (hours != 24)
            resultHours = abs(hours);
    }
    return to_string(days);
}