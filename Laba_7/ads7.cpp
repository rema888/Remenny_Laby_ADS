#include <iostream> 

void ShellSort(int arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        // Сортировка вставками для подмассивов с шагом `gap`
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];  // текущий элемент для вставки
            int j = i;

            // Сдвигаем элементы, которые больше temp, на `gap` вперёд
            while (j >= gap && arr[j - gap] > temp) 
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;  // вставляем temp на правильное место
        }
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
    
    ShellSort(arr, X);
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}