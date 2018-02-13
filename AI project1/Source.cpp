////Antonio De La Garza
////20334472
//// February 12, 2018

////AI Project 1: Vacuum Agent////////

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


void moveEast(int &posX, int &posY) {
	posY++;
}

void moveWest(int &posX, int &posY) {
	posY--;
}

void moveNorth(int &posX, int &posY) {
	posX--;
}

void moveSouth(int &posX, int &posY) {
	posX++;
}



void fillArray(char**arr, int num) {
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr[i][j] = '0';
		}
	}
}

void randomOnes(char**arr, int per, int n) {
	int square = n*n;
	int percentOnes;
	
	if (per == 25) {
		percentOnes = square * 0.25;
	}
	else if (per == 50) {
		percentOnes = square * 0.50;
	}
	else if (per == 75) {
		percentOnes = square * 0.75;
	}

	else {
		return;
	}
	
	srand(time(0));
	int ran1 = rand() % n;
	int ran2 = rand() % n;


	for (int i = 0; i < percentOnes; i++) {		
		ran1 = rand() % n;
		ran2 = rand() % n;

		if (arr[ran1][ran2] == '1') {
			i--;
		}
		else {
			arr[ran1][ran2] = '1';
		}
	}
	
}

void printArray(char**&arr, int num) {
	for (int row = 0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			cout <<setw(5)<< arr[row][col];
		}
		cout << endl;
	}
}

