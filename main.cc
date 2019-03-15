// =====================================================================================
//
//       Filename:  main.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  10/27/2014 10:26:54 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jinkun Lin, jkunlin@gmail.com
//   Organization:  School of EECS, Peking University
//
// =====================================================================================

#include <iostream>
#include <string>

#include "SpecificationFile.h"
#include "ConstraintFile.H"
#include "LocalSearch.h"


using namespace std;

int main(int argc, char const *argv[]) {
	if (argc == 0) {
		return 1;
	}
	string modelFile(argv[1]);
	string constrFile;
	unsigned long long maxTime;
	int seed;
	unsigned tabuSize, randomSize;
	if (argc == 7) {
		constrFile = argv[2];
		maxTime = atoi(argv[3]);
		seed = atoi(argv[4]);
		tabuSize = atoi(argv[5]);
		randomSize = atoi(argv[6]);
	}
	else {
		maxTime = atoi(argv[2]);
		seed = atoi(argv[3]);
		tabuSize = atoi(argv[4]);
		randomSize = atoi(argv[5]);
	}
	SpecificationFile specificationFile(modelFile);
	ConstraintFile constraintFile(constrFile);
	localSearch(specificationFile, constrFile, maxTime, seed, tabuSize, randomSize);
	return 0;
}
