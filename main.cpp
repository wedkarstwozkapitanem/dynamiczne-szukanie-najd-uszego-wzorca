/*
    author: Dominik Łempicki Kapitan,
    nazwa: szukanie wzorca,
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<string>


std::string szukaj_wzorca(std::string wzor,std::string tekst) {
    int m = wzor.size();
    int n = tekst.size();
    std::vector<std::vector<int>> wystopienia(m+1,std::vector<int>(n+1,0));
    std::queue<char> ostatnielitery;
    for(const auto &i : wzor) ostatnielitery.push(i);
    char ostatnielitera = ostatnielitery.front();
    ostatnielitery.pop();
    
    for(int i{1};i<=m;i++) {
        for(int j{i};j<=n;j++) {
            if(tekst[j-1] == wzor[i-1] && (ostatnielitery.front() == wzor[i-1] || ostatnielitera == wzor[i-1])) {
                if(ostatnielitery.front() == wzor[i-1]) {
                     ostatnielitera = ostatnielitery.front();
                    ostatnielitery.pop();
                }
                wystopienia[i][j] = std::max(wystopienia[i-1][j-1]+1,wystopienia[i][j-1]+1);
            }
            else wystopienia[i][j] = std::max(wystopienia[i-1][j],wystopienia[i][j-1]);
        }
    }

    int k = tekst.size()-1;
    while(tekst[k] != wzor[wzor.size()-1]) k--;
    
    int p = m;
   
    std::vector<char> wynik;

    wynik.push_back(tekst[k]);


   while(p!=0 && k != 0) {
            if(wystopienia[p][k] == wystopienia[p-1][k] )  p--;
            if(wystopienia[p][k] - 1 == wystopienia[p][k-1]) wynik.push_back(tekst[k-1]);
            k--;
    }



    std::reverse(wynik.begin(),wynik.end());
    std::string str(wynik.begin(), wynik.end());
    return str;
}

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n,m;std:;std::cin >> m >> n;

    std::string wzor,tekst; std::cin >> wzor >> tekst;

    std::cout << szukaj_wzorca(wzor,tekst);
    return 0;
}
