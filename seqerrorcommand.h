#ifndef SEQERRORCOMMAND
#define SEQERRORCOMMAND

/*
 *  seqerrorcommand.h
 *  Mothur
 *
 *  Created by Pat Schloss on 7/15/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */

#include "mothur.h"
#include "command.hpp"
#include "sequence.hpp"

struct Compare {
	int AA, AT, AG, AC,	TA, TT, TG, TC,	GA, GT, GG, GC,	CA, CT, CG, CC,	NA, NT, NG, NC, Ai, Ti, Gi, Ci, Ni, dA, dT, dG, dC;
	string refName, queryName, sequence;
	double errorRate;
	int weight, matches, mismatches, total;
	
	Compare(){
		AA=0; AT=0; AG=0; AC=0;
		TA=0; TT=0; TG=0; TC=0;
		GA=0; GT=0; GG=0; GC=0;
		CA=0; CT=0; CG=0; CC=0;
		NA=0; NT=0; NG=0; NC=0;
		Ai=0; Ti=0; Gi=0; Ci=0; Ni=0;
		dA=0; dT=0; dG=0; dC=0;
		refName = "";
		queryName = "";
		weight = 1;
		matches = 0;
		mismatches = 0;
		total = 0;
		errorRate = 1.0000;
		sequence = "";
	}
};

class SeqErrorCommand : public Command {
public:
	SeqErrorCommand(string);
	SeqErrorCommand();
	~SeqErrorCommand();
	vector<string> getRequiredParameters();
	vector<string> getValidParameters();
	vector<string> getRequiredFiles();
	map<string, vector<string> > getOutputFiles() { return outputTypes; }
	int execute();
	void help();
	
private:
	bool abort;

	void getReferences();
	map<string,int> getWeights();
	Compare getErrors(Sequence, Sequence);
	void printErrorHeader();
	void printErrorData(Compare);
	
	string queryFileName, referenceFileName, qualFileName, reportFileName, namesFileName, errorSummaryFileName, errorSeqFileName, outputDir;
	double threshold;
	int numRefs;
	ofstream errorSummaryFile, errorSeqFile;
	vector<string> outputNames;
	map<string, vector<string> > outputTypes;
	
	vector<Sequence> referenceSeqs;
	vector<vector<int> > substitutionMatrix;
	int a,t,g,c,gap,n;
};

#endif
