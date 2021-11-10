#include <iostream>
#include <string>
using namespace std;

string get_rhyme(string words) {
    int size = words.size();
    int i;
    for (i = size - 1; i >= 0; i--) {
        if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u' || words[i] == ' ')
            break;
    }
    if (i < 0) i = 0;
    return words.substr(i);
}

string to_lower(string s) {
    string t = "";
    for (auto c : s) {
        t += tolower(c);
    }
    return t;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(1000, '\n');
    for (int i = 0; i < N; i++) {
        string rhymes[4];
        for (int j = 0; j < 4; j++) {
            string words;
            getline(cin, words);
            string rhyme = get_rhyme(to_lower(words));
            rhymes[j] = rhyme;
        }
        if (rhymes[0] == rhymes[1] && rhymes[1] == rhymes[2] && rhymes[2] == rhymes[3]) {
            cout << "perfect" << endl;
        }
        else if (rhymes[0] == rhymes[1] && rhymes[2] == rhymes[3]) {
            cout << "even" << endl;
        }
        else if (rhymes[0] == rhymes[2] && rhymes[1] == rhymes[3]) {
            cout << "cross" << endl;
        }
        else if (rhymes[0] == rhymes[3] && rhymes[1] == rhymes[2]) {
            cout << "shell" << endl;
        }
        else {
            cout << "free" << endl;
        }
    }
}