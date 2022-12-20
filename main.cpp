#include "Task.h"

/// <summary>
/// Program entry point.
/// </summary>
/// <param name="argc"> Number of command line arguments. </param>
/// <param name="argv"> List of command line arguments. </param>
/// <returns> 0, if the program executed successfully. </returns>
int main(int argc, char* argv[])
{
	try
	{
		Task task{ "Enter your name here",
				R"(Create a program for processing the array A[N, N]
 where the entries are integers in the range [-1000, 1000]. The program must do the following:
-> print the description of the task;
-> print the names of the program author;
-> enter input data.
-> print input data.
-> a) zero out the elements of array A, for which the sum with the corresponding
element in array B is an even number on the interval [K-L];
-> b) keep track of the number of changed elements in array A.
-> print the results after processing a) and after processing b))" };

		task.Run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "An error occured! What: " << e.what() << '\n';
	}
	return 0;
}
