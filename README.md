**Word Composition Problem**

### Overview:

The program processes two input files, `Input_01.txt` and `Input_02.txt`, each containing a list of words sorted alphabetically. It reads these words and determines the longest and second-longest compounded words. A compounded word is one that can be formed by concatenating other smaller words from the same list. Additionally, the program measures the time taken to process each file.

In `Input_01.txt`, which contains a relatively small dataset, the longest compounded word found was `ratcatdogcat`, while the second-longest was `catsdogcats`. The processing time for this file was **500 milliseconds**.

On the other hand, `Input_02.txt` contained a much larger dataset with over 100,000 words. The longest compounded word identified was `ethylenediaminetetraacetates`, and the second-longest was `electroencephalographically`. Due to the large dataset, the processing time was **8000 milliseconds**.

### Approach:

To efficiently search for compounded words within these files, multiple approaches were considered, such as **Dynamic Programming (DP)** or using a **Trie (prefix tree) with DP**. The implementation relies on a **Trie data structure**, which groups common prefixes and suffixes, making it highly efficient for word lookups.

### Implementation Steps:

The program begins by reading the input files and storing the words in a structured format. Once the data is loaded, a **Trie** is built to facilitate quick lookups. Each word is inserted into the Trie while tracking its length.

To determine if a word is a valid compounded word, the program sorts the words by length and then checks each word recursively to see if it can be formed using smaller words from the Trie. If both the prefix and suffix of a word exist in the Trie, it is marked as a valid compound word.

Finally, the program retrieves the results by identifying the longest and second-longest compounded words and measuring the execution time for performance analysis.

This approach ensures optimal efficiency, even for large datasets, by leveraging advanced data structures and well-optimized search algorithms.

