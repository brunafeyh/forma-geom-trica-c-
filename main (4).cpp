#include <iostream>
#include <vector>
#include <cmath>


class FormaGeometrica {
public:
    FormaGeometrica() {} // construtor padrão

    virtual ~FormaGeometrica() {} // destrutor virtual

    virtual double getArea() = 0; // função virtual
};


class Ponto {
public:
    Ponto(double x, double y) : x(x), y(y) {} // construtor

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

private:
    double x;
    double y;
};


class Circulo : public Ponto, public FormaGeometrica {
public:
    Circulo(double x, double y, double raio) : Ponto(x, y), raio(raio) {} // construtor

    // função virtual para calcular a área do círculo
    double getArea() override {
        return 3.14159 * raio * raio;
    }

private:
    double raio;
};

// Classe do retângulo
class Retangulo : public FormaGeometrica {
public:
    Retangulo(Ponto ponto1, Ponto ponto2) : ponto1(ponto1), ponto2(ponto2) {} // construtor

    // função virtual para calcular a área do retângulo
    double getArea() override {
        double base = std::abs(ponto1.getX() - ponto2.getX());
        double altura = std::abs(ponto1.getY() - ponto2.getY());
        return base * altura;
    }

private:
    Ponto ponto1;
    Ponto ponto2;
};

// Classe do triângulo retângulo
class TrianguloRetangulo : public FormaGeometrica {
public:
    TrianguloRetangulo(Ponto ponto1, Ponto ponto2) : ponto1(ponto1), ponto2(ponto2) {} // Construtor

    // função virtual para calcular a área do triângulo retângulo
    double getArea() override {
        double base = std::abs(ponto1.getX() - ponto2.getX());
        double altura = std::abs(ponto1.getY() - ponto2.getY());
        return base * altura / 2;
    }

private:
    Ponto ponto1;
    Ponto ponto2;
};


class Esfera : public Ponto, public FormaGeometrica {
public:
    Esfera(double x, double y, double raio) : Ponto(x, y), raio(raio) {} // cons[trutor

    // função virtual para calcular a área da superfície de uma esfera
    double getArea() override {
        return 4 * 3.14159 * raio * raio;
    }

private:
    double raio;
};

int main() {
    std::vector<FormaGeometrica*> formas;


    formas.push_back(new Circulo(0, 0, 5));
    formas.push_back(new Retangulo(Ponto(0, 0), Ponto(3, 4)));
    formas.push_back(new TrianguloRetangulo(Ponto(0, 0), Ponto(3, 4)));
    formas.push_back(new Esfera(0, 0, 5));

    for (auto forma : formas) {
        std::cout << "Área: " << forma->getArea() << std::endl;
        delete forma; // Libera a memória alocada dinamicamente
    }

    return 0;
}

