/**
 *   @file: product.cc
 * @author: Hannah Culver
 *   @date: March 30, 2022
 *  @brief: implementation file for the product class
 */

#include "product.h"
using namespace std;

int ww_menu();

void Product::input(istream& ins){
    if(&ins == &cin){
        char student;
        cout << "Are you a witch or wizard? ";
        cin >> wizard;
        cout << "Are you a returning student(y/n)? ";
        cin >> student;
        if(student == 'y') returning = true;
    }
    else{
        ins >> wizard;
        ins >> returning;
        ins >> order_num;
    }
}

void Product::output(ostream& outs)const{
    if(&outs == &cout){
        if(returning == false){
            outs << setfill('=') << setw(100) << "=" << endl;
            outs << "Welcome to Hogwarts! Your order is order #" << order_num << endl;
            outs << setfill('=') << setw(100) << "=" << endl;
        }
        else{
            outs << setfill('=') << setw(100) << "=" << endl;
            outs << "Welcome back to Hogwarts! Your order is order #" << order_num << endl;
            outs << setfill('=') << setw(100) << "=" << endl;
        }
    }
    else{
        outs << "product" << endl;
        outs << wizard << endl;
        outs << returning << endl;
        outs << order_num << endl;
    }
}

void Wand::input(istream& ins){
    if(&ins == &cin){
        int choice;
        cout << "Please enter type of wood (enter a '?' if you would like to see available options): ";
        ins >> wood;
        
        if(wood == "?"){
            ww_menu();
            cout << "Enter type of wood (please spell it out): ";
            ins >> wood;
        }

        cout << "Your options include..." << endl;
        cout << "1. unicorn hair" << endl;
        cout << "2. dragon heartstring" << endl;
        cout << "3. phoenix feather" << endl;
        cout << "Please enter type of core (input as a number): ";
        ins >> choice;

        while(choice != 1 && choice != 2 && choice != 3){
            cout << "Error: invalid choice" << endl;
            cout << "Please try again: ";
            ins >> choice;
        }

        if(choice == 1) core = "unicorn hair";
        else if(choice == 2) core = "dragon heartstring";
        else if(choice == 3) core = "phoenix feather";

        cout << "Please enter wand length (in): ";
        ins >> length;

        while(length < 9 || length > 14){
            cout << "Error: must be between 9 and 14 inches" << endl;
            cout << "Please try again: ";
            ins >> length;
        }
    }
    else{
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins,wood);
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins,core);
        ins >> length;
    }
}

void Wand::output(ostream& outs)const{
    if(&outs == &cout) outs << "You have selected a " << length << " inch wand made of " << wood << " with " << core << endl;
    else{
        outs << "wand" << endl;
        outs << wood << endl;
        outs << core << endl;
        outs << length << endl;
    }
}

void Robe::input(istream& ins){
    if(&ins == &cin){
        char chouse;
        char csize;

        cout << "Please enter house (g/s/r/h): ";
        ins >> chouse;

        if(chouse == 'g') house = "gryffindor";
        else if(chouse == 's') house = "slytherin";
        else if(chouse == 'r') house = "ravenclaw";
        else if(chouse == 'h') house = "hufflepuff";

        cout << "Please enter size (s/m/l): ";
        ins >> csize;

        if(csize == 's') size = "small";
        else if(csize == 'm') size = "medium";
        else if(csize == 'l') size = "large";
    }
    else{
        ins >> house;
        ins >> size;
    }
}

void Robe::output(ostream& outs)const{
    if(&outs == &cout) outs << "You have selected a " << house << " robe, size " << size << endl;
    else{
        outs << "robe" << endl;
        outs << house << endl;
        outs << size << endl;
    }
}

void Broomstick::input(istream& ins){
    if(&ins == &cin){
        int mchoice;
        int pchoice;

        cout << "Your options include..." << endl;
        cout << "1. toy" << endl;
        cout << "2. nimbus 2000" << endl;
        cout << "3. firebolt" << endl;
        cout << "Please enter model (input as a number): ";
        ins >> mchoice;

        while(mchoice != 1 && mchoice != 2 && mchoice != 3){
            cout << "Error: invalid choice" << endl;
            cout << "Please try again: ";
            ins >> mchoice;
        }

        if(mchoice == 1) model = "toy";
        else if(mchoice == 2) model = "nimbus 2000";
        else if(mchoice == 3) model = "firebolt";

        cout << "Your options include..." << endl;
        cout << "1. sports" << endl;
        cout << "2. recreation" << endl;
        cout << "3. both" << endl;
        cout << "Please enter purpose (input as a number): ";
        ins >> pchoice;

        while(pchoice != 1 && pchoice != 2 && pchoice != 3){
            cout << "Error: invalid choice" << endl;
            cout << "Please try again: ";
            ins >> pchoice;
        }

        if(pchoice == 1) purpose = "sports";
        else if(pchoice == 2) purpose = "recreation";
        else if(pchoice == 3) purpose = "both";
    }
    else{
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins,model);
        ins >> purpose;
    }
}

