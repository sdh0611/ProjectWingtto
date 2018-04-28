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
		player.SetDirection(Types::DIR_UP);
		//return;
	}
	else if (KEY_DOWN(VK_DOWN)) {
		player.SetDirection(Types::DIR_DOWN);
		//return;
	}
	else if (KEY_DOWN(VK_LEFT)) {
		player.SetDirection(Types::DIR_LEFT);
		//return;
	}
	else if (KEY_DOWN(VK_RIGHT)) {
		player.SetDirection(Types::DIR_RIGHT);
		//return;
	}
	else {
		//����Ű �Է��� ������ IDLE���·� ������.
		player.SetDirection(Types::DIR_IDLE);
	}

	if (KEY_DOWN(VK_SPACE)) {
		if (player.GetObjectState() != Types::OS_JUMP) {
			player.SetObjectState(Types::OS_JUMP);
			//return;
		}
	}

}
