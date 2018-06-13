#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

template <typename T>
void print_streight(const vector<T> &veint);

template <typename T>
void print_back(const vector<T> &veint);

void fillVector(vector<int>& vi, size_t size);

bool comparison(int extremum, int i);

void discover(vector<int>& vi);


int main() {
    srand(time(0));
    vector<int> vi;
    fillVector(vi, 10);
    print_streight(vi);
    discover(vi);
    return 0;
}


template <typename T>
void print_streight(const vector<T> &veint) {
    for(auto it = veint.begin(); it != veint.end(); ++it)  cout << *it << " ";
    cout << endl;
}


template <typename T>
void print_back(const vector<T> &veint) {
    auto it = veint.end();
    while (true) {
        it--;
        if (it != veint.end()) cout << *it << " ";
        if (it == veint.begin()) break;
    }
    cout << endl;
}

void fillVector(vector<int> &vi, size_t size) {
    while (size--) vi.push_back(rand() % 100);
}

void discover(vector<int>& vi) {
    vector<int> minMax;
    int min = vi[0], max = vi[0];
    int next;

    minMax.push_back(vi[0]);
    for (int i = 1; i < vi.size() - 1; ++i) {
        if (vi[i] > max) {
            max = vi[i];
            //cout << "max: " << vi[i] << endl;
            if (vi[i] > vi[i + 1]) { /*cout << "max: " << vi[i] << endl;*/ minMax.push_back(vi[i]);
                min = max;
            }
        }

        if (vi[i] < min) {
            min = vi[i];
            //cout << "min: " << vi[i] << endl;
            if (vi[i] < vi[i + 1]) { /*cout << "min: " << vi[i] << endl;*/ minMax.push_back(vi[i]);
                max = min;
            }
        }
    }
    minMax.push_back(vi[vi.size() - 1]);

    cout << "=================================================" << endl;
    print_streight(minMax);

    if (minMax[0] < minMax[1]) {
        cout << "min " << minMax[0] << endl;
    } else if (minMax[0] > minMax[1]) {
        cout << "max " << minMax[0] << endl;
    }
    int extremum = minMax[0];
    for (int j = 1; j < minMax.size(); ++j) {
        if (extremum > minMax[j] && comparison(extremum, minMax[j])) {
            extremum = minMax[j];
            cout << "min " << extremum << endl;
        } else if (extremum < minMax[j] && comparison(extremum, minMax[j])) {
            extremum = minMax[j];
            cout << "max " << extremum << endl;
        }
    }
}

bool comparison(int p1, int p2) {
    double maxim, minim;
    if (p1 > p2) {
        maxim = p1;
        minim = p2;
    } else {
        maxim = p2;
        minim = p1;
    }
    return maxim / minim > 1.5;
}
