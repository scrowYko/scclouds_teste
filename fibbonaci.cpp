/*
1 - Fibonacci

    -- Criar uma função em sua linguagem preferida. A função deve receber um numero N >= 0 (deve validar o input para a função), e retornar o valor correspondente desse número na sequência Fibonacci. EX. fib(0) =0; fib(1) = 1; fib(2) = 1; fib(3) = 2; fib(5) = 5; fib(6) = 8.

    --- Criar uma função recursiva que resolva Fibonacci

    --- Criar uma função linear que resolva Fibonacci
*/

#include <iostream>
#include <cctype>

using namespace std;

bool validacao_input(string);
int fibonacci_recursivo(int);
int fibonacci_linear(int);

int main() {
    string n;

    do{
        cout << "Informe um numero inteiro nao negativo: ";
        cin >> n;
    } while (!validacao_input(n));
    
    int num = stoi(n);

    try {
        cout << "Fibonacci (recursiva) de " << n << ": " << fibonacci_recursivo(num) << endl;
        cout << "Fibonacci (linear) de " << n << ": " << fibonacci_linear(num) << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

bool validacao_input(string input) {

    for(char c : input) {
        if(isblank(c)) {
            cout << "Entrada invalida. Por favor, insira um numero inteiro nao negativo." << endl;
            return false;
        } else if (!isdigit(c)) {
            cout << "Entrada invalida. Por favor, insira um numero inteiro nao negativo." << endl;
            return false;
        } else if (c == '-' ) {
            cout << "Entrada invalida. Por favor, insira um numero inteiro nao negativo." << endl;
            return false;
        }
    }

    return true;
}

int fibonacci_recursivo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int fibonacci_linear(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}


