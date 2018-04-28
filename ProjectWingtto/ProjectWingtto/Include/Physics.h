//�������õ� �۾��� ������ ����������Ʈ ��ü
//�߷� ���� �� �Ϸ��.
#pragma once

#include "../pch.h"

class MoveObject;

class Physics
{
public:
	Physics();
	~Physics();


public:
	bool Init();
	void Update(MoveObject& object, const float& deltaTime);
	void Move(MoveObject& object, const float& deltaTime);
	//void Move(const Types::Direction& dir, const float& speed, const float& deltaTime);
	void Gravity(MoveObject& object, const float& deltaTime);


public:
	inline void SetPhysicsOn(bool bIsPhysics) { m_bPhysicsOn = bIsPhysics; }



private:
	bool					m_bPhysicsOn;
	float					m_fGravityAccel;
	float					m_fSpeed;
	float					m_fWeight;
	float					m_fJumpForce;
	MoveObject*			m_pOwner;

};
