#include <iostream>
#include <set>
#include <vector>
#include "../helper/Helper.h"
#include "../helper/TestHelper.h"
#include "TreeTests.h"

bool debug = false;
int numberOfTestValues = 30;

void fillSets(TreeSet* uut, set<string>* exemplar)
{
    for (int i = 0; i < numberOfTestValues; i++)
    {
        char c = (char)((rand() % 26) + 'a');
        if (debug) cout << c << " ";
        uut->add(string(1, c));
        exemplar->insert(string(1, c));
    }
    if (debug) cout << "========================\n";
}

string testAdd(TreeSet* uut)
{
    string results;
    set<string> exemplar;

    for (int i = 0; i < numberOfTestValues; i++)
    {
        char c = (char)((rand() % 26) + 'a');
        uut->add(string(1, c));
        exemplar.insert(string(1, c));

        results += checkEquals(uut->size(), exemplar.size(), string(1, c), "Added value, but the size did not increase");

        if (results.size() > 0)
        {
            break;
        }
    }

    return results;
}

string testClear(TreeSet* uut)
{
	string results;
    set<string>* exemplar = new set<string>;
    fillSets(uut, exemplar);

    results += checkEquals(uut->size(), exemplar->size(), "n/a", "Failed to add values for the clear test");
    if (results.size() > 0)
    {
    	return results;
    }

    exemplar->clear();
    uut->clear();
    results += checkEquals(uut->size(), 0, "n/a", "Size was not zero after a clear");
    results += checkTrue(uut->isEmpty(), "n/a", "isEmpty() was not true after clear");
    return results;
}

string testContains(TreeSet* uut)
{
    string results;
    set<string>* exemplar = new set<string>;

    fillSets(uut, exemplar);

    set<string>::iterator i;
    for (i = exemplar->begin(); i != exemplar->end(); i++)
    {
    	results += checkTrue(uut->contains(*i), *i, "Your code did not contain the expected value");
    }
    return results;
}

string testToVector(TreeSet* uut)
{
    string results;
    set<string>* exemplar = new set<string>;

    fillSets(uut, exemplar);
    vector<string>* target = new vector<string>(exemplar->begin(), exemplar->end());
    vector<string>* testing = uut->toVector();

    results += checkFalse(testing == NULL, "n/a", "toVector() failed:  Your code returned a null vector\n");
    if (results.length() > 0)
    {
        return results;
    }

    results += checkEquals(testing->size(), target->size(), "n/a", "Size of the created vectors did not match");
    for (int i = 0; i < testing->size(); i++)
    {
    	results += checkEquals(testing->at(i), target->at(i), to_string(i), "The value at the index did not match");
    }
    return results;
}

string testRemove(TreeSet* uut)
{
    string results;
    set<string>* exemplar = new set<string>;

    fillSets(uut, exemplar);

    vector<string>* target = new vector<string>(exemplar->begin(), exemplar->end());
    vector<string>::iterator i;
    for (i = target->begin(); i != target->end(); i++)
    {
        results += checkTrue(uut->remove(*i), *i, "Your code did remove a value in the tree");
        exemplar->erase(*i);
        results += checkEquals(uut->size(), exemplar->size(), *i, "Size did not reduce after remove");
    }
    return results;
}
