#include "../pch.h"
#include "../Include/InputComponent.h"
#include "../Include/Object.h"
#include "../Include/MoveObject.h"


InputComponent::InputComponent()
	:m_pOwner(nullptr)
{
}


InputComponent::~InputComponent()
{
}

bool InputComponent::Init(Object* object)
{
	if (object->GetObjectType() != Types::OT_PLAYER)
		return false;

	m_pOwner = static_cast<MoveObject*>(object);

	return true;
}

void InputComponent::Update(const float& deltaTime)
{

	if (KEY_DOWN(VK_UP)) {
		m_pOwner->SetDirection(Types::DIR_UP);
		//return;
	}
	else if (KEY_DOWN(VK_DOWN)) {
		m_pOwner->SetDirection(Types::DIR_DOWN);
		//return;
	}
	else if (KEY_DOWN(VK_LEFT)) {
		m_pOwner->SetDirection(Types::DIR_LEFT);
		//return;
	}
	else if (KEY_DOWN(VK_RIGHT)) {
		m_pOwner->SetDirection(Types::DIR_RIGHT);
		//return;
	}
	else {
		//방향키 입력이 없으면 IDLE상태로 변경함.
		m_pOwner->SetDirection(Types::DIR_IDLE);
	}

	if (KEY_DOWN(VK_SPACE)) {
		if (m_pOwner->GetObjectState() != Types::OS_JUMP) {
			m_pOwner->SetObjectState(Types::OS_JUMP);
			//return;
		}
	}

}
