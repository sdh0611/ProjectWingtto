#include "../pch.h"
#include "../Include/Physics.h"
#include "../Include/MoveObject.h"



Physics::Physics()
	:m_pOwner(nullptr)
{
}

Physics::~Physics()
{
}

bool Physics::Init()
{
	m_bPhysicsOn = true;
	m_fGravityAccel = 20.f;
	m_fSpeed = 500.f;
	m_fWeight = 50.f;
	m_fJumpForce = 100.f;


	return true;
}

void Physics::Update(MoveObject& object, const float& deltaTime)
{
	Move(object, deltaTime);
	
	if(object.GetObjectState() == Types::OS_JUMP)
		Gravity(object, deltaTime);



}

void Physics::Move(MoveObject& object, const float& deltaTime) {


	switch (object.GetDirection()) {
	case Types::DIR_UP:
		object.SetPosition(object.GetPosition().x, object.GetPosition().y - m_fSpeed * deltaTime);
		break;
	case Types::DIR_DOWN:
		object.SetPosition(object.GetPosition().x, object.GetPosition().y + m_fSpeed * deltaTime);
		break;
	case Types::DIR_RIGHT:
		object.SetPosition(object.GetPosition().x + m_fSpeed * deltaTime, object.GetPosition().y);
		break;
	case Types::DIR_LEFT:
		object.SetPosition(object.GetPosition().x - m_fSpeed * deltaTime, object.GetPosition().y);
		break;
	}


}

void Physics::Gravity(MoveObject & object, const float & deltaTime)
{

	if (object.GetPosition().y < 300) {
		object.SetPosition(object.GetPosition().x, object.GetPosition().y + m_fGravityAccel*deltaTime);
		if(m_fGravityAccel < 300.f)
			m_fGravityAccel += 5.f;
	}

/*
	if (object.GetObjectState() == Types::OS_JUMP) {
		if (m_fJumpForce > 0) {
			object.SetPosition(object.GetPosition().x, object.GetPosition().y - m_fGravityAccel);
			m_fGravityAccel += 2.f;
		}
		else if (m_fJumpForce) {


		}
	}*/

}

//void Physics::Move(const Types::Direction & dir, const float & speed, const float & deltaTime)
//{
//	
//
//}