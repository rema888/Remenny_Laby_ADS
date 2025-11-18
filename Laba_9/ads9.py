def heapify(arr, n, i):

    largest = i  # Предполагаем, что корень — наибольший
    left = 2 * i + 1  # Индекс левого потомка
    right = 2 * i + 2  # Индекс правого потомка

    # Если левый потомок существует и больше корня
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Если правый потомок существует и больше текущего наибольшего
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Если наибольший элемент — не корень
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Обмен
        # Рекурсивно применяем heapify к затронутому поддереву
        heapify(arr, n, largest)
def heap_sort(arr):

    n = len(arr)

    # Построение max-heap: значение каждого узла ≥ значений его потомков
    # Начинаем с последнего узла, имеющего потомков: индекс n//2 - 1
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Извлечение элементов из кучи по одному
    for i in range(n - 1, 0, -1):
        # Перемещаем текущий максимум (корень) в конец
        arr[0], arr[i] = arr[i], arr[0]
        # Восстанавливаем кучу в уменьшенном массиве (размер = i)
        heapify(arr, i, 0)


data = [12, 11, 13, 5, 6, 7]
print("Исходный массив:", data)
heap_sort(data)
print("Отсортированный массив:", data)