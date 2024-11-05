#include <iostream>
#include <bits/stdc++.h>
#define NIL -999999999
#define N 10000
#define Chaining 1
#define Double 2
#define Custom 3
using namespace std;

class HashTable;
void wordGenerator(string s[], int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<7; j++) {
            string c(1, 'a'+rand()%26);
            s[i] += c;
        }
    }
}

class HashNode
{
    int val;
    string key;
    HashNode *next;
    friend class HashTable;
public:
    HashNode() {
        val = NIL;
        key = "";
        next = nullptr;
    }
    HashNode(string key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
    }
};

class HashTable
{
    int len;
    int colres;
    int maxsize;
    int nCol;
    int func;
    int probe;
    int nSearch;
    HashNode **table;
    int hashfuncOne(string key);
    int hashfuncTwo(string key);
    int hashfuncAux(string key);
public:
    HashTable(int func=1, int colres=Chaining) {
        len = 0;
        maxsize = 0;
        this->func = func;
        this->colres = colres;
        nCol = 0;
        probe = 0;
        nSearch = 0;
        table = nullptr;
    }
    HashTable(int n, int func = 1, int colres = Chaining) {
        len = 0;
        nCol = 0;
        maxsize = n;
        probe = 0;
        nSearch = 0;
        table = new HashNode*[maxsize];
        for(int i=0; i<maxsize; i++)
        {
            table[i] = new HashNode();
        }
        this->colres = colres;
        this->func = func;
    }
    void setTableSize(int n) {
        maxsize = n;
        table = new HashNode*[maxsize];
        for(int i=0; i<maxsize; i++)
        {
            table[i] = new HashNode();
        }
    }
    void inSert(string key, int val);
    int seArch(string key);
    void deleteKey(string key);
    void printResult();
};

int HashTable::hashfuncOne(string key)
{
    long long hashind = 31;
    int c;
    for(int i=0; i<key.length();  i++) {
        c = key[i];
        hashind = 67*hashind + c;
    }
    hashind %= maxsize;
    if(hashind<0) {
        hashind += maxsize;
    }
    return hashind;
}

int HashTable::hashfuncTwo(string key)
{
    long long hashind = 5381;
    int c, i=0;
    while(i<key.length()) {
        c = key[i];
        hashind = ((hashind << 5) + hashind) + c;
        i++;
    }
    return hashind%maxsize;
}

int HashTable::hashfuncAux(string key)
{
    long long hashind = 29;
    int c;
    for(int i=0; i<key.length();  i++) {
        c = key[i];
        if(c%2==0)
            hashind = hashind*3 + c;
        else
            hashind = hashind*3 + c*7;
        if(hashind%5==0 && hashind%10!=0)
            hashind += 6;
        else if(hashind%5==0 && hashind%10==0)
            hashind += 1;
        if(hashind%2==0 && hashind%10==8)
            hashind += 3;
        else if(hashind%2==0)
            hashind += 7;
    }

    hashind %= maxsize;
    if(hashind<0)
        hashind += maxsize;
    return hashind;
}

