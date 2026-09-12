#include <stdio.h>
#include <stdlib.h>

#define Name "Misha"
#define LastName "Kreys"
#define GroupName "RB-61"
#define Faculty "RTF"
#define University "Igor Sikorsky KPI"
int main()
{
//--Оголошення змінних. Цілочисельна. Без знаку
  unsigned int semestr;
  unsigned int age;
//--Оголошення змінних. Цілочисельна. Знакова
           int grade1;
           int grade2;
           int grade3;
//--Оголошення змінних. Плаваюча кома
    double averageGrade;
    float admissionScore;
//--
printf("%s %s Follow these steps.\n", Name, LastName);
//--Ініціація змінних
printf("Enter the semester number: ");
scanf("%u", &semestr);

printf("Enter your admission score: ");
scanf("%f", &admissionScore);

printf("Enter your grade for this course ¹1: ");
scanf("%d", &grade1);

printf("Enter your grade for this course ¹2: ");
scanf("%d", &grade2);

printf("Enter your grade for this course ¹3: ");
scanf("%d", &grade3);

printf("Enter your age: ");
scanf("%u", &age);

averageGrade = (double)(grade1 + grade2 + grade3) / 3;

 system("cls");
 //Вивід данних
    printf("\n***************************");
    printf("\n---------------------------");

    printf("\n%s", University);
    printf("\n%s", Faculty);
    printf("\n%s", GroupName);

    printf("\n---------------------------");

    printf("\nstudent: %s %s", Name, LastName );
    printf("\nage: %u", age);
    printf("\nsemestr: %u", semestr);

    printf("\n---------------------------");

    printf("\nadmission score: %.2f", admissionScore);
    printf("\naverage grade = %.3lf", averageGrade);
    printf("\n");
 return 0;
}
