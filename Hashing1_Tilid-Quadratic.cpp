#include <iostream>

using namespace std;

// Hash function to map keys to array indices
int hashFunction(int key) {
    return key % 17; // Using modulo operator to fit within array bounds
}

// Function to count the total number of probes
int countProbes(int keys[], int n) {
    int probeCount = 0;
    bool occupied[17] = {false}; // Track array slots occupancy

    // Create and initialize the table
    int table[17][3] = {0}; // Columns: Key, Hash value, Number of probes

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hashFunction(key);
        int probes = 0;

        // Probe until an empty slot is found
        while (occupied[index]) {
            probes++;
            index = (index + probes * probes) % 17; // Linear probing
        }

        occupied[index] = true; // Mark slot as occupied
        probeCount += probes;    // Add probes to total count

        // Store key, hash value, and number of probes in the table
        table[index][0] = key;
        table[index][1] = index;
        table[index][2] = probes;
    }

    // Print the table
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
