#include <iostream> 

void InsertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i]; // Текущий элемент, который нужно вставить
        int j = i - 1; // Индекс последнего элемента в отсортированной части

        // Сдвигаем элементы, которые больше key, на одну позицию вправо
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Вставляем key на своё место
        arr[j + 1] = key;
    }
}

int main()
{
    const int X = 40;
    int arr[X];   

    std::cout << "Исходный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        arr[i] = rand() % 500;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    InsertionSort(arr, X);
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}