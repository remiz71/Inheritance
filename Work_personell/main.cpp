#include <iostream>
using namespace std;

#define delim "\n------------------------\n"

class Employee
{
    string last_name;
    string first_name;
    string job;
    string salary_type;
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
    }const string& get_type() const
    {
        return salary_type;
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
    void set_type(const string& salary_type)
    {
        this->salary_type = salary_type;
    }


    /////////////////// Constructors

    Employee(const string& last_name, const string& first_name, const string& job, const string& salary_type)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_job(job);
        set_type(salary_type);
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
public:
    double get_salary() const
    {
        return salary;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }

    /////////////////// Constructors

    Hourly
    (const string& last_name, const string& first_name,
        const string& job, const string& salary_type, double salary
    ) :Employee(last_name, first_name, job, salary_type)
    {
        set_salary(salary);
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
    }
};
class Monthly :public Employee
    {
        double salary;
    public:
        double get_salary() const
        {
            return salary;
        }
        void set_salary(double salary)
        {
            this->salary = salary;
        }
        //Constructors:
        Monthly
            (const string& last_name, const string& first_name,
                const string& job, const string& salary_type, double salary
            ) :Employee(last_name, first_name, job, salary_type)
        {
            set_salary(salary);
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
        }

    };
int main()
{
    setlocale(LC_ALL, "");
    Employee* group[] =
    {
        new Monthly("Парикожа", "Кирилл" , "Инженер линии","помесячно", 53000),
        new Hourly("Ремизов", "Дмитрий" , "Младший инженер линии", "почасово", 200 ),
        new Hourly("Фролов", "Денис", "начальник участка","почасово",350),
        new Monthly("Лейко", "Дарья", "Руководитель инженерной группы", "помесячно", 65000),
        new Hourly("Hu", "Xiaoliang" , "Head of paintshop" , "почасово", 500)
    };
    for (int i = 0; i < sizeof(group) / sizeof(Employee*); i++)
    {
        group[i]->print();
        cout << delim << endl;
    }
    
}