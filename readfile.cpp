#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <commdlg.h>

using namespace std;

// Bubble sort function
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // If no swaps occurred, the array is already sorted
        if (!swapped) break;
    }
}

int main() {
    const int Max_size = 1000;
    double data[Max_size];
    int count = 0;

    // This buffer will hold the selected file path
    char filePath[MAX_PATH] = "";

    // Set up the OPENFILENAME structure
    OPENFILENAME ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    ofn.lpstrDefExt = "txt";

    // Show the file browser dialog
    if (!GetOpenFileName(&ofn)) {
        cout << "No file selected or dialog canceled." << endl;
        return 1;
    }

    cout << "Selected file: " << filePath << endl;

    // Use the selected file path
    ifstream file(filePath);

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read numbers into the array
    while (file >> data[count] && count < Max_size) {
        count++;
    }

    file.close();

    cout << "\nTotal numbers read: " << count << endl;

    // Display original numbers
    cout << "\nOriginal numbers:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }

    // Sort the array
    bubbleSort(data, count);

    // Display sorted numbers
    cout << "\n\nSorted numbers:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

