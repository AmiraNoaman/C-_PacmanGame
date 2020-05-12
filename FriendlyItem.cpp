#include "FriendlyItem.h"
#include "Gold.h"
#include "Live.h"
#include "Platinum.h"
#include "Heart.h"

FriendlyItem::FriendlyItem(const Cell & pos):GameObject(pos)
{
}

FriendlyItem::FriendlyItem()
{
}

void FriendlyItem::ResetJustMoved()
{
	justMoved = false;
}

FriendlyItem::~FriendlyItem()
{
}

void FriendlyItem::Save(ofstream &OutFile, OBJECT_TYPE o)
{
	Cell m = GameObject::GetPosition();
	int x = m.HCell();
	int y = m.VCell();
	if (OutFile.is_open())
	{
		Gold* g = dynamic_cast<Gold*>(this);
		Heart *h = dynamic_cast<Heart*>(this);
		Platinum* p = dynamic_cast<Platinum*>(this);
		Live *l = dynamic_cast<Live*>(this);

		if (g)
			OutFile << "Gold" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << g->getTimeStep() << endl;
		else if (h)
			OutFile << "Hearts" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << h->getTimeStep() << endl;
		else if (p)
			OutFile << "Platinum" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << p->getTimeStep() << endl;
		else if (l)
			OutFile << "Lives" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << l->getTimeStep()<<"\t"<<l->GetL() << endl;
	}
}




