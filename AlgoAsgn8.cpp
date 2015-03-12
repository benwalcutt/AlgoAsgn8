#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

static int col[9] = {0,0,0,0,0,0,0,0,0};
static int num = 8;
static int counter = 0;

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
			for (int i = 1; i <= 8; i++) {
				cout << col[i];
				if (col[6] == 7) {
					//counter++;
				}
			}
			
			cout << endl;
			if (col[6] == 7) {
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
	int num = 8;
	queens(0);
	cout << counter << endl;
}