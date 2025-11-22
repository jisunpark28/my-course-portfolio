/******************************************

1. How many different values can be stored using 8 bit?

    : 2^8 = 256


2. What are the similarity/differences between float and double data type?

    : [The similarity]  Both are used to store numbers with decimal places.
                        Both use some of their memory to store the mantissa and some to store the exponent. 
    : [The diffences]   Different amounts of memory used for each variables of these types. 
                        Doubles have highter accuracy than float.


3. What is the best data type to store each of the values below?

    The number of people living in Canada
        : int or unsigned int (It does not have a negative or decimal value.)

    Pi to 2 decimal places
        : float or double. (It requires a decimal, but a double could be considered for more accuracy.)

    The answer to a multiple choice quiestion where the choices are A,B,C, and D
        : char (The values are only going to be one of 4 letters.)

    pi to 10 decimal places
        : double (In pi, 10 decimal places is 11 disits in total. This would be require a larger mantisa than a float can store.)
                [float] 32bits - 1bits for the sign + 8 bits for the exponents + 23 bits for the mantissa (7 to 8 decimal digit)
                [double] 64bits - 1bits for the sign + 11 bits for the exponents + 52 bits for the mantissa (15 to 17 decimal digit)

    Number of muffins sold by your company
        : int or unsigned int (long long int or long long)

    Taxes due on a bottle of pop
        : float or double (The accuracy is good to avoid rounding errors in a large sequence of operations.)

    The number of people living in the entire world
        : long long or long long int (It is roughly 8.1 billion. It can't be stored in an int or even an unsigned int.)




4. What does mantissa mean? Provide an example to illustrate your answer?

    : The mantissa is the significant digits of a number in scientific notation.
      For example, 123 is 1.23*10^2 in scientific notation. The mantissa for this number is 1.23

******************************************/






