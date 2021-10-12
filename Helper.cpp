#include "Helper.h"

string toString(vector<string>* v)
{
    string out;
    for (int i = 0; i < v->size(); i++)
    {
        out = out + v->at(i);
    }
    return out;
}
