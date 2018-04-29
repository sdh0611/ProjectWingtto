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

bool Physics::Init(Object* pOwner)
{
	m_pOwner = static_cast<MoveObject*>(pOwner);

	m_bPhysicsOn = true;
	m_fGravityAccel = 20.f;
	m_fSpeed = 500.f;
	m_fWeight = 50.f;
	m_fJumpForce = 100.f;


	return true;
}

void Physics::Update(const float& deltaTime)
{
	Move(deltaTime);
	
	if(m_pOwner->GetObjectState() == Types::OS_JUMP)
		Gravity(deltaTime);



}

void Physics::Move(const float& deltaTime) {


	switch (m_pOwner->GetDirection()) {
	case Types::DIR_UP:
		m_pOwner->SetPosition(m_pOwner->GetPosition().x, m_pOwner->GetPosition().y - m_fSpeed * deltaTime);
		break;
	case Types::DIR_DOWN:
		m_pOwner->SetPosition(m_pOwner->GetPosition().x, m_pOwner->GetPosition().y + m_fSpeed * deltaTime);
		break;
	case Types::DIR_RIGHT:
		m_pOwner->SetPosition(m_pOwner->GetPosition().x + m_fSpeed * deltaTime, m_pOwner->GetPosition().y);
		break;
	case Types::DIR_LEFT:
		m_pOwner->SetPosition(m_pOwner->GetPosition().x - m_fSpeed * deltaTime, m_pOwner->GetPosition().y);
		break;
	}


}

void Physics::Gravity(const float & deltaTime)
{

	if (m_pOwner->GetPosition().y < 300) {
		m_pOwner->SetPosition(m_pOwner->GetPosition().x, m_pOwner->GetPosition().y + m_fGravityAccel*deltaTime);
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