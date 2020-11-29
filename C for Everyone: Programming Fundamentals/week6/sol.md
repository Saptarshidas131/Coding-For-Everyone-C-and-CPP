## Final exam
# TOTAL POINTS 41

# 1.Who invented the C language?

[x]	Dennis Ritchie invented C at Bell Labs

	Don Knuth invented C at Stanford

	Nick Wrath invented C at ETH

	None of these

# 2.When you compile a correct C program you get a machine executable file such as a.out produced by the gnu compiler gcc.

[x]	True

	False

# 3.Which is true:

 #define is a preprocessor command often used to introduce named constants
double and goto are keywords declaring types.
return (0); is normally the last statement in main()
The file stdio.h is where the compiler finds scanf().

    All of these

    1, 4

    1, 2, 3

[x] 1, 3, 4

# 4.The statement printf(“HELLO\t\tWORLD\n”);

	Prints HELLO t t WORLD followed by a new line

[x]	Prints HELLO WORLD followed by a new line

	Prints HELLO

    WORLD

Prints HELLO WORLD in italics

#5.The expression PI * radius * radius would be used to compute

[x]	A circles area

	A circles volume

	A circles circumference

None of these

#6.In a format string for printf which would you use to print an int?

	%e

[x]	%d

	\t

	%lf

#7.The code

i = -10;
while ( i < 0)
{ … do something ; i--; }

	Displays a common error

[x]	its an infinite loop

	it starts at the wrong value of i; (i = -1) would work

	normally you want i == 0 not &lt; .

	other

#8.The following program is suppose to write Hello World onto the screen but it has syntax errors - find and correct.

#include <stdio.h>
int main(void)
{
     printf(“ Hello World\n”);
     return 0,
}

	It should be void main(void)

	It should be scanf not printf

	It should be \t not \n

[x]	It should be return 0;

#9.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: a % b

3

#10.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: b % a

1

#11.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: a < b

1

#12.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: c < b && a > 3

0

#13.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: a / b > c

0

#14.Assume the given declarations and fill in the value of the expression . int a = 3, b = 4, c = 0, d = '1';

Expression: c = a++

3

#15.Assume the given declarations and fill in the value of the expression . int a = 1, b = 2, c = 3;

Expression: a - b * c

-5

#16.Assume the given declarations and fill in the value of the expression . int a = 1, b = 2, c = 3;
Expression: c / a * b

6

#17.Assume the given declarations and fill in the value of the expression . int a = 1, b = 2, c = 3;

Expression: a++ + --b

2

#18.ssume the given declarations and fill in the value of the expression . int a = 1, b = 2, c = 3;

Expression: b = a = c

3

#19.Assume the given declarations and fill in the value of the expression . int i = 0, j = 1, k = 2;

Expression: i && j

0

#20.Assume the given declarations and fill in the value of the expression . int i = 0, j = 1, k = 2;

Expression: !!i

0

#21.Assume the given declarations and fill in the value of the expression . int i = 0, j = 1, k = 2;

Expression: i || !k

0

#22.Assume the given declarations and fill in the value of the expression. int i = 0, j = 1, k = 2;

Expression: (i && (j = k)) || (k > j)

1

Enter answer here

#23.If a function’s declaration is int foo(void):

	The function must return 0

[x]	The function has no arguments

	The function does not need a return statement

	The function should not have a printf in its definition

#24.In ANSI standard C(1989) code - this is what we are teaching- declarations can occur in a for statement as in

for(int i; i < 10; i++0 …


	True

[x]	False

#25.What happens when the return statement has a double expression and the function return type is int?

	Nothing

	This causes a run-time error

	This is system dependent

[x]	There is a conversion from double to int

#26.With the code

int foobar(int* n){
     *n = *n +1;
     return *n;
}

when called

int k = 6;
printf("foobar(k) = %d,",foobar(&k) );
printf(" k = %d\n", k);

what gets printed?

	foobar(k) = 6, k = 6

[x]	foobar(k) = 7, k = 7

	foobar(k) = 6, k = 7

	foobar(k) = 7, k = 6

#27.A variable declared in a inner block that has the same name as one in the surrounding block causes an error.

	True

[x]	False

#28.The original intent of using register int i; was	//I

	it was special under UNIX

	it was needed to compile correct machine code on a PDP8

[x]	It was intended to compile optimized code

	None of these

#29.When declaring fact() why not use double fact() so that you do not have integer overflow?	//I

	This is a great idea.

	The function computed in double would run way too slow.

[x]	There would be problems with accuracy.

	This is un-mathematical.

#30.True/False - Factorial can only be computed recursively.

	True

[x]	False

#31.The function mystery is defined as

int mystery(int p, int q){
     
    int r;
    if ((r = p % q) == 0)
        return q; 
    else return mystery(q, r);
}

When called with mystery(2, 6) it will return

	0

	1

[x]	2

	3

#32.The function mystery is defined as

int mystery(int p, int q){
     int r;
     if ((r = p % q) == 0)
          return q; 
     else return mystery(q, r);
}

When called with mystery(7, 91) it will return

[x]	7

	1

	15

	91

#33.True/False A while can always be used to replace a for.

[x]	True

	False

#34.True/ False An if-else statement can always replace an if statement.

[x]	True

	False

#35.If you declare the array char mystr[10];

	Then mystr[5] is the fifth element of the array

	The array has 11 elements

	Each element can store a string;

[x]	None of these

#36.In the following code fragment what gets printed?

int data[5] = {0 ,1, 2, 3, 4}, sum = 0 , i;

for (i = 0; i < 5 ; i++)
    sum = sum + data[i];
printf(“%d\n”, sum);

	Nothing

	4

	This is system dependent

[x]	10

#37.In the following code fragment

int a[10] = {1,2,3,4,5,6,7,8,9,10}, i = 6 ;
int *p = &a[0];
printf(“%d\n”, *(p + i));

what gets printed?

	4

	5

	6

[x]	7

#38.True/False: The declaration char* str = & a[0]; where char a[5] = “abcd”; The value of *str is the char ‘a’;

[x]	True

	False

#39.The input function scanf() uses “call by reference” to pass in argument values.

[x]	True

	False

#40.True/False mergesort is less efficient than bubblesort for very large sorting problems.


	True

[x]	False

#41.if p and q are pointers to double and x and y are double which of the following is legal:	//I	

	p = &5.15;

	p = (int)q;

	q = &p;

[x]	y = *q;
