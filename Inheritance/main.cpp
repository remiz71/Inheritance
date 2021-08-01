#include <iostream>
#include <string>
using namespace std;

#define delim "\n-----------------------------\n"
#define tab "\t"

class Human
{
	string lastName;
	string firstName;
	unsigned int age;
public:
	//get-methods
	const string& get_last_name()const
	{
		return lastName;
	}
	const string& get_first_name()const
	{
		return firstName;
	}
	unsigned int get_age()const
	{
		return age;
	}
	//set-methods
	void set_last_name(const string& lastName)
	{
		this->lastName = lastName;
	}
	void set_first_name(const string& firstName)
	{
		this->firstName = firstName;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constructors
	Human(const string& lastName, const string& firstName, unsigned int age)
	{
		set_last_name(lastName);
		set_first_name(firstName);
		set_age(age);
		cout << "HConstructor:" << tab << this << endl;
	}
	~Human()
	{
		cout << endl;
		cout << "HDestructor:" <<tab<< this<< endl;	
	}
	//Methods
	virtual void print()const
	{
		cout << lastName << " " << firstName << " " << age;
		print_year_suffix(age);
		cout << endl;

	}
protected:
	void print_year_suffix(unsigned int age)const
	{
		if (age%20>= 5 && age%20 <= 20 || age % 10 >= 5 || age % 10 == 0) cout << " лет" << endl;
		else if (age % 10 > 1 && age % 10 < 5) cout << " года" << endl;
		else cout << " год" << endl;
	}

};

class Student:public Human
{
	string speciality;
	string group;
	double rating;
public:
	//get-methods
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	//set-methods
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//Constructors
	Student
	(
		const string& lastName, const string& firstName, unsigned int age,
		const string& speciality, const string& group, double rating
	):Human(lastName,firstName,age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:" << tab << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:" << tab << this << endl;
	}
	//Methods
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int exp;
public:
	//get-Methods
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_exp()const
	{
		return exp;
	}
	//set-Methods
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_exp(unsigned int exp)
	{
		this->exp = exp;
	}
	//Constructors
	Teacher
	(
		const string& lastName, const string& firstName, unsigned int age,
		const string& speciality, unsigned int exp
	) :Human(lastName, firstName, age)
	{
		set_speciality(speciality);
		set_exp(exp);
		cout << "TConstructor:" << tab << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:" << tab << this << endl;
	}
	//Methods
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", опыт работы: " << exp ;
		print_year_suffix(exp);
		cout << endl;
	}



};

class Graduate :public Student
{
	string diploma_topic;
public:
	//get-methods
	const string& get_topic()const
	{
		return diploma_topic;
	}
	//set-methods
	void set_topic(const string& diploma_topic)
	{
		this->diploma_topic = diploma_topic;
	}
	//Constructors
	Graduate
	(
		const string& lastName, const string& firstName, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_topic
	) :Student(lastName, firstName, age, speciality, group, rating)
	{
		set_topic(diploma_topic);
		cout << "GConstructor:" << tab << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:" << tab << this << endl;
	}
	//Methods
	void print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diploma_topic << endl;
	}
};

//#define INHERITANCE
#define POLYMORPHISM

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE
	cout << tab << "Inheritance" << endl;
	Human vasya("Тупенко", "Василий", 20);
	vasya.print();
	cout << delim << endl;
	Student student("Иванов", "Федор", 25, "РПО", "ВПУ_011", 90);
	student.print();
	cout << delim << endl;
	Teacher teacher("Einstein", "Albert", 142, "Astronomy", 112);
	teacher.print();
	cout << delim << endl;
	Graduate graduater("Сидров", "Федор", 34, "РПО", "ВПУ_011", 90, "Освоение марса");
	graduater.print();
	cout << delim << endl;
#endif // INHERITANCE
#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Student("Галлямутдинова", "Альбина" , 25, "РПО" , "ВБУ_011", 95),
		new Graduate("Ремизов", "Альбина" , 27, "РПО" , "ВБУ_011", 95, "Фиг его знает"),
		new Teacher("Eishtein","Albert",142,"Astronomy",112),
		new Student("Сорокина", "Мария" , 27, "РПО" , "ВБУ_011", 99)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << delim << endl;
	}
#endif // POLYMORPHISM

	return 0; 
}
