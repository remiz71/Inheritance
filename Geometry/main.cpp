#include <iostream>
#include <Windows.h>
#include <math.h>
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

		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
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
			HWND hwnd = GetDesktopWindow();//Получаем контекст устройства:
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, 200, 200, 200 + aSide, 200 + bSide);

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

		Circle(double rad, Color color) :Shape(color)
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
	public:
		Triangle(Color color) :Shape(color) {}
		~Triangle() {}

		virtual double getHeight()const = 0;
	};

	class EquilaterialTriangle :public Triangle
	{
		double side;
	public:
		double getSide()const
		{
			return side;
		}
		double setSide(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
			return this->side;
		}
		EquilaterialTriangle(double side, Color color) :Triangle(color)
		{
			setSide(side);
		}
		~EquilaterialTriangle() {}

		double getHeight()const
		{
			return sqrt(3) / 2 * side;
		}
		double get_area()const
		{
			return getHeight() / 2 * side;
		}

		double get_perimeter()const
		{
			return side * 3;
		}
		void print()const
		{
			cout << "Hello" << endl;;
			cout << getSide();
		}
		void draw()const
		{
			HWND hwnd = GetDesktopWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);


			unsigned int startX = 400;
			unsigned int startY = 400;
			POINT points[] =
			{
				{startX,startY + side},
				{startX + side,startY + side},
				{startX + side / 2, startY}
			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));



			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}

	};

	class IsoscelesTriangle : public Triangle
	{
		double side;
		double base;
	public:
		double get_side() const
		{
			return side;
		}
		double get_base() const
		{
			return base;
		}
		double set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
			return this->side;
		}
		double set_base(double base)
		{
			if (base <= 0)base = 1;
			this->base = base;
			return this->base;
		}
		IsoscelesTriangle(double side, double base, Color color) : Triangle(color)
		{
			set_side(side);
			set_base(base);
		}
		~IsoscelesTriangle() {}
		double getHeight() const
		{
			double a = sqrt(((side * side) - ((base * base)/4)));
			return a;
		}
		double get_area() const
		{
			return getHeight() * base * 0.5;
		}
		double get_perimeter() const
		{
			return 2 * side + base;
		}
		void draw()const
		{
			HWND hwnd = GetDesktopWindow();
			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN h_pen = CreatePen(PS_SOLID, 5, color);
			HBRUSH h_brush = CreateSolidBrush(color);

			SelectObject(hdc, h_pen);
			SelectObject(hdc, h_brush);

			unsigned int start_x = 600;
			unsigned int start_y = 400;

			POINT points[]
			{
			  {start_x + base, start_y},
			  {start_x + base, start_y + side},
			  {start_x , start_y + side / 2}
			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));
			DeleteObject(h_brush);
			DeleteObject(h_pen);

			ReleaseDC(hwnd, hdc);

		}
		void print()const
		{
			cout << "Длина равнобедренного треугольника: " << get_side() << endl;
			cout << "Площадь равнобедренного треугольника: " << get_area() << endl;
			cout << "Периметр  равнобедренного треугольника: " << get_perimeter() << endl;
		}
	};
}


