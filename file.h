#pragma once

#include <fstream>
#include "data.h"
using namespace std;
vector<plane> loadInVector();
void fromVectorToFile(vector<plane>);
int getCountOfPlane();