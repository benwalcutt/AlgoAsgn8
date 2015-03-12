#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// it just works better this way for me
// less thinking really
static int col[9] = {0,0,0,0,0,0,0,0,0};
static int num = 8;
static int counter = 0;
static int search_col = 0;
static int search_row = 0;

bool promising(int i) {
	int k;
	bool switch_;
	
	k = 1;
	switch_ = true;
	
	while (k < i && switch_) {
		if (col[i] == col[k] || (abs(col[i] - col[k]) == (i-k))) {
			switch_ = false;
		}
		k++;
	}
	return switch_;
}

void queens(int i) {
	
	if (promising(i)) {
		if (i == 8) {
			if (col[search_col] == search_row) {
				counter++;
			}
		}
		else {
			for (int j = 1; j <= 8; j++) {
				col[i + 1] = j;					
				queens(i + 1);
			}		
		}
	}
}

int main() {
	int num_of_cases = 0;
	int input = 0;
	int num = 8;
	
	cin >> num_of_cases;
	cin.ignore();
	
	while (num_of_cases-- != 0) {
		counter = 0;
		cin >> input;
		cin.ignore();
		search_col = input;
		cin >> input;
		cin.ignore();
		search_row = input;
		queens(0);
		cout << counter << endl;
	}
}