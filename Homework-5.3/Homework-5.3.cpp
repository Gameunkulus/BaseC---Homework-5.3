﻿// Homework-5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class figure {
protected:

    int numSides;

public:

    figure() {
        this->numSides = 0;
    };

    int getSides() {
        return numSides;
    };

    void setSides(int num) {
        this->numSides = num;
    };

    virtual bool check() {
            return true;        
    };

    virtual string printInfo() {
        if (check()) {
            return "Правильная";
        }
        else {
            "Неправильная";
        };
    }

    void getSidesCount() {
        cout << "Фигура: " << endl << printInfo() << endl << "Количество сторон: " << getSides() << endl;
    };

};

class Triangle : public figure {

protected:
    int a, b, c;
    int A, B, C;

public:

    Triangle(int a, int b, int c, int A, int B, int C) : figure() {
        numSides = 3;
        if (a == 0 || b == 0 || c == 0) {
            cout << "Ошибка, стороны треугольника не могут быть равны нулю." << endl;
        }
        else if (A == 0 || B == 0 || C == 0) {
            cout << "Ошибка, углы треугольника не могут быть равны нулю." << endl;
        }
        else if ((a + b) < c || (b + c) < a || (c + a) < b)
        {
            cout << "Ошибка, недопустимые значения сторон треугольника." << endl;
        }
        else if ((A + B + C) > 180) {
            cout << "Ошибка, сумма значений углов не могут быть больше 180." << endl;
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        };
    };

    string getSidesNum() {
        return "Количество сторон " + to_string(numSides);
    };

    bool check() override {
        if (a == b && b == c && c == a && A == B && B == C && C == A) {
            return true;
        }
        else {
            return false;
        };
    };

    string printInfo() override {
        if (check() != true) {
            return "Неправильная";
        }
        else {
            "Правильная";
        };
    }

    string getSides() {
        string text = getSidesNum() + "\n" + "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\n" +
            "Углы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
        return text;
    };

    void getSidesCount() {
        string triangleType = "Треугольник: ";
            cout << triangleType << endl << printInfo() << endl << getSides() << endl;     
    };

};

class Fourangle : public figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:

    Fourangle(int a, int b, int c, int d, int A, int B, int C, int D) : figure() {
        numSides = 4;
        if (a == 0 || b == 0 || c == 0 || d == 0) {
            cout << "Ошибка, стороны четырехугольника не могут быть равны нулю." << endl;
        }
        else if (A == 0 || B == 0 || C == 0 || D == 0) {
            cout << "Ошибка, углы четырехугольника не могут быть равны нулю." << endl;
        }
        else if ((A + B + C + D) > 360) {
            cout << "Ошибка, сумма значений углов не могут быть больше 360." << endl;
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        };


    };

    string getSidesNum() {
        return "Количество сторон " + to_string(numSides);
    };

    string getSides() {
        string text = getSidesNum() + "\n" + "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\n" +
            "Углы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
        return text;
    };

    bool check() override {

        if (a == b && b == c && c == d && d == a && A == B && B == C && C == D && D == A) {
            return true;
        }
        else {
            return false;
        };
        
    };

    string printInfo() override {
        if (check() != true) {
            return "Неправильная";
        }
        else {
            return "Правильная";
        };
    }

    void getSidesCount() {

            cout << "Четырехугольник " << endl << printInfo() << endl << getSides() << endl;
        
    };


};


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    figure figure;
    figure.getSidesCount();

    Triangle triangle(10, 10, 10, 60, 60, 60);
    triangle.getSidesCount();


    Triangle triangleTwo(20, 10, 20, 60, 50, 60);
    triangleTwo.getSidesCount();

    Triangle triangleThree(10, 25, 15, 25, 65, 90);
    triangleThree.getSidesCount();

    Triangle triangleFour(10, 25, 15, 35, 65, 80);
    triangleFour.getSidesCount();

    Fourangle fourangle(10, 20, 30, 40, 50, 60, 70, 80);
    fourangle.getSidesCount();

    Fourangle fourangleTwo(10, 20, 10, 20, 90, 90, 90, 90);
    fourangleTwo.getSidesCount();

    Fourangle fourangleThree(20, 20, 20, 20, 90, 90, 90, 90);
    fourangleThree.getSidesCount();

    Fourangle fourangleFour(20, 30, 20, 30, 30, 40, 30, 40);
    fourangleFour.getSidesCount();

    Fourangle fourangleFive(30, 30, 30, 30, 30, 40, 30, 40);
    fourangleFive.getSidesCount();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
