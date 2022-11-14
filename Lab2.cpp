#include <iostream>
#include <string>
#include <locale>

using namespace std;

string Istrseconds;
long ISeconds;
long resultMinute;
long resultHours;
long resultdays;
long resultYears; //31536000 second
long resultDecade; //315360000 second
long resultCentury; //3153600000 second

long inputSeconds();
string convertSecondsToMinute(long seconds);
string convertMinutesToHours(int minutes);
string convertHoursToDays(int hours);
string convertDaysToYears(int days);
string convertYearToDecade(int years);
string convertDecadeToCentury(int decade);
string Convertseconds_minutes(long number1, string name);
string ConvertHours(long number1, string name);
string ConvertDays(long number1, string name);
string resultOutput(long seconds, long minutes, long hours, long days, long years, long decades, long centuries);


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите секунды\n";
    inputSeconds();
}

long inputSeconds()
{
    cin >> Istrseconds;
    ISeconds = atol(Istrseconds.c_str());
    resultMinute = stol(convertSecondsToMinute(ISeconds));
    if (resultMinute >= 60)
        resultHours = stoi(convertMinutesToHours(resultMinute));
    if (resultHours >= 24)
        resultdays = stoi(convertHoursToDays(resultHours));
    if (resultdays >= 365)
        resultYears = stoi(convertDaysToYears(resultdays));
    if (resultYears >= 10)
        resultDecade = stoi(convertYearToDecade(resultYears));
    if (resultDecade >= 10)
        resultCentury = stoi(convertDecadeToCentury(resultCentury));

    cout << resultCentury << " " << resultDecade << " " << resultYears <<
        " " << resultdays << " " << ConvertDays(resultdays, "ден") << " " << resultHours << " " << ConvertHours(resultHours, "час") << " " << resultMinute <<
        " " << Convertseconds_minutes(resultMinute, "минут") <<
        " " << ISeconds << " " << Convertseconds_minutes(ISeconds, "секунд") << endl;
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

string resultOutput(long seconds, long minutes, long hours, long days, long years, long decades, long centuries)
{
    if (seconds)
        printf("hello");
    return "3";
}

string Convertseconds_minutes(long number1, string name) {
    string number_local;
    int number;
    number_local = to_string(number1);
    number_local = number_local.back(); // взять последний символ
    number = stol(number_local);
    string local;
    if (number == 1)
        local = name + "а";
    else if ((number >= 2 && number < 5) && !(number1 >= 11 && number1 <= 20))
        local = name + "ы";
    else if (number >= 5 || (number1 >= 11 && number1 <= 20))
        local = name;
    else if (number == 0 && (number1 != 0))
        local = name;
    else
        local = "";
    return local;
}
string ConvertHours(long number1, string name) {
    string number_local;
    int number;
    number_local = to_string(number1);
    number_local = number_local.back(); // взять последний символ
    number = stol(number_local);
    string local;
    if (number == 1)
        local = name;
    else if ((number >= 2 && number < 5) && !(number1 >= 11 && number1 <= 20))
        local = name + "а";
    else if (number >= 5 || ((number1 >= 11) && (number1 <= 20)))
        local = name + "ов";
    else if (number == 0 && (number1 != 0))
        local = name + "ов";
    else
        local = "";
    return local;
}

string ConvertDays(long number1, string name) {
    string number_local;
    int number;
    number_local = to_string(number1);
    number_local = number_local.back(); // взять последний символ
    number = stol(number_local);
    string local;
    if ((number == 1 || number == 21) && (!(number1 >= 11 && number1 <= 20)))
        local = name + "ь";
    else if (number >= 2 && number < 5 && (!(number1 >= 11 && number1 <= 20)))
        local = "дня";
    else if ((number >= 5) && (!(number1 >= 11 && number1 <= 20)) || ((number1 % 10 == 0) && (number1 != 0)) || (((number1 >= 11) && (number1 <= 20))))
        local = "дней";
    else
        local = "";
    return local;
}

string convertSecondsToMinute(long seconds)
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

string convertDaysToYears(int days) {
    int years = 0;
    if (days >= 365) {
        while (days >= 365)
        {
            days -= 365;
            if (!(days < 0))
                years++;
            else if (days == 0)
                years++;
        }
        if (days != 365)
            resultdays = abs(days);
    }
    return to_string(years);
}

string convertYearToDecade(int years) {
    int decade = 0;
    if (years >= 10) {
        while (years >= 10)
        {
            years -= 10;
            if (!(years < 0))
                decade++;
            else if (years == 0)
                decade++;
        }
        if (years != 10)
            resultYears = abs(years);
    }
    return to_string(decade);
}

string convertDecadeToCentury(int decade) {
    int Century = 0;
    if (decade >= 10) {
        while (decade >= 10)
        {
            decade -= 10;
            if (!(decade < 0))
                Century++;
            else if (decade == 0)
                Century++;
        }
        if (decade != 10)
            resultDecade = abs(decade);
    }
    return to_string(Century);
}