//	class Triangle :public Shape
//	{
//		double sideAB=0;
//		double sideBC = 0;
//		double sideAC = 0;
//	public:
//		double get_AB()const
//		{
//			return sideAB;
//		}
//		double get_BC()const
//		{
//			return sideBC;
//		}
//		double get_AC()const
//		{
//			return sideAC;
//		}
//		void set_AB(double sideAB)
//		{
//			this->sideAB = sideAB;
//		}
//		void set_BC(double sideBC)
//		{
//			this->sideBC = sideBC;
//		}
//		void set_AC(double sideAC)
//		{
//			this->sideAC=sideAC;
//		}
//		Triangle (double sideAB, double sideBC, double sideAC,Color color) :Shape(color) {}
//		
//		virtual ~Triangle() {}
//
//		virtual double get_area()const = 0;
//		virtual double get_perimeter()const = 0;
//		virtual void draw()const = 0;
//	};
//
//	class RecTriangle :public Triangle
//	{
//	public:
//		RecTriangle(double sideAB, double sideBC, double sideAC, Color color):Triangle(sideAB,sideBC,sideAC,color)
//		{
//			set_AB(sideAB);
//			set_BC(sideBC);
//			set_AC(sideAc);
//		}
//		~RecTriangle(){}
//		double get_AC()const
//		{
//			return sqrt(get_AB() * get_AB() + get_BC() * get_BC());
//		}
//		double get_area()const override
//		{
//			return 0.5 * get_AB() * get_BC() * 1; // 1 - синус угла 90 град.
//		}
//		double get_perimeter()const override
//		{
//			return  get_AB() + get_BC()+get_AC();
//		}
//		void draw()const
//		{
//			HWND hwnd = GetConsoleWindow();
//			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
//			HDC hdc = GetDC(hwnd);
//			HPEN hPen = CreatePen(PS_SOLID, 5, color);
//			HBRUSH hBrush = CreateSolidBrush(color);
//
//			SelectObject(hdc, hPen);
//			SelectObject(hdc, hBrush);
//
//
//			DeleteObject(hBrush);
//			DeleteObject(hPen);
//			ReleaseDC(hwnd, hdc);
//		}
//		void print()const
//		{
//			cout << "Length of AB " << get_AB() << endl;
//			cout << "Length of BC " << get_BC() << endl;
//			cout << "Length of AC " << get_AC() << endl;
//			cout << "Angle " << get_angleAB() << endl;
//			cout << "Area of rectangle triangle " << get_area() << endl;
//			cout << "Perimeter of ractangle triangle " << get_perimeter() << endl;
//			cout << delim << endl;
//		}
//		
//	};
//
//	class RightTriangle :public Triangle
//	{
//		
//	public:
//		RightTriangle(double sideAB,double sideBC, double sideAC, Color color) :Triangle(sideAB,sideBC, sideAC, color)
//		{
//			set_AB(sideAB);
//			set_BC(sideBC);
//			set_AC(sideAC);
//		}
//		double get_area()const override 
//		{
//			if (get_AB() == get_BC() && get_AB() == get_AC()) return (get_AB() * get_AB() * sqrt(3)) / 4;
//			else
//			{
//				cout << "Вы указали разносторонний треугольник!!!" << endl;
//				return 0;
//			}
//		}
//		double get_perimeter()const
//		{
//			if (get_AB() == get_BC() && get_AB() == get_AC()) return 3 * get_AB();
//			else
//			{
//				cout << "Вы указали разносторонний треугольник!!!" << endl;
//				return 0;
//			}
//		}
//		
//		void draw()const
//		{
//
//		}
//		void print()const
//		{
//			cout << "Length of all sides " << get_AB() << endl;
//			cout << "Area of right triangle " << get_area() << endl;
//			cout << "Perimeter of right triangle " << get_perimeter() << endl;
//			cout << delim << endl;
//		}
//	};
//
//	class RectTriangle :public Triangle
//	{
//	public:
//		RectTriangle(double side_AB, double side_BC, double side_AC, Color color) :Triangle(side_AB, side_AC, side_BC, color)
//		{
//			set_AB(side_AB);
//			set_BC(side_BC);
//			set_AC(side_AC);
//		}
//		double get_area()const
//		{
//			if (get_AB() * get_AB() + get_AC() * get_AC() == get_BC() * get_BC()) return 0.5 * get_AB() * get_AC();
//			
//		}
//	};
//
//}

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
		new Geometry::Rectangle(200,150,Geometry::Color::RED),
		new Geometry::Circle(10,Geometry::Color::BLUE),
		new Geometry::Square(50,Geometry::Color::CONSOLE_RED),
		new Geometry::EquilaterialTriangle(300,Geometry::Color::GREEN),
		new Geometry::IsoscelesTriangle(5,3,Geometry::Color::RED)
	};
	for (int i = 0; i < sizeof(group) / sizeof(Geometry::Shape*); i++)
	{
		group[i]->print();
		group[i]->draw();
	}

	
	return 0;
}