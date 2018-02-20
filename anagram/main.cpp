#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;

int solution(string &A, string &B) {
    unordered_map<char, pair<int, int>> letters;
    int difference = 0;

    for (char c : A)
    {
        auto it = letters.find(c);

        if (it == letters.end())
            letters.insert(pair<int, pair<int, int> >(c, make_pair(1,0)));
        else
            it->second.first ++;
    }

    for (char c : B)
    {
        auto it = letters.find(c);

        if (it == letters.end())
            letters.insert(pair<int, pair<int, int> >(c, make_pair(0,1)));
        else
            it->second.second ++;
    }

    for (auto i : letters)
        difference += abs(i.second.first - i.second.second);

    return difference;
}

int main() {

    string A = "suspense";
    string B = "sunsets";

    std::cout << "String A: " << A << std::endl;
    std::cout << "String B: " << B << std::endl;

    std::cout << "\nCharacters required: " << solution(A, B) << std::endl;

    return 0;
}

