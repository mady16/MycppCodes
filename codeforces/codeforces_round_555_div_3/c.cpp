#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)

#define printA(A, n) \
    foreq(p, 0, n - 1) { cout << p << ": " << A[p] << endl; }
#define print(s) cout << s << endl
#define scan(s) cin >> s
#define scanA(A, n) \
    foreq(p, 0, n - 1) { cin >> A[p]; }
#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

string findMaxSeq(vector<ll> &seq, vector<ll> &resseq, ll index, string operation, char move='~') {
    // print(operation);
    if ( move == 'L' || (resseq.back() < seq[index] &&
        (seq[index] < seq.back() || resseq.back() >= seq.back()))) {
        resseq.push_back(seq[index]);
        index++;
        operation += "L";
        operation = findMaxSeq(seq, resseq, index, operation);
    } else if ( move == 'R' || (resseq.back() < seq.back() &&
               (seq.back() < seq[index] || resseq.back() >= seq[index]))) {
        resseq.push_back(seq.back());
        seq.pop_back();
        operation += "R";
        operation = findMaxSeq(seq, resseq, index, operation);
    } else if (seq.back() == seq[index] && index != seq.size()-1 && resseq.back() < seq.back()) {
        vector<ll> seq1 = seq;
        vector<ll> seq2 = seq;
        vector<ll> resseq1 = resseq;
        vector<ll> resseq2 = resseq;
        string temp1 = findMaxSeq(seq1, resseq1, index, operation, 'L');
        string temp2 = findMaxSeq(seq2, resseq2, index, operation, 'R');

        if(temp1.length() > temp2.length()){
            operation = temp1;
            seq = seq1;
            resseq = resseq1;
        }else{
            operation = temp2;
            seq = seq2;
            resseq = resseq2;
        }
    }else if(index == seq.size()-1 && resseq.back() < seq.back()){
        resseq.push_back(seq.back());
        seq.pop_back();
        operation += operation[operation.length()-1];
    }

    return operation;
}

int main() {
    ll n;
    scan(n);

    vector<ll> seq;
    int temp;
    foreq(i, 0, n - 1) {
        scan(temp);
        seq.push_back(temp);
    }

    vector<ll> resseq;
    resseq.push_back(-1);

    string operation = "";
    ll index = 0;

    operation = findMaxSeq(seq, resseq, index, operation);

    print(operation.length());
    print(operation);

    return 0;
}