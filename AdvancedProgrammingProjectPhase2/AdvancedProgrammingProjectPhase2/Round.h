#pragma once
#ifndef ROUND_H
#define ROUND_H
#include <string>
using namespace std;

class Round
{
private:
	long int Roundnum; // The number of times this round will be implemented in the workout. 
	long int Rlength; // Length of the active round in milliseconds. 
	long int Rmet; // The metronome speed in BPM
	long int Restlength; // The length of the rest period (in milliseconds)
	long int RoundFreq; // Frequency of the tone to indicate the start of this round. 
public:

	// Publicly available integer for the # of times this round will be in the workout cycle. This will need to be set at the beginning of the workout and modified at each cycle.
	long int Roundsremain;
	// Constructor Default
	Round()
	{
		Roundnum = 0; Rlength = 0; Rmet = 0; Restlength = 0; RoundFreq = 0;
	}
	// Constructor
	Round(long int Ronum, long int Rlen, long int Rme, long int Resl, long int Rfreq)
	{
		Roundnum = Ronum; Rlength = Rlen; Rmet = Rme; Restlength = Resl; RoundFreq = Rfreq;
	}
	// Mutator Functions
	// Sets the # of rounds in the workout sequence.
	void Round::setRoundnum(long int Ronum)
	{
		Roundnum = Ronum;
	}

	// Sets the Round length
	void Round::setRlength(long int Rlen)
	{
		Rlength = Rlen;
	}

	// Sets the Rest length
	void Round::setRestlength(long int Restl)
	{
		Restlength = Restl;
	}
	// Sets the 'beep' frequency. 
	void Round::setRoundFreq(long int Rfreq)
	{
		RoundFreq = Rfreq;
	}

	//Accessor Functions
	
	// Return the # of workout cycles this round will be in. 
	long int Round::getRoundnum() const
	{
		return Roundnum;
	}

	// Return the length of the round.
	long int Round::getRlength() const
	{
		return Rlength;
	}
	// Return the metronome speed for the round.
	long int Round::getRmet() const
	{
		return Rmet;
	}
	// Return the Rest Length for the round.
	long int Round::getRestlength() const
	{
		return Restlength;
	}
	// Return the beep frequency for the round. 
	long int Round::getRoundfreq() const
	{
		return RoundFreq;
	}

	//Prototypes for functions to be defined in the Round.cpp file. These functions are used for the workout cycle based on the variables held by the "Round" object.
	long int Rmetcount(); // # of times the metronome will 'tick' during a round. (determined by a calculation using the R1length & R1met values).
	long int Rrem(); // Remaining # of microseconds in the round before the rest period after all metronome ticks have been spent. (determined using modulo operation).
	long int Rmetint(); // # of microseconds between metronome "ticks" (determined by subtracting R1rem from R1length and dividing R1length by R1metcount).
	void setRoundsremain(long int); // Used to manipulate the "Roundsremain" variable, defined in the "Round.cpp" file. 
	long int getRoundsremain(); // Used to return the "Roundsremain" variable. This function is defined in the "Round.cpp" file. 
	void setupround();
	void decrementroundsremain();

};
#endif