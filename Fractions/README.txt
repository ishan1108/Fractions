Converting float to Fraction:
Input: Float number
Returns: Fraction
Method: 
-> First, we would convert the float to a long by multipling it with 10^N, where N is the precision we want. 
-> At this point, we have out numerator and denominator. Numerator is (input * 10^N) and denominator is (10^N).
-> We then reduce the number (using similar method to the one defined in the Fraction class which takes two 
   long input instead of a fraction).
-> After reducing the number, we set the numerator and denominator of the fraction.


Operator overloading for float input:
Input: Float number
Returns: Fraction
Method:
-> using the float to fraction method, convert the float to a fraction.
-> Then use operator overloading functions defined for two fractions.