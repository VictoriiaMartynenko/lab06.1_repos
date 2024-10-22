#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Процес обчислення кількості, суми та заміни елементів на нулі за новим критерієм
void ProcessArray(int* a, const int size, int& count, int& sum)
{
    count = 0;
    sum = 0;
    for (int i = 0; i < size; i++) {
        if (!(a[i] % 2 != 0 && i % 3 == 0)) {
            sum += a[i];
            count++;
            a[i] = 0; // заміна елементів на нулі
        }
    }
}

int main() {
    srand((unsigned)time(0));

    const int n = 23; // кількість елементів
    int s[n];

    int Low = 4, High = 16;

    Create(s, n, Low, High);

    cout << "Start array: " << endl;
    Print(s, n);

    int count = 0, sum = 0;
    ProcessArray(s, n, count, sum);

    cout << "Number of elements that meet the criteria:  " << count << endl;
    cout << "Sum of those elements:  " << sum << endl;

    cout << "Modified array:  " << endl;
    Print(s, n);

    return 0;
}
