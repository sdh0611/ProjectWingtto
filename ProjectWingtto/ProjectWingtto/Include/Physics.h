//�������õ� �۾��� ������ ����������Ʈ ��ü
//�߷� ���� �� �Ϸ��.
#pragma once

#include "../pch.h"
#include "./ComponentBase.h"


class MoveObject;

class Physics:public ComponentBase
{
public:
	Physics();
	~Physics();


public:
	bool Init(class Object* pOwner) override;
	void Update(const float& deltaTime) override;
	void Move(const float& deltaTime);
	//void Move(const Types::Direction& dir, const float& speed, const float& deltaTime);
	void Gravity(const float& deltaTime);


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
