#include <cstdlib> 
#include <iostream>
#include <vector>
#include <string>

// using namespace std;

class KMP { 
    private: 
    std::string pattern;
    std::vector<std::vector<int> > dfa;
  public:             // Access specifier
    KMP(std::string pattern)
    {
        this->pattern = pattern;
        int M = pattern.length();
        int R = 256;
        dfa = std::vector<std::vector<int> >(R, std::vector<int>(M));
        dfa[pattern[0]][0] = 1;
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++)
                dfa[c][j] = dfa[c][X];     // Copy mismatch cases.
            dfa[pattern[j]][j] = j+1;       // Set match case.
            X = dfa[pattern[j]][X];         // Update restart state.
        }
    }  
    int search(std::string text)
    {
        int i, j, N = text.length(), M = pattern.length();
        for (i = 0, j = 0; i < N && j < M; i++)
            j = dfa[text[i]][j];
        if (j == M) return 1;    // found
        return -1;                    // not found
    }
};
int main(int argc, char *argv[])
{
    std::cout<< "hello world"<<std::endl;
    KMP kmp = KMP("ABABAC");
    std::cout<<kmp.search("ABABAC")<<std::endl;
    return EXIT_SUCCESS;
}
