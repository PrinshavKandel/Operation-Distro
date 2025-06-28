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
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    const int Max_size = 1000;
    double data[Max_size];
    int count = 0;

    // Use wide char buffer
    wchar_t filePath[MAX_PATH] = L"";

    OPENFILENAMEW ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = L"Text Files\0*.txt\0All Files\0*.*\0";
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    ofn.lpstrDefExt = L"txt";

    if (!GetOpenFileNameW(&ofn)) {
        wcout << L"No file selected or dialog canceled." << endl;
        return 1;
    }

    // Convert wchar_t to string for ifstream
    wcout << L"Selected file: " << filePath << endl;
    wstring ws(filePath);
    string filePathStr(ws.begin(), ws.end());

    ifstream file(filePathStr);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (file >> data[count] && count < Max_size) {
        count++;
    }

    file.close();

    cout << "\nTotal numbers read: " << count << endl;

    cout << "\nOriginal numbers:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }

    bubbleSort(data, count);

    cout << "\n\nSorted numbers:\n";
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
