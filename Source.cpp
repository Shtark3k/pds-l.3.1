#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>
#include <cstdlib>

using namespace std;


const int MAX_N = 13;


void обчислити_стірлінга_белла(int variant_i) {
    // 3) Обчислити n:= i + 5;
    int n = variant_i + 5;

    // Вивід повідомлень українською
    if (n <= 0 || n > MAX_N) {
        cerr << "Помилка: Обчислене n (" << n << ") є недійсним або перевищує MAX_N (" << MAX_N << ").\n";
        return;
    }

    // Оголошення 2D масиву для чисел Стірлінга F[j, k]. Використовуємо long long.
    vector<vector<long long>> F(n + 1, vector<long long>(n + 1, 0));

    // Оголошення масиву для чисел Белла B[j]. 6.1) B[j] := 0 - ініціалізація нулями.
    vector<long long> B(n + 1, 0);

    // 4) Ініціалізація F[j, k] для першого стовпчика (k=1) та головної діагоналі (k=j).
    for (int j = 1; j <= n; j++) {
        // 4.1.1) F[j, 1]:=1;
        F[j][1] = 1;

        // 4.1.2) F[j, j]:=1;
        F[j][j] = 1;
    }

    // 5) Обчислити решту значень чисел Стірлінга другого роду.
    // Рекурентна формула: F[j, k] = F[j - 1, k - 1] + k * F[j - 1, k].
    for (int j = 2; j <= n; j++) {
        for (int k = 2; k < j; k++) {
            F[j][k] = F[j - 1][k - 1] + (long long)k * F[j - 1][k];
        }
    }

    // 7) Обчислити числа Белла: B[j] = сума(F[j, k] для k=1 до j).
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= j; k++) {
            // 7.1.1.1) B[j] = B[j] + F[j , k]
            B[j] += F[j][k];
        }
    }

    // 1) Вивести результат у вигляді таблиці. ВИВІД АНГЛІЙСЬКОЮ.

    cout << "\n=== Table of Stirling Numbers of the Second Kind F[j, k] (S(j, k)) (n=" << n << ") ===\n";

    // Виведення заголовків стовпців (k)
    cout << setw(5) << "j\\k";
    for (int k = 1; k <= n; k++) {
        cout << setw(10) << k;
    }
    cout << endl;

    // Виведення рядків таблиці
    for (int j = 1; j <= n; j++) {
        cout << setw(5) << j;
        for (int k = 1; k <= n; k++) {
            if (k <= j) {
                cout << setw(10) << F[j][k];
            }
            else {
                cout << setw(10) << "";
            }
        }
        cout << endl;
    }

    cout << "\n=== Table of Bell Numbers B[j] ===\n";
    cout << setw(5) << "j" << setw(15) << "B[j]" << endl;
    for (int j = 1; j <= n; j++) {
        cout << setw(5) << j << setw(15) << B[j] << endl;
    }
}

int main() {
    // Налаштування локалі на українську для коректного виведення службових повідомлень.
    setlocale(LC_ALL, "uk_UA.UTF-8");
    // Команда для Windows для коректного відображення кирилиці.
    system("chcp 65001 > nul");

    // Введення номера варіанту.
    int variant_i = 8;

    // Службові повідомлення українською
    cout << "1) Початок обчислення.\n";
    cout << "2) Номер варіанту i = " << variant_i << "\n";
    cout << "3) Обчислено n = i + 5 = " << variant_i + 5 << "\n";

    обчислити_стірлінга_белла(variant_i);

    cout << "\n2) Кінець програми.\n";

    return 0;
}