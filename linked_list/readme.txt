/*******************************************************************************
L I N K E D  L I S T
*******************************************************************************/

This is my solution to a linked list that can remove nodes containing odd 
numbers. Instead of using functions and passing a pointer to the head by 
reference I decided to create a class to store the head, and decided to also 
include a tail data member which maintained a pointer to the tail of the list 
for fast back insertions. I also decided to use unique_ptr instead of the 
typical raw pointer, as I wanted to play around with move semantics and see how 
the pointers were managed.

/*******************************************************************************
Main Input Example:
*******************************************************************************/

LinkedList list;

list.print();

list.pushBack(1);
list.print();
list.deleteNode(0);
list.print();

list.pushBack(7);
list.pushBack(5);
list.pushBack(4);
list.pushBack(7);

list.print();

list.deleteNode(3);
list.print();
list.pushBack(2);
list.print();
list.pushBack(11);

list.print();

list.insertNode(0, 15);
list.insertNode(3, 20);

list.print();

list.deleteOdd();

list.print();

list.printLength();

std::cout << "Nodes created: " << nodes_created << '\n';
std::cout << "Nodes deleted: " << nodes_deleted << '\n';
printf("Exiting...\n");
return EXIT_SUCCESS;

/*******************************************************************************
Output Example:
*******************************************************************************/

printing list:
list empty!

inserting 1 at back; length: 1

printing list:
list[0]: 1

delete at position[0]
Node Destructor: Node with value: 1 deleted

printing list:
list empty!

inserting 7 at back; length: 1

inserting 5 at back; length: 2

inserting 4 at back; length: 3

inserting 7 at back; length: 4

printing list:
list[0]: 7
list[1]: 5
list[2]: 4
list[3]: 7

delete at position[3]
Node Destructor: Node with value: 7 deleted

printing list:
list[0]: 7
list[1]: 5
list[2]: 4

inserting 2 at back; length: 4

printing list:
list[0]: 7
list[1]: 5
list[2]: 4
list[3]: 2

inserting 11 at back; length: 5

printing list:
list[0]: 7
list[1]: 5
list[2]: 4
list[3]: 2
list[4]: 11

insert 15 at position[0]

insert 20 at position[3]

printing list:
list[0]: 15
list[1]: 7
list[2]: 5
list[3]: 20
list[4]: 4
list[5]: 2
list[6]: 11

deleting odds

list[0]: 15 -odd
Node Destructor: Node with value: 15 deleted

list[1]: 7 -odd
Node Destructor: Node with value: 7 deleted

list[2]: 5 -odd
Node Destructor: Node with value: 5 deleted

list[3]: 20

list[4]: 4

list[5]: 2

list[6]: 11 -odd
Node Destructor: Node with value: 11 deleted

printing list:
list[0]: 20
list[1]: 4
list[2]: 2

length: 3
Nodes created: 9
Nodes deleted: 6
Exiting...
Node Destructor: Node with value: 20 deleted
Node Destructor: Node with value: 4 deleted
Node Destructor: Node with value: 2 deleted


