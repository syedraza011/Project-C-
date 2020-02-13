#pragma once
template <class Type>
class DataBase
{
	// Public data members
public:
	// The abstract add function declaration
	virtual bool add(Type) = 0;
	// The abstract edit function declaration
	virtual bool edit(Type) = 0;
	// The abstract remove function declaration
	virtual bool remove(Type) = 0;
};

