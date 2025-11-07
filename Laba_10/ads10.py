def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    # разделить массив на две половины
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # рекурсивно отсортировать обе половины
    left_sorted = merge_sort(left_half)
    right_sorted = merge_sort(right_half)

    # слить две отсортированные половины
    return merge(left_sorted, right_sorted)


def merge(left, right):
    result = []
    i = j = 0  # указатели для left и right

    # Пока есть элементы в обоих списках
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Добавить остатки (если один список закончился раньше)
    result.extend(left[i:])
    result.extend(right[j:])

    return result

arr = [38, 27, 43, 3, 9, 82, 10]
sorted_arr = merge_sort(arr)
print(sorted_arr)