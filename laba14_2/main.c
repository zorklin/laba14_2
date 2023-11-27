#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//сума масиву, повертає суму
int averege_value_of_array(int* array, int size_of_array)
{
    int sum_of_array = 0;
    for (int i = 0; i < size_of_array; i++) {
        sum_of_array += *(array + i);
    }
    return sum_of_array;
}


int main()
{

    while (true) 
    {

        //типізація
        int size_of_array = 0;
        int sum_of_array = 0, average_value = 0;
        char stop[5], clean_string;

        //ввід розміру масиву
        printf("Enter size of array (natural number): ");
        scanf_s("%d", &size_of_array);


        //перевірка чи коректні значення (чи можливо створити масив)
        if (size_of_array > 1)
        {

            //виділення памяті під масив цілих чисел (array - вказіник на перший елемент масиву)
            int* array = (int*)malloc(size_of_array * sizeof(int));

            //перевірка чи коректні значення (чи створений масив)
            if (array == NULL)
            {
                printf("Error, null array\n");
                printf("Please enter a positive integer\n\n");
            }

            //якщо умова виконанна і массив створений
            else
            {

                //ввід масиву
                for (int i = 0; i < size_of_array; i++)
                {
                    printf("enter array element number %d: ", i + 1);
                    scanf_s("%d", array + i);
                }

                //функція обраховує суму значень і індиксів васиву
                sum_of_array = averege_value_of_array(array, size_of_array);


                //обрахунок середьного значення
                float average_value = (float)sum_of_array / (float)size_of_array;


                //вивід результату
                printf("\n");
                printf("sum of array: %d\n", sum_of_array);
                printf("average value of array: %.2f\n", average_value);

                //звільнення пам'яті
                free(array);

            }

        }

        //помилкові дані входу
        else
        {
            printf("Such an array cannot exist\n");
            printf("Please enter a positive integer\n");
        }

        //роздільний рядок
        printf("\n");

        //інформація про те як зупинит  програму
        printf("want to stop program?\nenter (S or s) if want stop: ");
        scanf_s("%s", &stop, 2);

        //зупинення роботи програми
        if ((*stop == 's' || *stop == 'S') && *(stop + 1) == '\0')
        {
            break;
        }

        //очищення потоку (якщо користувач вийшов за масив(рядок))
        do {
            clean_string = getchar();
        } while (clean_string != '\n');

        //роздільний рядок
        printf("\n\n");

    }

    return 0;

}