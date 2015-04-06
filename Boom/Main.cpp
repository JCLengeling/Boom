#include <iostream>
using namespace std;

void explode(char** field, int r, int n, int x, int y){

	for (int c = 1; c <= r; c++){
		if (x - c < 0){
			break;
		}
		if (field[x - c][y] == '#'){
			break;
		}else if (field[x - c][y] == 'S'){
			field[x - c][y] = '.';
		}else if (field[x - c][y] == '*'){
			field[x - c][y] = '.';
			explode(field, r, n, x - c, y);
		}

	}

	for (int c = 1; c <= r; c++){
		if (x + c >= n){
			break;
		}
		if (field[x + c][y] == '#'){
			break;
		}else if (field[x + c][y] == 'S'){
			field[x + c][y] = '.';
		}else if (field[x + c][y] == '*'){
			field[x + c][y] = '.';
			explode(field, r, n, x + c, y);
		}
	}

	for (int c = 1; c <= r; c++){
		if (y - c < 0){
			break;
		}
		if (field[x][y-c] == '#'){
			break;
		}else if (field[x][y-c] == 'S'){
			field[x][y-c] = '.';
		}else if (field[x][y-c] == '*'){
			field[x][y-c] = '.';
			explode(field, r, n, x, y-c);
		}
	}

	for (int c = 1; c <= r; c++){
		if (y + c >= n){
			break;
		}
		if (field[x][y + c] == '#'){
			break;
		}else if (field[x][y + c] == 'S'){
			field[x][y + c] = '.';
		}else if (field[x][y + c] == '*'){
			field[x][y + c] = '.';
			explode(field, r, n, x, y + c);
		}
	}


	return;
}

void main(){
	int n = 0, r = 0, possibleSolutions = 0;
	char **field;
	char ** tmpField;
	cin >> n >> r;

	field = new char*[n];
	tmpField = new char*[n];

	for (int i = 0; i < n; i++){
		field[i] = new char[n];
		tmpField[i] = new char[n];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (field[i][j] == '.'){
				// copy field
				for (int k = 0; k < n; k++){
					for (int l = 0; l < n; l++){
						tmpField[k][l] = field[k][l];
					}
				}

				//blow all possible stumps 
				explode(tmpField, r, n, i, j);
				
				//check if there are still stumps
				int counter = 0;
				for (int k = 0; k < n; k++){
					for (int l = 0; l < n; l++){
						if (tmpField[k][l] == 'S'){
							counter++;
							break;
						}
					}
					if (counter != 0){
						break;
					}
				}

				if (counter == 0){
					possibleSolutions++;
				}
			}
		}
	}

	cout << possibleSolutions  << "\n";
	system("pause");
}