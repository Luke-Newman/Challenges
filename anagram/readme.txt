/*******************************************************************************
A N A G R A M S
*******************************************************************************/

This is my solution to find how man characters are required to make two given 
words anagrams.

From memory, initial solution had a map with a character as key, and 
the number of occurrences for this character as value. My rule for deciding if 
an additional character was need I simply checked if the occurrence was even
however this does not solve all edge cases.

This final solution still uses a single map, however the value in the map is now
a pair of type int (count_string_1, count_string_2).
For each character in the map, the number of additional characters required
is incremented by the absolute value of count_string_1 - count_string_2.
This solution solves for all edge cases.

/*******************************************************************************
Output Examples:
*******************************************************************************/

String A: lemon
String B: melon

Words required: 0

Process finished with exit code 0

--------------------------------------------------------------------------------

String A: abacus
String B: delirium

Characters required: 12

Process finished with exit code 0

--------------------------------------------------------------------------------

String A: abbey
String B: bed

Characters required: 4

Process finished with exit code 0

--------------------------------------------------------------------------------

String A: suspense
String B: sunsets

Characters required: 3

Process finished with exit code 0