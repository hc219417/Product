/**
 *   @file: product.h
 * @author: Hannah Culver
 *   @date: March 30, 2022
 *  @brief: header file for the product class
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Product{
    public:
        Product() {wizard = "none"; returning = false; order_num = 1;}
        virtual void input(istream& ins);
        virtual void output(ostream& outs)const;
        int get_order_num() {return order_num;}
        void increment(int n) {order_num += n;}
    private:
        string wizard;
        bool returning;
        int order_num;
};

class Wand:public Product{
    public:
        Wand() {core = "N/A"; wood = "N/A"; length = 12.0;}
        void input(istream& ins);
        void output(ostream& outs)const;
    private:
        string wood;
        string core;
        double length;
};

class Robe:public Product{
    public:
        Robe() {house = "N/A"; size = "N/A";}
        void input(istream& ins);
        void output(ostream& outs)const;
    private:
        string house;
        string size;
};

class Broomstick:public Product{
    public:
        Broomstick() {model = "N/A"; purpose = "N/A";}
        void input(istream& ins);
        void output(ostream& outs)const;
    private:
        string model;
        string purpose;
};

class Owl:public Product{
    public:
        Owl() {breed = "N/A"; gender = "N/A";}
        void input(istream& ins);
        void output(ostream& outs)const;
    private:
        string breed;
        string gender;
};

class Event:public Product{
    public:
        Event() {name = "N/A"; quantity = 0;}
        void input(istream& ins);
        void output(ostream& outs)const;
    private:
        string name;
        int quantity;
};