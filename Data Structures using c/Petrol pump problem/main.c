#include <stdio.h>
struct Petrol_pump
{
int petrol;
int distance;
};
int travel(struct Petrol_pump arr[], int n)
{
	int starting = 0;
	int ending = 1;
	int curr_petrol = arr[starting].petrol - arr[starting].distance;
	while (ending != starting || curr_petrol < 0)
	{
		while (curr_petrol < 0 && starting != ending)
		{
			curr_petrol -= arr[starting].petrol - arr[starting].distance;
			starting = (starting + 1)%n;
			if (starting == 0)
			return -1;
		}
		curr_petrol += arr[ending].petrol - arr[ending].distance;
		ending = (ending + 1)%n;
	}
	return starting;
}
int main()
{
	struct Petrol_pump arr[] = {{5, 6}, {5, 4}, {6, 3}};
	int n = sizeof(arr)/sizeof(arr[0]);
	int starting = travel(arr, n);
	(starting == -1)? printf("No solution"): printf("Start = %d", starting);
	return 0;
}
