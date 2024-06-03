#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Transaction {
    string product;
    double value;
};

bool loadTransactions(const string& filename, vector<Transaction>& transactions) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string product;
    double value;
    while (file >> product >> value) {
        if (file.fail()) {
            cerr << "Error reading line" << endl;
            return false;
        }
        transactions.push_back({product, value});
    }
    file.close();
    return true;
}

void generateReport(const vector<Transaction>& transactions, const string& reportFilename) {
    int totalTransactions = transactions.size();
    double totalSales = 0;
    double highestSale = transactions.size() > 0 ? transactions[0].value : 0;
    double lowestSale = transactions.size() > 0 ? transactions[0].value : 0;
    vector<string> products;
    vector<int> counts;

    for (const auto& t : transactions) {
        totalSales += t.value;
        if (t.value > highestSale) highestSale = t.value;
        if (t.value < lowestSale) lowestSale = t.value;

        bool found = false;
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i] == t.product) {
                counts[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            products.push_back(t.product);
            counts.push_back(1);
        }
    }

    double averageSale = totalTransactions > 0 ? totalSales / totalTransactions : 0;

    ofstream reportFile(reportFilename);
    if (!reportFile.is_open()) {
        cerr << "Error opening report file: " << reportFilename << endl;
        return;
    }

    reportFile << "Sales Report\n";
    reportFile << "============\n";
    reportFile << "Total Transactions: " << totalTransactions << "\n";
    reportFile << "Total Sales: $" << fixed << setprecision(2) << totalSales << "\n";
    reportFile << "Average Sale: $" << fixed << setprecision(2) << averageSale << "\n";
    reportFile << "Highest Sale: $" << fixed << setprecision(2) << highestSale << "\n";
    reportFile << "Lowest Sale: $" << fixed << setprecision(2) << lowestSale << "\n";
    reportFile << "Sales per Product:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        reportFile << "  " << products[i] << ": " << counts[i] << "\n";
    }
    reportFile.close();
}

int main() {
    string inputFilename = "sales.txt";
    string reportFilename = "report.txt";
    vector<Transaction> transactions;

    if (!loadTransactions(inputFilename, transactions)) {
        cerr << "Failed to load transactions." << endl;
        return 1;
    }

    generateReport(transactions, reportFilename);
    cout << "Report generated successfully: " << reportFilename << endl;

    return 0;
}