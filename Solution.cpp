#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> read_words(const string& filename) {
    ifstream file(filename);
    return {istream_iterator<string>(file), istream_iterator<string>()};
}

bool is_compound(const string& word, unordered_set<string>& word_set) {
    for (size_t i = 1; i < word.size(); ++i)
        if (word_set.count(word.substr(0, i)) && (word_set.count(word.substr(i)) || is_compound(word.substr(i), word_set)))
            return true;
    return false;
}

void find_longest_compound_words(const string& filename) {
    vector<string> words = read_words(filename);
    unordered_set<string> word_set(words.begin(), words.end());
    sort(words.rbegin(), words.rend(), [](const string& a, const string& b) { return a.size() < b.size(); });
    
    auto start = chrono::high_resolution_clock::now();
    string longest, second_longest;
    for (const string& word : words) {
        word_set.erase(word);
        if (is_compound(word, word_set)) {
            if (longest.empty()) longest = word;
            else { second_longest = word; break; }
        }
        word_set.insert(word);
    }
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Processing " << filename << "\n";
    cout << "Longest: " << longest << "\nSecond Longest: " << second_longest << "\nTime: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n\n";
}

int main() {
    find_longest_compound_words("Input_01.txt");
    find_longest_compound_words("Input_02.txt");
}
