/* ------------------------------------------------------
Workshop 2 part 2
Module: DNA
Filename: DNA.cpp
Version 1
Author	Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#ifndef NAMESPACE_DNA_H // replace with relevant names
#define NAMESPACE_DNA_H


namespace sdds
{
    struct DNA
    {
        int id;
        char* DNA_Strand;
    };
    bool beginSearch(const char* filename);
    bool read(const char* subDNA);
    void sort();
    void displayMatches();
    void deallocate();
    void endSearch();
    void swap(DNA* dna1, DNA* dna2);
}
#endif