#include <iostream>
#include <ctime>

using namespace std;

class Point
{
private: // ��������� �������(����������)
	int x; // ���� ������
	int y;
public:
	void Init() // ������ ������
	{
		cin >> x >> y; // ������������� �������
	}
	void Init(int a, int b) // ������������� � ������� ���������� �� ���������
	{
		x = a;
		y = b;
	}
	void Print() // �����
	{
		cout << x << "\n-\n" << y << "\n\n\n";
	}
	Point Reduction(Point c) // ����� ����������
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
	Point Sum(Point b) // ����� �����
	{
		Point c;
		c.x = x * b.y + b.x * y;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Minus(Point b) // ����� ������
	{
		Point c;
		c.x = x * b.y - y * b.x;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Multiply(Point b) // ����� ���������
	{
		Point c;
		c.x = x * b.x;
		c.y = y * b.y;
		c = Reduction(c);
		return c;
	}
	Point Dividing(Point b) // ����� �������
	{
		Point c;
		c.x = x * b.y;
		c.y = y * b.x;
		c = Reduction(c);
		return c;
	}
};

int main() // ������
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