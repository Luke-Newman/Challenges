/*******************************************************************************
B S T
*******************************************************************************/


This is my solution for the question which asks to list 'visible nodes' in a 
binary search tree (i.e. child nodes greater then the parent). 

When reading the question I was not sure whether to list nodes which had a value
were greater than their parent, or to list nodes which are greater than the 
highest predecessor so I've provided a solution for both cases. 



/*******************************************************************************
Output Example:
*******************************************************************************/


Level:   3................  9
Level:   2............  8
Level:   3................  7
Level:   1........  5
Level:   2............  5
Level:   0....  4
Level:   2............  4
Level:   1........  3
Level:   3................  3
Level:   2............  1

In Order:
 1  3  3  4  4  5  5  7  8  9
Pre Order:
 4  3  1  3  4  5  5  8  7  9
Post Order:
 3  1  4  3  5  7  9  8  5  4

List of visible nodes higher than the parent
where parent is referring to the predecessor with the highest value:
5 8 9

List of visible nodes higher than parent,
where parent is referring to the immediate parent of two child nodes:
3 4 5 8 9

Process finished with exit code 0