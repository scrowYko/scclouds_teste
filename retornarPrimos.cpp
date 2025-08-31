/*
2 - Números primos

    - Criar uma função em sua linguagem preferida. A função deve receber um número N > 1 (validar o input), e retornar todos os números primos até o número N. EX. p(2) = [2]; p(3) = [2, 3]; p(10) = [2, 3, 5, 7];

    --- Criar uma função recursiva que resolva p

    --- Criar uma função linear que resolva p
*/

#include <iostream>
#include <cctype>

using namespace std;

void primos_recursivo(int, int);
void primos_linear(int);
bool validacao_input(string);

int main() {
    string n;

    do{
        cout << "Informe um numero inteiro nao negativo: ";
        getline(cin, n);
    } while (!validacao_input(n));

    int num = stoi(n);

    cout << "Primos (recursivo) ate " << n << ": ";
    primos_recursivo(num, 2);
    cout << endl;
    cout << "Primos (linear) ate " << n << ": ";
    primos_linear(num);
    cout << endl;

    return 0;
}

bool validacao_input(string input) { // Mesma validação do Fibonacci.cpp, por serem os mesmos requisitos.

    for(char c : input) {
        if(isblank(c) || !isdigit(c) || c == '-') {
            cout << "Entrada invalida. Por favor, insira um numero inteiro nao negativo." << endl;
            return false;
        } 
    }

    return true;
}

void primos_recursivo(int n, int current) {
    if (current > n) return;

    bool e_primo = true;
    for (int i = 2; i * i <= current; ++i) {
        if (current % i == 0) {
            e_primo = false;
            break;
        }
    }

    if (e_primo && current > 1) {
        cout << current << " ";
    }

    primos_recursivo(n, current + 1);
}

void primos_linear(int n) {
    if (n < 2) return;

    bool* e_primo = new bool[n + 1];
    for (int i = 0; i <= n; ++i) {
        e_primo[i] = true;
    }
    e_primo[0] = e_primo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (e_primo[i]) {
            for (int j = i * i; j <= n; j += i) {
                e_primo[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (e_primo[i]) {
            cout << i << " ";
        }
    }
    delete[] e_primo;
}
