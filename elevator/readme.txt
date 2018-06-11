/*******************************************************************************
E L E V A T O R  P R O B L E M
*******************************************************************************/

People are waiting for an elevator in a hotel. The elevator has limited capacity
and you would like to analyse its movement.

The hotel has floors numbered from 0 (ground floor) to M. The elevator has a
maximum capacity of X people and a weight limit of Y. There are N people 
gathered at the ground floor, standing in a queue for the elevator. You are 
given every person's weight A[K] and target floor B[K]. (That is, A[0] and B[0]
represent the first person in the queue).

People continue to enter the elevator, in order of their position in the queue
(and push the buttons for their target floors), for as long as there is room for
them. (The queue order cannot be changed even if there is room in the elevator
for a particular person from the middle of the queue).

The elevator goes up and stops at every selected floor, and finally returns to 
the ground floor. This process is repeated until there are no more people in the
queue. The goal is to count the total number of times that the elevator stops.


Example:

Consider a hotel with floors numbered from 0 to M = 5, with an elevator with a
maximum capacity of X = 2 people and a weight limit of Y = 200. The weights A
and target floors B are:

A[0] = 60
A[1] = 80
A[2] = 40

B[0] = 2
B[1] = 3
B[2] = 5


The elevator will take the first two passengers together, stop at the 2nd and 
3rd floors, then return to the ground floor. In total, the elevator wil stop 
five times. Note that this number includes the last stop at the ground floor.

/*******************************************************************************
Main input example:
*******************************************************************************/

/* A = vec of each person's weight, B = vec of each person's target floor */
vector<int> A = {40, 40, 100, 80, 20, 20, 200, 20};
vector<int> B = {3, 1, 2, 2, 3, 4, 1, 1}; /* 4 + 4 + 2 + 2 = 12 stops */

/* 0 - M floors, people cap = X, weight limit = Y  */
int M = 3, X = 5, Y = 200;
int ans = run(A, B, M, X, Y);
cout << "num stops: " << ans << endl;


/*******************************************************************************
Output Example:
*******************************************************************************/

capacity: 180
num people in lift: 3
capacity: 120
num people in lift: 3
capacity: 200
num people in lift: 1
capacity: 20
num people in lift: 1
num stops: 12
Lukes-MacBook-Pro:hr_algo luke$ 

