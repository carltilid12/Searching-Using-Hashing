//Carl Christian G. Tilid
//Searching Using Hashing, (a) Linear Probing
#include <iostream>

using namespace std;

//Hash function
int hashFunction(int key) {
    return key % 17; //k mod 17
}

//Count the total no of probes
int countProbes(int keys[], int n) {
    int probeCount = 0;
    bool occupied[17] = {false}; //Bool value to check if occupied for probing

    int table[17][3] = {0}; //Table to show the final contents of the table

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hashFunction(key);
        int probes = 1;

        //Probe by check occupied bool value then add count 
        while (occupied[index]) {
            probes++;
            index = (index + 1) % 17; //Linear probing
        }

        occupied[index] = true; //Mark index as occupied
        probeCount += probes;  

        //Store table values
        table[index][0] = key;
        table[index][1] = index;
        table[index][2] = probes;
    }

    //Show table
    cout << "Key\tHash\tProbes" << endl;
    for (int i = 0; i < 17; i++) {
        if (occupied[i]) {
            cout << table[i][0] << "\t" << table[i][1] << "\t" << table[i][2] << endl;
        }
    }

    return probeCount;
}

int main() {
    int keys[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    int totalProbes = countProbes(keys, numKeys);

    cout << "Total number of probes: " << totalProbes << endl;

    return 0;
}
//Carl Christian G. Tilid
//Searching Using Hashing, (b) Quadratic Probing
#include <iostream>

using namespace std;

//Hash function
int hashFunction(int key) {
    return key % 17; //k mod 17
}

//Count the total no of probes
int countProbes(int keys[], int n) {
    int probeCount = 0;
    bool occupied[17] = {false}; //Bool value to check if occupied for probing

    int table[17][3] = {0}; //Table to show the final contents of the table

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hashFunction(key);
        int probes = 0;

        //Probe by check occupied bool value then add count 
        while (occupied[index]) {
            probes++;
            index = hashFunction(key);
            index = (index + probes*probes) % 17; //Quadratic Probing
        }

        probes++;
        occupied[index] = true; //Mark index as occupied
        probeCount += probes;  

        //Store table values
        table[index][0] = key;
        table[index][1] = index;
        table[index][2] = probes;
    }

    //Show table
    cout << "Key\tHash\tProbes" << endl;
    for (int i = 0; i < 17; i++) {
        if (occupied[i]) {
            cout << table[i][0] << "\t" << table[i][1] << "\t" << table[i][2] << endl;
        }
    }

    return probeCount;
}

int main() {
    int keys[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    int totalProbes = countProbes(keys, numKeys);

    cout << "Total number of probes: " << totalProbes << endl;

    return 0;
}
//Carl Christian G. Tilid
//Searching Using Hashing, (c) Double Hashing
#include <iostream>

using namespace std;

//Hash function
int hashFunction(int key) {
    return key % 17; //k mod 17
}

int dashFunction(int key) {
    return 13 - (key % 13); //13 - k mod 13
}

//Count the total no of probes
int countProbes(int keys[], int n) {
    int probeCount = 0;
    bool occupied[17] = {false}; //Bool value to check if occupied for probing

    int table[17][4] = {0}; //Table to show the final contents of the table

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hashFunction(key);
        int probes = 0;

        //Probe by check occupied bool value then add count 
        while (occupied[index]) {
            probes++;
            index = hashFunction(key);
            index = (index + probes*dashFunction(key)) % 17; //Double Hashing
        }

        probes++;
        occupied[index] = true; //Mark index as occupied
        probeCount += probes;  

        //Store table values
        table[index][0] = key;
        table[index][1] = index;
        table[index][2] = dashFunction(key);
        table[index][3] = probes;
    }

    //Show table
    cout << "Key\tHash\tD(k)\tProbes" << endl;
    for (int i = 0; i < 17; i++) {
        if (occupied[i]) {
            cout << table[i][0] << "\t" << table[i][1] << "\t\t" << table[i][2] << "\t\t" << table[i][3] << endl;
        }
    }

    return probeCount;
}

int main() {
    int keys[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    int totalProbes = countProbes(keys, numKeys);

    cout << "Total number of probes: " << totalProbes << endl;

    return 0;
}
