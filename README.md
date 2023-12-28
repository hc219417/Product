# Product

Congratulations! You are enrolling at Hogwarts School of Witchcraft and Wizardry. Fill out an order and select a wand, house robe, broomstick, owl, and event to attend.

This project contains a group of classes, including a parent class and five other classes which are children of this class. These children, as all they really need are input and output functions, are virtual in the parent.

A UML class diagram which describes these classes has been constructed using *Star UML* (download for free at https://staruml.io/download) and is available in the form of a .mdj file.

<img src="./project5/star uml/diagram pic.png" width="600" height="400">

The application for this project declares an *STL list* of pointers of the parent class (`Product`) which dynamically holds allocated products that have been ordered. The user is presented with a menu from which they can choose a product that they would like to order. They are then taken to an input function for that item where they can enter its attributes. Once the customized product is constructed, it is put into the list with the `push_back` member function.

The menu also offers a means to view all the items in the list. Since the list class has no “`show_all`” function, we rely on the iterator to do this, and note that since we are storing pointers to items instead of the items itself, and since non-member overloaded operators don’t work well with this paradigm, the syntax for outputting each thing looks like: `(*it) -> output(cout);`

Finally, a backup file system is written so that a user does not have to reenter all the products that have been ordered every time they start the program. This backup file is invisible to the user (called `orders.txt`). The program simply looks for the file, and if it is not found it is assumed that this is the first use of the program, but if it is found the product orders are put into the list the same way as they were when entered from the keyboard. Following the loading of the list from a file the user is taken to the menu where they can see the orders that are waiting to be filled or add new orders to the list.

*Please note*: This is NOT a container but instead uses the STL list class (available if you just `#include <list>`.) For this project just the `push_back` function and the iterator, which is bidirectional—but which is only being used in a forward direction for order output—are needed.
