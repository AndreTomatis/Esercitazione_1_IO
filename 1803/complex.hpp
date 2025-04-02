#pragma once

#include <iostream>
#include <concepts>

template <typename T>
requires (std::same_as<T, float> || std::same_as<T, double>)
class complex_number {
private:
    T real;
    T imag;

public:
    // Costruttore di default
    complex_number() : real(0), imag(0) {}
    
    // Costruttore parametrizzato
    explicit complex_number(T r, T i) : real(r), imag(i) {}
    
    // Metodi per ottenere le parti reale e immaginaria
    T get_real() const { return real; }
    T get_imag() const { return imag; }

    // Metodo per ottenere il coniugato
    complex_number conjugate() const { return complex_number(real, -imag); }
    
    // Overload dell'operatore +=
    complex_number& operator+=(const complex_number& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    complex_number& operator+=(const T& other) {
        real += other;
        return *this;
    }

    // Overload dell'operatore +
    complex_number operator+(const complex_number& rhs) const {
        complex_number ret = *this;
        ret += rhs;
        return ret;
    }

    complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    // Overload dell'operatore *=
    complex_number& operator*=(const complex_number& other) {
        T new_real = real * other.real - imag * other.imag;
        T new_imag = real * other.imag + imag * other.real;
        real = new_real;
        imag = new_imag;
        return *this;
    }

    complex_number& operator*=(const T& rhs) {
        real *= rhs;
        imag *= rhs;
        return *this;
    }

    // Overload dell'operatore *
    complex_number operator*(const complex_number& rhs) const {
        complex_number ret = *this;
        ret *= rhs;
        return ret;
    }

    complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

// Overload degli operatori per tipi scalari a sinistra
template<typename T>
complex_number<T> operator+(const T& i, const complex_number<T>& r) {
    return r + i;
}

template<typename T>
complex_number<T> operator*(const T& i, const complex_number<T>& r) {
    return r * i;
}

// Overload dell'operatore << per la stampa
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
    os << c.get_real();
    if (c.get_imag() >= 0)
        os << "+";
    os << c.get_imag() << "i";
    return os;
}
