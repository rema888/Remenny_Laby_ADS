import os

# Делит файл на серии длины run_size и записывает их поочерёдно в output1 и output2
def split_into_runs(input_path, output1, output2, run_size):

    with open(input_path, 'r') as fin, \
         open(output1, 'w') as f1, \
         open(output2, 'w') as f2:

        out_files = [f1, f2]
        file_index = 0

        while True:
            # Читаем одну серию
            series = []
            for _ in range(run_size):
                line = fin.readline()
                if not line:
                    break
                series.append(line.strip())

            if not series:
                break

            # Записываем серию в текущий файл
            for val in series:
                out_files[file_index].write(val + '\n')

            # Переключаем файл для следующей серии
            file_index = 1 - file_index

# Слияние двух отсортированных списков
def merge(series1, series2):
    result = []
    i = j = 0
    while i < len(series1) and j < len(series2):
        if series1[i] <= series2[j]:
            result.append(series1[i])
            i += 1
        else:
            result.append(series2[j])
            j += 1
    result.extend(series1[i:])
    result.extend(series2[j:])
    return result


# Читает по одной серии длины run_size из file1 и file2, сливает их и записывает результат в output.
def merge_runs(file1, file2, output, run_size):
    with open(file1, 'r') as f1, open(file2, 'r') as f2, open(output, 'w') as fout:
        while True:
            # Читаем серию из file1
            series1 = []
            for _ in range(run_size):
                line = f1.readline()
                if not line:
                    break
                series1.append(int(line.strip()))

            # Читаем серию из file2
            series2 = []
            for _ in range(run_size):
                line = f2.readline()
                if not line:
                    break
                series2.append(int(line.strip()))

            if not series1 and not series2:
                break

            # Используем merge из 10 лабы
            merged = merge(series1, series2)
            for val in merged:
                fout.write(f"{val}\n")


def external_sort_3files(input_file):

    A = input_file
    B = 'temp_B.txt'
    C = 'temp_C.txt'

    # Подсчитаем общее число элементов
    with open(A, 'r') as f:
        total = sum(1 for line in f if line.strip())

    if total == 0:
        return

    run_size = 1

    while run_size < total:
        # 1. Разбиваем A на B и C: серии длины run_size → чередуются
        split_into_runs(A, B, C, run_size)

        # 2. Сливаем серии из B и C обратно в A → получаем серии длины 2*run_size
        merge_runs(B, C, A, run_size)
        run_size *= 2

    # Удаляем временные файлы
    for f in [B, C]:
        if os.path.exists(f):
            os.remove(f)





with open('data.txt', 'w') as f:
    import random
    numbers = [random.randint(1, 1000) for _ in range(32)]
    for n in numbers:
        f.write(f"{n}\n")

print("Исходные данные:", numbers)

external_sort_3files('data.txt')

with open('data.txt', 'r') as f:
    result = [int(line.strip()) for line in f if line.strip()]
    print("Отсортировано:", result)