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
    /*std::queue<char> ostatnielitery;
    for(const auto &i : wzor) ostatnielitery.push(i);
    char ostatnielitera = ostatnielitery.front();
    ostatnielitery.pop();*/

    int ktora_literka{0};
    char ostatnielitera = wzor[ktora_literka];
    ktora_literka++;
    
    for(int i{1};i<=m;i++) {
        for(int j{i};j<=n;j++) {
            if(tekst[j-1] == wzor[i-1] && (wzor[ktora_literka] == wzor[i-1] || ostatnielitera == wzor[i-1])) {
                if(wzor[ktora_literka] == wzor[i-1]) {
                     ostatnielitera = wzor[i-1];
                    ktora_literka++;
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

    ++k;
   while(p!=0 && k != 0) {
            if(wystopienia[p][k] == wystopienia[p-1][k] )  p--;
            if(wystopienia[p][k] - 1 == wystopienia[p][k-1]) wynik.push_back(tekst[k-1]);
            k--;
    }



    std::reverse(wynik.begin(),wynik.end());
    std::string str(wynik.begin(), wynik.end());


    std::cout << "  ";
    for(const auto &i : wynik) std::cout << i << ' ';
    std::cout << '\n';
    for(int i{1};i<=m;i++) {
        std::cout << wzor[i-1] <<":";
        for(int j{1};j<=n;j++) {
            std::cout << wystopienia[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    return str;
}

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n,m;std:;std::cin >> m >> n;

    std::string wzor,tekst; std::cin >> wzor >> tekst;

    std::cout << szukaj_wzorca(wzor,tekst);
    return 0;
}
