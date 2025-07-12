#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <commdlg.h>
#include<algorithm>
#include<unordered_map>
#include <cmath>

using namespace std;
// structure definition
struct tstats{
    double mean;
    double median;
    double mode;
    double std_dev;
    double variance;
    double iqr;
};
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
void calculateStats(double arr[],int n, tstats& s)
{
 bubbleSort(arr,n);
     // Mean
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    s.mean = sum / n;

    // Median
    if (n % 2 == 0)
        s.median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        s.median = arr[n / 2];

    // Mode
    unordered_map<double, int> freq;
    int maxFreq = 0;
    s.mode = arr[0];
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];
            s.mode = arr[i];
        }
    }

    // Variance and Standard Deviation
    double var_sum = 0;
    for (int i = 0; i < n; i++) {
        var_sum += (arr[i] - s.mean) * (arr[i] - s.mean);
    }
    s.variance = var_sum / n;
    s.std_dev = sqrt(s.variance);

    // Interquartile Range (IQR)
    double q1, q3;
    int mid = n / 2;
    if (n % 2 == 0) {
        // Even
        q1 = (arr[mid / 2 - 1] + arr[mid / 2]) / 2.0;
        q3 = (arr[mid + mid / 2 - 1] + arr[mid + mid / 2]) / 2.0;
    } else {
        // Odd
        q1 = arr[mid / 2];
        q3 = arr[mid + mid / 2 + 1];
    }
    s.iqr = q3 - q1;
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
   
   
    tstats s;
    calculateStats(data,count,s);
    cout << "Mean: " << s.mean << endl;
    cout << "Median: " << s.median << endl;
    cout << "Mode: " << s.mode << endl;
    cout << "Standard Deviation: " << s.std_dev << endl;
    cout << "Variance: " << s.variance << endl;
    cout << "IQR: " << s.iqr << endl;

    return 0;
}
