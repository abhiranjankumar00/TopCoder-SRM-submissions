#include <bits/stdc++.h>
using namespace std;

int lastRoom=588;

class roomSelector {
	int base;
	int N;
public:
	roomSelector(int N) {
		base = 144;
		this->N = N;
		time_t tm; time(&tm); srand(tm);
	}
	int getRandomRoom() {
		return base + rand() % (N-base+1);
	}
};

int main(int argc, char **argv)
{
	if(argc > 1) {
		stringstream ss(argv[1]);
		ss >> lastRoom;
	}

	cout << "Goto room number " << roomSelector(lastRoom).getRandomRoom() << endl;

	return 0;
}

