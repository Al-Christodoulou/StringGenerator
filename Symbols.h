#pragma region Definition Of Class Symbols

#ifndef SYMBOLS_H
#define SYMBOLS_H

// Necessary imports
#include <map>
#include <string>

enum class Symbols
{
	Z,
	K,
	G,
	M,
	v,
	Open,
	Close,
	Minus,
	Plus
};

const std::map<const Symbols, const char> MapToChar
{
	std::pair<Symbols, char>{ Symbols::Z, 'Z' },
	std::pair<Symbols, char>{ Symbols::K, 'K' },
	std::pair<Symbols, char>{ Symbols::G, 'G' },
	std::pair<Symbols, char>{ Symbols::M, 'M' },
	std::pair<Symbols, char>{ Symbols::v, 'v' },
	std::pair<Symbols, char>{ Symbols::Open, '(' },
	std::pair<Symbols, char>{ Symbols::Close, ')' },
	std::pair<Symbols, char>{ Symbols::Minus, '-' },
	std::pair<Symbols, char>{ Symbols::Plus, '+' }
};

#endif

#pragma endregion