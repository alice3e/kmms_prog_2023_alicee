#include <iostream>

#define MAX 10

int arr_global[100];

int main() {

    {
        int n;
		// Ошибка компиляции
        //n = ++MAX;
        std::cout << n;
    }

    {
        const int a = 5;
		// Ошибка компиляции
        //std::cout << a++;
    }

    {
        int i = 10;
        if (i == 20) {
            std::cout << i;
        }
    }

    {
        int a = 5, b = 6, c;
        c = a > b ? a : b;
        std::cout << c;
    }

    {
        int x = 4;
        if (x == 4) {
            if (x == 4) {
				// Ошибка компиляции
                //break;
                std::cout << "Buy-buy!";
            }
        }
        std::cout << "Buy!";
    }

    {
        int i = 1;
        do {
            std::cout << i;
            i++;
            if (i < 3) continue;
        } while (false);
    }

    {
		// Ошибка компиляции
        //char x[3] = "12345";
        //std::cout << x;
    }

    {
        char str[5] = "ABC";
        std::cout << str[3] << std::endl;
        std::cout << str << std::endl;
    }

    {
        int arr_local[100];
        static int arr_static_local[100];

        std::cout << arr_local[99] << std::endl;
        std::cout << arr_static_local[99] << std::endl;
        std::cout << arr_global[99] << std::endl;
    }

    {
        int arr[] = { 10, 20, 30 };
        std::cout << *arr + 1;
    }

    {
        int arr[] = { 10, 20, 30 };
        std::cout << -2[arr];
    }
	
    {
        std::cout << 2["HELLO"];
    }

    {
        std::cout << sizeof(0)["abcdefghij"] << std::endl;
    }

    { 
		// После второй теории
        // Сколько раз выполнится цикл
		// Почему бесконечно?
		std::cout << "Бесконечный цикл. Почему?" << std::endl;
        unsigned char value = 150;
        for (unsigned char i = 0; i < 2 * value; i++) {

        }
    }

    return 0;
}
