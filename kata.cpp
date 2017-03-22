#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
using std::vector;

#include <string>
using std::string;

//i did something wrong with throw or string cat, doesnt compile 

int add(string expr)
{
	int n=0;
	char last;
	vector<strings> negs;

	for( auto c : expr)
	{
		if ( (int) c >= 48 && (int) c <= 57)
		{
			n += (int)c - 48;
			if (last == '-') negs.push_back("-"+ string(c));
		}

		last = c;
	}
	
	if(negs.size())
	{
		negs[0];
	}

	return n;
}


TEST_CASE("kata test" , "[add]")
{

	REQUIRE( add("0") == 0);
	REQUIRE( add("1") == 1);
	REQUIRE( add("1,2") == 3);
	REQUIRE( add("1,2,3") == 6);
	REQUIRE( add("1\n,2,//;f3st/?4") == 10);
	REQUIRE_THROWS(add("1,2,3,-4"))



}
