#pragma region Definition Of Class Process

#ifndef PROCESS_H
#define PROCESS_H

// Necessary imports
#include <list>
#include "Symbols.h"

class Process
{
public:

	void Mbegin();
private:

	// Shows the given list of Symbols.
	void MshowList( const std::list<Symbols>& list, unsigned& currentStep )
	{
		std::cout << "\n(Generation step): " << currentStep;
		std::cout << "\n--> ";

		for ( const Symbols& symb : list )
			std::cout << MapToChar.at( symb );
		std::cout << "\n";
	};

	void MgenerateString( std::list<Symbols> & );
};

#endif

#pragma endregion