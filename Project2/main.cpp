#include <iostream>
#include <Windows.h>

// 1

//проверяет високосный год
int vis(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    return 0;
}


long long calcdays(int day, int month, int year)
{
    long long totaldays = day;

    // считаем дни
    for (int y = 1; y < year; ++y)
    {
        if (vis(y) == 1)
        {
            totaldays += 366;
        }
        else {
            totaldays += 365;
        }
    }

    // считаем дни за прошедшие месяцы текущего года
    for (int m = 1; m < month; ++m)
    {
        int days = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            days = 30;
        }
        else if (m == 2)
        {
            if (vis(year) == 1)
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
        }
        totaldays += days;
    }

    return totaldays;
}

//разность дат и среднее арифМИТИЧЕСКОЕ
void average() {
    int day1 = 0, mnth1 = 0, yr1 = 0;
    int day2 = 0, mnth2 = 0, yr2 = 0;

    std::cout << "Введите первую дату (день месяц год через пробел): ";
    std::cin >> day1 >> mnth1 >> yr1;

    std::cout << "Введите вторую дату (день месяц год через пробел): ";
    std::cin >> day2 >> mnth2 >> yr2;

    long long totalDays1 = calcdays(day1, mnth1, yr1);
    long long totalDays2 = calcdays(day2, mnth2, yr2);

    long long diff = totalDays1 - totalDays2;
    if (diff < 0)
    {
        diff = -diff;
    }

    std::cout << "Разность в днях: " << diff << "\n";

    // Считаем среднее арифметическое чисел
    int count = 0;
    std::cout << "Введите количество элементов для расчета среднего:";
    std::cin >> count;

    if (count <= 0)
    {
        std::cout << "Ошибка: количество элементов должно быть больше 0!\n";
    }
    else {
        double sum = 0.0;
        std::cout << "Введите числа по очереди через пробел:";
        for (int i = 0; i < count; ++i)
        {
            double numbernow = 0.0;
            std::cin >> numbernow;
            sum += numbernow;
        }

        double average = sum / count;
        std::cout << "Среднее арифметическое: " << average << "\n";
    }
}


//функ2 И 3


void CountNumbers()
{
    int elem = 0;
    std::cout << "Введите количество элементов для подсчета типов: \n";
    std::cin >> elem;

    if (elem <= 0)
    {
        std::cout << "Ошибка: количество элементов должно быть больше 0!\n";
    }
    else
    {
        int positiveCount = 0;
        int negativeCount = 0;
        int zeroCount = 0;

        std::cout << "Введите числа по очереди через пробел или Enter:";
        for (int i = 0; i < elem; ++i)
        {
            int currentNumber = 0;
            std::cin >> currentNumber;

            if (currentNumber > 0)
            {
                positiveCount++;
            }
            else if (currentNumber < 0)
            {
                negativeCount++;
            }
            else {
                zeroCount++;
            }
        }

        std::cout << "Положительных элементов: " << positiveCount << "\n";
        std::cout << "Отрицательных элементов: " << negativeCount << "\n";
        std::cout << "Нулевых элементов: " << zeroCount << "\n";
    }
}



int main()
{

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "задание 1\n";
    average();



    std::cout << "\nВыполнение заданий 2 и 3\n";
    CountNumbers();

    return 0;
}