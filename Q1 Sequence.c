#include <iostream.h>
#include <string>

using namespace std;

// Recursive function to extract words between starting and ending indices
string extractWords (const string& sentence, int start, int end) {
    // if starting index exceeds ending index or sentence is empty
    if (start > end || start >= sentence.length()) {
        return "";
    }

    string result = ""; // Store the result

    // If the current character is not a space and falls within the range,
    // add it to the result string
    if (sentence[start] != ' ' && start <= end) {
        result += sentence[start];
    }

    // If the current character is a space and the previous character was part of a word,
    // add a space to separate words
    if (sentence[start] == ' ' && start <= end && start > 0 && sentence[start - 1] != ' ') {
        result += ' ';
    }

    // Recurr with the next index
    return result + extractWords(sentence, start + 1, end);
}

int main() {
    string sentence;
    int start, end;

    // Input sentence, starting index, and ending index
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Enter starting index: ";
    cin >> start;
    cout << "Enter ending index: ";
    cin >> end;
    // Extract words between starting and ending indices
    string result = extractWords(sentence, start, end);
    // Output the extracted words
    cout << "Words between indices " << start << " and " << end << ": " << result << endl;
    return 0;
}


