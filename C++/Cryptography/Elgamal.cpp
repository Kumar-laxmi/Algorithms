#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int gen_key(int q) {
    int key = rand_r() % q + pow(10, 20);
    while (gcd(q, key) != 1) {
        key = rand_r() % q + pow(10, 20);
    }
    return key;
}

int power(int a, int b, int c) {
    int x = 1;
    int y = a;

    while (b > 0) {
        if (b % 2 != 0) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b = b / 2;
    }
    return x % c;
}

vector<int> encrypt(string msg, int q, int h, int g) {
    vector<int> en_msg;
    int k = gen_key(q);
    int s = power(h, k, q);
    int p = power(g, k, q);
    for (int i = 0; i < msg.length(); i++) {
        en_msg.push_back(msg[i]);
    }

    cout << "g^k used: " << p << endl;
    cout << "g^ak used: " << s << endl;

    for (int i = 0; i < en_msg.size(); i++) {
        en_msg[i] = s * en_msg[i];
    }

    return en_msg;
}

string decrypt(vector<int> en_msg, int p, int key, int q) {
    string dr_msg;
    int h = power(p, key, q);
    for (int i = 0; i < en_msg.size(); i++) {
        dr_msg.push_back(en_msg[i] / h);
    }

    return dr_msg;
}

int main() {
    srand(time(0));
    string msg;
    cout << "Enter the message: ";
    getline(cin, msg);
    cout << "Original Message: " << msg << endl;
    int q = rand_r() % static_cast<int>(pow(10, 50) - pow(10, 20) + 1) + pow(10, 20);
    int g = rand_r() % (q - 2) + 2;
    int key = gen_key(q);
    int h = power(g, key, q);
    cout << "g used: " << g << endl;
    cout << "g^a used: " << h << endl;
    vector<int> en_msg = encrypt(msg, q, h, g);
    string dr_msg = decrypt(en_msg, en_msg[0], key, q);
    cout << "Decrypted Message: " << dr_msg << endl;
    return 0;
}
