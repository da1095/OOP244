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
#define _CRT_SECURE_NO_WARNINGS
#include "DNA.h"
#include "cStrTools.h"
#include <stdio.h>
#include <iostream>
using namespace std;

namespace sdds
{
    int no_of_match;
    struct DNA* dna;
    FILE* file_name;

    bool beginSearch(const char* filename){
        no_of_match = 0;
        cout << "DNA search program" << endl;
        file_name = fopen(filename, "r");
        if (file_name == NULL) {
            return false;
        }
        return true;
    }

    bool read(const char* subDNA){
        int id;
        char strand[1001];

        while (fscanf(file_name, "%d, %s", &id, strand) != EOF){
            if (strStr(strand, subDNA)) {
                no_of_match++;
            }
                
        }
        rewind(file_name);
        if (no_of_match == 0) {
            return false;
        }
            

        dna = new DNA[no_of_match];
        int i = 0;
        while (fscanf(file_name, "%d, %s", &id, strand) != EOF){
            if (strStr(strand, subDNA)){
                dna[i].id = id;
                dna[i].DNA_Strand = new char[strLen(strand) + 1];
                strCpy(dna[i].DNA_Strand, strand);
                i++;
            }
        }
        rewind(file_name);
        return true;
    }

    void sort()
    {
        for (int i = 0; i < no_of_match - 1; i++) {
            for (int j = 0; j < no_of_match - i - 1; j++) {
                if (dna[j].id > dna[j + 1].id)
                    swap(&dna[j], &dna[j + 1]);
            }
                
        }
            
    }

    void displayMatches(){
        cout << no_of_match << " matches found:" << endl;
        for (int i = 0; i < no_of_match; i++){
            cout << i + 1 << ") " << dna[i].id << ":" << endl;
            cout << dna[i].DNA_Strand << endl;
            cout << "======================================================================" << endl;
        }
    }

    void deallocate(){
        for (int i = 0; i < no_of_match; i++)
            delete[] dna[i].DNA_Strand;
        delete[] dna;
        no_of_match = 0;
    }

    void endSearch(){
        fclose(file_name);
        cout << "DNA Search Program Closed." << endl;
    }

    void swap(DNA* dna1, DNA* dna2){ 
        DNA d;
        d = *dna1;
        *dna1 = *dna2;
        *dna2 = d;
    }

}