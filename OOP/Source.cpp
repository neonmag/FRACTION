#include <iostream>
#include <ctime>

using namespace std;

class Point
{
private: // состояние объекта(реализация)
	int x; // поля класса
	int y;
public:
	void Init() // методы класса
	{
		cin >> x >> y; // Инициализация вручную
	}
	void Init(int a, int b) // Инициализация с помощью параметров по умолчанию
	{
		x = a;
		y = b;
	}
	void Print() // Вывод
	{
		cout << x << "\n-\n" << y << "\n\n\n";
	}
	Point Reduction(Point c) // Метод сокращения
	{
		for (size_t i = 2;;i++)
		{
			if (c.x % i == 0 && c.y % i == 0)
			{
				c.x /= i;
				c.y /= i;
				i--;
			}
			else if (c.x < i && c.y < i)
			{
				return c;
			} 
		}
		return c;
	}
	Point Sum(Point b) // Метод суммы
	{
		Point c;
		c.x = x * b.y + b.x * y;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Minus(Point b) // Метод минуса
	{
		Point c;
		c.x = x * b.y - y * b.x;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Multiply(Point b) // Метод умножения
	{
		Point c;
		c.x = x * b.x;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Dividing(Point b) // Метод деления
	{
		Point c;
		c.x = x * b.y;
		c.y = y * b.x;
		c = Reduction(c);
		return c;
	}
};

int main() // Клиент
{
	srand(time(0));
	int first_upper = 1 + rand() % 9;
	int first_down = 1 + rand() % 9;
	int second_upper = 1 + rand() % 9;
	int second_down = 1 + rand() % 9;
	Point a;
	a.Init(first_upper, first_down);
	a.Print();

	Point b;
	b.Init(second_upper, second_down);
	b.Print();

	Point c = a.Sum(b);
	c.Print();
}