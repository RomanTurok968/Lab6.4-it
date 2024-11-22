#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функція для виведення масиву
void COUT(double mas[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << mas[i] << " ";
    }
    cout << endl;
}

// Функція для обчислення кількості елементів, більших за C
int CountGreaterThanC(double mas[], int size, double C) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] > C) {
            count++;
        }
    }
    return count;
}

// Функція для пошуку індексу максимального елемента за модулем
int MaxModulusIndex(double mas[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (fabs(mas[i]) > fabs(mas[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функція для обчислення добутку елементів після максимального за модулем елемента
double ProductAfterMaxModulus(double mas[], int size, int maxIndex) {
    double product = 1;
    bool found = false;
    for (int i = maxIndex + 1; i < size; i++) {
        if (!found) {
            found = true;
        }
        product *= mas[i];
    }
    if (!found) {
        return 0; // Якщо елементів після максимального немає, повертаємо 0
    }
    return product;
}

// Функція для перестановки елементів масиву (від'ємні спочатку, потім додатні)
void Rearrange(double mas[], int size) {
    int negativeIndex = 0;
    int positiveIndex = size - 1;

    while (negativeIndex <= positiveIndex) {
        if (mas[negativeIndex] < 0) {
            negativeIndex++;
        }
        else if (mas[positiveIndex] >= 0) {
            positiveIndex--;
        }
        else {
            swap(mas[negativeIndex], mas[positiveIndex]);
            negativeIndex++;
            positiveIndex--;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    double C;

    cout << "Введiть кiлькiсть елементiв масиву n: ";
    cin >> n;

    cout << "Введiть число C: ";
    cin >> C;

    double* mas = new double[n];

    cout << "Введiть елементи масиву: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "Початковий масив: " << endl;
    COUT(mas, n);

    // Обчислення кількості елементів більших за C
    int count = CountGreaterThanC(mas, n, C);
    cout << "Кількість елементів масиву, більших за C: " << count << endl;

    // Пошук максимального елемента за модулем
    int maxIndex = MaxModulusIndex(mas, n);

    // Обчислення добутку елементів після максимального елемента за модулем
    double product = ProductAfterMaxModulus(mas, n, maxIndex);
    cout << "Добуток елементів після максимального за модулем: " << product << endl;

    // Перестановка елементів масиву
    Rearrange(mas, n);

    cout << "Перетасований масив: " << endl;
    COUT(mas, n);

    delete[] mas;

    return 0;
}
