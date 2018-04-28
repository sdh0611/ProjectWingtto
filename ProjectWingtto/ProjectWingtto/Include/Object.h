//게임에서 사용될 Object들의 공통 인터페이스 정의
//움직일수 있는 오브젝트들에 대한 정보를
//첨가클래스로 따로 분리해내는게 좋을 것 같긴하네..
// -> 그럼 좌표값에 대한 정보는 어떤 클래스에서..?
// 그냥 Object에 speed에 대한 값도 넣어놓기로..(18.04.27)


#pragma once

#include "../pch.h"


class Object
{
public:
	Object(Types::ObjectType, Types::POINT point, Types::SIZE size);
	virtual ~Object();


public:
	virtual bool Init(const HDC& hDC) { return true; }
	virtual bool Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(float deltaTime, const HDC& hDC) = 0;


public:
	Types::ObjectType GetObjectType() const { return m_ObjectType; }
	void SetSize(int width, int height) { m_iSize.width = width; m_iSize.height = height; }
	const Types::SIZE& GetSize() const { return m_iSize; }
	void SetObjectState(Types::ObjectState state) { m_ObjectState = state; }
	Types::ObjectState GetObjectState() const { return m_ObjectState;  }
	void SetPosition(float nx, float ny) { m_Position.x = nx; m_Position.y = ny; }
	const Types::POINT& GetPosition() const { return m_Position; }


protected:




protected:
	class Sprite *						m_pSprite;
	class ColliderBox*				m_pCollider;	//미구현(18.04.25)
	Types::ObjectType				m_ObjectType;
	Types::ObjectState				m_ObjectState;
	//Types::Direction					m_ObjectDirection;
	Types::POINT						m_Position;
	Types::SIZE						m_iSize;
	

};
