/***************************************************************** 
[Cohesion and coupling]

cohesion: refers to the relationship of the code within a function.
    A highly cohesive function 
        : means that all the code are parts of a single task.
        : are easy to maintain due to their focus.

types of cohesion
    Functional Cohesion: The function performs a single well-defined task.
    Sequential Cohesion: The output from one part of the function serves as input for another part.
    Communicational Cohesion: The function performs tasks that are related by the data they operate on.
    Procedural Cohesion: The function contains multiple tasks that need to be executed in a specific order.
    Temporal Cohesion: The function contains tasks that are related by the timing at which they need to be executed.
    Logical Cohesion: The function contains tasks that are logically related.
    Coincidental Cohesion: The function contains tasks that have little or no meaningful relationship to each other.

Note! When we write functions we want them to be highly cohesive and loosely coupled.
***************************************************************/


// function prototypes
double volumeOfSphere(double);
double surfaceAreaOfSphere(double);
double getRadius(int);

