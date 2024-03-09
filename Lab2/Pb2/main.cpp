#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Student.h"
#include "Global_function.h"
int main()
{
	Student p1,p2;
	char ex1[30] = "Alex", ex2[30] = "Andrei";
	float mg1 = 9.2, me1 = 6.7, mh1 = 8.6;
	float mg2 = 9.5, me2 = 7.7, mh2 = 8.1;
	p1.Set_name(ex1);
	p1.Set_math_grade(mg1);
	p1.Set_english_grade(me1);
	p1.Set_history_grade(mh1);
	p2.Set_name(ex2);
	p2.Set_math_grade(mg2);
	p2.Set_english_grade(me2);
	p2.Set_history_grade(mh2);
	int result;
	result = compare_name(p1.Get_name(), p2.Get_name());
	printf("Comparint the names: %d \n", result);
	result = compare_math_grade(p1.Get_math_grade(), p2.Get_math_grade());
	printf("Comparing the math grades: %d \n", result);
	result = compare_english_grade(p1.Get_english_grade(), p2.Get_english_grade());
	printf("Comparing the english grades: %d \n", result);
	result = compare_history_grade(p1.Get_history_grade(), p2.Get_history_grade());
	printf("Comparing the history grades: %d \n", result);
	result = compare_average(p1.Get_average(), p2.Get_average());
	printf("Comparing average grades: %d \n", result);
}