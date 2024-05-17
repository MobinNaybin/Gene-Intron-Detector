#include <stdio.h>
char dna[3000];
char protein[2900];


char codonToAmino(char r[]){
    if (r[0] == 'U') {
        if (r[1] == 'U') {
            if (r[2] == 'U') return 'f';
            if (r[2] == 'C') return 'f';
            if (r[2] == 'A') return 'l';
            if (r[2] == 'G') return 'l';
        }
        if (r[1] == 'C') {
            if (r[2] == 'U') return 's';
            if (r[2] == 'C') return 's';
            if (r[2] == 'A') return 's';
            if (r[2] == 'G') return 's';
        }
        if (r[1] == 'A') {
            if (r[2] == 'U') return 'y';
            if (r[2] == 'C') return 'y';
            if (r[2] == 'A') return '.';
            if (r[2] == 'G') return '.';
        }
        if (r[1] == 'G') {
            if (r[2] == 'U') return 'c';
            if (r[2] == 'C') return 'c';
            if (r[2] == 'A') return '.';
            if (r[2] == 'G') return 'w';
        }
    }

    if (r[0] == 'C') {
        if (r[1] == 'U') {
            if (r[2] == 'U') return 'l';
            if (r[2] == 'C') return 'l';
            if (r[2] == 'A') return 'l';
            if (r[2] == 'G') return 'l';
        }
        if (r[1] == 'C') {
            if (r[2] == 'U') return 'p';
            if (r[2] == 'C') return 'p';
            if (r[2] == 'A') return 'p';
            if (r[2] == 'G') return 'p';
        }
        if (r[1] == 'A') {
            if (r[2] == 'U') return 'h';
            if (r[2] == 'C') return 'h';
            if (r[2] == 'A') return 'q';
            if (r[2] == 'G') return 'q';
        }
        if (r[1] == 'G') {
            if (r[2] == 'U') return 'r';
            if (r[2] == 'C') return 'r';
            if (r[2] == 'A') return 'r';
            if (r[2] == 'G') return 'r';
        }
    }

    if (r[0] == 'A') {
        if (r[1] == 'U') {
            if (r[2] == 'U') return 'i';
            if (r[2] == 'C') return 'i';
            if (r[2] == 'A') return 'i';
            if (r[2] == 'G') return 'm';
        }

        if (r[1] == 'C') {
            if (r[2] == 'U') return 't';
            if (r[2] == 'C') return 't';
            if (r[2] == 'A') return 't';
            if (r[2] == 'G') return 't';
        }
        if (r[1] == 'A') {
            if (r[2] == 'U') return 'n';
            if (r[2] == 'C') return 'n';
            if (r[2] == 'A') return 'k';
            if (r[2] == 'G') return 'k';
        }
        if (r[1] == 'G') {
            if (r[2] == 'U') return 's';
            if (r[2] == 'C') return 's';
            if (r[2] == 'A') return 'r';
            if (r[2] == 'G') return 'r';
        }
    }

    if (r[0] == 'G') {
        if (r[1] == 'U') {
            if (r[2] == 'U') return 'v';
            if (r[2] == 'C') return 'v';
            if (r[2] == 'A') return 'v';
            if (r[2] == 'G') return 'v';
        }

        if (r[1] == 'C') {
            if (r[2] == 'U') return 'a';
            if (r[2] == 'C') return 'a';
            if (r[2] == 'A') return 'a';
            if (r[2] == 'G') return 'a';
        }
        if (r[1] == 'A') {
            if (r[2] == 'U') return 'd';
            if (r[2] == 'C') return 'd';
            if (r[2] == 'A') return 'e';
            if (r[2] == 'G') return 'e';
        }
        if (r[1] == 'G') {
            if (r[2] == 'U') return 'g';
            if (r[2] == 'C') return 'g';
            if (r[2] == 'A') return 'g';
            if (r[2] == 'G') return 'g';
        }
    }
}


void DNAToRNA(int i)
{
    if (dna[i] == 'T'){
        dna[i] = 'A';
    }
    else if (dna[i] == 'C'){
        dna[i] = 'G';
    }
    else if (dna[i] == 'G'){
        dna[i] = 'C';
    }
    else if (dna[i] == 'A'){
        dna[i] = 'U';
    }
}



int isValid(int startIntron1, int lenIntron1, int startIntron2, int lenIntron2, char nucleotides[], int lenNucleotides, char protein[], int lenProtein)
{
    int nucleotide = 0, proteinIdx = 0;
    for (; nucleotide <= lenNucleotides - 3;)
    {
        char codon[3];
        if (nucleotide == startIntron1)
            nucleotide += lenIntron1;
        if (nucleotide == startIntron2)
            nucleotide += lenIntron2;

        codon[0] = nucleotides[nucleotide], codon[1] = nucleotides[nucleotide + 1], codon[2] = nucleotides[nucleotide + 2];
        if (codonToAmino(codon) == protein[proteinIdx])
        {
            proteinIdx++;
            nucleotide += 3;
        }
        else
            return 0;
    }
    return 1;
}

int main(){
    int lProtein, lNucleotide;
    int lExons, lIntrons;
    int lIntron1 = 1, lIntron2;
    int flag = 1;
    int i;
    int j;
    int p;

    for (i = 0; i <= 3000; i++)
    {
        scanf("%c ", &dna[i]);
        if (dna[i] == '.')
            break;
        DNAToRNA(i);
        lNucleotide = i + 1;
    }

    for (p = 0; p < 2900; p++)
    {
        scanf(" %c", &protein[p]);
        lProtein = p + 1;
        if (protein[p] == '.')
            break;
    }


lExons = lProtein * 3;
lIntrons = lNucleotide - lExons;
lIntron2 = lIntrons - 1;

for (; lIntron2 > 0; lIntron1++, lIntron2--)
{
    int startIntron1, startIntron2;
    for (startIntron1 = 3; startIntron1 <= lNucleotide - lIntron2 - lIntron1 - 3; startIntron1 += 3)
    {
        for (startIntron2 = startIntron1 + lIntron1 + 3; startIntron2 <= lNucleotide - lIntron2 - 3; startIntron2 += 3)
        {
            if (isValid(startIntron1, lIntron1, startIntron2, lIntron2, dna, lNucleotide, protein, lProtein))
            {
                flag = 0;
                printf("%d %d %d %d", startIntron1, startIntron1 + lIntron1 - 1, startIntron2, startIntron2 + lIntron2 - 1);
                goto A;
            }
        }
    }
}
A:

if (flag)
    printf("NONE");

return 0;
}