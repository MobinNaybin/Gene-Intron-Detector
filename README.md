# Gene-Intron-Detector
Gene Intron Detector is a C project designed to analyze gene structures and facilitate protein synthesis. The project aims to accurately map gene structures, ensuring efficient protein synthesis while locating and distinguishing introns (Junk DNA) within the gene.
## Features
- Converts DNA sequences into mRNA for transcription.
- Translates codons into amino acids for protein synthesis.
- Identifies introns by matching translated codons with protein amino acids.
- Handles gene and protein sequences efficiently, accommodating whitespace and terminating characters.
- Implements error handling mechanisms to ensure data integrity and reliability.
- Returns the intorn indexes.
  
## Usage
1. Compile the project using a C compiler.
2. Run the executable and follow the prompts to input DNA sequences and protein data.
3. The program will output the start and end positions of introns if the protein is the product of the given gene, otherwise, it will print "NONE".

## Example
#### Input:<br>
Gene Sequence:<br>
TCTGCAGCAGAGGGGCCGTC
GGCAGAAGGAGGGCTCGGGC
AGGCTCTGCGACTCGTAGGC
ACCAGGCGTGAGACCTGTAG
CCCCCGATCACCATGTACAG
CTTCATGGGTGGTGGCCTGT
TCTGTGCCTGGGTGGGGACC
ATCCTCCTGGTGGTGGCCAT
GGCAACAGACGGGGCCAAGG
ACACCTGTATTCCAGATGGA
GAACTCTGCGGCTCAAAGAG
GGAAAGGGAGCAACCCAAGG
TCACTCAGCGGAGGCTGACT
CCTGGTCCTAGGCTGGAAGG
AGGAAGAATAGGGCCCATGG
GAGGGAGCTGAGAAGACT.

Protein Sequence:<br>
rrrlpgsrlppepvrdaelvvhvevpttgqdtdpplvggpppvplspptedqdptflllipgtlprlf.

#### Output:<br>
54 84 169 248

Output Description:<br>
intron1start = 54<br>
intron1end = 84<br>
intron2start = 169<br>
intron2end = 248<br>


## Contributions
Contributions to the project are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).
