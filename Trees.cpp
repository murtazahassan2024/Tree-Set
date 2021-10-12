#include <iostream>
#include "tree/TreeSet.h"
#include "tests/TreeTests.h"

string subtest = "all";

void processParamters(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	processParamters(argc, argv);

    TreeSet* uut = new TreeSet();

    string results;
    if (subtest == "all")
    {
    	cout << "-------Test Add----------------------------" << endl;
		results += testAdd(uut);
		uut->clear();
    	cout << "-------Test Clear----------------------------" << endl;
		results += testClear(uut);
		if (results.size() > 0)
		{
			results += "Without add and clear the other tests are not accurate, fix these and then continue\n";
		} else
		{
	    	cout << "-------Test toVector----------------------------" << endl;
			results += testToVector(uut);
			uut->clear();
	    	cout << "-------Test Contains----------------------------" << endl;
			results += testContains(uut);
			uut->clear();
	    	cout << "-------Test Remove----------------------------" << endl;
			results += testRemove(uut);
			uut->clear();
		}
    } else if (subtest == "add")          { results += testAdd(uut);
    } else if (subtest == "contains")     { results += testContains(uut);
    } else if (subtest == "remove")       { results += testRemove(uut);
    } else                                { results += "Invalid subtest\n";}

    if(results.size() == 0)
    {
    	cout << "All Test Passed!";
    } else
    {
    	cout << results;
    }
}

void processParamters(int argc, char *argv[])
{
	if (argc == 1) {return;}

	if (argc > 1) subtest = argv[1];
}
