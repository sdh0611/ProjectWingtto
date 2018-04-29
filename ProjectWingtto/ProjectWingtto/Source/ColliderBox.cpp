#include "../pch.h"
#include "../Include/ColliderBox.h"
#include "../Include/Object.h"


ColliderBox::ColliderBox()
	:Collider(Types::CT_BOX)
{


}


ColliderBox::~ColliderBox()
{


}

bool ColliderBox::Init(Object * object)
{
	m_pOwner = object;
	SetColliderBox(m_pOwner->GetPosition().x, m_pOwner->GetPosition().y - m_pOwner->GetSize().height,
		m_pOwner->GetPosition().x + m_pOwner->GetSize().width, m_pOwner->GetPosition().y);

	return true;
}

void ColliderBox::Update(const float& deltaTime)
{
	SetColliderBox(m_pOwner->GetPosition().x, m_pOwner->GetPosition().y - m_pOwner->GetSize().height,
		m_pOwner->GetPosition().x + m_pOwner->GetSize().width, m_pOwner->GetPosition().y);

	
}

void ColliderBox::SetColliderBox(float left, float top, float right, float bottom)
{

	m_rBox.left = left;
	m_rBox.top = top;
	m_rBox.right = right;
	m_rBox.bottom = bottom;

}

const Types::RECTANGLE& ColliderBox::GetColliderBox() const
{



	return m_rBox;
}
