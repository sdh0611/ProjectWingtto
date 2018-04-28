#include "../pch.h"
#include "../Include/CollisionDetector.h"
#include "../Include/ColliderBox.h"



CollisionDetector::CollisionDetector()
{
}


CollisionDetector::~CollisionDetector()
{
}

bool CollisionDetector::CheckCollisionRect(ColliderBox * pBox, ColliderBox * pOtherBox)
{
	


	if ((pBox->GetColliderBox().right > pOtherBox->GetColliderBox().left)
		&& (pBox->GetColliderBox().left < pOtherBox->GetColliderBox().right)) 
		if ((pBox->GetColliderBox().bottom < pOtherBox->GetColliderBox().top)
			&& (pBox->GetColliderBox().top > pOtherBox->GetColliderBox().bottom))
			return true;
	
	return false;
}

bool CollisionDetector::CheckCollisionCircle(ColliderCircle * pCircle, ColliderCircle * pOtherCircle)
{
	



	return false;
}

bool CollisionDetector::CheckCollisionRectCircle(ColliderBox * pBox, ColliderCircle * pCircle)
{



	return false;
}
