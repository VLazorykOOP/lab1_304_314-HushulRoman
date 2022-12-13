// ЛБ№3_Зд1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

class Square {
	double a; //side square
	unsigned int color;
public:
	Square() : a(1.0), color(0) {}
	Square(double ai) : a(ai), color(0) {}
	Square(int ic) : a(1.0) { if (ic >= 0) color = ic; else color = 0; }
	Square(double a, int c) {
		this->a = a;
		if (c >= 0) color = c; else color = 0;
	}
	double getA() const
	{
		return a;
	}
	void setA(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << "Error set a \n";
			return;
		}
		this->a = a;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << "Error set color \n";
		}
		this->color = c;
	}
	double P(){
		return a + a + a + a;
	}
	double S() {
		return a * a;
	}
	void printInfo()
	{
		cout << "\n a = " << a << " | " << " color = " << color;
		cout << "\n P = " << P() << " | " << " S = " << S() << endl;
	}
	                
};

int main() {
	Square obj;
	obj.printInfo();
	double in_a; int in_color;
	cout << " Input side and color Square "; cin >> in_a >> in_color;
	Square  obj1(in_a), obj2(in_color), obj3(in_a, in_color);
	obj1.printInfo(); 
	obj2.printInfo();
	obj3.printInfo();
	obj.setA(-5);
	obj.printInfo();
	obj.setA(5);
	obj.printInfo();
	obj.setA(2.e100);
	obj.printInfo();
	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
	cout << "End testing \n";
	return 0;

}


