// Copyright 2008, 2009 Brady J. Garvin

// This file is part of Covering Arrays by Simulated Annealing (CASA).

// CASA is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// CASA is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with CASA.  If not, see <http://www.gnu.org/licenses/>.


// Other SAT solvers can be substituted by altering SAT.H and SAT.C.

//#include "sat/SAT.H"

#include "SAT.H"

InputClause::InputClause() : maxVariable(-1) {}

//jkunlin
InputClause::InputClause(const std::vector<InputTerm> &terms) : maxVariable(-1) {
	unsigned size = terms.size();
	for (unsigned i = 0; i < size; ++i) {
		append(terms[i]);
	}
}

//InputClause::InputClause(Array<InputTerm>terms) :
//  maxVariable(-1) {
//  unsigned size = terms.getSize();
//  for (unsigned i = 0; i < size; ++i) {
//    append(terms[i]);
//  }
//}

//jkunlin
InputClause::InputClause(const std::vector<unsigned> &symbols) : maxVariable(-1) {
	unsigned size = symbols.size();
	for (unsigned i = 0; i < size; ++i) {
		append(InputTerm(false, symbols[i]));
	}
}

//InputClause::InputClause(Array<unsigned>symbols) :
//  maxVariable(-1) {
//  unsigned size = symbols.getSize();
//  for (unsigned i = 0; i < size; ++i) {
//    append(InputTerm(false, symbols[i]));
//  }
//}

InputClause::~InputClause() {}

void InputClause::getlit(std::vector<InputTerm>& lits){
	lits.assign(literals.begin(), literals.end());
}

void InputClause::clear(){
	maxVariable = -1; //jkunlin
	literals.clear();
}

void InputClause::append(InputTerm term) {
	int variable = term.getVariable();
	if (variable > maxVariable) {
		maxVariable = variable;
	}
	literals.push_back(term);
}

void InputClause::undoAppend() {
	literals.pop_back();
}

InputKnown::InputKnown(int size){
	candidate.reserve(size);
	for(int i = 0;i<candidate.size();i++)
		candidate[i] = false;
}


void InputKnown::append(InputTerm term){
	int variable = term.getVariable();
	appendStack.push_back(variable);
	if (!term.isNegated()){
		candidate[variable] = 1;
	}	
}

void InputKnown::undoAppend(){
	int variable = appendStack[appendStack.size()-1];
	candidate[variable] = 0;
	appendStack.pop_back();
}
	
bool InputKnown::getvalue(int index){
	return candidate[index];
}


//void SATSolver::addClause(std::vector<InputClause>& newClauses) {
//	//clauses.assign(clause.begin(), clause.end());
//	clauses.insert(clauses.end(), newClauses.begin(), newClauses.end());
//}

void SATSolver::addClause(const InputClause& clause) {
	//clauses.assign(clause.begin(), clause.end());
	clauses.push_back(clause);
}

bool SATSolver::operator()(InputKnown& known) {
	if (disable) {
		return true;
	}
	for(int i = 0;i<clauses.size();i++){
		std::vector<InputTerm> lit;
		clauses[i].getlit(lit);
		int max_ = lit.size();
		bool part = false;
		for(int j = 0;j<max_;j++){
			
			bool isnegated = lit[j].isNegated();
			int variable = lit[j].getVariable();
			if(!isnegated && known.getvalue(variable))
				part = true;
		}
		if(part == false)
			return false;
	}
	return true;
	
}
