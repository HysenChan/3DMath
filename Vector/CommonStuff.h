#pragma once

template <class Type>
inline const Type& min(const Type& a, const Type& b)
{
	return (a < b) ? a : b;
}

template <class Type>
inline const Type& max(const Type& a, const Type& b)
{
	return (a > b) ? a : b;
}