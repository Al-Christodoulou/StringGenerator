#pragma region Definition Of Class Random

#ifndef RANDOM_H
#define RANDOM_H

// Necessary imports
#include <random>
#include <chrono>

namespace Random
{
	// Creation of a random generator engine.
	static std::default_random_engine generator 
	{ 
		// Initialize generator, based on the current time.
		static_cast<unsigned>( std::chrono::steady_clock::now().time_since_epoch().count() ) 
	};

	// Returns a number, between [min, max].
	unsigned getNumber( unsigned min, unsigned max )
	{
		std::uniform_int_distribution<unsigned> randomEngine( min, max );
		return randomEngine( generator );
	}
}

#endif

#pragma endregion