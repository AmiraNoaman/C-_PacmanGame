#pragma once 

class Cell
{
	int vCell; // the vertical cell number: starts from 0 to number of vertical cells - 1
	int hCell; // the horizontal cell number: starts from 0 to number of horizontal cells - 1

public:
	Cell (); // Initializes the cell to (-1,-1) indicating uninitialized with valid values
	Cell (int v, int h); // Sets vCell and hCell if they are valid
	                     // If not valid, it sets the invalid with -1

	bool SetVCell(int v); // The setter of vCell (this setter sets only if the cell is in grid range), otherwise, no change
	bool SetHCell(int h); // The setter of hCell (this setter  sets only if the cell is in grid range), otherwise, no change

	int VCell() const; // The getter of vCell
	int HCell() const; // The getter of hCell

	bool IsValidCell() const; // Checks if the cell is valid (inside grid range)
	
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION
	bool operator == (const Cell & other) const; // Operator Overloading : Check if the passed cell equals the current cell

	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION
	bool operator != (const Cell & other) const; // Operator Overloading : Check if the passed cell does NOT equal the current cell

	// note: this struct does NOT deal with real coordinates, it deals with the cell number instead
	// Example: if vCell = 1 and hCell = 2 --> that means cell with ** in the grid drawn below

	// any pair is: (vCell, hCell)

	// ----------------------------
	// | (0,0) | (0,1) | (0,2)   |
	// ----------------------------
	// | (1,0) | (1,1) | (1,2)** |
	// ----------------------------
	// | (2,0) | (2,1) | (2,2)   |
	// ----------------------------
};

