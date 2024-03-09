class Student
{
	char name[30];
	float math_grade;
	float english_grade;
	float history_grade;
	float average;
public:
	void Set_name(char* s);
	void Set_math_grade(float x);
	void Set_english_grade(float x);
	void Set_history_grade(float x);
	char* Get_name();
	float Get_math_grade();
	float Get_english_grade();
	float Get_history_grade();
	float Get_average();
};
