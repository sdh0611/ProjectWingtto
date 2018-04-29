//충돌을 검사하는데 필요한 정보들을 담고 있는 Collider 객체
//Object 내부에 포함되어 사용된다.
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
