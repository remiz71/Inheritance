#include <iostream>
#include <Windows.h>
using namespace std;
#define delim "----------------------------------------"

namespace Geometry
{
	enum Color
	{
		CONSOLE_DEFAULT = 0x07,
		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,

		RED		= 0x000000FF,
		GREEN	= 0x0000FF00,
		BLUE	= 0x00FF0000,
	};
	//ENUM - (enumeration - перечисление) - набор целочисленных констант. к сожалению в 
	// языке си++ перечисление погут хранить....Перечисление являются типом данных
	// И переменные типа енум могут принимать только одно из перечисленных значений

	class Shape
	{
	protected:
		Color color;//Любую фигуру можно нарисовать каким либо цветом
	public:
		Color get_color()const
		{
			return color;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		Shape(Color color = Color::CONSOLE_DEFAULT) :color(color) {}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void print()const = 0;
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void create_tools()const
		{

		}
		void draw()const
		{
			//Получаем Обработчик окна
			HWND hwnd = GetConsoleWindow();
			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");//Получаем контекст устройства:
			HDC hdc = GetDC(hwnd); // Handlet=to-Device context
			//создаем карандаш и кисть
			HPEN hPen = CreatePen(PS_SOLID, 5, color);//Solid - сплошная , 5 - толщина линии
			//пэн рисует контур
			HBRUSH hBrush = CreateSolidBrush(color);
			//берем кисть и карандаш
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Рсиуем квадрат
			::Rectangle(hdc, 300, 300, 500 + side, 500 + side);


			// Освобожлаем ресурсы
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void print()const
		{
			cout << "Length of side: " << get_side() << endl;
			cout << "Area of square: " << get_area() << endl;
			cout << "Perimeter of square: " << get_perimeter() << endl;
			cout << delim << endl;
		}
};

	class Rectangle :public Shape
	{
		double aSide;
		double bSide;
	public:
		double get_aSide()const
		{
			return aSide;
		}
		double get_bSide()const
		{
			return bSide;
		}
		void set_aSide(double aSide)
		{
			if (aSide <= 0)aSide = 1;
			this->aSide = aSide;
		}
		void set_bSide(double bSide)
		{
			if (bSide <= 0)bSide = 1;
			this->bSide = bSide;
		}
		Rectangle(double aSide, double bSide, Color color) :Shape(color)
		{
			set_aSide(aSide);
			set_bSide(bSide);
		}
		~Rectangle() {}

		double get_area() const
		{
			return aSide * bSide;
		}
		double get_perimeter()const
		{
			return aSide * 2 + bSide * 2;
		}
		void draw()const
		{
			//Получаем Обработчик окна
			HWND hwnd = GetConsoleWindow();
			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");//Получаем контекст устройства:
			HDC hdc = GetDC(hwnd); 
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, 300, 300, 300 + aSide, 300 + bSide);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void print()const
		{
			cout << "Length of  A side: " << get_aSide() << endl;
			cout << "Length of  B side: " << get_bSide() << endl;
			cout << "Area of rect: " << get_area() << endl;
			cout << "Perimeter of rect: " << get_perimeter() << endl;
			cout << delim << endl;
		}
	};
	
	class Circle :public Shape
	{
		double rad;
	protected:
		double PI = 3.1415926;
	public:
		double get_rad()const
		{
			return rad;
		}
		void set_rad(double rad)
		{
			if (rad <= 0)rad = 1;
			this->rad = rad;
		}
		
		Circle(double rad, Color color):Shape(color)
		{
			set_rad(rad);
		}
		~Circle() {}

		double get_area()const
		{
			return PI * (rad * rad);
		}
		double get_perimeter()const
		{
			return 2 * PI * rad;
		}
		void draw()const
		{
			
			HWND hwnd = GetConsoleWindow();
			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, 300, 300, 100 + rad, 100 + rad);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void print()const
		{
			cout << "Radius of circle " << get_rad() << endl;
			cout << "Area of circle " << get_area() << endl;
			cout << "Perimeter of circle " << get_perimeter() << endl;
			cout << delim << endl;
		}
	};

	class Triangle :public Shape
	{
		double sideAB=0;
		double sideBC = 0;
		double sideAC = 0;
	public:
		double get_AB()const
		{
			return sideAB;
		}
		double get_BC()const
		{
			return sideBC;
		}
		double get_AC()const
		{
			return sideAC;
		}
		void set_AB(double sideAB)
		{
			this->sideAB = sideAB;
		}
		void set_BC(double sideBC)
		{
			this->sideBC = sideBC;
		}
		void set_AC(double sideAC)
		{
			this->sideAC=sideAC;
		}
		Triangle (double sideAB, double sideBC, double sideAC,Color color) :Shape(color) {}
		
		virtual ~Triangle() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
	};

	//class RecTriangle :public Triangle
	//{
	//public:
	//	RecTriangle(double sideAB, double sideBC, double sideAC, Color color):Triangle(sideAB,sideBC,sideAC,color)
	//	{
	//		set_AB(sideAB);
	//		set_BC(sideBC);
	//		set_AC(sideAc);
	//	}
	//	~RecTriangle(){}
	//	double get_AC()const
	//	{
	//		return sqrt(get_AB() * get_AB() + get_BC() * get_BC());
	//	}
	//	double get_area()const override
	//	{
	//		return 0.5 * get_AB() * get_BC() * 1; // 1 - синус угла 90 град.
	//	}
	//	double get_perimeter()const override
	//	{
	//		return  get_AB() + get_BC()+get_AC();
	//	}
	//	void draw()const
	//	{
	//		HWND hwnd = GetConsoleWindow();
	//		hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
	//		HDC hdc = GetDC(hwnd);
	//		HPEN hPen = CreatePen(PS_SOLID, 5, color);
	//		HBRUSH hBrush = CreateSolidBrush(color);

	//		SelectObject(hdc, hPen);
	//		SelectObject(hdc, hBrush);

	//		::Triangle(hdc, 300, 300, 300 + rad, 300 + rad);

	//		DeleteObject(hBrush);
	//		DeleteObject(hPen);
	//		ReleaseDC(hwnd, hdc);
	//	}
	//	void print()const
	//	{
	//		cout << "Length of AB " << get_AB() << endl;
	//		cout << "Length of BC " << get_BC() << endl;
	//		cout << "Length of AC " << get_AC() << endl;
	//		cout << "Angle " << get_angleAB() << endl;
	//		cout << "Area of rectangle triangle " << get_area() << endl;
	//		cout << "Perimeter of ractangle triangle " << get_perimeter() << endl;
	//		cout << delim << endl;
	//	}
	//	
	//};

	class RightTriangle :public Triangle
	{
		
	public:
		RightTriangle(double sideAB,double sideBC, double sideAC, Color color) :Triangle(sideAB,sideBC, sideAC, color)
		{
			set_AB(sideAB);
			set_BC(sideBC);
			set_AC(sideAC);
		}
		double get_area()const override 
		{
			if (get_AB() == get_BC() && get_AB() == get_AC()) return (get_AB() * get_AB() * sqrt(3)) / 4;
			else
			{
				cout << "Вы указали разносторонний треугольник!!!" << endl;
				return 0;
			}
		}
		double get_perimeter()const
		{
			if (get_AB() == get_BC() && get_AB() == get_AC()) return 3 * get_AB();
			else
			{
				cout << "Вы указали разносторонний треугольник!!!" << endl;
				return 0;
			}
		}
		
		void draw()const
		{

		}
		void print()const
		{
			cout << "Length of all sides " << get_AB() << endl;
			cout << "Area of right triangle " << get_area() << endl;
			cout << "Perimeter of right triangle " << get_perimeter() << endl;
			cout << delim << endl;
		}
	};

}

int main()
{
	setlocale(LC_ALL, "Russian");

	//Shape shape(Color::CONSOLE_BLUE);
	//cout <<hex<< shape.get_color() << endl;
	//Geometry::Square square(50, Geometry::Color::RED);
	//
	////square.draw();


	Geometry::Rectangle rect(50,70,Geometry::Color::RED);
	//
	rect.draw();

	//Geometry::RecTriangle recT(30,30,90,Geometry::Color::RED);
	//
	//
	//Geometry::RightTriangle rightT(30,Geometry::Color::RED);
	//

	//Geometry::Circle cir(100, Geometry::Color::RED);
	//cir.draw();

	Geometry::Shape* group[] =
	{
		new Geometry::Rectangle(100,60,Geometry::Color::RED),
		new Geometry::Circle(10,Geometry::Color::BLUE),
		new Geometry::RightTriangle(50,50,50,Geometry::Color::GREEN),
		new Geometry::Square(50,Geometry::Color::CONSOLE_RED),
	};
	for (int i = 0; i < sizeof(group) / sizeof(Geometry::Shape*); i++)
	{
		group[i]->print();
		group[i]->draw();
	}

	
	return 0;
}