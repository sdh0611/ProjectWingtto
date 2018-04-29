//�浹�� �˻��ϴµ� �ʿ��� �������� ��� �ִ� Collider ��ü
//Object ���ο� ���ԵǾ� ���ȴ�.
#pragma once

#include "../pch.h"
#include "../Include/Collider.h"

class Object;

class ColliderBox : public Collider
{
public:
	ColliderBox();
	~ColliderBox();


public:
	virtual bool Init(Object* object) override;
	virtual void Update(const float& deltaTime) override;
	void SetColliderBox(float left, float top, float right, float bottom);
	const Types::RECTANGLE& GetColliderBox() const;


private:
	Types::RECTANGLE			m_rBox;

};
