//*********************************************************************************//
//Name: Justin Tran
//
//Class: CSCI 1106
//
//Program: The program simulates a drunk lad that starts at n=2 blocks to n=7 blocks
//giving a simulation percentage of whether he would head to the pub or home with
//500 trials for each block.
//********************************************************************************//

#include<iostream>
#include<iomanip>
#include<ctime>
#include<time.h>

using namespace std;

const int TRIALS = 500;
const int LOOPBREAK = 9;

int main() {


	int block = 0;
	int num = 0;
	int sentinel = 0;
	
	double sumBlocksWalked = 0;
	double pubReached = 0;
	double homeReached = 0;
	double percentPub = 0;
	double percentHome = 0;
	double avgBlocksWalked = 0;


	srand(time(NULL));

	for (int j = 2; j <= 7; j++) {

		for (int i = 0; i < TRIALS; i++) { //500 trials
			block = j;

			while (sentinel != LOOPBREAK) {
				num = (rand() % 4) + 1; // Generate the number from 1-5
				if (num >= 1 && num <= 3) {
					block = block - 1;
				}
				else {
					block = block + 1;
				}
				sumBlocksWalked++;


				if (block == 1) {
					pubReached++; //increase pub points
					sentinel = 9; //whenever this assigment is reach it breaks the loop
					
				}
				else if (block == 8) {
					homeReached++; //increase home point 
					sentinel = 9; //whenever this assigment is reach it breaks the loop
				}
				
			} //end while loop
			sentinel = 0; //reset our loop breaker back to 0
			

		}//end of for loop

		//output the loop for n=2,n=3, etc.
		avgBlocksWalked = sumBlocksWalked / 500;

		percentHome = (homeReached / 500) * 100;

		percentPub = (pubReached / 500) * 100;

		cout << "Starting at block #" << j << endl;

		cout << "Average blocks he walked: " << avgBlocksWalked << endl;

		cout << "% of times he reached home: " << percentHome << endl;

		cout << "% of times he reached pub: " << percentPub << endl;

		cout << endl;

		//reset the loop for n+1 block calculations

		avgBlocksWalked = 0;

		percentHome = 0;

		percentPub = 0;

		sumBlocksWalked = 0;

		homeReached = 0;

		pubReached = 0;

	}


	return 0;
}