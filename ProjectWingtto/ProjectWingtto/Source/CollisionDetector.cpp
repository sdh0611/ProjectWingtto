#include "../pch.h"
#include "../Include/CollisionDetector.h"
#include "../Include/ColliderBox.h"
#include "../Include/ColliderCircle.h"




CollisionDetector::CollisionDetector()
{
}


CollisionDetector::~CollisionDetector()
{
}

bool CollisionDetector::Init()
{
	return false;
}

void CollisionDetector::Update(Collider* collider, Collider* other)
{
	switch (collider->GetColliderType()) {
	case Types::CT_BOX:
		if (other->GetColliderType() == Types::CT_CIRCLE)
			CheckCollisionBoxCircle(static_cast<ColliderBox*>(collider), static_cast<ColliderCircle*>(other));
		else if(other->GetColliderType() == Types::CT_BOX)
			CheckCollisionBox(static_cast<ColliderBox*>(collider), static_cast<ColliderBox*>(other));

	case Types::CT_CIRCLE:
		if (other->GetColliderType() == Types::CT_CIRCLE)
			CheckCollisionCircle(static_cast<ColliderCircle*>(collider), static_cast<ColliderCircle*>(other));
		else if (other->GetColliderType() == Types::CT_BOX)
			CheckCollisionBoxCircle(static_cast<ColliderBox*>(other), static_cast<ColliderCircle*>(other));

	}



}

bool CollisionDetector::CheckCollisionBox(ColliderBox * pBox, ColliderBox * pOtherBox)
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

bool CollisionDetector::CheckCollisionBoxCircle(ColliderBox * pBox, ColliderCircle * pCircle)
{



	return false;
}
