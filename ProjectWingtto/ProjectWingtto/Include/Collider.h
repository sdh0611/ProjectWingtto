//Collider들의 추상클래스 정의

#pragma once
#include "../pch.h"
#include "./ComponentBase.h"


class Object;

class Collider : public ComponentBase{
public:
	Collider(Types::ColliderType type) : m_pOwner(nullptr), m_ColliderType(type) { };
	virtual ~Collider(){ }


public:
	virtual bool Init(Object* object) = 0;
	virtual void Update(const float& deltaTime) = 0;
	


public:
	virtual void SetColliderActive(bool bIsActive) { m_bOn = bIsActive; }
	virtual const bool GetOccurCollision() const { return m_bOccurCollision; }
	virtual void SetOccurCollision(bool bOccurCollsion) { m_bOccurCollision = bOccurCollsion; }
	virtual const Types::ColliderType GetColliderType() { return m_ColliderType; }


protected:
	bool							m_bOn;
	bool							m_bOccurCollision;
	Types::ColliderType			m_ColliderType;
	Object*						m_pOwner;

};