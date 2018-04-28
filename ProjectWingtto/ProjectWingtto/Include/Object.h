//���ӿ��� ���� Object���� ���� �������̽� ����
//�����ϼ� �ִ� ������Ʈ�鿡 ���� ������
//÷��Ŭ������ ���� �и��س��°� ���� �� �����ϳ�..
// -> �׷� ��ǥ���� ���� ������ � Ŭ��������..?
// �׳� Object�� speed�� ���� ���� �־�����..(18.04.27)


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
	class ColliderBox*				m_pCollider;	//�̱���(18.04.25)
	Types::ObjectType				m_ObjectType;
	Types::ObjectState				m_ObjectState;
	//Types::Direction					m_ObjectDirection;
	Types::POINT						m_Position;
	Types::SIZE						m_iSize;
	

};
