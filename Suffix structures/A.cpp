#include <iostream>
#include <vector>
#include <string>
 
enum { alphabet = 256 };
 
int main() {
    std::string s;
    std::cin >> s;
 
    std::vector<int> p(s.size()), cnt(alphabet, 0), c(s.size());
    
	for (char c : s) ++cnt[c];
    for (int i = 1; i < alphabet; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < s.size(); ++i) p[--cnt[s[i]]] = i;
    
	c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[p[i]] != s[p[i - 1]]) ++classes;
        c[p[i]] = classes - 1;
    }
 
    std::vector<int> pn(s.size()), cn(s.size());
    for (int pow = 1; pow < s.size(); pow <<= 1) {
        for (int i = 0; i < s.size(); ++i) {
            pn[i] = p[i] - pow;
            if (pn[i] < 0) pn[i] += s.size();
        }
        cnt.assign(classes, 0);
        for (int i = 0; i < s.size(); ++i) ++cnt[c[pn[i]]];
        for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
        for (int i = s.size() - 1; i >= 0; --i) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < s.size(); ++i) {
            int
                mid1 = (p[i] + pow) % s.size(),
                mid2 = (p[i - 1] + pow) % s.size();
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) ++classes;
            cn[p[i]] = classes - 1;
        }
        c = cn;
    }
 
    for (int e : p) std::cout << e + 1 << ' ';
 
    return 0;
}
