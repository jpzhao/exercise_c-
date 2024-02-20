#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR{
    class Vector{
        public:
            enum Mode{RECT,POL};/*RECT:直角坐标,POL:极坐标*/
        private:
            double x;/*horizontal value 水平值*/
            double y;/*vertical value 垂直值*/
            double mag;/*length of vector 矢量长度*/
            double ang;/*direction of vector in degrees 矢量的方向（度）*/
            Mode mode;
            void set_mag();
            void set_ang();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double n1,double n2,Mode form=RECT);
            void reset(double n1,double n2,Mode form=RECT);
            ~Vector();
            double xval() const{return x;}
            double yval() const{return y;}
            double magval() const{return mag;}
            double angval() const{return ang;}
            void polar_mode();
            void rect_mode();
            Vector operator+(const Vector &b)const;
            Vector operator-(const Vector &b)const;
            Vector operator-()const;
            Vector operator*(double n)const;
            friend Vector operator*(double n,const Vector &a);
            friend std::ostream & operator<<(std::ostream &os,const Vector &v);
    };
}
#endif