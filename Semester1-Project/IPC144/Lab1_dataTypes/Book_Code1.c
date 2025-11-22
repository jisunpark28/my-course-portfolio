/******************************************

data type	format code
int	            %d
char	        %c
float	        %f
double      	%lf

Description	                     Data Type	             Format Codes	      Size	                            Range (Inclusive)

floating point	                float	                     %f	        32 bits - 4 bytes	                        N/A
more accurate floating point	double	                     %lf	    64 bits - 8 bytes	                        N/A
characters	                    char	                     %c	        8 bits - 1 byte	                            -128 to 127, values are often used to encode various characters
whole numbers	                int	                         %d	        32 bits - 4 bytes	                        -2147483648 to 2147483647
small whole numbers	            short or short int	         %hd	    16 bits - 2 bytes	                        -32768 to 32767
big whole number	            long or long int	         %ld	    32 bits - 4 bytes or 64 bits - 8 bytes	    -2147483648 to 2147483647 or −2^63 to 2^63 -1
much bigger whole number	    long long or long long int	 %lld	    64 bits - 8 bytes	                        −2^63 to 2^63 -1 

can be applied to integer types (long, int, char, short)
all bits of the value are used to represent a number without the use of a sign bit
unsigned int range from 0 to 4294967295 inclusive
unsigned char range from 0 to 255 inclusive


******************************************/

#include <stdio.h>
int main(void)
{
    int a = 15;
    int b = -15;    
    double pi = 3.1415926535;

    printf("pi = %lf\n", pi);  //standard double output
    printf("pi = %.8lf\n", pi); //double output with 8 decimal places
    printf("pi = %.12lf\n\n", pi); //double output with 12 decimal places

    printf("|%lf|\n", pi); //standard double output	
    printf("|%d|\n\n", a); //standard integer output

    printf("|%.2lf|\n", pi); //double output with 2 decimal places
    printf("|%6.2lf|\n", pi); //double output with field width of 6 and 2 decimal places
    printf("|%-6.2lf|\n", pi);      //double output with field width of 6 and 2 decimal places, padded with spaces but left justified
    printf("|%06.2lf|\n\n", pi); // double output field with 6 and 2 decimal places, padded with 0's

    printf("|%+d|\n", a);  //integer output where sign is always shown
    printf("|%+d|\n\n", b);

    printf("|%6d|\n", a); //integer output field with 6, padded with spaces (right justified by default)
    printf("|%-6d|\n\n", a); // nteger output field with 6, padded with spaces but left justified

    printf("|%06d|\n\n", a); // integer output field with 6, padded with 0's

    printf("|%o|\n", a); //integer printed in octo (base 8)
    printf("|%x|\n", a); //integer printed in lower case hex(base 16)
    printf("|%X|\n", a); //integer printed in upper case hex (base 16)
    return 0;
}