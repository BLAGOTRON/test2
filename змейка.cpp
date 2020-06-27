#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameover;
const int dlinn = 30;
const int visota = 30;
int x, y, fX, fY, score, endt;
int tx[100], ty[100];
enum edirection { stop = 0, lef, rig, up, down };
edirection dir;
 
void setup() {
	gameover = false;
	dir = stop;
	x = dlinn / 2 - 1;
	y = visota / 2 - 1;
	fX = rand() % (dlinn);
	fY = rand() % (visota);
	score = 0;
	
}

void draw() {
	system("cls");
	for (int i = 0; i < dlinn+1; i++)
		cout << "#";
	cout << endl;


	for (int i = 0; i < visota; i++) {
		for (int j = 0; j <= dlinn; j++) {
			if (j == 0 || j == dlinn)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fY && j == fX)
				cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < endt; k++) {
					if (tx[k] == j && ty[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print)
				cout << " ";
			}

			
		}

		cout << endl;
	}


	for (int i = 0; i < dlinn+1; i++)
			cout << "#";
		cout << endl;

		cout << "score=" << score;

	}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = lef;
			break;
		case 'd':
			dir = rig;
			break;
		case 'w':
			dir = up;
			break;
		case 's':
			dir = down;
			break;
		case 'x':
			gameover = true;
			break;

		}

	}
}

void Logic() {
	int prevx = tx[0];
	int prevy = ty[0];
	int prev2x, prev2y;
	tx[0] = x;
	ty[0] = y;
	for (int i = 1; i < endt; i++) {
		prev2x = tx[i];
		prev2y = ty[i];
		tx[i] = prevx;
		ty[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{
	
	case lef:
		x--;
		break;
	case rig:
		x++;
		break;
	case up:
		y--;
		break;
	case down:
		y++;
		break;
     }
	if (x >= dlinn || x < 0 || y >= visota || y < 0)
		gameover = true;
	for (int i = 0; i < endt; i++) {
		if (tx[i] == x && ty[i] == y)
			gameover = true;
	}
	if (x == fX && y == fY) {
		score++;
		endt++;
		srand(time(NULL));
		fX = rand() % dlinn;
		fY = rand() % visota;

	}


}


 

int main() {
	setup();
	while (!gameover) {
		draw();
		Input();
		Logic();
	}
	return 0;
}

