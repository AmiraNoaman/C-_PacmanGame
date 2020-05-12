#include "Current_Grid.h"
#include "ApplicationManager.h"


Current_Grid::Current_Grid(ApplicationManager *pApp):Action(pApp)
{
}
void Current_Grid::ReadActionParameters() {

}
void Current_Grid::Execute() {
	pManager->StartGame();
}
Current_Grid::~Current_Grid()
{
}
