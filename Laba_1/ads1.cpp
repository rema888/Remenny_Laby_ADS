#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidExpression(const string& s) 
{
    stack<char> st;
    
    for (char c : s) 
    {
        // Если открывающая скобка — добавляем в стек
        if (c == '(' || c == '{' || c == '[')
            st.push(c);

        // Если закрывающая скобка
        else if (c == ')' || c == '}' || c == ']') 
        {
            // Если стек пуст — нет соответствующей открывающей скобки
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            // Проверяем соответствие пары
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                return false; 
        }
        // Игнорируем другие символы (если они есть)
    }

    // Если стек не пуст — есть незакрытые скобки
    return st.empty();
}

int main() 
{
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    if (input.empty())
        cout << "Строка не существует" << endl;
    else 
    {
        if (isValidExpression(input))
            cout << "Строка существует" << endl;
        else
            cout << "Строка не существует" << endl;
    }
}