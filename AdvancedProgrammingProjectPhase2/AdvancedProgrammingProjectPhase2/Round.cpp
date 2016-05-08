#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "Round.h"
using namespace std;

// Define "Rmetcount()" function, which derives the # of times the metronome will 'beep' during the active round. 

long int Round::Rmetcount()
{
	long int Rmetcount;
	// We need to convert the Rlength(Round length) and Rmet (metronome speed in BPM) to double variables in order to perform
	// the necessary calculation. Otherwise, we might end up inadvertently dividing by 0 in the main workout during the Rrem() function
	// defined later. Converting the result of the calculation back to the long int class removes the rational portion automatically.
	Rmetcount = long int((double(Rlength) / 60000.0)*double(Rmet));
	return(Rmetcount);
}

// Define "Rrem()" function, which returns the remaining # of milliseconds in the active phase of the round
// after all of the metronome "ticks" are completed. This enables better accuracy in timing the activation of the "Rest" phase. 

long int Round::Rrem()
{
	long int Rrem;						// The returned value.
	long int Rmetcount;					// A variable to hold the result of "Rmetcount()" defined above, which is needed for this calculation.
	Rmetcount = Round::Rmetcount();		// The # of metronome ticks is found and stored in Rmetcount.
	Rrem = (Rlength%Rmetcount);			// The length of the round (Rlength) is modulo divided by Rmetcount, and the remainder is assigned to Rrem.
	return(Rrem);						// Rrem is returned. 
}

// Define the Rmetint() function, which returns the # of milliseconds between each metronome 'tick'. 
long int Round::Rmetint()
{
	long int Rmetcount;					// A variable to hold the result of "Rmetcount()", necessary for this calculation.
	long int Rrem;						// A variable to hold the result of "Rrem()", also necessary for this calculation. 
	long int Rmetint;					// Variable to hold the result that's returned at the end of the function.
	// Perform Rmetcount & Rrem functions. 
	Rmetcount = Round::Rmetcount();
	Rrem = Round::Rrem();
	// Subtract the Rrem variable from Rlength (the total length of the active round), then divide by the result of Rmetcount.
	// Because Rrem is already the remainder of dividing Rlength by Rmetcount, there's no need to use type conversion. 
	Rmetint = (Rlength - Rrem) / Rmetcount;
	// Return Rmetint
	return(Rmetint);
}

// A function to set the # of remaining rounds, used in the 'decrementroundsremain()' function.
void Round::setRoundsremain(long int i)
{
	Roundsremain = i;
}

// This function sets the "Roundsremain" variable to the Round's Roundnum variable. 
// This is used at the beginning of the workout so that the value can be decremented at each cycle.
void Round::setupround()
{
	Roundsremain = Roundnum;
}

// This function returns the # of remaining rounds in a cycle. Used in the workout cycle to determine whether 
// or not a round should be included in the current cycle and when to end the workout altogether.
long int Round::getRoundsremain()
{
	return(Roundsremain);
}

// This function decrements the # of remaining rounds by one, used at the end of each instance of a round in a workout cycle. 
void Round::decrementroundsremain()
{
	long int Rounrem;
	Rounrem = Round::getRoundsremain();
	Rounrem--;
	Round::setRoundsremain(Rounrem);

}