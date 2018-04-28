//움직이는 오브젝트들의 인터페이스

#pragma once
#include "../pch.h"
#include "../Include/Object.h"



class MoveObject : public Object{
public:
	MoveObject(Types::ObjectType, Types::POINT point, Types::SIZE size);
	virtual ~MoveObject();


public:
	virtual bool Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(float deltaTime, const HDC& hDC) = 0;

public:
	void SetDirection(Types::Direction dir) { m_Direction = dir; }
	Types::Direction GetDirection() { return m_Direction; }


protected:
	Types::Direction			m_Direction;
	class Physics*			m_pPhysics;



};