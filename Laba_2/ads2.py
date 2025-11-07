import sys

def main():
    line = sys.stdin.readline()
    if line.strip() == '':
        print("Ошибка: пустой ввод")
        return

    if line[-1] == '\n':
        line = line[:-1]

    if not line.endswith('='):
        print("Ошибка: в конце ожидался символ '='")
        return

    expr = line[:-1]  # убираем '='
    if not expr.strip():
        print("Ошибка: пустое выражение")
        return

    pos = [0]  # изменяемый указатель

    def peek():  # посмотреть текущий символ
        if pos[0] >= len(expr):
            return None
        return expr[pos[0]]

    def next_char():  # прочитать текущий символ и перейти к следующему
        if pos[0] >= len(expr):
            return None
        ch = expr[pos[0]]
        pos[0] += 1
        return ch

    def chislo():  # читаем число
        num = 0
        while True:
            ch = peek()
            if ch is not None and ch.isdigit():
                num = num * 10 + int(next_char())
            else:
                break
        return num

    def mnozh():  # читаем множитель (число или выражение в скобках)
        ch = peek()
        if ch == '(':
            next_char()  # '('
            val = vyrazh()  # рекурсивно парсим выражение внутри скобок
            if peek() != ')':
                raise ValueError("Ожидалась закрывающая скобка ')'")
            next_char()  # ')'
            return val
        elif ch is not None and ch.isdigit():
            return chislo()
        else:
            raise ValueError("Неожиданный символ")

    def slag():  # обрабатывает цепочку множителей с '*' и '/'
        val = mnozh()  # первый множитель
        while peek() in ('*', '/'):
            op = next_char()
            right = mnozh()
            if op == '*':
                val *= right
            else:  # '/'
                if right == 0:
                    raise ValueError("Деление на ноль")
                val //= right  # целочисленное деление
        return val

    def vyrazh():  # обрабатывает цепочку слагаемых с '+' и '-'
        val = slag()  # первое слагаемое
        while peek() in ('+', '-'):
            op = next_char() # читаем + или -
            right = slag() # читаем второе слагаемое
            if op == '+':
                val += right
            else:
                val -= right
        return val

    try:
        result = vyrazh()
        if pos[0] < len(expr):
            raise ValueError("Лишние символы после выражения")
        print(result)
    except Exception as e:
        print("Ошибка:", e)

main()