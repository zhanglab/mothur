#ifndef SFFINFOCOMMAND_H
#define SFFINFOCOMMAND_H

/*
 *  sffinfocommand.h
 *  Mothur
 *
 *  Created by westcott on 7/7/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */

#include "command.hpp"
#include "groupmap.h"

/**********************************************************/

class SffInfoCommand : public Command {
	
public:
	SffInfoCommand(string);
	SffInfoCommand();
	~SffInfoCommand(){}
	
	vector<string> setParameters();
	string getCommandName()			{ return "sffinfo";					}
	string getCommandCategory()		{ return "Sequence Processing";		}
	
	string getHelpString();	
    string getOutputPattern(string);	
	string getCitation() { return "http://www.mothur.org/wiki/Sffinfo"; }
	string getDescription()		{ return "extract sequences reads from a .sff file"; }

	int execute(); 
	void help() { m->mothurOut(getHelpString()); }	
	
private:
	string sffFilename, sfftxtFilename, outputDir, accnosName, currentFileName, oligosfile, noMatchFile, groupfile;
	vector<string> filenames, outputNames, accnosFileNames, oligosFileNames, groupFileNames;
	bool abort, fasta, qual, trim, flow, sfftxt, hasAccnos, hasOligos, hasGroup;
	int mycount, split, numFPrimers, numLinkers, numSpacers, pdiffs, bdiffs, ldiffs, sdiffs, tdiffs, numNoMatch;
	set<string> seqNames;
    map<string, int> barcodes;
    map<string, int> primers;
    GroupMap* groupMap;
    vector<string> linker, spacer, primerNameVector, barcodeNameVector, revPrimer;
    vector<vector<int> > numSplitReads;
    vector<vector<string> > filehandles;
    vector<vector<string> > filehandlesHeaders;
    
	//extract sff file functions
	int extractSffInfo(string, string, string);
	int readCommonHeader(ifstream&, CommonHeader&);
	int readHeader(ifstream&, Header&);
	bool readSeqData(ifstream&, seqRead&, int, Header&);
	int decodeName(string&, string&, string&, string);
    bool readOligos(string oligosFile);
    bool readGroup(string oligosFile);
	
	int printCommonHeader(ofstream&, CommonHeader&); 
	int printHeader(ofstream&, Header&);
	int printSffTxtSeqData(ofstream&, seqRead&, Header&);
	int printFlowSeqData(ofstream&, seqRead&, Header&);
	int printFastaSeqData(ofstream&, seqRead&, Header&);
	int printQualSeqData(ofstream&, seqRead&, Header&);
	int readAccnosFile(string);
	int parseSffTxt();
	bool sanityCheck(Header&, seqRead&);
    int adjustCommonHeader(CommonHeader);
    int findGroup(Header header, seqRead read, int& barcode, int& primer);
    int findGroup(Header header, seqRead read, int& barcode, int& primer, string);
    string reverseOligo(string oligo);
    
	//parsesfftxt file functions
	int parseHeaderLineToInt(ifstream&);
	vector<unsigned short> parseHeaderLineToFloatVector(ifstream&, int);
	vector<unsigned int> parseHeaderLineToIntVector(ifstream&, int);
	string parseHeaderLineToString(ifstream&);
};

/**********************************************************/
 
#endif


