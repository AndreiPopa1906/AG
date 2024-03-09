#include <stdio.h>
#include <string.h>
#include "Student.h"
void Student::Set_name(char s[])
{
	strcpy(this->name, s);
}
void Student::Set_math_grade(float x)
{
	this->math_grade = x;
}
void Student::Set_english_grade(float x)
{
	this->english_grade = x;
}
void Student::Set_history_grade(float x)
{
	this->history_grade = x;
}
char* Student::Get_name()
{
	return this->name;
}
float Student::Get_math_grade()
{
	return this->math_grade;
}
float Student::Get_english_grade()
{
	return this->english_grade;
}
float Student::Get_history_grade()
{
	return this->history_grade;
}
float Student::Get_average()
{
	return (this->math_grade + this->english_grade + this->history_grade) / 3;
}
