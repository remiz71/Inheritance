#include <iostream>
using namespace std;

#define delim "\n------------------------\n"

class Employee
{
    string last_name;
    string first_name;
    string job;
public:
    const string& get_last_name() const
    {
        return last_name;
    }
    const string& get_first_name() const
    {
        return first_name;
    }
    const string& get_job() const
    {
        return job;
    }
    void set_last_name(const string& last_name)
    {
        this->last_name = last_name;
    }
    void set_first_name(const string& first_name)
    {
        this->first_name = first_name;
    }
    void set_job(const string& job)
    {
        this->job = job;
    }



    /////////////////// Constructors

    Employee(const string& last_name, const string& first_name, const string& job)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_job(job);
        cout << "E_Constructor: \t" << this << endl;

    }
    ~Employee()
    {
        cout << "E_Destructor: \t" << this << endl;
    }

    ///////////////////  Methods

    virtual void print() const
    {
        cout << last_name << "  " << first_name << ", " << job ;
        cout << endl;
    }
};
class Hourly : public Employee
{
    double salary;
    double work_hours;
public:
    double get_salary() const
    {
        return salary;
    }
    double get_hours() const
    {
        return work_hours;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }
    void set_hours(double work_hours)
    {
        this->work_hours = work_hours;
    }

    /////////////////// Constructors

    Hourly
    (const string& last_name, const string& first_name,
        const string& job,double work_hours, double salary
    ) :Employee(last_name, first_name, job)
    {
        set_salary(salary);
        set_hours(work_hours);
        cout << "H_Constructor: \t" << this << endl;
    }
    ~Hourly()
    {
        cout << "H_Destructor: \t" << this << endl;
    }
    //   Methods

    void print() const
    {
        Employee::print();
        cout << "Заработная плата " << salary << " руб. в час" << endl;
        cout << "Отработано " << work_hours << " часов" << endl;
    }
    
    double count_salary(int salary, double work_hours) const
    {
        double total_salary;
        total_salary = get_salary() * get_hours();
        return total_salary;
    }
};
class Monthly :public Employee
    {
        double salary;
        int work_days;
    public:
        double get_salary() const
        {
            return salary;
        }
        void set_salary(double salary)
        {
            this->salary = salary;
        }int get_days() const
        {
            return work_days;
        }
        void set_days(int work_days)
        {
            this->work_days = work_days;
        }
        //Constructors:
        Monthly
            (const string& last_name, const string& first_name,
                const string& job,int work_days, double salary
            ) :Employee(last_name, first_name, job)
        {
            set_salary(salary);
            set_days(work_days);
            cout << "M_Constructor: \t" << this << endl;
        }
        ~Monthly()
        {
            cout << "M_Destructor: \t" << this << endl;
        }
        //Methods
        void print() const
        {
            Employee::print();
            cout << "Заработная плата " << salary << " руб. в месяц" << endl;
            cout << "Отработано дней: " << work_days << endl;
        }
        double count_salary(int salary,double work_days)const
        {
            return (get_salary() / 31) * get_days();
        }

    };
int main()
{
    setlocale(LC_ALL, "");
    Employee* group[] =
    {
        new Monthly("Парикожа", "Кирилл" , "Инженер линии", 22, 53000),
        new Hourly("Ремизов", "Дмитрий" , "Младший инженер линии",158.5, 200 ),
        new Hourly("Фролов", "Денис", "начальник участка",50.7,350),
        new Monthly("Лейко", "Дарья", "Руководитель инженерной группы",15, 65000),
        new Hourly("Hu", "Xiaoliang" , "Head of paintshop" ,700, 500)
    };
    for (int i = 0; i < sizeof(group) / sizeof(Employee*); i++)
    {
        group[i]->print();
        cout << delim << endl;
    } 
    for (int i = 0; i < sizeof(group) / sizeof(Employee*); i++)
    {
        group[i];
        cout << delim << endl;
    }
    
}