#include <iostream> 

float Addition(float x, float y) {
    return x + y;
}

float Subtraction(float x, float y) {
    return x - y;
}

float Multiplication(float x, float y) {
    return x * y;
}

float Division(float x, float y) {
    if (y != 0) {
        return x / y;
    } else {
        std::cout << "no se puede dividir por 0" << std::endl;
        return 0; 
    }
}

int main() {
    typedef float (*lpfnOperation)(float, float);

    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};

    float a, b, c; 
    int opt;

    std::cout << "Ingrese dos numeros: ";
    std::cin >> a >> b;

    std::cout << "Seleccione la operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    std::cin >> opt;

    c = (*vpf[opt])(a, b);

    return 0;
}