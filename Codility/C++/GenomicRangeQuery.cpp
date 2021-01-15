// Genomic range query.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q);

int main()
{
    std::string S = "CAGCCTA";
    std::vector<int>
        P = { 2, 5, 0 },
        Q = { 4, 5, 6 };
    std::vector<int> Sol = solution(S, P, Q);
    for (int i = 0; i < Sol.size(); i++)
        std::cout << Sol[i] << '\n';
}

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
    std::vector<int> prefixA(S.size()), prefixC(S.size()),
        prefixG(S.size()), prefixT(S.size()),
        result(P.size());
    //Construct prefix sum arrays
    switch (S[0]) {
    case 'A': prefixA[0] = 1; break;
    case 'C': prefixC[0] = 1; break;
    case 'G': prefixG[0] = 1; break;
    case 'T': prefixT[0] = 1; break;
    }
    for (int i = 1; i < S.size(); i++) {
        prefixA[i] = prefixA[i - 1] + (S[i] == 'A');
        prefixC[i] = prefixC[i - 1] + (S[i] == 'C');
        prefixG[i] = prefixG[i - 1] + (S[i] == 'G');
        prefixT[i] = prefixT[i - 1] + (S[i] == 'T');
    }

    for (int i = 0; i < P.size(); i++) {
        if (!P[i]) {
            if (prefixA[Q[i]])
                result[i] = 1;
            else if (prefixC[Q[i]])
                result[i] = 2;
            else if (prefixG[Q[i]])
                result[i] = 3;
            else
                result[i] = 4;
        }
        else {
            if (prefixA[Q[i]] - prefixA[P[i] - 1])
                result[i] = 1;
            else if (prefixC[Q[i]] - prefixC[P[i] - 1])
                result[i] = 2;
            else if (prefixG[Q[i]] - prefixG[P[i] - 1])
                result[i] = 3;
            else
                result[i] = 4;
        }
    }
    return result;
}