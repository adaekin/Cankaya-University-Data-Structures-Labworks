#pragma once
#include <string>
using namespace std;
class IntSet {
public:
	virtual int size()const = 0;
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;
	/** Adds a new entry to this set, avoiding duplicates.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful, or
	false if the item already is in the set. */
	virtual bool add(int newEntry) = 0;
	/** Removes a specific entry from this set, if possible.
	@param anEntry The entry to be removed.
	@return True if the removal was successful, or false if not. */
	virtual bool remove(int anEntry) = 0;
	virtual void clear() = 0;
	virtual bool contains(int anEntry) = 0;
	virtual string toString() = 0;// returns the content of set as a string
};