void Broomstick::output(ostream& outs)const{
    if(&outs == &cout){
        if(purpose == "sports") outs << "You have selected the " << model << " broomstick for sporting use" << endl;
        else if(purpose == "recreation") outs << "You have selected the " << model << " broomstick for recreational use" << endl;
        else if(purpose == "both") outs << "You have selected the " << model << " broomstick for both sporting and recreational use" << endl;
    }
    else{
        outs << "broomstick" << endl;
        outs << model << endl;
        outs << purpose << endl;
    }
}

void Owl::input(istream& ins){
    if(&ins == &cin){
        int choice;
        char cgender;

        cout << "Your options include..." << endl;
        cout << "1. eagle" << endl;
        cout << "2. little" << endl;
        cout << "3. snowy" << endl;
        cout << "Please enter breed (input as a number): ";
        ins >> choice;

        while(choice != 1 && choice != 2 && choice != 3){
            cout << "Error: invalid choice" << endl;
            cout << "Please try again: ";
            ins >> choice;
        }

        if(choice == 1) breed = "eagle";
        else if(choice == 2) breed = "little";
        else if(choice == 3) breed = "snowy";

        cout << "Please enter gender (m/f): ";
        ins >> cgender;

        if(cgender == 'm') gender = "male";
        else if(cgender == 'f') gender = "female";
    }
    else{
        ins >> breed;
        ins >> gender;
    }
}

void Owl::output(ostream& outs)const{
    if(&outs == &cout) outs << "You have selected a(n) " << breed << " owl (" << gender << ")" << endl;
    else{
        outs << "owl" << endl;
        outs << breed << endl;
        outs << gender << endl;
    }
}

void Event::input(istream& ins){
    if(&ins == &cin){
        int choice;

        cout << "Your options include..." << endl;
        cout << "1. quidditch match" << endl;
        cout << "2. triwizard tournament" << endl;
        cout << "3. yule ball" << endl;
        cout << "Please enter event name (input as a number): ";
        ins >> choice;

        while(choice != 1 && choice != 2 && choice != 3){
            cout << "Error: invalid choice" << endl;
            cout << "Please try again: ";
            ins >> choice;
        }

        if(choice == 1) name = "quidditch match";
        else if(choice == 2) name = "triwizard tournament";
        else if(choice == 3) name = "yule ball";

        cout << "Please enter quantity: ";
        ins >> quantity;

        while(quantity < 1){
            cout << "Error: must be greater than 0" << endl;
            cout << "Please try again: ";
            ins >> quantity;
        }
    }
    else{
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins,name);
        ins >> quantity;
    }
}

void Event::output(ostream& outs)const{
    if(&outs == &cout) outs << "You have selected " << quantity << " ticket(s) to the " << name << endl;
    else{
        outs << "event" << endl;
        outs << name << endl;
        outs << quantity << endl;
    }
}

int ww_menu(){
    cout << "1. acacia" << endl;
    cout << "2. alder" << endl;
    cout << "3. apple" << endl;
    cout << "4. ash" << endl;
    cout << "5. aspen" << endl;
    cout << "6. beech" << endl;
    cout << "7. blackthorn" << endl;
    cout << "8. black walnut" << endl;
    cout << "9. cedar" << endl;
    cout << "10. cherry" << endl;
    cout << "11. chestnut" << endl;
    cout << "12. cypress" << endl;
    cout << "13. dogwood" << endl;
    cout << "14. ebony" << endl;
    cout << "15. elder" << endl;
    cout << "16. elm" << endl;
    cout << "17. english oak" << endl;
    cout << "18. fir" << endl;
    cout << "19. hawthorn" << endl;
    cout << "20. hazel" << endl;
    cout << "21. holly" << endl;
    cout << "22. hornbeam" << endl;
    cout << "23. larch" << endl;
    cout << "24. laurel" << endl;
    cout << "25. maple" << endl;
    cout << "26. pear" << endl;
    cout << "27. pine" << endl;
    cout << "28. poplar" << endl;
    cout << "29. red oak" << endl;
    cout << "30. redwood" << endl;
    cout << "31. rowan" << endl;
    cout << "32. silver lime" << endl;
    cout << "33. spruce" << endl;
    cout << "34. sycamore" << endl;
    cout << "35. vine" << endl;
    cout << "36. walnut" << endl;
    cout << "37. willow" << endl;
    cout << "38. yew" << endl;
    return 0;
}