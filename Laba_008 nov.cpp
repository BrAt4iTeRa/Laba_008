#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
#include <locale.h>
void analiz(char**, int, int, int);
int main()
{
	char** str = nullptr;
	int raz, n, i, j = 0, m, ch, kolvo = 0, beg;
	do {
		setlocale(LC_ALL, "Russian");
		printf_s("Введите размерность матрицы: \n Колво строк = ");
		ch = scanf_s("%d", &n);
		if (ch == 0 || n <= 0) {
			system("CLS");
			printf_s("No memory. Try again\n");
			rewind(stdin);
			continue;
		}
		printf_s("Введите кол-во символов в строке:\nm = ");
		ch = scanf_s("%d", &m); //Аналогичная проверка на ввод, как и при строках.
		str = (char**)malloc(n * sizeof(char*));
		for (i=0; i<n; i++)
			str[i] = (char*)malloc(m * sizeof(char));

	} while (!str);
	printf_s("Вводите текст:\n");
	rewind(stdin);
	for (i = 0; i < n; i++)
		fgets(*(str + i), m, stdin);
	printf_s("Ваша строка:\n");
	for (i = 0; i < n; i++) {
		puts(*(str + i));
	}
	for (i = 0; i < n; i++)                  //fgets не ставит 0 - символ в конце, он ставит \n значит мы поставим \0 сами)
		for (j = 0; j < m; j++)
			if (*(*(str + i) + j) == '\n') *(*(str + i) + j) = '\0';
	printf("Слова, в которых гласных больше согласных:\n");
	for (i = 0; i < n && (*(*(str + i) + j) != '\0'); i++) {
		if (i!=0) printf_s(" ");
		for (j = 0; j < m && *(*(str + i) + j);) {
			if (*(*(str + i) + j) == ' ' && *(*(str + i) + j)) while (*(*(str + i) + j) == ' ' && *(*(str + i) + j)) j++;
			beg = j;
			for (raz = 1; *(*(str + i) + j) != ' ' && *(*(str + i) + j); raz++, j++);
			kolvo = 1;
			for (int nach = beg; nach <= j; nach++) {
				if (*(*(str + i) + nach) == 'a' || *(*(str + i) + nach) == 'e' || *(*(str + i) + nach) == 'y' || *(*(str + i) + nach) == 'u' || *(*(str + i) + nach) == 'i' || *(*(str + i) + nach) == 'o') kolvo++;
			}
			if (kolvo > (raz - kolvo))
				for (beg; beg <= j; beg++)
					printf_s("%c", *(*(str + i) + beg));
		}
	}

 
}
