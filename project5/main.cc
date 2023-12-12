/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: March 30, 2022
 *  @brief: project 5 main
 */

#include <list>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "product.h"
using namespace std;

int menu();

int main(){

    char status;
    cout << "I'm not a muggle (y/n) "; // the joke here is that it's like the 'I'm not a robot' test
    cin >> status;

    if(status == 'y') cout << "Happy shopping!" << endl;
    else if(status == 'n'){
        cout << "Sorry, Hogwarts students only :(" << endl;
        return 0;
    }

    Product* tmp;
    int order_num;

    list<Product*> order;
    list<Product*>::iterator it;

    ifstream fin;
    ofstream fout;

    string filename = "orders.txt";
    fin.open(filename);

    if(!fin.fail()){
        while(!fin.eof()){
            string tag;
            fin >> tag;
            if(tag == "product"){
                tmp = new Product;
                tmp -> input(fin);
                order_num = tmp -> get_order_num();
            }
            else if(tag == "wand"){
                tmp = new Wand;
                tmp -> input(fin);
            }
            else if(tag == "robe"){
                tmp = new Robe;
                tmp -> input(fin);
            }
            else if(tag == "broomstick"){
                tmp = new Broomstick;
                tmp -> input(fin);
            }
            else if(tag == "owl"){
                tmp = new Owl;
                tmp -> input(fin);
            }
            else if(tag == "event"){
                tmp = new Event;
                tmp -> input(fin);
            }
            while(fin.peek() == '\n' || fin.peek() == '\r') fin.ignore();
            order.push_back(tmp);
        }
    }
    fin.close();

    char choice;
    choice = menu();

    while(choice != 'q'){
        if(choice == '0'){
            tmp = new Product;
            tmp -> increment(order_num);
            order_num++;
        }
        else if(choice == '1'){
            tmp = new Wand;
        }
        else if(choice == '2'){
            tmp = new Robe;
        }
        else if(choice == '3'){
            tmp = new Broomstick;
        }
        else if(choice == '4'){
            tmp = new Owl;
        }
        else if(choice == '5'){
            tmp = new Event;
        }
        else if(choice == '6'){
            it = order.begin();
            while(it != order.end()){
                (*it) -> output(cout);
                ++it;
            }
            cout << setfill('=') << setw(100) << "=" << endl;
            choice = menu();
            continue;
        }
        tmp -> input(cin);
        Product* otmp = tmp;
        otmp -> output(cout);
        order.push_back(tmp);
        choice = menu();
    }

    fout.open(filename);
    if(!fout.fail()){
        it = order.begin();
        while(it != order.end()){
            (*it) -> output(fout);
            ++it;
        }
    }
    else cout << "Error: unable to save order" << endl;
    fout.close();

    cout << "Come back soon!" << endl;
    return 0;
}

int menu(){
	char ans;
    cout << "Enter 0 to start a new order" << endl;
	cout << "Enter 1 to add a wand" << endl;
	cout << "Enter 2 to add a robe" << endl;
	cout << "Enter 3 to add a broomstick" << endl;
    cout << "Enter 4 to add an owl" << endl;
    cout << "Enter 5 to add an event" << endl;
    cout << "Enter 6 to view your current order(s)" << endl;
	cout << "Enter q to quit" << endl;
	cin >> ans;
	return ans;
}