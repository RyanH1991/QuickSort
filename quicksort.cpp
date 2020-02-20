#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <time.h>  
using namespace std;

struct tripleVector {
  int year;
  string firstname;
  string lastname;
};

tripleVector make_tripleVector(int year, string first, string last){
    tripleVector cum = {year,first,last};
    return cum;
}
  
void print(vector<tripleVector> *penis) 
{ 
    /*for (int i=0;i<year.size();i++){
        cout << *(firstname.begin()+i) << " " << *(lastname.begin()+i) << " " << *(year.begin()+i) << endl;
    }*/
    for (int i=0;i<penis->size();i++){
        cout << (*penis)[i].firstname << " " << (*penis)[i].lastname << " " << (*penis)[i].year << endl;
    }
    cout << endl;
} 

int partition(vector<tripleVector> *penis, int left, int right) {
    int pivotIndex = (rand() % (right-left))+left;
    int pivotValue = (*penis)[pivotIndex].year;
    string pivotValue2 = (*penis)[pivotIndex].firstname;
    string pivotValue3 = (*penis)[pivotIndex].lastname;
    int i = left, j = right;
    tripleVector temp;
    while(i <= j) {
        while(((*penis)[i].year < pivotValue) || (((*penis)[i].year == pivotValue)&&(((*penis)[i].firstname.compare(pivotValue2) < 0))) || (((*penis)[i].year == pivotValue)&&(((*penis)[i].firstname.compare(pivotValue2) == 0)) && (((*penis)[i].lastname.compare(pivotValue3) < 0)))) {
            i++;
        }
        while(((*penis)[j].year > pivotValue) || (((*penis)[j].year == pivotValue)&&(((*penis)[j].firstname.compare(pivotValue2) > 0))) || (((*penis)[j].year == pivotValue)&&(((*penis)[j].firstname.compare(pivotValue2) == 0)) && (((*penis)[j].lastname.compare(pivotValue3) > 0)))) {
            j--;
        }
        if(i <= j) {
            temp = (*penis)[i];
            (*penis)[i] = (*penis)[j];
            (*penis)[j] = temp;
            i++;
            j--;
        }
    }
    print(penis);
    return i;
}

void quicksort(vector<tripleVector> *penis, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(penis, left, right);
        quicksort(penis, left, pivotIndex - 1);
        quicksort(penis, pivotIndex, right);
    }
    //print(penis);
}


int main() {
    vector<tripleVector> cream;
    vector<tripleVector> *penis = &cream;
    penis->push_back(make_tripleVector(2014,"mingming","feng"));
    penis->push_back(make_tripleVector(2014,"emma","ziegellaub-eichler"));
    penis->push_back(make_tripleVector(2014,"john","yu"));

    quicksort(penis, 0, penis->size()-1);
    //print(penis);
    return 0;
}