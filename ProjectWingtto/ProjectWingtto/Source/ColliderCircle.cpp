#include "../pch.h"
#include "../Include/ColliderCircle.h"

ColliderCircle::ColliderCircle()
	:Collider(Types::CT_CIRCLE)
{

}

bool ColliderCircle::Init(Object * object)
{
	m_pOwner = object;
	

	return true;
}

void ColliderCircle::Update(const float & deltaTime)
{
}

void ColliderCircle::SetRadius(float radius)
{
	fRadius = radius;
}
