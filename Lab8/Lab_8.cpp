#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct WordCompare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second < b.second; 
        }
        return a.first < b.first; 
    }
};

int main() {
    string filename = "input.txt";
    ifstream infile(filename);

    string text;
    getline(infile, text);

    string word;
    map<string, int> wordCounts;
    /*for (char c : text) {
        if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!') {
            if (!word.empty()) {
                wordCounts[word]++;
                word.clear();
            }
        }
        else {
            if ('A' <= c && c <= 'Z') c += 32;
            word += c;
        }
    }

    if (!word.empty()) 
        wordCounts[word]++;*/

    transform(text.begin(), text.end(), text.begin(), [](char c) { return tolower(c); });
    string delim = " .,?!";

    int ind = text.find_first_of(delim);

    while (ind != string :: npos)
    {
        word = text.substr(0, ind);
        if (!word.empty()) {
            wordCounts[word]++;
            word.clear();
        }
        text.erase(text.begin(), text.begin() + ind + 1);
        ind = text.find_first_of(delim);

    }

    word = text.substr(0, ind);
    if (!word.empty()) {
        wordCounts[word]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, WordCompare> wordQueue;
    for (const auto& pair : wordCounts) 
        wordQueue.push(pair);

    while (!wordQueue.empty()) {
        const auto& pair = wordQueue.top();
        cout << pair.first << " => " << pair.second << endl;
        wordQueue.pop();
    }

    return 0;
}
