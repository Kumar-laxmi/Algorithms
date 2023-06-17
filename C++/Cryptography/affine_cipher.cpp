#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to compute the greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to compute the inverse modulo of a number 'a' modulo 'm'
int inverse_modulo(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;

        // m is remainder now, process same as euclid's algo
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to encrypt the message
string encrypt(string message, /*string key, */ int a, int b)
{
    // Convert message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    // Encrypt message
    string encrypted_message = "";
    for (char c : message)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int x = c - 'A';
            int y = (a * x + b) % 26;
            char encrypted_char = y + 'A';
            encrypted_message += encrypted_char;
        }
        else
        {
            encrypted_message += c;
        }
    }

    return encrypted_message;
}

// Function to decrypt the message
string decrypt(string encrypted_message, /*string key, */ int a, int b)
{
    // Convert message to uppercase
    transform(encrypted_message.begin(), encrypted_message.end(), encrypted_message.begin(), ::toupper);

    // Compute inverse of a modulo 26
    int inverse = inverse_modulo(a, 26);

    // Decrypt message
    string decrypted_message = "";
    for (char c : encrypted_message)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int y = c - 'A';
            int x = (inverse * (y - b + 26)) % 26;
            char decrypted_char = x + 'A';
            decrypted_message += decrypted_char;
        }
        else
        {
            decrypted_message += c;
        }
    }

    return decrypted_message;
}

int main()
{
    string message, key;
    int a, b;
    int choice;

    // Get message, key, and multiplier from user
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    // Ensure a is relatively prime to 26
    if (gcd(a, 26) != 1)
    {
        cout << "Error: a must be relatively prime to 26" << endl;
        return 1;
    }

    // Display menu
    cout << "1. Encrypt message" << endl;
    cout << "2. Decrypt message" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // Process choice
    if (choice == 1)
    {
        // Encrypt message
        string encrypted_message = encrypt(message, /*key,*/ a, b);
        cout << "Encrypted message: " << encrypted_message << endl;
    }
    else if (choice == 2)
    {
        // Decrypt message
        string decrypted_message = decrypt(message, /*key,*/ a, b);
        cout << "Decrypted message: " << decrypted_message << endl;
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 1;
    }
    return 0;
}
