#include <iostream> 

void CombSort(int arr[], int n) 
{
    if (n <= 1) return;

    int gap = n; 
    bool swapped = true; 

    while (gap > 1 || swapped) 
    {
        gap = static_cast<int>(gap / 1.3);
        if (gap < 1) gap = 1;

        swapped = false; // Перед каждым проходом сбрасываем флаг обмена
        for (int i = 0; i < n - gap; i++) 
        {
            if (arr[i] > arr[i + gap]) 
            {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
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
    
    CombSort(arr, X);
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}