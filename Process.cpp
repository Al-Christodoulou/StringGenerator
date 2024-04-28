// Necessary imports
#include <iostream>
#include "Random.h"
#include "Process.h"

/*
 * Generates a random String, based on
 * the given Grammar rules.
 */
void Process::MgenerateString( std::list<Symbols> &list )
{

	list.push_front( Symbols::Z );
	std::list<Symbols>::iterator genListIterator { list.begin() };

	constexpr unsigned maxGenerationSteps { 81 };
	unsigned numOfSteps { 0 };

	while ( genListIterator != list.end() )
	{

		if (*genListIterator == Symbols::Z)
		{
			*genListIterator = Symbols::Close;

			/*
			 * Insert a Symbol at the previous location
			 * & return the iterator at that location.
			 */
			genListIterator = list.insert( genListIterator, Symbols::K );
			genListIterator = list.insert( genListIterator, Symbols::Open );
		}
		else if (*genListIterator == Symbols::K)
		{
			*genListIterator = Symbols::M;
			genListIterator = list.insert( genListIterator, Symbols::G );
		}
		else if (*genListIterator == Symbols::G)
		{
			unsigned randomChoice = (numOfSteps < maxGenerationSteps ?
									 Random::getNumber( 0, 1 ) : 0);

			switch (randomChoice)
			{
			case 0:

				*genListIterator = Symbols::v;
				break;
			case 1:

				*genListIterator = Symbols::Z;
				break;
			}
		}
		else if (*genListIterator == Symbols::M)
		{
			*genListIterator = Symbols::K;

			unsigned randomChoice = (numOfSteps < maxGenerationSteps ?
									  Random::getNumber( 0, 2 ) : 2);

			switch (randomChoice)
			{
			case 0:

				genListIterator = list.insert( genListIterator, Symbols::Minus );
				break;
			case 1:

				genListIterator = list.insert( genListIterator, Symbols::Plus );
				break;
			case 2:

				genListIterator = list.erase( genListIterator );
				break;
			}
		}
		else if (genListIterator != list.end())
		{
			genListIterator++;
			continue;
		}
		
		MshowList( list, numOfSteps );
		++numOfSteps;

	}

	std::cout << "\n\nGeneration terminated...";
	std::cout << "\n";

}

// Starts program's main process.
void Process::Mbegin()
{
	std::list<Symbols> symbolList {};
	MgenerateString( symbolList );
}