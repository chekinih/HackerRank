#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int knownTopicNumber(string topic1, string topic2) {

    int i = 0;
    int nb = 0;

    while (i < topic1.length()) {
        int first = topic1.at(i) - '0';
        int second =topic2.at(i) - '0';
        nb += first | second;
        i ++;
    }

    return nb;
}

int maxElement(vector<int> arr) {
    int max = 0;
    for (int i = 0; i< arr.size(); i++) {
        if (arr.at(i) > max) {
            max = arr.at(i);
        }
    }
    return max;
}

int nbOccurence(int elm, vector<int>arr) {

    int nb = 0;
    for (int i = 0; i< arr.size(); i++) {
        if (arr.at(i) == elm) {
            nb ++;
        }
    }
    return nb;
}
/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic) {

    int nbOcc = 0;
    vector<int> teams;

    for (int i = 0; i < topic.size(); i++) {
        for (int j = i+1; j < topic.size(); j++) {
            teams.push_back(knownTopicNumber(topic[i], topic[j]));
        }
    }

    int maxElm = maxElement(teams);
    int nbOccu = nbOccurence(maxElm, teams);

    vector <int> result = {maxElm, nbOccu};
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
