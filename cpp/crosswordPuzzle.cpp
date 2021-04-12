// # A 10*10 Crossword grid is provided to you, along with a set of words (or names of places)
// # which need to be filled into the grid. Cells are marked either + or -.
// # Cells marked with a - are to be filled with the word list.

// # The following shows an example crossword from the input
// # grid and the list of words to fit, 
// # words = [POLAND,INDIA,LHASA, SPAIN]

// # Input 	   		Output

// # ++++++++++ 		++++++++++
// # +------+++ 		+POLAND+++
// # +++-++++++ 		+++H++++++
// # +++-++++++ 		+++A++++++
// # +++-----++ 		+++SPAIN++
// # +++-++-+++ 		+++A++N+++
// # ++++++-+++ 		++++++D+++
// # ++++++-+++ 		++++++I+++
// # ++++++-+++ 		++++++A+++
// # ++++++++++ 		++++++++++

// # POLAND;LHASA;SPAIN;INDIA
#include<iostream>
using namespace std;

void printGrid(char grid[10][10]); 
void puzzle(char grid[10][10], string words[], int windx);
bool canplaceWordHorizontally(char grid[10][10], string word, int i,int j);
bool canplaceWordVertically(char grid[10][10], string word, int i,int j);
bool * placeWordHorizontally(char grid[10][10], string word,int i, int j,bool * weplaced);
bool * placeWordVertically(char grid[10][10], string word,int i, int j, bool * weplaced);
void unplaceWordHorizontally(char grid[10][10], bool * weplaced, string word, int i, int j);
void unplaceWordVertically(char grid[10][10], bool * weplaced, string word, int i, int j);


int main() {
	char grid[10][10];
	string words[4];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> words[i];
	}
	printGrid(grid);

	puzzle(grid, words, 0);

	return 0;
}

void printGrid(char grid[10][10]) {
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void puzzle(char grid[10][10], string words[], int windx) {
	// int word_length = word.length();

	if(windx == 4)  {        //base case
		printGrid(grid);
		return;
	}
	string word = words[windx];
	cout << windx << endl;

	for (int i = 0; i < 10; ++i)  
	{

		for (int j= 0; j < 10; ++j)
		{

			if(grid[i][j]=='-' || grid[i][j] == word[0]) {

				if(canplaceWordHorizontally(grid, word, i, j)) {
					bool * weplaced = new bool[word.length()];
					for (int i = 0; i < word.length(); ++i)
					{
						weplaced[i] = false;
					}
					cout << weplaced << endl;

				 	weplaced = placeWordHorizontally(grid, word, i, j, weplaced);
					puzzle(grid, words, windx+1);
					unplaceWordHorizontally(grid, weplaced, word, i, j);
				}

				if(canplaceWordVertically(grid, word, i, j)) {

					bool * weplaced = new bool[word.length()];
					for (int i = 0; i < word.length(); ++i)
					{
						weplaced[i] = false;
					}

					weplaced = placeWordVertically(grid, word, i, j, weplaced);
					puzzle(grid, words, windx+1);
					unplaceWordVertically(grid, weplaced, word, i, j);
				}
			}
		}
	}
}

bool canplaceWordHorizontally(char grid[10][10], string word, int i,int j) {
	
	if(j-1 >= 0 && grid[i][j-1] != '+') {
		// cout << "returning false1 " << i << j << endl;
		return false; // left check
	}

	else if(j + word.length()  <= 10 && grid[i][j] + word.length() != '+') {
		// cout << "returning false2 "<< i << j << endl;
		return false; //right check
	}

	for (int jj = 0; jj < word.length(); ++jj)
	{
		if (j+jj >= 9) 
			return false;

		if(grid[i][j+jj] == '-' || grid[i][j+jj] == word[jj]) 
			continue;
		else
			// cout << "returning false3 "<< i << j << endl;
			return false;
	}
	cout << "in canplaceWordHorizontally\n";
	return true;
}

bool canplaceWordVertically(char grid[10][10], string word, int i,int j) {
	if(i-1 >= 0 && grid[i-1][j] != '+') return false; //upper check

	if(i + word.length() <= 10 && grid[i][j] + word.length() != '+') return false; //lower check

	for (int ii = 0; ii < word.length(); ++ii)
	{
		if (i + ii >= 9) 
			return false;
		if(grid[i+ii][j] == '-' || grid[i+ii][j] == word[ii]) 
			continue;
		else
			return false;
	}
	return true;
}


bool * placeWordHorizontally(char grid[10][10], string word, int i, int j, bool * weplaced) {

	for (int jj = 0; jj < word.length(); ++jj)
	{
		if(grid[i][j+jj] == '-'){
			grid[i][j+jj] = word[jj];
			weplaced[jj] = true;
		}
	}
	cout << "executed\n";
	cout << weplaced << endl;
	return weplaced;
}


bool * placeWordVertically(char grid[10][10], string word, int i, int j, bool * weplaced) {
	for (int ii = 0; ii < word.length(); ++ii)
	{
		if(grid[i+ii][j] == '-'){
			grid[i+ii][j] = word[ii];
			weplaced[ii] = true;
		}
	}
	return weplaced;
}


void unplaceWordHorizontally(char grid[10][10], bool weplaced[] ,string word, int i, int j) {
	for (int jj = 0; jj < word.length(); ++jj)
	{
		if(*(weplaced+jj) == true) 
			grid[i][j+jj] = '-';
	}
}

void unplaceWordVertically(char grid[10][10], bool weplaced[] ,string word, int i, int j) {
	for (int ii = 0; ii < word.length(); ++ii)
	{
		if(*(weplaced+ii) == true) 
			grid[i+ii][j] = '-';
	}
}