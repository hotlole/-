#include <iostream>
#include <cmath>

using namespace std;

// Функция для решения нелинейного уравнения методом Ньютона
double newtonMethod(double initialGuess, double epsilon, double (*function)(double), double (*derivative)(double)) {
    double x = initialGuess; // начальное предположение
    double f, fPrime;

    do {
        f = function(x);
        fPrime = derivative(x);
        x = x - f / fPrime;
    } while (fabs(f) > epsilon);

    return x;
}

// Произвольные функции и их производные
double function1(double x) {
    return x * x - 2;
}

double derivative1(double x) {
    return 2 * x;
}

double function2(double x) {
    return sin(x);
}

double derivative2(double x) {
    return cos(x);
}

double function3(double x) {
    return exp(x) - 1;
}

double derivative3(double x) {
    return exp(x);
}

double function4(double x) {
    return log(x);
}

double derivative4(double x) {
    return 1 / x;
}

double function5(double x) {
    return 5 * sin(x) * sin(x) + pow(x,2) - 4;
}

double derivative5(double x) {
    return 10 * sin(x) * cos(x) + 2*x;
}

int main() {

    // Функция 1: f(x) = x^2 - 2
    double root1 = newtonMethod(1.0, 0.0001, function1, derivative1);
    cout << "Root 1: " << root1 << endl;

    // Функция 2: f(x) = sin(x)
    double root2 = newtonMethod(2.0, 0.0001, function2, derivative2);
    cout << "Root 2: " << root2 << endl;

    // Функция 3: f(x) = exp(x) - 1
    double root3 = newtonMethod(0.0, 0.0001, function3, derivative3);
    cout << "Root 3: " << root3 << endl;

    // Функция 4: f(x) = log(x)
    double root4 = newtonMethod(2.0, 0.0001, function4, derivative4);
    cout << "Root 4: " << root4 << endl;

    // Функция 5: f(x) = x^3 + 2x^2 - 5
    double root5 = newtonMethod(2.0, 0.0001, function5, derivative5);
    cout << "Root 5: " << root5 << endl;

    return 0;
}
