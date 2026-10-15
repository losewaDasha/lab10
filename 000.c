#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <windows.h> 
#include <stdlib.h>


float S(float a, float b);
void nazvanie();
void draw(int a, int b);
void krug(float* a, float* b);
float sravinenie(float a1, float b1, float a2, float b2);

int main() {
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "RUS");
    float a, b;
    int choice;

    printf("=== Программа для работы с прямоугольным треугольником ===\n");
    printf("Введите катет a: ");
    scanf("%f", &a);
    printf("Введите катет b: ");
    scanf("%f", &b);

    do {
        printf("\n--- Меню ---\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("4. Вывести параметры фигуры\n");
        printf("5. Сравнить с другим треугольником по площади\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Площадь прямоугольного треугольника: %.2f\n", S(a, b));
            break;
        case 2:
            nazvanie();
            break;
        case 3:
            printf("Рисуем прямоугольный треугольник (высота %d, основание %d):\n", (int)a, (int)b);
            draw((int)a, (int)b);
            break;
        case 4: {
            float cur_a, cur_b;
            krug(&cur_a, &cur_b);
            printf("Текущие параметры: катет a = %.2f, катет b = %.2f\n", a, b);
            break;
        }
        case 5: {
            float a2, b2;
            printf("Введите катет a второго треугольника: ");
            scanf("%f", &a2);
            printf("Введите катет b второго треугольника: ");
            scanf("%f", &b2);

            float diff = sravinenie(a, b, a2, b2);
            if (diff > 0) {
                printf("Первый треугольник больше второго на %.2f\n", diff);
            }
            else if (diff < 0) {
                printf("Второй треугольник больше первого на %.2f\n", -diff);
            }
            else {
                printf("Треугольники равны по площади.\n");
            }
            break;
        }
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}

float S(float a, float b) {
    return 0.5f * a * b;
}

void nazvanie() {
    setlocale(LC_ALL, "RUS");
    printf("Прямоугольный треугольник — это треугольник, в котором один угол прямой (равен 90 градусам).\n");
    printf("Стороны, образующие прямой угол, называются катетами (a и b), а противолежащая сторона — гипотенузой (c).\n");
}

void draw(int a, int b) {
    setlocale(LC_ALL, "RUS");
    if (a <= 0 || b <= 0) {
        printf("Некорректные размеры для рисования.\n");
        return;
    }

    for (int i = 1; i <= a; i++) {
        int stars = (i * b) / a;
        if (stars == 0) stars = 1;

        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void krug(float* a, float* b) {
}

float sravinenie(float a1, float b1, float a2, float b2) {
    float area1 = S(a1, b1);
    float area2 = S(a2, b2);
    return area1 - area2;
}