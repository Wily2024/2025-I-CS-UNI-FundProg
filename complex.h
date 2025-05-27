#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
#include <cmath> 

using namespace std;

using RealType = double;
using ImagType = double;

class Complex
{
private:
    RealType m_r = 0;
    ImagType m_i = 0;

public:
    Complex() = default;
    Complex(RealType r, ImagType i) : m_r(r), m_i(i) {}
    Complex(const Complex& other) = default;

    ~Complex() = default;

    Complex& operator+=(const Complex& other) {
        m_r += other.m_r;
        m_i += other.m_i;
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        m_r -= other.m_r;
        m_i -= other.m_i;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        RealType r = m_r * other.m_r - m_i * other.m_i;
        ImagType i = m_r * other.m_i + m_i * other.m_r;
        m_r = r;
        m_i = i;
        return *this;
    }

    Complex& operator/=(const Complex& other) {
        RealType denom = other.m_r * other.m_r + other.m_i * other.m_i;
        m_r = (m_r * other.m_r + m_i * other.m_i) / denom;
        m_i = (m_i * other.m_r - m_r * other.m_i) / denom;
        return *this;
    }

    Complex operator+(const Complex& other) const {
        return Complex(m_r + other.m_r, m_i + other.m_i);
    }

    Complex operator-(const Complex& other) const {
        return Complex(m_r - other.m_r, m_i - other.m_i);
    }

    Complex operator*(const Complex& other) const {
        return Complex(m_r * other.m_r - m_i * other.m_i,
                      m_r * other.m_i + m_i * other.m_r);
    }

    Complex operator/(const Complex& other) const {
        RealType denom = other.m_r * other.m_r + other.m_i * other.m_i;
        return Complex((m_r * other.m_r + m_i * other.m_i) / denom,
                      (m_i * other.m_r - m_r * other.m_i) / denom);
    }

    bool operator==(const Complex& other) const {
        return m_r == other.m_r && m_i == other.m_i;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    Complex& operator=(const Complex& other) = default;

    operator RealType() const { return m_r; }
    operator ImagType() const { return m_i; }

    RealType getReal() const { return m_r; }
    ImagType getImag() const { return m_i; }

    void setReal(RealType r) { m_r = r; }
    void setImag(ImagType i) { m_i = i; }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.m_r << (c.m_i >= 0 ? " + " : " - ") << abs(c.m_i) << "i)";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        char ch;
        is >> ch; // '('
        is >> c.m_r;
        is >> ch; // '+' o '-'
        if (ch == '-') {
            is >> c.m_i;
            c.m_i = -c.m_i;
        } else {
            is >> c.m_i;
        }
        is >> ch; // 'i'
        is >> ch; // ')'
        return is;
    }
};

#endif // __COMPLEX_H__
