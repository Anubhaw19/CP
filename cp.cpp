#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
using namespace std;


int main() {
	long n;
	cout<<"enter a number:"<<endl;;
	cin>>n;
    time_t now = time(nullptr); 	//  time in seconds
	long random=(long)now%n;
	cout<<"random number="<<random;

    return EXIT_SUCCESS;
}
