
/*
FILE- ���������
�������� �����:

FILE *fopen (��� ������ �����)    // !!!��������� �� ����� ���������� ���� � �����
 ������:


 ���� �� ������ ����, ������ error
 ���� ���� ��� ������, ����������� ���������� ��� �������
 */

 /* fputc- ���������� ������� � �����
 fputc(int ch, FILE*fp
 */

 /*
 getc () -  */

 /* int feof (FILE*uf);
 ������� �������� ������� ����� �����*/

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
		printf("������� ����� �������: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
		case 1: {
			if ((fp = fopen("test.txt", "w")) == NULL)
			{
				printf("���� �� ������\n");
				exit(1); // ��� EXIT_FAILURE
			}
			else // ���� ������ �������
			{
				printf("Create \n");

				//system("chcp 1251");
				//
				///* ���� ����� setConsoleCP(1251);
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

			//fclose(fp); //������� ������, ������� ����� � ����� ������������ ����� �����

			if (fclose(fp) == 0)
			{
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;

			//1.������� �������������� ���� � �������� � ����:
			//a.����� 500
			//b.����� 4, 5
			//c.����� ������
		case 2: {

			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("���� ������\n");
				int k = 500;
				float c = 4.5;
				fprintf(fp, "%d %2.1f ������ \n", k, c);
			}
			if (fclose(fp) == 0)
			{
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;
			//2.	������� �������������� ���� � �������� � ���� (������������ ����� � ����� �������� � ����������)
			//a.	5 ���������� ����� �����
			//	b.	5 ���������� ������������ �����
			//	c.	5 ���������� ����

		case 3: {
			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("���� ������\n");
				int a;
				float b;
				char k[] = "Masha";

				printf("������� ����� �����:");
				scanf("%d", &a);

				printf("������� ������������ �����:");
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
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;

			//3.	��� ������ �� �������� ������������ �����. �������� ��� ����� ������� � �������������� ���� � ��� �� �������
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
				printf("���� ������\n");

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
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;
			//4.	� ����� ������������� ��������������� ����� ��������
					//	a.����� 0
					//		b.����� �� ��������!

		case 5: {
			if ((fp = fopen("test.txt", "a")) != NULL)
			{
				int k = 0;
				fprintf(fp, "%d �� ��������! \n", k);
			}
			if (fclose(fp) == 0)
			{
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;

			//5.	� ����� ������������� ����� ��������
		//	a.	6 ����� �����
		//		b.	5 ������������ �����
		//		c.	4 �����

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
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}
		}break;

			//1.	��� �������������� ����, ���������� �������� �������� �����. ����������
			//a.n - � �������
			//	b.��������� �������
		case 7: {
			int m[5], k;

			if ((fp = fopen("test.txt", "w")) != NULL)
			{
				printf("���� ������\n");
				for (int i = 0;i < 5;i++)
				{
					m[i] = 1 + rand() % 20;
					fprintf(fp,"%d\t", m[i]);
				}
			}

			if (fclose(fp) == 0)
			{
				printf("���� ������ �������");
			}
			else
			{
				printf("������ �������� ������");
				exit(1);
			}

			printf("������� ����� ��������: ");
			scanf("%d\n", &k);
			 ftell()
		}break;
		}
		system("pause");
	} while (n > 0);



}