int main() {
	srand(time(0));
	int n;
	int percent;
	int strategy;
	char**grid;
	int dirtyTiles;
	int moves = 0;
	cout << "Hello and Wellcome to the Vacuum Simulator!!!" << endl;
	cout << "What will be the dimensions of your grid? Your number will be squared. " << endl;;
	cin >> n;
	grid = new char*[n];
	
	for (int i = 0; i < n; i++) {
		grid[i] = new char[n];
	}

	cout << "What percentage of the grid will be dirty? You can choose either 25%, 50%, or 75%. " << endl;;
	cin >> percent;

	fillArray(grid, n);
	randomOnes(grid, percent, n);
	printArray(grid, n);

	if (percent == 25) {
		dirtyTiles = (n*n) * 0.25;
	}
	else if (percent == 50) {
		dirtyTiles = (n*n) * 0.50;
	}
	else if (percent == 75) {
		dirtyTiles = (n*n) * 0.75;
	}

	else {
		dirtyTiles = 0;
		cout << "Your grid is already clean. No need for a vacuum." << endl;
		system("pause");
		return 0;
	}
	
	cout << "What strategy would you like your agent to follow? " << endl;
	cin >> strategy;

	
	
	if (strategy == 1) {
		int i = 0;
		int x = rand() % n;
		int y = rand() % n;
		char hold;

		hold = grid[x][y];
		grid[x][y] = 'V';
		moves++;
		cout << endl;
		cout << "moves: " << moves << endl;
		printArray(grid, n);
		if (hold == '0') {
			grid[x][y] = '2';
		}
		else if (hold == '1') {
			grid[x][y] = '3';
			i++;
		}
		cout << endl;
		printArray(grid, n);
		if (i == dirtyTiles) {
			cout << endl;
			cout << "Your strategy took you " << moves << " moves to clean the grid" << endl;

			system("pause");
			return 0;
		}

		while (true) {
//////////////////////////////////////////////////////////////////////////////////
			// A) Keep moving to the east until it hits the east boundary.
			while (true) {
				if (y + 1 == n) {
					break;
				}
				else {
					moveEast(x, y);
					while (y < n) {
						if (y + 1 == n) {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
							break;
						}
						else {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
						}
						moveEast(x, y);
					}
					break;
				}
	
			}
			if (i == dirtyTiles) break;

//////////////////////////////////////////////////////////////////////////////////
			// B) Move one square to the south. If the south boundary is reached, go to (e). 
			while (true) {
				if (x + 1 == n) {
					goto e;
				}
				else {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					break;
				}
				
			}
			if (i == dirtyTiles) break;
			

//////////////////////////////////////////////////////////////////////////////////
			// C) Keep moving to the west until it hits the west boundary.
			c:
			while (true) {
				if (y - 1 < 0) {
					break;
				}
				else {
					moveWest(x, y);
					while (y >= 0) {
						if (y - 1 < 0) {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
							break;
						}
						else {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
						}
						moveWest(x, y);
					}
					break;
				}
			}
			if (i == dirtyTiles) break;

//////////////////////////////////////////////////////////////////////////////////
			//D) Move one square to the south, If the south boundary is reached, go to (f). Otherwise, go to (a)
			while (true) {
				if (x + 1 == n) {
					goto f;
				}
				else {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					break;
				}
			}
			if (i == dirtyTiles) break;
			
			continue;

//////////////////////////////////////////////////////////////////////////////////
			// E) Keep moving to the north until it hits the north boundary and then go to (c)
			e:
			while (true) {
				if (x - 1 < 0) {
					break;
				}
				else {
					moveNorth(x, y);
					while (x >= 0) {
						if (x - 1 < 0) {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
							break;
						}
						else {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
						}
						moveNorth(x, y);
					}
					break;
				}
				
			}
			if (i == dirtyTiles) break;
			goto c;

//////////////////////////////////////////////////////////////////////////////////
			// F) Keep moving to the north until it hits the north boundary and then go to (a)
			f:
			while (true) {
				if (x - 1 < 0) {
					break;
				}
				else {
					moveNorth(x, y);
					while (x >= 0) {
						if (x - 1 < 0) {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
							break;
						}
						else {
							hold = grid[x][y];
							grid[x][y] = 'V';
							moves++;
							cout << endl;
							cout << "moves: " << moves << endl;
							printArray(grid, n);
							if (hold == '0') {
								grid[x][y] = '2';
							}
							else if (hold == '1') {
								grid[x][y] = '3';
								i++;
							}
							else if (hold == '2') {
								grid[x][y] = '2';
							}
							else if (hold == '3') {
								grid[x][y] = '3';
							}
							cout << endl;
							printArray(grid, n);
							if (i == dirtyTiles) break;
						}
						moveNorth(x, y);
					}
					break;
				}
				
			}
			if (i == dirtyTiles) break;

			continue;

		}
	}
 //////// Done with strategy 1////////
//////////////////////////////////////////////////////////////////////////////////
	else if (strategy == 2) {
		int i = 0;
		int x = rand() % n;
		int y = rand() % n;
		char hold;
		int selectFunction;

		hold = grid[x][y];
		grid[x][y] = 'V';
		cout << endl;
		moves++;
		cout << "moves: " << moves << endl;
		printArray(grid, n);
		if (hold == '0') {
			grid[x][y] = '2';
		}
		else if (hold == '1') {
			grid[x][y] = '3';
			i++;
		}
		cout << endl;
		printArray(grid, n);
		if (i == dirtyTiles) {
			cout << "Your strategy took you " << moves << " moves to clean the grid" << endl;
			system("pause");
			return 0;
		}

		while (true) {
			////////////// Check each corner ///////////////
			//// top left corner
			if (x == 0 && y == 0) {
				selectFunction = rand() % 2;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " <<moves<< endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			////// bottom left corner
			else if (x + 1 == n && y == 0) {
				selectFunction = rand() % 2;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			///////top right corner
			else if (x == 0 && y + 1 == n) {
				selectFunction = rand() % 2;
				if (selectFunction == 0) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			////bottom right corner
			else if (x + 1 == n && y + 1 == n) {
				selectFunction = rand() % 2;
				if (selectFunction == 0) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			
			////////////// Check the edges ///////////////////
			////top edge
			else if (x == 0 && (y != 0 && y != n - 1)) {
				selectFunction = rand() % 3;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 2) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			/////left edge
			else if ((x != 0 && x != n - 1) && y == 0) {
				selectFunction = rand() % 3;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 2) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			////bottom edge
			else if (x + 1 == n && (y != 0 && y != n - 1)) {
				selectFunction = rand() % 3;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 2) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
			/////right edge
			else if ((x != 0 && x != n - 1) && y + 1 == n) {
				selectFunction = rand() % 3;
				if (selectFunction == 0) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 2) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}

			////////////// Agent is on the center ///////////////////
			else {
				selectFunction = rand() % 4;
				if (selectFunction == 0) {
					moveEast(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 1) {
					moveWest(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 2) {
					moveNorth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
				else if (selectFunction == 3) {
					moveSouth(x, y);
					hold = grid[x][y];
					grid[x][y] = 'V';
					moves++;
					cout << endl;
					cout << "moves: " << moves << endl;
					printArray(grid, n);
					if (hold == '0') {
						grid[x][y] = '2';
					}
					else if (hold == '1') {
						grid[x][y] = '3';
						i++;
					}
					else if (hold == '2') {
						grid[x][y] = '2';
					}
					else if (hold == '3') {
						grid[x][y] = '3';
					}
					cout << endl;
					printArray(grid, n);
					if (i == dirtyTiles) break;
					continue;
				}
			}
		}


	}
///////// done with strategy 2///////////////////////
//////////////////////////////////////////////////////////////////////////////////

	cout << "Your strategy took you " << moves << " moves to clean the grid" << endl;

	system("pause");
	return 0;
}