Word Composition Problem
Overview:
The program reads two input files (Input_01.txt and Input_02.txt), each containing a list of words sorted alphabetically. It then identifies and displays the following information:

The longest compounded word
The second longest compounded word
The time taken to process the input file
Input_01.txt contains a smaller list of words, whereas Input_02.txt contains a much larger dataset with over 100,000 words.

Approach:
To efficiently search for words in the given text files, we can use multiple approaches, such as Dynamic Programming (DP) or a Trie (prefix tree) combined with DP.

In this implementation, a Trie data structure is used. The Trie is an ordered tree-based structure that allows efficient storage and retrieval of words by grouping common prefixes and suffixes.

Implementation Steps:
Reading Input Files:

Open the file in read mode ("r"), read its contents, and store the words in a list.
Strip unnecessary characters, split words properly, and close the file after processing.
Building the Trie:

Define a Trie node and initialize it.
Insert each word into the Trie while maintaining word length information.
Finding Compounded Words:

Sort words based on length.
For each word, check if it can be formed using smaller words in the Trie.
Use a recursive approach to verify whether the word is a valid concatenated word.
If both prefix and suffix exist in the Trie, count the word as a valid compound word.
Retrieving Results:

Identify the longest and second-longest compounded words from the sorted list.
Measure the execution time to analyze performance.
