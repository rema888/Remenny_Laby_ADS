#include <iostream> 

void SelectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;  
        }
        
        if (minIndex != i) 
        {
            std::swap(arr[i], arr[minIndex]);
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
    
    SelectionSort(arr, X);
    std::cout << "Отсортированный массив: " << std::endl;
    for (int i=0;i<X;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}