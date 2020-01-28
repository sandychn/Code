#include <bits/stdc++.h>
using namespace std;

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(),
                find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(),
                input.end());
}

void trimTrailingSpaces(string &input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        trimTrailingSpaces(item);
        output.push_back(item.substr(1, item.length() - 2));
    }
    return output;
}