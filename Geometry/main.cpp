#include <iostream>
#include <Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		CONSOLE_DEFAULT = 0x07,
		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
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
		void draw()const
		{
			//#define SIMPLEE_DRAW
#ifdef SIMPLEE_DRAW 
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем обработчик окна консоли
			SetConsoleTextAttribute(hConsole, get_color());//Задаем цвет текста в консоли
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
	}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
#endif // SIMPLEE_DRAW

			//Получаем Обработчик окна
			HWND hwnd = GetConsoleWindow();
			hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");//Получаем контекст устройства:
			HDC hdc = GetDC(hwnd); // Handlet=to-Device context
			//создаем карандаш и кисть
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));//Solid - сплошная , 5 - толщина линии
			//пэн рисует контур
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
			//берем кисть и карандаш
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Рсиуем квадрат
			Rectangle(hdc, 300, 300, 300 + side, 300 + side);


			// Освобожлаем ресурсы
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

}
};

	class Rectangle :public Shape
	{

	};
	}

int main()
{
	setlocale(LC_ALL, "Russian");

	//Shape shape(Color::CONSOLE_BLUE);
	//cout <<hex<< shape.get_color() << endl;
	Geometry::Square square(50, Geometry::Color::CONSOLE_BLUE);
	cout<<"Length of side: " << square.get_side() << endl;
	cout << "Area of square: " << square.get_area() << endl;
	cout << "Perimeter of square: " << square.get_perimeter() << endl;
	square.draw();


	Geometry::Rectangle rect;
	
	
	return 0;
}