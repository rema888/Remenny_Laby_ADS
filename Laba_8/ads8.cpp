#include <iostream>
#include <vector>

using namespace std;

void countingSortByDigit(int arr[], int n, int exp) 
{
    vector<int> output(n);
    vector<int> count(10, 0);

    // Подсчёт цифр
    for (int i = 0; i < n; i++) 
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Префиксные суммы
    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1];
    }

    // Заполняем output справа налево
    for (int i = n - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Копируем отсортированный по текущему разряду массив output обратно в arr
    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
}

void radixSortNonNegative(int arr[], int n) 
{
    if (n <= 1) return;

    // Находим максимум
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // Сортируем по разрядам
    for (int exp = 1; maxVal / exp > 0; exp *= 10) 
    {
        countingSortByDigit(arr, n, exp);
    }
}

// Radix Sort с поддержкой отрицательных чисел
void radixSort(int arr[], int n) 
{
    if (n <= 1) return;

    // Подсчитываем количество отрицательных и неотрицательных
    int negCount = 0, posCount = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0) negCount++;
        else posCount++;
    }

    // Выделяем временные массивы
    vector<int> negatives(negCount);
    vector<int> positives(posCount);

    // Заполняем их
    int negIdx = 0, posIdx = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0) 
            negatives[negIdx++] = -arr[i];  // сохраняем модуль
        else 
            positives[posIdx++] = arr[i];      
    }

    // Сортируем обе части
    if (negCount > 0) 
        radixSortNonNegative(negatives.data(), negCount);
    
    if (posCount > 0) 
        radixSortNonNegative(positives.data(), posCount);
    
    // Собираем результат обратно в arr
    int idx = 0;

    // Отрицательные — в обратном порядке
    for (int i = negCount - 1; i >= 0; i--) 
    {
        arr[idx++] = -negatives[i];
    }

    // Неотрицательные — в прямом порядке
    for (int i = 0; i < posCount; i++) 
    {
        arr[idx++] = positives[i];
    }
}

int main()
{
    const int X = 30;
    int arr[X];   

    std::cout << "Исходный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        arr[i] = rand() % 500;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    radixSort(arr, X);
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}