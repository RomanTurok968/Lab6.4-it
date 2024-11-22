#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ������� ��� ��������� ������
void COUT(double mas[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << mas[i] << " ";
    }
    cout << endl;
}

// ������� ��� ���������� ������� ��������, ������ �� C
int CountGreaterThanC(double mas[], int size, double C) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] > C) {
            count++;
        }
    }
    return count;
}

// ������� ��� ������ ������� ������������� �������� �� �������
int MaxModulusIndex(double mas[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (fabs(mas[i]) > fabs(mas[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// ������� ��� ���������� ������� �������� ���� ������������� �� ������� ��������
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
        return 0; // ���� �������� ���� ������������� ����, ��������� 0
    }
    return product;
}

// ������� ��� ������������ �������� ������ (��'��� ��������, ���� ������)
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

    cout << "����i�� �i���i��� �������i� ������ n: ";
    cin >> n;

    cout << "����i�� ����� C: ";
    cin >> C;

    double* mas = new double[n];

    cout << "����i�� �������� ������: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "���������� �����: " << endl;
    COUT(mas, n);

    // ���������� ������� �������� ������ �� C
    int count = CountGreaterThanC(mas, n, C);
    cout << "ʳ������ �������� ������, ������ �� C: " << count << endl;

    // ����� ������������� �������� �� �������
    int maxIndex = MaxModulusIndex(mas, n);

    // ���������� ������� �������� ���� ������������� �������� �� �������
    double product = ProductAfterMaxModulus(mas, n, maxIndex);
    cout << "������� �������� ���� ������������� �� �������: " << product << endl;

    // ������������ �������� ������
    Rearrange(mas, n);

    cout << "������������� �����: " << endl;
    COUT(mas, n);

    delete[] mas;

    return 0;
}
