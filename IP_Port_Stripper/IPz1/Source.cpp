#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool in_file(ifstream& input_file, string file_path) {
    input_file.open(file_path);
    if (!input_file.is_open()) {
        cout << "Failed to open the ip list to read from. " << file_path << endl;
        cout << "Remember that you need to format as such 'C/ipDir/Input.txt'. " << endl;
        return false;
    }
    return true;
}

bool out_file(ofstream& output_file, string file_path) {
    output_file.open(file_path);
    if (!output_file.is_open()) {
        cout << "Failed to open the new ip list to write to. " << file_path << endl;
        cout << "Remember that you need to create a new .txt doc to write to." << endl;
        return false;
    }
    return true;
}

void extract_ips(ifstream& input_file, ofstream& output_file) {
    string line;
    while (getline(input_file, line)) {
        int pos = line.find(":");
        string ip = line.substr(0, pos);
        output_file << ip << endl;
    }
}

int main() {
    cout << "Enter the path to the input file: ";
    string input_file_path;
    cin >> input_file_path;

    ifstream input_file;
    if (!in_file(input_file, input_file_path)) {
        return 1;
    }

    cout << "Enter the path to the output file: ";
    string output_file_path;
    cin >> output_file_path;

    ofstream output_file;
    if (!out_file(output_file, output_file_path)) {
        return 1;
    }

    extract_ips(input_file, output_file);

    input_file.close();
    output_file.close();

    cout << "Done!" << endl;

    return 0;
}