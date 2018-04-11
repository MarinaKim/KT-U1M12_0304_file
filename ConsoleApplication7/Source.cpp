
/*
FILE- структура
открытие фыйла:

FILE *fopen (имя файлаб режим)    // !!!указывает на пакет содержащий инфо о файле
 режимы:


 если не открыл файл, вернет error
 если файл был открыт, обязательно необходимо его закрыть
 */

 /* fputc- записывает символы в файлы
 fputc(int ch, FILE*fp
 */

 /*
 getc () -  */

 /* int feof (FILE*uf);
 функцая помогает поймать конец файла*/

 /*char buffer[100];
 sprintf(buffer,"md folder"); */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>

using namespace std;
void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	FILE *fp = NULL;

	int n;
	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
		case 1: {
			if ((fp = fopen("test.txt", "w")) == NULL)
			{
				printf("Файл не открыт\n");
				exit(1); // или EXIT_FAILURE
			}
			else // если открыт успешно
			{
				printf("Create \n");

				//system("chcp 1251");
				//
				///* тоже самое setConsoleCP(1251);
				//setConsoleOutputCP(1251);*/

				//for (int i = -128; i < 128; i++)
				//{
				//	fputc(i, fp);
				//}

				int ch = getc(fp);
				while (feof(fp) == 1) //while (ch != EOF)
				{
					printf(" - %c\n", ch);
					ch = getc(fp);
				}

			}

			//fclose(fp); //очищает память, очищает буфер и можно использовать место снова

			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;

			//1.Создать типизированный файл и записать в него:
			//a.число 500
			//b.число 4, 5
			//c.слово Привет
		case 2: {

			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("Файл открыт\n");
				int k = 500;
				float c = 4.5;
				fprintf(fp, "%d %2.1f Привет \n", k, c);
			}
			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;
			//2.	Создать типизированный файл и записать в него (Записываемые числа и слова вводятся с клавиатуры)
			//a.	5 одинаковых целых чисел
			//	b.	5 одинаковых вещественных чисел
			//	c.	5 одинаковых слов

		case 3: {
			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("Файл открыт\n");
				int a;
				float b;
				char k[] = "Masha";

				printf("введите целое число:");
				scanf("%d", &a);

				printf("введите вещественное число:");
				scanf("%f", &b);

				for (int i = 0; i < 5;i++)
				{
					fprintf(fp, "%d\t", a);
					printf("\n");
				}
				for (int i = 0; i < 5;i++)
				{
					fprintf(fp, "%2.2f\t", b);
					printf("\n");
				}

				for (int i = 0; i < 5;i++)
				{
					fprintf(fp, "%s\t", k);
					printf("\n");
				}

			}
			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;

			//3.	Дан массив из двадцати вещественных чисел. Записать все числа массива в типизированный файл в том же порядке
		case 4: {
			float mas[20];
			for (int i = 0;i < 20;i++)
			{
				mas[i] = 1.1 + rand() % 20 / (1.1 + rand() % 10);
				printf("%2.1f\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("Файл открыт\n");

				for (int i = 0;i < 20;i++)
				{
					fprintf(fp, "%2.1f\t", mas[i]);
				}
				//int ch = getc(fp);
				//while (feof(fp) == 1) //while (ch != EOF)
				//{
				//	printf(" - %c\n", ch);
				//	ch = getc(fp);
				//}
			}

			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;
			//4.	В конец существующего типизированного файла записать
					//	a.число 0
					//		b.фразу До свидания!

		case 5: {
			if ((fp = fopen("test.txt", "a")) != NULL)
			{
				int k = 0;
				fprintf(fp, "%d до свидания! \n", k);
			}
			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;

			//5.	В конец существующего файла записать
		//	a.	6 целых чисел
		//		b.	5 вещественных чисел
		//		c.	4 слова

		case 6: {
			int m[5];
			float mas[6];
			for (int i = 0;i < 6;i++)
			{
				mas[i] = 1.1 + rand() % 20 / (1.1 + rand() % 10);
				printf("%2.1f\t", mas[i]);
			}
			printf("\n");
			for (int i = 0;i < 5;i++)
			{
				m[i] = 1 + rand() % 20;
				printf("%d\t", m[i]);
			}
			printf("\n");

			if ((fp = fopen("test.txt", "a")) != NULL)
			{

				for (int i = 0;i < 5;i++)
				{
					fprintf(fp, "%d\t", m[i]);
				}
				for (int i = 0;i < 6;i++)
				{
					fprintf(fp, "%2.1f\t", mas[i]);
				}

				fprintf(fp, "jfkkjf sfjsdfk kfl;f kfa;fl\n");

			}

			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}
		}break;

			//1.	Дан типизированный файл, элементами которого являются числа. Напечатать
			//a.n - й элемент
			//	b.последний элемент
		case 7: {
			int m[5], k;

			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("Файл открыт\n");
				for (int i = 0;i < 5;i++)
				{
					m[i] = 1 + rand() % 20;
					fprintf(fp,"%d\t", m[i]);
				}
			}

			if (fclose(fp) == 0)
			{
				printf("файл закрыт успешно");
			}
			else
			{
				printf("Ошибка закрытия потока");
				exit(1);
			}

			printf("Введите номер элемента: ");
			scanf("%d\n", &k);
			 ftell()
		}break;
		}
		system("pause");
	} while (n > 0);



}