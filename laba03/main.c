#include <stdio.h>

int main() {
    char str[80];
    printf("Vvedi strochky: ");
    fgets(str, sizeof(str), stdin); 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        } else if (str[i] == 'b') 
            str[i] = 'B';
    }

    printf("Result: %s\n", str);
    return 0;
}
1 Рассчитать количество дней до даты, ввод даты читается из файла input.txt
2 Сделать функцию создания матрицы размера m*m заполненную случайными числами от 0 до 9
3 Создать матрицы пока не появится две с одинаковой суммой всех элементов. Вывести их в файл output.txt
4 замерить время работы программы