void HashTable::inSert(string key, int val)
{
    long long hindx;
    int col = 0;
    if(func == 1)
        hindx = hashfuncOne(key);
    else if(func == 2)
        hindx = hashfuncTwo(key);
    else
        return;

    if(table[hindx]->key.empty())
    {
        table[hindx]->key = key;
        table[hindx]->val = val;
        len++;
        return;
    }
    else if(colres == Chaining)
    {
        HashNode *node = new HashNode(key, val);
        HashNode *last = table[hindx];
        while(last->next != nullptr) {
            last = last->next;
        }
        last->next = new HashNode();
        last->next = node;
        nCol++;
        return;
    }

    if(colres == Double && len<maxsize)
    {
        int i=1;
        while(!table[hindx]->key.empty()) {
            if(func == 1)
                hindx = (hashfuncOne(key) + i*hashfuncAux(key)) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + i*hashfuncAux(key)) % maxsize;
            if(hindx<0)
                hindx += maxsize;
            if(i == maxsize)
                return;
            i++;
            col++;
        }
        table[hindx]->key = key;
        table[hindx]->val = val;
        nCol += col;
        len++;
    }
    else if(colres == Custom && len<maxsize)
    {
        int c1=13, c2=20;
        int i=1;
        while(!table[hindx]->key.empty()) {
            if(func == 1)
                hindx = (hashfuncOne(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;
            if(hindx<0)
                hindx += maxsize;
            if(i == maxsize)
                return;
            i++;
            col++;
        }
        table[hindx]->key = key;
        table[hindx]->val = val;
        nCol += col;
        len++;
    }
    else
        cout << "HashTable is full" << endl;
}

int HashTable::seArch(string key)
{
    int hindx, p=0;
    if(func == 1)
        hindx = hashfuncOne(key);
    else if(func == 2)
        hindx = hashfuncTwo(key);
    else
        return NIL;

    if(table[hindx]->key == key) {
        probe++;
        nSearch++;
        return table[hindx]->val;
    }
    else if(colres == Chaining)
    {
        HashNode *last = table[hindx]->next;
        p++;
        while(last!=nullptr && last->key != key) {
            p++;
            last = last->next;
            if(last->key == key) {
                nSearch++;
                probe += p;
                return last->val;
            }
        }
        int ans = last->val;
        if(ans!=NIL) {
            nSearch++;
            probe += p;
        }
        return ans;
    }
    else if(colres == Double)
    {
        int i=1;
        p++;
        while(table[hindx]->key != key) {
            p++;
            if(func == 1)
                hindx = (hashfuncOne(key) + i*hashfuncAux(key)) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + i*hashfuncAux(key)) % maxsize;

            if(table[hindx]->key == key) {
                nSearch++;
                probe += p;
                return table[hindx]->val;
            }
            else if(i==maxsize)
                return NIL;
            i++;
        }
        return NIL;
    }
    else if(colres == Custom)
    {
        int c1=13, c2=20;
        int i=1;
        p++;
        while(table[hindx]->key != key) {
            p++;
            if(func == 1)
                hindx = (hashfuncOne(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;

            if(table[hindx]->key == key) {
                nSearch++;
                probe += p;
                return table[hindx]->val;
            }
            else if(i==maxsize)
                return NIL;
            i++;
        }
        return NIL;
    }
}

void HashTable::deleteKey(string key)
{
    int hindx;
    if(func == 1)
        hindx = hashfuncOne(key);
    else if(func == 2)
        hindx = hashfuncTwo(key);
    else
        return;

    if(table[hindx]->key == key)
    {
        if(colres == Chaining) {
            HashNode *x = table[hindx];
            HashNode *nxt = table[hindx]->next;
            HashNode *nxtnxt = nullptr;
            if(nxt != nullptr)
                nxtnxt = nxt->next;
            x->key = nxt->key;
            x->val = nxt->val;
            x->next = nxtnxt;
        }
        else if(colres == Double || colres == Custom) {
            table[hindx]->val = NIL;
            table[hindx]->key = "";
        }
    }
    else if(colres == Chaining)
    {
        HashNode *prevx = nullptr;
        HashNode *x = table[hindx];
        while(x->key != key) {
            prevx = x;
            x = x->next;
        }
        if(prevx != nullptr)
            prevx->next = x->next;
    }
    else if(colres == Double)
    {
        int i=1;
        while(table[hindx]->key != key) {
            if(func == 1)
                hindx = (hashfuncOne(key) + i*hashfuncAux(key)) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + i*hashfuncAux(key)) % maxsize;

            if(i == maxsize)
                return;
            i++;
        }
        table[hindx]->key = "";
        table[hindx]->val = NIL;
        len--;
    }
    else if(colres == Custom)
    {
        int c1=13, c2=20;
        int i=1;
        while(table[hindx]->key != key) {
            if(func == 1)
                hindx = (hashfuncOne(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;
            else if(func == 2)
                hindx = (hashfuncTwo(key) + c1*i*hashfuncAux(key) + c2*i*i) % maxsize;

            if(i==maxsize)
                return;
            i++;
        }
        table[hindx]->key = "";
        table[hindx]->val = NIL;
        len--;
    }
}

void HashTable::printResult()
{
    if(colres == Chaining)
        cout << "Chaining Method" << endl;
    else if(colres == Double)
        cout << "Double Hashing" << endl;
    else if(colres == Custom)
        cout << "Custom Probing" << endl;

    if(func == 1)
        cout << "Using Hash1" << endl;
    else if(func == 2)
        cout << "Using Hash2" << endl;

    cout << "num of collision : " << nCol << endl;
    cout << "average probes: " << (double)probe/(double)nSearch << endl;
    //cout << "nsearch: " << nSearch << endl;
    cout << endl;
}

int main()
{
    int n;
    cout << "size of the table: ";
    cin >> n;
    string *word = new string[N];
    string *searchword = new string[1000];
    wordGenerator(word, N);
    int indx = 0;
    for(int i=0; i<1000; i++) {
        indx = rand()%15 + indx;
        searchword[i] = word[indx];
        indx++;
    }

    HashTable hashChainOne(n, 1, Chaining);
    HashTable hashDoubleOne(n, 1, Double);
    HashTable hashCustomOne(n, 1, Custom);

    HashTable hashChainTwo(n, 2, Chaining);
    HashTable hashDoubleTwo(n, 2, Double);
    HashTable hashCustomTwo(n, 2, Custom);

    ///**Chaining method**
    for(int i=0; i<N; i++)
        hashChainOne.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashChainOne.seArch(searchword[i]);
    hashChainOne.printResult();

    for(int i=0; i<N; i++)
        hashChainTwo.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashChainTwo.seArch(searchword[i]);
    hashChainTwo.printResult();

    ///**Double Hashing method**
    for(int i=0; i<N; i++)
        hashDoubleOne.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashDoubleOne.seArch(searchword[i]);
    hashDoubleOne.printResult();

    for(int i=0; i<N; i++)
        hashDoubleTwo.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashDoubleTwo.seArch(searchword[i]);
    hashDoubleTwo.printResult();

    ///**Custom Hashing method**
    for(int i=0; i<N; i++)
        hashCustomOne.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashCustomOne.seArch(searchword[i]);
    hashCustomOne.printResult();

    for(int i=0; i<N; i++)
        hashCustomTwo.inSert(word[i], i+1);
    for(int i=0; i<1000; i++)
        hashCustomTwo.seArch(searchword[i]);
    hashCustomTwo.printResult();

    return 0;
}
