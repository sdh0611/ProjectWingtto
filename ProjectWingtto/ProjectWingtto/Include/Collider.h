//Collider���� �߻�Ŭ���� ����

#pragma once
#include "../pch.h"
#include "./ComponentBase.h"


class Object;

class Collider : public ComponentBase{
public:
	Collider() : m_pOwner(nullptr) { };
	virtual ~Collider(){ }


public:
	virtual bool Init(Object* object) = 0;
	virtual void Update(const float& deltaTime) = 0;
	


public:
	virtual void SetColliderActive(bool bIsActive) { m_bOn = bIsActive; }


protected:
	bool							m_bOn;
	Object*						m_pOwner;

};