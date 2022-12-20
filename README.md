Create a program for processing the array A[N, N]
 where the entries are integers in the range [-1000, 1000]. The program must do the following:
-> print the description of the task;
-> print the names of the program author;
-> enter input data.
-> print input data.
-> a) zero out the elements of array A, for which the sum with the corresponding
element in array B is an even number on the interval [K-L];
-> b) keep track of the number of changed elements in array A.
-> print the results after processing a) and after processing b)
==================================================================================================
Sample Input:
N: 2
K: 1
L: 12
==================================================================================================
Sample Output:
Enter N: 2

Enter K: 1

Enter L: 12
Input Matrix[A] of size: 2
Enter value for [0][0]: 1

Enter value for [0][1]: 100

Enter value for [1][0]: 300

Enter value for [1][1]: 2


Input Matrix[B] of size: 2
Enter value for [0][0]: 11

Enter value for [0][1]: -98

Enter value for [1][0]: 400

Enter value for [1][1]: -1


N: 2, K: 1, L: 12
Matrix[A] size[2] Contents:
      1    100
    300      2

Matrix[B] size[2] Contents:
     11    -98
    400     -1

After processing the number of changes is 2
Matrix[A] size[2] Contents:
      0      0
    300      2
