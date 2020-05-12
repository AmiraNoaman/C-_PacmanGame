#include "Cell.h"

#include "UI_Info.h"

Cell::Cell () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

Cell::Cell (int v, int h)
{ 
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

bool Cell::SetVCell(int v) // the setter of vCell (the setter here sets only if in the the cell is in grid range)
{
	if (v >=0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	return false;
}

bool Cell::SetHCell(int h) // the setter of hCell (the setter here sets only if in the the cell is in grid range)
{
	if (h >=0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	return false;
}

int Cell::VCell() const // the getter of vCell
{
	return vCell;
}

int Cell::HCell() const // the getter of hCell
{
	return hCell;
}

bool Cell::IsValidCell() const
{
	return (vCell >= 0 && vCell < NumVerticalCells) 
			&& (hCell >=0 && hCell < NumHorizontalCells);
}

bool Cell::operator == (const Cell & other) const
{
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION
	if (hCell == other.hCell && vCell == other.vCell)
		return true;
	else
		return false; // this line should be removed and replaced by your code
}

bool Cell::operator != (const Cell & other) const
{
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION

	return !(*this == other); // this line should be removed and replaced by your code
}