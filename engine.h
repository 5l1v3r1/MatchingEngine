#include <map>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include "common.h"
#include "order.h"

#ifndef ENGINE
#define ENGINE

using namespace std;

class CMatchEngine
{
public:
	// match a new order in buybook or sellbook, most important function..
	void Match(COrder& order);
	
	void Modify(COrder& order);

	// return true if a order was cancelled, return false if no order cancelled..
	// triggered by Modify()..
	bool Cancel(COrder& order);
    
	void Print();

    // sort sellbook and buybook for PRINT operation..
    void SortBook(map<uint64_t, uint64_t>& sortedBook, list<COrder> orderList);

private:
	unordered_map<string, list<COrder>::iterator> m_hashsell;
	unordered_map<string, list<COrder>::iterator> m_hashbuy;
	list<COrder>  m_sellbook;
	list<COrder>   m_buybook;

    // only used when a trade was done..
	void TradePrint(COrder& o1, COrder& o2, uint64_t qty);

};
// end of class engine..

// parse a cmd line in to a vector of different fields, and return a order object for engine..
// another very important function
COrder ParserCommand(string cmd);

#endif
