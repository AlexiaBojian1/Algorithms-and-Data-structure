#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        uint64_t cur = ipToUint(ip);
        vector<string> out;

        while (n > 0) {
            // Largest power-of-two allowed by alignment at 'cur'
            uint64_t lowbit = cur & (~cur + 1);        // == cur & -cur
            if (lowbit == 0) lowbit = (1ull << 32);    // cur==0 ⇒ no alignment limit

            // Largest power-of-two allowed by remaining 'n'
            uint64_t byN = highestPow2LE((uint64_t)n);

            uint64_t block = min(lowbit, byN);         // must satisfy both constraints

            int prefix = 32 - log2pow(block);          // block = 2^(32 - prefix)
            out.push_back(uintToIp(cur) + "/" + to_string(prefix));

            cur += block;
            n   -= (int)block;
        }
        return out;
    }

private:
    // Parse "a.b.c.d" → 32-bit value
    static uint64_t ipToUint(const string& ip) {
        uint64_t a=0,b=0,c=0,d=0; char dot;
        stringstream ss(ip);
        ss >> a >> dot >> b >> dot >> c >> dot >> d;
        return (a<<24) | (b<<16) | (c<<8) | d;
    }

    // 32-bit value → "a.b.c.d"
    static string uintToIp(uint64_t x) {
        return to_string((x>>24)&255) + "." +
               to_string((x>>16)&255) + "." +
               to_string((x>>8)&255)  + "." +
               to_string(x&255);
    }

    // Largest power of two ≤ n (n ≥ 1)
    static uint64_t highestPow2LE(uint64_t n) {
        uint64_t p = 1;
        while ((p << 1) <= n) p <<= 1;
        return p;
    }

    // log2 for a power-of-two value: find k s.t. p2 == (1ULL << k)
    static int log2pow(uint64_t p2) {
        int k = 0;
        while ((1ull << k) < p2) ++k;
        return k;
    }
};
